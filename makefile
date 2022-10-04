CC = gcc
CFLAGS = -Wall -g -pedantic

all: uniq
	
uniq: uniq.o
	$(CC) $(CFLAGS) uniq.o -o uniq
uniq.o: uniq.c
	$(CC) $(CFLAGS) -c uniq.c
test:
	echo Testing...
	./uniq < INPUT
	echo Done.
clean:
	rm -f uniq.o 
