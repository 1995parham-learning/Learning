# C
Makefile is a good thing ! have this for have fun:
```Makefile
all: calc_lcm_gcd

calc_lcm_gcd: main.o gcd.o lcm.o
	$(CC) -o $@ $^ $(CFLAGS) $(LDLIBS)

%.o: %.c functions.h
	$(CC) -c -o $@ $< $(CFLAGS)

.PHONY: clean
clean:
	rm main.o gcd.o lcm.o calc_lcm_gcd
```
check [here](http://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/) for having even more fun !

## [Threads](Threads)
Let's learn to use new feature in C11, C11 threads.
Please see [here](http://en.cppreference.com/w/c/thread) as a reference for C11 threads.

**But at the current time nobody implements this feature.**

## [Generic](Generic)
Generic selection is implemented with a new keyword: `_Generic`.
The syntax is similar to a simple switch statement for types:

```c
_Generic( 'a', char: 1, int: 2, long: 3, default: 0)
```

evaluates to 2 (character constants are ints in C).
The use of `_Generic` can be abstracted in a macro:

```c
#define type_idx(T) _Generic( (T), char: 1, int: 2, long: 3, default: 0)
```

So that `type_idx('a')` evaluates to 2 and `type_idx("a")` evaluates to 0.

## [AhmadGuess](AhmadGuess)
My Teacher Assistant have guess about floating point number implementation:

1 + 1/2 + 1/3 + .. + 1/n != 1/n + 1/(n - 1) + ... + 1/2 + 1

Let's check it.
