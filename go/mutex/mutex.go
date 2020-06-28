/*
 * +===============================================
 * | Author:        Parham Alvani <parham.alvani@gmail.com>
 * |
 * | Creation Date: 10-10-2017
 * |
 * +===============================================
 */

package mutex

// Mutex interface provides acquire and release functions
// as a basis for mutex locks.
type Mutex interface {
	Acquire()
	Release()
}
