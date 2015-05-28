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

import "fmt"

/* with type */
const M64 int64 = 1 << 20
/* without type */
const M = 1 << 20

func main() {
	fmt.Println("hello world\n")
	var s, t string = "foo", "bar"
	fmt.Println(M)
	fmt.Println(s + t)
}
