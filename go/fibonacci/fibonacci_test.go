/*
 * In The Name Of God
 * ========================================
 * [] File Name : fibonacci_test.go
 *
 * [] Creation Date : 22-11-2015
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
 */
/*
 * Copyright (c) 2015 Parham Alvani.
 */
package fibonacci_test

import (
	"fibonacci"
	"fmt"
	"testing"
)

func TestFibonacci(t *testing.T) {
	tests := []struct {
		input    int
		expected int
	}{
		{
			input:    2,
			expected: 2,
		},
		{
			input:    3,
			expected: 3,
		},
		{
			input:    4,
			expected: 5,
		},
	}

	for _, tc := range tests {
		tc := tc
		t.Run(fmt.Sprintf("%d", tc.input), func(t *testing.T) {
			if fibonacci.Fibonacci(tc.input) != tc.expected {
				t.Errorf("Fibonacci(%d) ==> %d != %d)", tc.input, fibonacci.Fibonacci(tc.input), tc.expected)
			}
		})
	}
}
