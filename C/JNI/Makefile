# In The Name Of God
# ========================================
# [] File Name : Makefile
#
# [] Creation Date : 11-04-2015
#
# [] Created By : Parham Alvani (parham.alvani@gmail.com)
# =======================================

P=libHelloJNI.so
OBJ=HelloJNI.o
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

CFLAGS+=-I"/usr/lib/jvm/java-7-openjdk-amd64/include" -fPIC

$(P): $(OBJ)
	$(CC) -shared -o $(P) $(OBJ) $(LDLIBS)
HelloJNI.o: HelloJNI.h

.PHONY: clean
clean:
	rm $(OBJ) $(P)
