/*
* +===============================================
* | Author:        Parham Alvani (parham.alvani@gmail.com)
* |
* | Creation Date: 14-03-2016
* |
* | File Name:     condvar.go
* +===============================================
 */
package main

import (
	"fmt"
	"log"
	"sync"
)

// Cond implements a condition variable,
// a rendezvous point for goroutines waiting for or announcing the occurrence of an event.

func main() {
	var m sync.Mutex
	c := sync.NewCond(&m)
	n := 2

	running := make(chan bool, n)
	awake := make(chan bool, n)

	for i := 0; i < n; i++ {
		go func(i int) {
			m.Lock()
			running <- true
			c.Wait()
			fmt.Printf("Goroutine %d: start\n", i)
			awake <- true
			m.Unlock()
		}(i)
	}

	// Wait for everyone to run.
	for i := 0; i < n; i++ {
		<-running
	}
	close(running)

	for n > 0 {
		select {
		case <-awake:
			log.Fatal("goroutine not asleep")
		default:
		}
		m.Lock()
		c.Signal()
		m.Unlock()
		<-awake // Will deadlock if no goroutine wakes up so waits for one to wake up
		select {
		case <-awake:
			log.Fatal("too many goroutines awake")
		default:
		}
		n--
	}
	c.Signal()
}
