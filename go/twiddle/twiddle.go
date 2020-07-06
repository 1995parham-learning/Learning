/*
 * +===============================================
 * | Author:        Parham Alvani <parham.alvani@gmail.com>
 * |
 * | Creation Date: 12-12-2017
 * |
 * | File Name:     twiddle.go
 * +===============================================
 */

// nolint: gofumpt
package twiddle

// Twiddle type contains all information twiddle algorithm
// need between each iteration.
type Twiddle struct {
	p   []int
	b   []bool
	end bool
}

// New creates new twiddle algorithm instance.
// nolint: gomnd
func New(m int, n int) *Twiddle {
	p := make([]int, n+2)

	b := make([]bool, n)

	// initiate p
	p[0] = n + 1

	var i int

	for i = 1; i < n-m; i++ {
		p[i] = 0
	}

	for i < n+1 {
		p[i] = i + m - n
		i++
	}

	p[n+1] = -2

	if m == 0 {
		p[1] = 1
	}

	// initiate b
	for i = 0; i != n-m; i++ {
		b[i] = false
	}

	for i != n {
		b[i] = true
		i++
	}

	return &Twiddle{
		p: p,
		b: b,
	}
}

// Next creates next combination and return it.
// it returns nil on end of combinations.
func (t *Twiddle) Next() []bool {
	if t.end {
		return nil
	}

	r := make([]bool, len(t.b))
	for i := 0; i < len(t.b); i++ {
		r[i] = t.b[i]
	}

	x, y, end := t.twiddle()
	t.b[x] = true
	t.b[y] = false
	t.end = end

	return r
}

// nolint: nestif
func (t *Twiddle) twiddle() (int, int, bool) {
	var i, j, k int

	var x, y int

	j = 1
	for t.p[j] <= 0 {
		j++
	}

	if t.p[j-1] == 0 {
		for i = j - 1; i != 1; i-- {
			t.p[i] = -1
		}

		t.p[j] = 0
		x = 0
		t.p[1] = 1
		y = j - 1
	} else {
		if j > 1 {
			t.p[j-1] = 0
		}
		j++
		for t.p[j] > 0 {
			j++
		}
		k = j - 1
		i = j
		for t.p[i] == 0 {
			t.p[i] = -1
			i++
		}
		if t.p[i] == -1 {
			t.p[i] = t.p[k]
			x = i - 1
			y = k - 1
			t.p[k] = -1
		} else {
			if i == t.p[0] {
				return x, y, true
			}

			t.p[j] = t.p[i]
			t.p[i] = 0
			x = j - 1
			y = i - 1
		}
	}

	return x, y, false
}
