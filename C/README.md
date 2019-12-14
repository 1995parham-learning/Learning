# C
## Introduction
C is my life, here I try to have good time with C.

## Introduction to Makefile
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

## [clone](clone)
Linux provides the ability to create threads using the `clone()` system call.
when `clone()` is invoked, it is passed a set of flags that determine how much
sharing is to take place between the parent and child tasks.

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

The above expression evaluates to 2 (character constants are ints in C).
The use of `_Generic` can be abstracted in a macro:

```c
#define type_idx(T) _Generic( (T), char: 1, int: 2, long: 3, default: 0)
```

So that `type_idx('a')` evaluates to 2 and `type_idx("a")` evaluates to 0.

## [AhmadGuess](AhmadGuess)
My Teacher Assistant, Ahmad Asadi, had guess about floating point number implementation in C:

1 + 1/2 + 1/3 + .. + 1/n != 1/n + 1/(n - 1) + ... + 1/2 + 1

Let's check it in AhamadGuess :joy:.

## [Alloca](alloca)
The `alloca()` function allocates `size` bytes of space in the stack
frame of the caller. This temporary space is automatically freed
when the function that called `alloca()` returns to its caller.

```c
#include <alloca.h>

void *alloca(size_t size);
```

## [Fork](Fork)
Learn `fork` system call with it's related things like `wait`.

## [BahadorGuess](BahadorGuess)
This program shows that the expressions with side effects has no side effect in an unevaluted context.

```c
sizeof(a++)
```

## [CMakeTest](CMakeTest)
Example project for using CMake.

## [DataToFile](DataToFile)
Write user given string into file after some manipulation.

## [c-to-assembly](c-to-assembly)
Convert some known syntax of C into assembly.

## [random](random)
Generate random number between 0 to 3 with `random` instead of `rand`.

## [static](static)
Static variable in C and how to use them for storing the functions states.

## [pointer](pointer)
Let's have fun with pointers and try to understand them even more!

## [TwinPrimes](TwinPrimes)
A twin prime is a prime number that is either 2 less or 2 more than another prime number—for example, either member of the twin prime pair (41, 43).
