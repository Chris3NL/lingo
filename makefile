all: filehandler.o lingo.o main.o
	gcc filehandler.o lingo.o main.o -o lingo

filehandler.o:
	gcc -c filehandler.c

lingo.o:
	gcc -c lingo.c

main.o:
	gcc -c main.c

clean:
	rm *.o
