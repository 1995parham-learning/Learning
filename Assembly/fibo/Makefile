# In The Name Of God
# ========================================
# [] File Name : Makefile
#
# [] Creation Date : 12-01-2015
#
# [] Created By : Parham Alvani (parham.alvani@gmail.com)
# =======================================

P=fibo
OBJ=fibo.o

ASFLAGS=-Wall -O0 -g
LDFLAGS=

$(P): $(OBJ)
	ld $(LDFLAGS) -o $(P) $(OBJ)

fibo.o: fibo.asm
	nasm $(ASFLAGS) -felf64 -l fibo.lst fibo.asm

.PHONY: clean
clean:
	rm $(OBJ) $(P) fibo.lst
