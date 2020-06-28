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

type sample interface {
	sampler(int, int) (int, int)
}

type integer int

func (i *integer) sampler(a int, b int) (int, int) {
	return b + int(*i), a - int(*i)
}

func justForHavingFun(input sample) {
	fmt.Printf("%s\n", input)
}

// nolint: wsl
func main() {
	var A, B int

	var gain integer

	fmt.Scanf("%d %d %d", &A, &B, &gain)

	A, B = gain.sampler(A, B)

	fmt.Printf("%d %d\n", A, B)

	justForHavingFun(&gain)

	// And for having more fun uncomment the following line
	// justForHavingFun(gain)
}
