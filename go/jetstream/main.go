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

	"github.com/nats-io/nats.go"
)

const server = "nats://127.0.0.1:4222"

func main() {
	nc, err := nats.Connect(server)
	if err != nil {
		log.Fatal(err)
	}

	fmt.Printf("Connected to %s from %v\n", nc.ConnectedAddr(), nc.DiscoveredServers())

	c, err := nats.NewEncodedConn(nc, nats.GOB_ENCODER)
	if err != nil {
		log.Fatal(err)
	}

	defer c.Close()
}
