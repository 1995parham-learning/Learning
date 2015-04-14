# In The Name Of God
# ========================================
# [] File Name : Makefile
#
# [] Creation Date : 20-01-2015
#
# [] Created By : Parham Alvani (parham.alvani@gmail.com)
# =======================================

P=libhello.so
OBJ=hello.o
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

CFLAGS+=-fPIC

$(P): $(OBJ)
	$(CC) -shared -o $(P) $(OBJ) $(LDLIBS)

.PHONY: clean
clean:
	rm $(OBJ) $(P)
