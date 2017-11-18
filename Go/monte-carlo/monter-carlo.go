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

func main() {
	var N int
	ch := make(chan int, 4)
	inner := 0

	fmt.Scanf("%d", &N)

	for i := 0; i < 4; i++ {
		go func(n int) {
			inner := 0
			for i := 0; i < n; i++ {
				x := rand.Intn(1000)
				y := rand.Intn(1000)

				if (x-500)*(x-500)+(y-500)*(y-500) <= 500*500 {
					inner++
				}
			}
			ch <- inner
		}(N / 4)
	}
	for i := 0; i < 4; i++ {
		inner += <-ch
	}
	fmt.Printf("%f\n", 4.0*float64(inner)/float64(N))
}
