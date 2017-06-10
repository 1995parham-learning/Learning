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

## [Threads](C/Threads)
Let's learn to use new feature in C11, C11 threads.
Please see [here](http://en.cppreference.com/w/c/thread) as a reference for C11 threads.

**But at the current time nobody implements this feature.**
