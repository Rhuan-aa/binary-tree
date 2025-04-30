CC = gcc
CFLAGS = -Wall -Wextra

all: my_program

my_program: main.o binary_tree.o
	$(CC) $(CFLAGS) -o my_program main.o binary_tree.o

main.o: main.c binary_tree.h
	$(CC) $(CFLAGS) -c -o main.o main.c

binary_tree.o: binary_tree.c binary_tree.h
	$(CC) $(CFLAGS) -c -o binary_tree.o binary_tree.c

clean:
	rm -f my_program main.o binary_tree.o

run:
	./my_program.exe