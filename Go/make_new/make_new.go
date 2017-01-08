/*
 * In The Name Of God
 * ========================================
 * [] File Name : make_new.go
 *
 * [] Creation Date : 16-11-2015
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

type Parham struct {
	age int
}

func main() {
	parham_new := new(Parham)
	parham_make := make([]Parham, 10)

	fmt.Println(parham_new)
	fmt.Println(parham_make)
}
