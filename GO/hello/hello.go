/*
 * In The Name Of God
 * ========================================
 * [] File Name : hello.go
 *
 * [] Creation Date : 28-05-2015
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
)

/* with type */
const M64 int64 = 1 << 20
/* without type */
const M = 1 << 20

var ch chan int

/* Point is public but point is private */
type Point struct {
	x int
	y int
}

func (p Point) ToString() string {
	return fmt.Sprintf("%d %d", p.x, p.y)
}

type Stringer interface {
	ToString() string
}

func whileTrue() {
	for i := 0; i < 10; i++ {
		fmt.Println(i)
	}
	ch <- 1
}

func main() {
	fmt.Println("hello world\n")
	var s, t string = "foo", "bar" 
	var p1 Point
	p1.x = 10
	p1.y = 20
	fmt.Println(M)
	fmt.Println(s + t)
	fmt.Println(p1.ToString())
	var p2 Stringer
	p2 = Point {2, 3}
	fmt.Println(p2)
	
	/* channel is lock that can store value */
	ch = make(chan int, 1)

	/* the go statement launches a function call as goroutine */
	go whileTrue()

	<-ch
}
