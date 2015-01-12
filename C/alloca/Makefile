# In The Name Of God
# ========================================
# [] File Name : Makefile
#
# [] Creation Date : 08-01-2015
#
# [] Created By : Parham Alvani (parham.alvani@gmail.com)
# =======================================

P=alloca
OBJ=alloca.o
LIB=
ifdef LIB
CFLAGS=-Wall -O0 -g -std=gnu11 \
       $(shell pkg-config --cflags $(LIB))
LDLIBS=$(shell pkg-config --libs $(LIB))
else
CFLAGS=-Wall -O0 -g -std=gnu11
LDLIBS=
endif

$(P): $(OBJ)

.PHONY: clean
clean:
	rm $(OBJ) $(P)
