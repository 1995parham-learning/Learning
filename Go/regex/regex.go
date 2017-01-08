/*
 * +===============================================
 * | Author:        Parham Alvani (parham.alvani@gmail.com)
 * |
 * | Creation Date: 17-12-2015
 * |
 * | File Name:     regex.go
 * +===============================================
 */
package main

import (
	"fmt"
	"regexp"
)

func main() {
	r, _ := regexp.Compile("[abcd]+")
	str := "aa bb c dd de f"
	fmt.Printf("Replaced: %v\n", r.ReplaceAllString(str, "-"))
}
