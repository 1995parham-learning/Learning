/*
 * In The Name Of God
 * ========================================
 * [] File Name : non-blocking.go
 *
 * [] Creation Date : 19-11-2015
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
 */
/*
 * Copyright (c) 2015 Parham Alvani.
 */

package main

import "fmt"

func main() {
	messages := make(chan string, 0)
	signals := make(chan bool, 0)

	/*
	 * Here’s a non-blocking receive.
	 * If a value is available on messages then select will take the <-messages case with that value.
	 * If not it will immediately take the default case.
	 */
	select {
	case msg := <-messages:
		fmt.Println("received message", msg)
	default:
		fmt.Println("no message received")
	}

	/*
	 * A non-blocking send works similarly.
	 */
	msg := "hi"
	select {
	case messages <- msg:
		fmt.Println("sent message", msg)
	default:
		fmt.Println("no message sent")
	}

	/*
	 * We can use multiple cases above the default clause to implement a multi-way non-blocking select.
	 * Here we attempt non-blocking receives on both messages and signals.
	 */
	select {
	case msg := <-messages:
		fmt.Println("received message", msg)
	case sig := <-signals:
		fmt.Println("received signal", sig)
	default:
		fmt.Println("no activity")
	}
}
