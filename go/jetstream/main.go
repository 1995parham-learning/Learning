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
	"errors"
	"log"
	"time"

	"github.com/nats-io/nats.go"
)

const (
	ConsumerName = "elconsumer"
	NATSServer   = "nats://127.0.0.1:4222"
)

func main() {
	nc, err := nats.Connect(NATSServer)
	if err != nil {
		log.Println(err)

		return
	}
	defer nc.Close()

	log.Printf("Connected to %s from %v\n", nc.ConnectedAddr(), nc.DiscoveredServers())

	jsm, err := nc.JetStream()
	if err != nil {
		log.Println(err)

		return
	}

	info, err := jsm.StreamInfo("ORDERS")

	switch {
	case errors.Is(err, nats.ErrStreamNotFound):
		// nolint: exhaustivestruct
		if _, err := jsm.AddStream(&nats.StreamConfig{
			Name:     "ORDERS",
			Subjects: []string{"ORDERS.>"},
			MaxAge:   24 * 365 * time.Hour,
			Storage:  nats.MemoryStorage,
		}); err != nil {
			log.Println(err)

			return
		}
	case err != nil:
		log.Println(err)

		return
	default:
		log.Printf("%+v\n", info)
	}

	// simply publish on nats but also they can publish directly on jet stream
	// but in both case you need to create the stream.
	if err := nc.Publish("ORDERS.new", []byte("hello world")); err != nil {
		log.Println(err)

		return
	}

	if _, err := jsm.Subscribe("ORDERS.new", func(msg *nats.Msg) {
		log.Printf("receive message from %s\n", msg.Subject)

		metadata, err := msg.Metadata()
		if err != nil {
			log.Println("not a jetstream message")
		} else {
			log.Printf("metadata: %+v\n", metadata)
		}

		log.Println(string(msg.Data))
		if err := msg.Ack(); err != nil {
			log.Println(err)
		}
	}, nats.Durable(ConsumerName), nats.DeliverAll(), nats.ManualAck()); err != nil {
		log.Println(err)

		return
	}

	wait := make(chan struct{})
	<-wait
}
