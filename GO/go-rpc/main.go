/*
 * In The Name Of God
 * ========================================
 * [] File Name : main.go
 *
 * [] Creation Date : 14-11-2015
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
 */
/*
 * Copyright (c) 2015 Parham Alvani.
 */

package main

import (
	"errors"
	"fmt"
	"log"
	"net"
	"net/http"
	"net/rpc"
)

type Args struct {
	A, B int
}

type Quotient struct {
	Quo, Rem int
}

type Arith int

func (t *Arith) Multiply(args *Args, reply *int) error {
	*reply = args.A * args.B
	return nil
}

func (t *Arith) Divide(args *Args, reply *Quotient) error {
	if args.B == 0 {
		return errors.New("divide by zero")
	}
	reply.Quo = args.A / args.B
	reply.Rem = args.A % args.B
	return nil
}

func main() {
	/*
	 * Server side
	 * ===========
	 */

	/* This new syntax is gooooooood :) */
	arith := new(Arith)

	rpc.Register(arith)
	rpc.HandleHTTP()

	l, e := net.Listen("tcp", ":1373")
	if e != nil {
		log.Fatal("listen error:", e)
	}

	go http.Serve(l, nil)

	/*
	 * Client side
	 * ===========
	 */

	client, err := rpc.DialHTTP("tcp", "localhost"+":1373")
	if err != nil {
		log.Fatal("dialing:", err)
	}

	/* Synchronous RPC call */
	args := &Args{7, 8}
	var reply int
	err = client.Call("Arith.Multiply", args, &reply)
	if err != nil {
		log.Fatal("arith error:", err)
	}
	fmt.Printf("Arith: %d * %d = %d\n", args.A, args.B, reply)
}
