/*
 *
 * In The Name of God
 *
 * +===============================================
 * | Author:        Parham Alvani <parham.alvani@gmail.com>
 * |
 * | Creation Date: 07-09-2019
 * |
 * | File Name:     wrap.go
 * +===============================================
 */

package main

import (
	"errors"
	"fmt"
)

// ErrInnerFailure represents core system failure.
var ErrInnerFailure = errors.New("something is wrong with core")

func main() {
	if err := outerError(); err != nil {
		if errors.Is(err, ErrInnerFailure) {
			fmt.Printf("core system failure with (%v)\n", errors.Unwrap(err))
		}
	}
}

func innerError() error {
	return ErrInnerFailure
}

func outerError() error {
	err := innerError()
	if err != nil {
		return fmt.Errorf("inner failure: %w", err)
	}

	return nil
}
