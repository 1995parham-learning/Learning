package mutex

// Mutex interface provides acquire and release functions
// as a basis for mutex locks.
type Mutex interface {
	Acquire()
	Release()
}
