ASMFLAGS=-fbin

floopy-disk: bootloader.asm 
	nasm $(ASMFLAGS) -o floppy-disk.img -l bootloader.lst bootloader.asm
.PHONY:clean
clean:
	rm floopy-disk.img bootloader.lst
