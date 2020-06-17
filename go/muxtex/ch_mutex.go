/*
 * +===============================================
 * | Author:        Parham Alvani <parham.alvani@gmail.com>
 * |
 * | Creation Date: 10-10-2017
 * |
 * | File Name:     ch_mutex.go
 * +===============================================
 */

package mutex

type channelMutex struct {
	ch chan int
}

// NewChannelMutex creates new channel mutex implementation of mutex
func NewChannelMutex() Mutex {
	return &channelMutex{
		ch: make(chan int, 1),
	}
}

func (cm *channelMutex) Release() {
	<-cm.ch
}

func (cm *channelMutex) Acquire() {
	cm.ch <- 1
}
