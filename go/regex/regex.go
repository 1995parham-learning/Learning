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
	"log"
	"regexp"
)

func main() {
	r := regexp.MustCompile("[abcd]+")
	str := "aa bb c dd de f"

	log.Printf("replaced: %v\n", r.ReplaceAllString(str, "-"))
}
