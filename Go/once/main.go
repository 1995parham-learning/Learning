package main

import (
	"fmt"
	"sync"
)

type LazyInit struct {
	once  sync.Once
	value int
}

func (s *LazyInit) Value() int {
	s.init()
	return s.value
}

func (s *LazyInit) init() {
	s.once.Do(func() { s.value = 1820 })
}

func (s *LazyInit) SetValue(v int) {
	s.value = v
}

func main() {
	var l LazyInit
	/*
	 * if you use SetValue() berfore getting the value (initiation happens on Value())
	 * your setted value is replaced by initiation value.
	 *	l.SetValue(13)
	 *	l.Value() --> 1820
	 */
	fmt.Printf("%d\n", l.Value())
	l.SetValue(12)
	fmt.Printf("%d\n", l.Value())
}
