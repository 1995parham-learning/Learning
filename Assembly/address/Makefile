# In The Name Of God
# ========================================
# [] File Name : Makefile
#
# [] Creation Date : 22-01-2015
#
# [] Created By : Parham Alvani (parham.alvani@gmail.com)
# =======================================

P=address
OBJ=address.o
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
ASFLAGS=-Wall -g

$(P): $(OBJ)
address.o:
	$(CPP) $(CPPFLAGS) -o address.s address.S
	$(AS) $(ASFLAGS) -o address.o -a=address.lst address.s

.PHONY: clean
clean:
	rm $(OBJ) $(P)
	rm address.lst address.s
