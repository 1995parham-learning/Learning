# In The Name Of God
# ========================================
# [] File Name : Makefile
#
# [] Creation Date : 12-01-2015
#
# [] Created By : Parham Alvani (parham.alvani@gmail.com)
# =======================================

P=c-to-assembly
OBJ=c-to-assembly.o
LIB=

ifdef LIB
CFLAGS=-Wall -O0 -g -std=gnu11 \
       $(shell pkg-config --cflags $(LIB))
LDLIBS=$(shell pkg-config --libs $(LIB))
else
CFLAGS=-Wall -O0 -g -std=gnu11
LDLIBS=
endif
ASFLAGS=-Wall -O0 -g

$(P): $(OBJ)

c-to-assembly.o: c-to-assembly.c
	$(CC) -S c-to-assembly.c
	$(CC) $(CFLAGS) -c c-to-assembly.c $(LDLIBS)

.PHONY: clean
clean:
	rm $(OBJ) $(P)
	rm c-to-assembly.s
