OBJ=Practical.o main.o
CFLAGS=-Wall

TCPEchoClient: $(OBJ)
	gcc $(CFLAGS) -o TCPEchoClient $(OBJ)
main.o: Practical.h main.c
	gcc $(CFLAGS) -c main.c
Practical.o: Practical.h Practical.c
	gcc $(CFLAGS) -c Practical.c
