/*
 * +===============================================
 * | Author:        Parham Alvani <parham.alvani@gmail.com>
 * |
 * | Creation Date: 10-10-2017
 * |
 * | File Name:     ch_mutex_test.go
 * +===============================================
 */
package mutex_test

import (
	"testing"

	"mutex"
)

func TestOne(t *testing.T) {
	m := mutex.NewChannelMutex()
	f := 0

	t.Log(t.Name())

	go func() {
		m.Acquire()
		t.Log("Thread-1")

		f = 1

		m.Release()
	}()

	for {
		m.Acquire()
		t.Log("Thread-2")

		if f == 1 {
			m.Release()
			break
		} else {
			m.Release()
		}
	}
}
