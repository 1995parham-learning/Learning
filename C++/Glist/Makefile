P=Glist
OBJ=Glist.o
LIB=glib-2.0
CFLAGS=-Wall -O0 -g -std=gnu11 $(shell pkg-config --cflags $(LIB))
LDLIBS= $(shell pkg-config --libs $(LIB))

$(P): $(OBJ)

.PHONY: clean
clean:
	rm $(OBJ) $(P)
