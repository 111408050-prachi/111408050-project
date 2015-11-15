project: main.o hotel.o
	cc main.o hotel.o -o project
main.o: hotel.h main.c
	cc -Wall -c main.c
list.o: hotel.h hotel.c
	cc -Wall -c hotel.c
