/*
 * In The Name Of God
 * ========================================
 * [] File Name : main.go
 *
 * [] Creation Date : 13-11-2015
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
 */
/*
 * Copyright (c) 2015 Parham Alvani.
 */

package main

import (
	fib "./fibonacci"
	"fmt"
)

func main() {
	fmt.Println(fib.Fibonacci(10))
}
