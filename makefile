FLAGS =-Wall -g
CC = gcc

all: stringProg

stringProg: main.o 
	$(CC) $(FLAGS) -o stringProg main.o

main.o: main.c function.h
	$(CC) $(FLAGS) -c main.c 

function.o: function.c function.h
	$(CC) $(FLAGS) -c function.c

.PHONY: clean
clean:
	rm -f *.o *.a *.so stringProg

	