CC = gcc
FL = -Wall -Wextra

all: grep

grep: grep.o
	@$(CC) $(FL) grep.o -o test
	@echo "grep made"

grep.o: grep.c
	@$(CC) $(FL) -c grep.c -o grep.o

clean: 
	@rm -f *.o test map