# In The Name Of God
# ========================================
# [] File Name : Makefile
#
# [] Creation Date : 12-01-2015
#
# [] Created By : Parham Alvani (parham.alvani@gmail.com)
# =======================================

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
all: function-call ifthen for inline args flonum move \
	attributes

function-call: function-call.o
function-call.o:
	$(CC) -fverbose-asm -S function-call.c
	$(CC) $(CFLAGS) -c function-call.c

ifthen: ifthen.o
ifthen.o:
	$(CC) -fverbose-asm -S ifthen.c
	$(CC) $(CFLAGS) -c ifthen.c

for: for.o
for.o:
	$(CC) -fverbose-asm -S for.c
	$(CC) $(CFLAGS) -c for.c

inline: inline.o
inline.o:
	$(CC) -fverbose-asm -S inline.c
	$(CC) $(CFLAGS) -c inline.c

args: args.o
args.o:
	$(CC) -fverbose-asm -S args.c
	$(CC) $(CFLAGS) -c args.c

flonum: flonum.o
flonum.o:
	$(CC) -fverbose-asm -S flonum.c
	$(CC) $(CFLAGS) -c flonum.c

move: move.o
move.o:
	$(CC) -fverbose-asm -S move.c
	$(CC) $(CFLAGS) -c move.c

attributes: attributes.o
attributes.o:
	$(CC) -fverbose-asm -S attributes.c
	$(CC) $(CFLAGS) -c attributes.c

.PHONY: clean
clean:
	rm -f function-call.o function-call function-call.s
	rm -f ifthen.o ifthen ifthen.s
	rm -f for.o for for.s
	rm -f inline.o inline inline.s
	rm -f args.o args args.s
	rm -f flonum.o flonum flonum.s
	rm -f move.o move move.s
	rm -f attributes.o attributes attributes.s
