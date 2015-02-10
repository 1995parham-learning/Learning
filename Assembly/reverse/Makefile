# In The Name Of God
# ========================================
# [] File Name : Makefile
#
# [] Creation Date : 11-02-2015
#
# [] Created By : Parham Alvani (parham.alvani@gmail.com)
# =======================================

P=reverse
OBJ=reverse.o

$(P): $(OBJ)
	ld -melf_i386 -o $(P) $(OBJ)
reverse.o: reverse.asm
	nasm -felf32 reverse.asm

.PHONY: clean
clean:
	rm $(OBJ) $(P)
