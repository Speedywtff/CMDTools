CC = gcc
FL = -Wall -Wextra

all: initial

initial: initial.o
	@$(CC) $(FL) initial.o -o test
	@echo "initial made"

initial.o: initial.c
	@$(CC) $(FL) -c initial.c -o initial.o
	
map: hashmap.o
	@$(CC) $(FL) hashmap.o -o map

map.o: hashmap.c hashmap.h
	@$(CC) $(FL) -c hashmap.c -o hashmap.o

clean: 
	@rm -f *.o test