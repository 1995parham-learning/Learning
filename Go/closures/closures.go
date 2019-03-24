/*
 * In The Name Of God
 * ========================================
 * [] File Name : closures.go
 *
 * [] Creation Date : 15-11-2015
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
 */
/*
 * Copyright (c) 2015 Parham Alvani.
 */

package main

import "fmt"

func createFunc() func(i int) int {
	a := 1
	b := 1

	innerFunc := func(i int) int {
		fmt.Printf("[%d] a = %d\n", i, a)
		fmt.Printf("[%d] b = %d\n", i, b)

		b++

		return 0
	}

	a++

	return innerFunc
}

func main() {
	innerFunc := createFunc()

	innerFunc(1)
	innerFunc(2)

	// At the end innerFunc read `a` and `b` on time of its execution.
	// Please note that innerFunc hold a reference to `a` and `b`.
}
