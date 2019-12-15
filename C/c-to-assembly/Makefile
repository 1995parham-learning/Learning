# In The Name Of God
# ========================================
# [] File Name : Makefile
#
# [] Creation Date : 12-01-2015
#
# [] Created By : Parham Alvani (parham.alvani@gmail.com)
# =======================================

CFLAGS=-Wall -O0 -g -std=gnu11
ASFLAGS=-Wall -O0 -g

.PHONY: all
all: function-call.out ifthen.out for.out inline.out args.out flonum.out move.out \
	attributes.out global.out

%.out: %.c
	$(CC) -fverbose-asm -S $<
	$(CC) $(CFLAGS) -c $<
	$(CC) $(CFLAGS) -o $@ $<

.PHONY: clean
clean:
	rm -f *.o *.out *.s
