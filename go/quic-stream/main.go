package main

import (
	"context"
	"crypto/rand"
	"crypto/rsa"
	"crypto/tls"
	"crypto/x509"
	"encoding/pem"
	"io"
	"log"
	"math/big"
	"os"

	"github.com/lucas-clemente/quic-go"
)

const (
	addr  = "localhost:4242"
	nargs = 2
)

// a wrapper for io.Writer that also logs the message.
type loggingWriter struct {
	Mode string
	io.Writer
}

// nolint: wrapcheck
func (w loggingWriter) Write(b []byte) (int, error) {
	log.Printf("%s: got %q\n", w.Mode, string(b))

	return w.Writer.Write(b)
}

func main() {
	if len(os.Args) != nargs {
		log.Fatalf("%s <mode>\nmode: client, server", os.Args[0])
	}

	if os.Args[1] == "server" {
		listener, err := quic.ListenAddr(addr, generateTLSConfig(), nil)
		if err != nil {
			log.Fatalf("quic listen failed %s", err)
		}

		for {
			conn, err := listener.Accept(context.Background())
			if err != nil {
				log.Fatalf("quic accept failed %s", err)
			}

			go handler(conn)
		}
	} else {
		client()
	}
}

// handler accepts first stream of the client.
func handler(conn quic.Connection) {
	stream, err := conn.AcceptStream(context.Background())
	if err != nil {
		log.Printf("stream acceptance failed %s", err)

		return
	}

	log.Printf("connection from %s", conn.RemoteAddr())

	// echo through the loggingWriter
	if _, err = io.Copy(loggingWriter{"server", stream}, stream); err != nil {
		log.Printf("stream copy failed %s %s", conn.RemoteAddr(), err)

		return
	}
}

func client() {
	tlsConf := &tls.Config{
		InsecureSkipVerify: true,
		NextProtos:         []string{"quic-echo-example"},
	}

	conn, err := quic.DialAddr(addr, tlsConf, nil)
	if err != nil {
		log.Fatalf("cannot dial to server %s", err)
	}

	stream, err := conn.OpenStreamSync(context.Background())
	if err != nil {
		log.Fatalf("cannot open an stream %s", err)
	}

	go func() {
		if _, err := io.Copy(loggingWriter{"client", stream}, os.Stdin); err != nil {
			log.Fatalf("cannot read from stdin to stream %s", err)
		}
	}()

	if _, err := io.Copy(os.Stdout, stream); err != nil {
		log.Fatalf("cannot read from stdin to stream %s", err)
	}
}

// Setup a bare-bones TLS config for the server.
func generateTLSConfig() *tls.Config {
	key, err := rsa.GenerateKey(rand.Reader, 2048)
	if err != nil {
		panic(err)
	}

	template := x509.Certificate{SerialNumber: big.NewInt(1)}
	certDER, err := x509.CreateCertificate(rand.Reader, &template, &template, &key.PublicKey, key)
	if err != nil {
		panic(err)
	}

	keyPEM := pem.EncodeToMemory(&pem.Block{Type: "RSA PRIVATE KEY", Bytes: x509.MarshalPKCS1PrivateKey(key)})
	certPEM := pem.EncodeToMemory(&pem.Block{Type: "CERTIFICATE", Bytes: certDER})

	tlsCert, err := tls.X509KeyPair(certPEM, keyPEM)
	if err != nil {
		panic(err)
	}

	return &tls.Config{
		Certificates: []tls.Certificate{tlsCert},
		NextProtos:   []string{"quic-echo-example"},
	}
}
