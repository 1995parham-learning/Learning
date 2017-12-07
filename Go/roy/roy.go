/*
 * +===============================================
 * | Author:        Parham Alvani (parham.alvani@gmail.com)
 * |
 * | Creation Date: 04-12-2015
 * |
 * | File Name:     roy.go
 * +===============================================
 */

package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	var n = 4

	if len(os.Args) > 1 {
		n, _ = strconv.Atoi(os.Args[1])
	}

	var acc = 1.0
	fmt.Printf("1")

	for i := 2; i <= n; i++ {
		term := 1.0 / float64(i*i)

		for j := 1; j < i; j++ {
			term *= -1
		}
		acc += term

		fmt.Printf(" + (-1)^%d * (1/%d)", i-1, i*i)
	}
	fmt.Printf("%d: %g\n", n, acc)
}
