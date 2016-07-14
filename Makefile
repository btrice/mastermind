CFLAGS = -g -Wall -ansi -pedantic 

all : mastermind.o partie.o 
	   gcc $(CFLAGS) partie.o  mastermind.o -o mastermind

partie.o: partie.c 
	gcc -c $(CFLAGS) partie.c

mastermind.o: mastermind.c
	gcc -c $(CFLAGS) mastermind.c

clean:
	rm -f *.o mastermind
