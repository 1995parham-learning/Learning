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
all: function-call ifthen for inline args

function-call: function-call.o
function-call.o:
	$(CC) -S function-call.c
	$(CC) $(CFLAGS) -c function-call.c

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

args: args.o
args.o:
	$(CC) -S args.c
	$(CC) $(CFLAGS) -c args.c

.PHONY: clean
clean:
	rm function-call.o function-call function-call.s
	rm ifthen.o ifthen ifthen.s
	rm for.o for for.s
	rm inline.o inline inline.s
	rm args.o args args.s
