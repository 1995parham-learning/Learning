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
	"sync"
)

const (
	maxValue    int = 10
	readerCount int = 10
)

// The storage that everyone wants access to it.
var buffer chan int
var end sync.WaitGroup

func reader(id int) {
	for {
		var value int
		value = <-buffer
		fmt.Printf("Reader %d: %d\n", id, value)
		buffer <- value
		if value >= maxValue {
			end.Done()
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
		if value >= maxValue {
			end.Done()
			return
		}
	}
}

func main() {
	buffer = make(chan int, 1)

	// storage is zero
	buffer <- 0

	for id := 0; id < readerCount; id++ {
		go reader(id)
		end.Add(1)
	}
	go writer()
	end.Add(1)

	end.Wait()
}
