/*
 * +===============================================
 * | Author:        Parham Alvani <parham.alvani@gmail.com>
 * |
 * | Creation Date: 12-12-2017
 * |
 * | File Name:     twiddle_test.go
 * +===============================================
 */

package twiddle_test

import (
	"testing"

	"twiddle"
)

func TestBasic1(t *testing.T) {
	tw := twiddle.New(2, 2)

	b := tw.Next()
	for _, v := range b {
		if !v {
			t.Fatalf("excpeting true found %v", v)
		}
	}
}

func TestBasic2(t *testing.T) {
	tw := twiddle.New(1, 2)

	table := []struct {
		ex [2]bool
	}{
		{[2]bool{false, true}},
		{[2]bool{true, false}},
	}

	i := 0

	for b := tw.Next(); b != nil; b = tw.Next() {
		for j := 0; j < len(b); j++ {
			if table[i].ex[j] != b[j] {
				t.Fatalf("excepting %v found %v", table[i].ex[j], b[j])
			}
		}
		i++
	}
}
