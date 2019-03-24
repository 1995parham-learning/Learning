/*
 * +===============================================
 * | Author:        Parham Alvani (parham.alvani@gmail.com)
 * |
 * | Creation Date: 17-12-2015
 * |
 * | File Name:     string.go
 * +===============================================
 */

package main

import "fmt"
import "unicode/utf8"

func main() {
	str := "ماهرپ"
	runes := make([]byte, 0, 4)
	for i := 0; i < len(str); i++ {
		runes = append(runes, str[i])
		if utf8.FullRune(runes) {
			char, _ := utf8.DecodeRune(runes)
			fmt.Printf("%c", char)
			runes = runes[0:0]
		}
	}
	fmt.Println()
}
