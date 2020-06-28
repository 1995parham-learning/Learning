/*
 * In The Name Of God
 * ========================================
 * [] File Name : beehive-hello.go
 *
 * [] Creation Date : 13-11-2015
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
 */
/*
 * Copyright (c) 2015 Parham Alvani.
 */

package main

import (
	"log"

	bh "github.com/kandoo/beehive"
)

const (
	helloDict = "HelloDictionary"

	replicationFactor = 2
)

// Hello represents a message in our hello world example.
type Hello struct {
	Name string // Name is the name of the person saying hello.
}

// Broad represents a broadcast message in our hello world example.
type Broad struct {
	ID int // ID is the id of the broadcast message
}

// Rcvf receives the message and the context.
func hrcvf(msg bh.Msg, ctx bh.RcvContext) error {
	// msg is an envelope around the Hello message.
	// You can retrieve the Hello, using msg.Data() and then
	// you need to assert that its a Hello.
	hello := msg.Data().(Hello)

	// Using ctx.Dict you can get (or create) a dictionary.
	dict := ctx.Dict(helloDict)

	// Using Get(), you can get the value associated with
	// a key in the dictionary. Keys are always string
	// and values are generic interface{}'s.
	v, err := dict.Get(hello.Name)

	// If there is an error, the entry is not in the
	// dictionary. Otherwise, we set cnt based on
	// the value we already have in the dictionary
	// for that name.
	cnt := 0
	if err == nil {
		cnt = v.(int)
	}

	// Now we increment the count.
	cnt++

	// And then we print the hello message.
	ctx.Printf("hello %s (%d)!\n", hello.Name, cnt)

	// Finally we update the count stored in the dictionary.
	return dict.Put(hello.Name, cnt)
}

func hmapf(msg bh.Msg, ctx bh.MapContext) bh.MappedCells {
	return bh.MappedCells{
		bh.CellKey{
			Dict: helloDict,
			Key:  msg.Data().(Hello).Name,
		},
	}
}

func brcvf(msg bh.Msg, ctx bh.RcvContext) error {
	ctx.Printf("broad[%v] message %d was received\n", msg.IsBroadCast(), msg.Data().(Broad).ID)
	return nil
}

func bmapf(msg bh.Msg, ctx bh.MapContext) bh.MappedCells {
	return bh.MappedCells{{}}
}

func main() {
	// Create the hello world application
	app := bh.NewApp("hello-world", bh.Persistent(replicationFactor))

	// Register the handler for Hello messages.
	if err := app.HandleFunc(Hello{}, hmapf, hrcvf); err != nil {
		log.Fatalf("Hello Handle Func: %s", err)
	}

	// Register the handler for broad messages.
	if err := app.HandleFunc(Broad{}, bmapf, brcvf); err != nil {
		log.Fatalf("Board Handle Func: %s", err)
	}

	go bh.Emit(Hello{Name: "Parham Alvani"})

	go bh.Emit(Hello{Name: "HamidReza Alvani"})

	go bh.Emit(Broad{ID: 1})

	if err := bh.Start(); err != nil {
		log.Fatalf("Start: %s", err)
	}
}
