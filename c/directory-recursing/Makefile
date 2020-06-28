# In The Name Of God
# ========================================
# [] File Name : Makefile
#
# [] Creation Date : 15-02-2015
#
# [] Created By : Parham Alvani (parham.alvani@gmail.com)
# =======================================

P=directory-recursing
OBJ=process_dir.o main.o asprintf.o
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
process_dir.o: process_dir.h asprintf.h
asprintf.o: asprintf.h
main.o: process_dir.h

.PHONY: clean
clean:
	rm $(OBJ) $(P)
