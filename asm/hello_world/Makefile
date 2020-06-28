# In The Name Of God
# ========================================
# [] File Name : Makefile
#
# [] Creation Date : 12-01-2015
#
# [] Created By : Parham Alvani (parham.alvani@gmail.com)
# =======================================

P=hello_world
OBJ=hello_world.o

AS=nasm
LD=ld
ASFLAGS=-Wall -O0 -g
LDFLAGS=

$(P): $(OBJ)
	$(LD) $(LDFLAGS) $^ -o $@

%.o: %.asm
	$(AS) $(ASFLAGS) -felf64 -l $@.lst $<

.PHONY: clean
clean:
	rm $(OBJ) $(P) *.lst
