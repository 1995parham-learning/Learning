/*
 * +===============================================
 * | Author:        Parham Alvani (parham.alvani@gmail.com)
 * |
 * | Creation Date: 11-05-2016
 * |
 * | File Name:     interface.go
 * +===============================================
 */
package main

import (
	"fmt"
)

type Sample interface {
	sampler(A int, B int) (int, int)
}

type Integer int

func (self *Integer) sampler(A int, B int) (int, int) {
	return B + int(*self), A - int(*self)
}

func justForHavingFun(input Sample) {
	fmt.Println(":)")
}

func main() {
	var A, B int
	var gain Integer
	fmt.Scanf("%d %d %d", &A, &B, &gain)
	A, B = gain.sampler(A, B)
	fmt.Printf("%d %d\n", A, B)

	justForHavingFun(&gain)
	/* And for having more fun :D */
	// justForHavingFun(gain)
}
