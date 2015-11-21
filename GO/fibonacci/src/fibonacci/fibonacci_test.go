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
package fibonacci

import (
	"testing"
)

func TestFibonacci(t *testing.T) {
	if Fibonacci(2) != 2 {
		t.Errorf("Fibonacci(2) ==> %d != 2)", Fibonacci(2))
	}
	if Fibonacci(3) != 3 {
		t.Errorf("Fibonacci(3) ==> %d != 3)", Fibonacci(3))
	}
	if Fibonacci(4) != 5 {
		t.Errorf("Fibonacci(4) ==> %d != 5)", Fibonacci(4))
	}
}
