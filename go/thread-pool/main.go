package main

import (
	"fmt"
	"time"
)

type Task[T, K any] struct {
	Input  T
	Output K
}

type Method[T, K any] interface {
	Run(T) K
}

func New[T, K any](m Method[T, K], size int) Pool[T, K] {
	return Pool[T, K]{
		Method: m,
		tokens: make(chan struct{}, size),
	}
}

type Pool[T, K any] struct {
	Method Method[T, K]
	tokens chan struct{}
}

func (p Pool[T, K]) Push(t *Task[T, K]) {
	p.tokens <- struct{}{}
	t.Output = p.Method.Run(t.Input)
	<-p.tokens
}

type Sleeper struct{}

func (s Sleeper) Run(d time.Duration) int {
	time.Sleep(d)
	return 0
}

func main() {
	pool := New(Method[time.Duration, int](Sleeper{}), 10)

	t := Task[time.Duration, int]{Input: 10 * time.Second, Output: -1}

	pool.Push(&t)

	fmt.Println(t.Output)
}
