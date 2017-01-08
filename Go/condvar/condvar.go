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

import "fmt"
import "sync"

func main() {
	m := make(map[int]string)
	m[2] = "First Value"
	var mutex sync.Mutex
	cv := sync.NewCond(&mutex)
	updateCompleted := false
	go func() {
		cv.L.Lock()
		m[2] = "Second Value"
		updateCompleted = true
		cv.Signal()
		cv.L.Unlock()
	}()
	cv.L.Lock()
	for !updateCompleted {
		cv.Wait()
	}
	v := m[2]
	cv.L.Unlock()
	fmt.Printf("%s\n", v)
}
