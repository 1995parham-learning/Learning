package mutex

type channelMutex struct {
	ch chan int
}

// NewChannelMutex creates new channel mutex implementation of mutex.
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
