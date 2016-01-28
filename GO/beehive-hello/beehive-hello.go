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
// Package main provides ...
package main

import (
	bh "github.com/kandoo/beehive"
)

const (
	helloDict = "HelloDictionary"
)

// Hello represents a message in our hello world example.
type Hello struct {
	Name string // Name is the name of the person saying hello.
}

// Rcvf receives the message and the context.
func rcvf(msg bh.Msg, ctx bh.RcvContext) error {
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

func mapf(msg bh.Msg, ctx bh.MapContext) bh.MappedCells {
	return bh.MappedCells{{helloDict, msg.Data().(Hello).Name}}
}

func main() {
	// Create the hello world application and make sure .
	app := bh.NewApp("hello-world", bh.Persistent(2))

	// Register the handler for Hello messages.
	app.HandleFunc(Hello{}, mapf, rcvf)

	// Emit simply emits a message, here a
	// string of your name.
	go bh.Emit(Hello{Name: "Parham Alvani"})

	// Emit another message with the same name
	// to test the counting feature.
	go bh.Emit(Hello{Name: "Parham Alvani"})

	bh.Start()
}
