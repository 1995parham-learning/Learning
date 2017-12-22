/*
 * In The Name Of God
 * ========================================
 * [] File Name : go-c.go
 *
 * [] Creation Date : 17-11-2015
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
 */
/*
 * Copyright (c) 2015 Parham Alvani.
 */

package main

// #include "hello.h"
import "C"

import (
	"fmt"
	"time"
)

func main() {
	fmt.Println("Hello world .. from Go :D")
	C.say_hello(C.CString("Parham Alvani"))
	C.setup_timer()
	C.setup_signal_handler()

	go func() {
		timer := time.Tick(100 * time.Millisecond)
		for {
			<-timer
			fmt.Println("Go Go ...")
		}
	}()

	for {
	}
}
