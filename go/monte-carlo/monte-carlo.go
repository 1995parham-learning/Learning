/*
 * +===============================================
 * | Author:        Parham Alvani <parham.alvani@gmail.com>
 * |
 * | Creation Date: 19-11-2017
 * |
 * | File Name:     monter-carlo.go
 * +===============================================
 */

package main

import (
	"fmt"
	"math/rand"
)

const (
	threadNum = 4

	width  = 1000
	height = 1000
)

func main() {
	var N int

	ch := make(chan int, threadNum)
	inner := 0

	fmt.Scanf("%d", &N)

	for i := 0; i < threadNum; i++ {
		go func(n int) {
			inner := 0

			for i := 0; i < n; i++ {
				x := rand.Intn(width)
				y := rand.Intn(height)

				if (x-width/2)*(x-width/2)+(y-height/2)*(y-height/2) <= (width/2)*(height/2) {
					inner++
				}
			}
			ch <- inner
		}(N / threadNum)
	}

	for i := 0; i < threadNum; i++ {
		inner += <-ch
	}

	fmt.Printf("%f\n", 4.0*float64(inner)/float64(N))
}
