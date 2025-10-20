CC = gcc
FL = -Wall -Wextra

all: grep

grep: grep.o
	@$(CC) $(FL) grep.o -o test
	@echo "grep made"

grep.o: grep.c
	@$(CC) $(FL) -c grep.c -o grep.o
	
map: hashmap.o
	@$(CC) $(FL) hashmap.o -o map

map.o: hashmap.c hashmap.h
	@$(CC) $(FL) -c hashmap.c -o hashmap.o

clean: 
	@rm -f *.o test map