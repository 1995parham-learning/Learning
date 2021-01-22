/*
 *
 * In The Name of God
 *
 * +===============================================
 * | Author:        Parham Alvani <parham.alvani@gmail.com>
 * |
 * | Creation Date: 22-01-2021
 * |
 * | File Name:     main.go
 * +===============================================
 */

package main

import (
	"fmt"
	"log"
	"time"

	"github.com/nats-io/jsm.go"
	"github.com/nats-io/nats.go"
)

const (
	ConsumerName      = "elconsumer"
	NATSServer        = "nats://127.0.0.1:4222"
	ConnectionTimeout = 10 * time.Second
)

func main() {
	nc, err := nats.Connect(NATSServer)
	if err != nil {
		log.Fatal(err)
	}
	defer nc.Close()

	fmt.Printf("Connected to %s from %v\n", nc.ConnectedAddr(), nc.DiscoveredServers())

	mgr, err := jsm.New(nc, jsm.WithTimeout(ConnectionTimeout))
	if err != nil {
		log.Fatal(err)
	}

	stream, err := mgr.LoadOrNewStream("ORDERS",
		jsm.Subjects("ORDERS.*"),
		jsm.MaxAge(24*365*time.Hour),
		jsm.MemoryStorage(),
	)
	if err != nil {
		log.Fatal(err)
	}

	consumer, err := stream.LoadOrNewConsumer(
		ConsumerName,
		jsm.FilterStreamBySubject("ORDERS.new"),
		jsm.DurableName(ConsumerName),
	)
	if err != nil {
		log.Fatal(err)
	}

	if err := nc.Publish("ORDERS.new", []byte("hello world")); err != nil {
		log.Fatal(err)
	}

	msg, err := consumer.NextMsg()
	if err != nil {
		log.Fatal(err)
	}

	fmt.Println(string(msg.Data))
}
