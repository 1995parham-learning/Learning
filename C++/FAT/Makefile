OBJ=main.o FAT.o
CFLAGS=-gstabs+ -Wall

FAT: $(OBJ)
	gcc $(CFLAGS) -o FAT $(OBJ) 
main.o: main.c FAT.h
	gcc $(CFLAGS) -c main.c
FAT.o: FAT.c FAT.h
	gcc $(CFLAGS) -c FAT.c
