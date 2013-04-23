CC=gcc
CFLAGS=-c -Wall -ansi -Wundef -Wstrict-prototypes -Wmissing-prototypes -Wmissing-declarations -O2

all: prob_b

prob_b: B.o mergesort.o
	$(CC) B.o mergesort.o -o prob_b

B.o: B.c
	$(CC) $(CFLAGS) B.c

mergesort.o: mergesort.c
	$(CC) $(CFLAGS) mergesort.c

clean:
	rm -rf *o
