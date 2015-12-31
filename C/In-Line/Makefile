# In The Name Of God
# ========================================
# [] File Name : Makefile
#
# [] Creation Date : 29-12-2015
#
# [] Created By : Parham Alvani (parham.alvani@gmail.com)
# =======================================

LIB=

ifdef LIB
CFLAGS=-Wall -O0 -g -std=gnu11 \
       $(shell pkg-config --cflags $(LIB))
LDLIBS=$(shell pkg-config --libs $(LIB)) $(MLIB)
else
CFLAGS=-Wall -O0 -g -std=gnu11
LDLIBS=$(MLIB)
endif
ASFLAGS=-Wall -O0 -g

.PHONY: all
all: In-Line

In-Line:
	$(CC) -fverbose-asm -S In-Line.c
	$(CC) $(CFLAGS) -c In-Line.c


.PHONY: clean
clean:
	rm In-Line In-Line.o In-Line.s
