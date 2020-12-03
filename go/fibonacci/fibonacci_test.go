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
	"testing"
)

func TestFibonacci(t *testing.T) {
	t.Parallel()

	tests := []struct {
		name     string
		input    int
		expected int
	}{
		{
			name:     "2",
			input:    2,
			expected: 2,
		},
		{
			name:     "3",
			input:    3,
			expected: 3,
		},
		{
			name:     "4",
			input:    4,
			expected: 5,
		},
	}

	for _, tc := range tests {
		tc := tc
		t.Run(tc.name, func(t *testing.T) {
			t.Parallel()
			if fibonacci.Fibonacci(tc.input) != tc.expected {
				t.Errorf("Fibonacci(%d) ==> %d != %d)", tc.input, fibonacci.Fibonacci(tc.input), tc.expected)
			}
		})
	}
}
