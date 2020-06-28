/*
 * In The Name Of God
 * ========================================
 * [] File Name : variadic.go
 *
 * [] Creation Date : 19-11-2015
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
 */
/*
 * Copyright (c) 2015 Parham Alvani.
 */

package main

import "fmt"

func sums(nums ...int) {
	fmt.Println("## ##")
	fmt.Println(nums)

	total := 0
	for _, num := range nums {
		total += num
	}

	fmt.Println(total)
}

// nolint: gomnd
func main() {
	sums(1, 2, 3)
	sums(2, 3, 4)

	nums := []int{1, 2, 3, 4}
	sums(nums...)
}
