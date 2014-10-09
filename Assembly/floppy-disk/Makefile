NASM = nasm -f bin
current_dir = $(notdir $(shell pwd))

all:
	${NASM} -o ${current_dir}.img ${current_dir}.asm

