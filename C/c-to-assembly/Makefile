# In The Name Of God
# ========================================
# [] File Name : Makefile
#
# [] Creation Date : 12-01-2015
#
# [] Created By : Parham Alvani (parham.alvani@gmail.com)
# =======================================

P=
OBJ=
LIB=

ifdef LIB
CFLAGS=-Wall -O0 -g -std=gnu11 \
       $(shell pkg-config --cflags $(LIB))
LDLIBS=$(shell pkg-config --libs $(LIB))
else
CFLAGS=-Wall -O0 -g -std=gnu11
LDLIBS=
endif
ASFLAGS=-Wall -O0 -g

.PHONY: all
all: c-to-assembly ifthen for inline

c-to-assembly: c-to-assembly.o
c-to-assembly.o:
	$(CC) -S c-to-assembly.c
	$(CC) $(CFLAGS) -c c-to-assembly.c

ifthen: ifthen.o
ifthen.o:
	$(CC) -S ifthen.c
	$(CC) $(CFLAGS) -c ifthen.c

for: for.o
for.o:
	$(CC) -S for.c
	$(CC) $(CFLAGS) -c for.c

inline: inline.o
inline.o:
	$(CC) -S inline.c
	$(CC) $(CFLAGS) -c inline.c

.PHONY: clean
clean:
	rm c-to-assembly.o c-to-assembly c-to-assembly.s
	rm ifthen.o ifthen ifthen.s
