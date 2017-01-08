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

import "fmt"

const N int = 4

func main() {
	var acc float64
	for i := 1; i <= N; i++ {
		term := 1.0 / float64(i)
		acc += term * term
		for j := 1; j < i; j++ {
			acc *= -1
		}
		fmt.Printf("%d: %g\n", i, acc)
	}
}
