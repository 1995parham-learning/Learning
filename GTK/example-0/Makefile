# In The Name Of God
# ========================================
# [] File Name : Makefile
#
# [] Creation Date : 03-02-2015
#
# [] Created By : Parham Alvani (parham.alvani@gmail.com)
# =======================================

P=example-0
OBJ=example-0.o
LIB=gtk+-2.0
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

.PHONY: clean
clean:
	rm $(OBJ) $(P)
