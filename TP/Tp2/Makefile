all:main

CFLAGS += -Wall -Wextra -Wconversion -g  -O0

main: main.o listechainer.o
	gcc -o main main.o listechainer.o

%.o: %.c liste.h
	gcc -c $(CFLAGS) $<