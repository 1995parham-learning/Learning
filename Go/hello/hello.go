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

// M defines without type
const M = 1 << 20

// Point is a public but point is private
type Point struct {
	x int
	y int
}

// ToString implements Stringer interface that works on *Point
func (p *Point) ToString() string {
	p.x *= 2
	return fmt.Sprintf("%d %d", p.x, p.y)
}

// Stringer interface provides toString method to remember us we are Java Developer
type Stringer interface {
	ToString() string
}

func increase(x *int) {
	*x++
}

func main() {
	// Create integer channel :)
	var ch chan int

	str := `
	Hello world of GoLang :)
	`
	fmt.Println(str)
	fmt.Println("hello world")
	var s = "foo"
	var t = "bar"

	var p1 Point
	p1.x = 10
	p1.y = 20
	fmt.Println(M)
	fmt.Println(s + t)
	fmt.Println(p1.ToString())
	fmt.Printf("%d %d\n", p1.x, p1.y)

	var p2 Stringer = &(Point{2, 3})
	fmt.Println(p2)

	var lst []int
	lst = append(lst, 10)
	lst = append(lst, 20)
	fmt.Println(lst)

	// Old but Gold, C formating in Go
	fmt.Printf("%.*f", 3, 8.9)

	/* channel is semaphore that can store value */
	ch = make(chan int, 1)

	/* the go statement launches a function call as goroutine */
	go func() {
		for i := 0; i < 10; i++ {
			fmt.Println(i)
		}
		ch <- 1

	}()

	<-ch

	var number = 10
	increase(&number)
}
