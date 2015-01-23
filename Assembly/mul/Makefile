# In The Name Of God
# ========================================
# [] File Name : Makefile
#
# [] Creation Date : 23-01-2015
#
# [] Created By : Parham Alvani (parham.alvani@gmail.com)
# =======================================

P=mul
OBJ=mul.o main.o
LIB=
MLIB=

ifdef LIB
CFLAGS=-Wall -O0 -g -std=gnu11 \
       $(shell pkg-config --cflags $(LIB))
LDLIBS=$(shell pkg-config --libs $(LIB)) $(MLIB)
else
CFLAGS=-Wall -O0 -g -std=gnu11
LDLIBS=$(MLIB)
endif
ASFLAGS=-Wall -O0 -g

$(P): $(OBJ)
	$(CC) -o $(P) $(OBJ) $(LDLIBS)
main.o: mul.h
	$(CC) -S main.c
	$(CC) $(CFLAGS) -c main.c
mul.o:

.PHONY: clean
clean:
	rm $(OBJ) $(P)
	rm main.s
