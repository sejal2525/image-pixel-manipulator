CC=gcc
CFLAGS=-std=c11 -Wall

all:
	$(CC) main.c -o pixel

clean:
	rm -f pixel *.o
