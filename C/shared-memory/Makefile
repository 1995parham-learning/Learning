# In The Name Of God
# ========================================
# [] File Name : Makefile
#
# [] Creation Date : 12-01-2015
#
# [] Created By : Parham Alvani (parham.alvani@gmail.com)
# =======================================

P1=SharedMemoryConsumer
OBJ1=SharedMemoryConsumer.o
P2=SharedMemoryProducer
OBJ2=SharedMemoryProducer.o
LIB=
MLIB=-lrt

ifdef LIB
CFLAGS=-Wall -O0 -g -std=gnu11 \
       $(shell pkg-config --cflags $(LIB))
LDLIBS=$(shell pkg-config --libs $(LIB)) $(MLIB)
else
CFLAGS=-Wall -O0 -g -std=gnu11
LDLIBS= $(MLIB)
endif
ASFLAGS=-Wall -O0 -g

all: $(P1) $(P2)
$(P1): $(OBJ1)
$(P2): $(OBJ2)

.PHONY: clean
clean:
	rm $(OBJ1) $(P1) $(OBJ2) $(P2)
