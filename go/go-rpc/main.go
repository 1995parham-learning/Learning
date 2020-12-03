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
	"math"
	"net"
	"net/http"
	"net/rpc"
)

// Args contains arithmatic parameters.
type Args struct {
	A, B int
}

// Quotient contains division reminder and quotient.
type Quotient struct {
	Quo, Rem int
}

// Arith is an integer with multiply and divide methods.
type Arith int

var (
	ErrOverflow       = errors.New("signed integer overflow")
	ErrDivisionByZero = errors.New("divide by zero")
)

// Multiply multiplies given parameters and stores it result.
func (t *Arith) Multiply(args *Args, reply *int) error {
	if args.A != 0 {
		if args.B > math.MaxInt32/args.A {
			return ErrOverflow
		}
	}

	*reply = args.A * args.B

	return nil
}

// Divide divides given parameters and stores it reminder and quotient.
func (t *Arith) Divide(args *Args, reply *Quotient) error {
	if args.B == 0 {
		return ErrDivisionByZero
	}

	reply.Quo = args.A / args.B

	reply.Rem = args.A % args.B

	return nil
}

func main() {
	// Server side
	// ===========
	arith := new(Arith)

	/* Register arith with its associated functions */
	if err := rpc.Register(arith); err != nil {
		log.Fatalf("rpc register error: %s", err)
	}

	/* Register http handler on http instance */
	rpc.HandleHTTP()

	l, err := net.Listen("tcp", "127.0.0.1:1373")
	if err != nil {
		log.Fatalf("listen error: %s", err)
	}

	go func() {
		if err := http.Serve(l, nil); err != nil {
			log.Fatalf("http serve error: %s", err)
		}
	}()

	// Client side
	// ===========
	client, err := rpc.DialHTTP("tcp", "localhost:1373")
	if err != nil {
		log.Fatal("dialing:", err)
	}

	/* Synchronous RPC call */
	// nolint: gomnd
	args := &Args{A: 7, B: 8}

	var reply int

	err = client.Call("Arith.Multiply", args, &reply)
	if err != nil {
		log.Fatal("arith error:", err)
	}

	fmt.Printf("Arith: %d * %d = %d\n", args.A, args.B, reply)
}
