/*
 * In The Name Of God
 * ========================================
 * [] File Name : rwp.go
 *
 * [] Creation Date : 22-11-2015
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
 */
/*
 * Copyright (c) 2015 Parham Alvani.
 */
package main

import (
	"fmt"
	"time"
)

const (
	max_value    int = 10
	reader_count int = 10
)

var buffer chan int
var end chan bool

func reader(id int) {
	for {
		var value int
		value = <-buffer
		fmt.Printf("Reader %d: %d\n", id, value)
		buffer <- value
		if value >= max_value {
			end <- true
			return
		}
	}
}

func writer() {
	for {
		var value int
		value = <-buffer
		value++
		fmt.Printf("Writer: %d\n", value)
		buffer <- value
		if value >= max_value {
			end <- true
			return
		}
	}
}

func main() {
	buffer = make(chan int, 1)
	end = make(chan bool, reader_count+1)
	buffer <- 0
	for id := 0; id < reader_count; id++ {
		go reader(id)
	}
	go writer()
	for len(end) < reader_count+1 {
		time.Sleep(100)
	}
}
