OBJ=TestClass.o main.o
CCFLAGS=-Wall -std=c++11

unique_ptr: $(OBJ)
	g++ -o unique_ptr $(OBJ)
TestClass.o: TestClass.h TestClass.cpp
	g++ $(CCFLAGS) -c TestClass.cpp
main.o: main.cpp TestClass.h
	g++ $(CCFLAGS) -c main.cpp
