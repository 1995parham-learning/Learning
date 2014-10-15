NASM = nasm -f bin
current_dir = $(notdir $(shell pwd))

all:
	${NASM} -o ${current_dir}.img -l ${current_dir}.lst ${current_dir}.asm

