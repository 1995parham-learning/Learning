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

import (
	"fmt"
)

func initFib() func() int {
	a := 1
	b := 1

	return func() int {
		temp := a
		a = b
		b = temp + b
		return temp
	}
}

func main() {
	seqFib := initFib()

	fmt.Println(seqFib())
	fmt.Println(seqFib())
	fmt.Println(seqFib())
	fmt.Println(seqFib())
	fmt.Println(seqFib())
}
