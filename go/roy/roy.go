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
	"log"
	"os"
	"strconv"
)

func main() {
	n := 4

	if len(os.Args) > 1 {
		arg, err := strconv.Atoi(os.Args[1])
		if err != nil {
			panic(err)
		}

		n = arg
	}

	acc := 1.0

	log.Printf("1")

	for i := 2; i <= n; i++ {
		term := 1.0 / float64(i*i)

		for j := 1; j < i; j++ {
			term *= -1
		}

		acc += term

		log.Printf(" + (-1)^%d * (1/%d)", i-1, i*i)
	}

	log.Printf("%d: %g\n", n, acc)
}
