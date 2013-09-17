all:
	echo "use win or unix"

files: filehandler.o lingo.o main.o

win: files
	gcc filehandler.o lingo.o main.o -o lingo.exe

unix: files
	gcc filehandler.o lingo.o main.o -o lingo

filehandler.o:
	gcc -c filehandler.c

lingo.o:
	gcc -c lingo.c

main.o:
	gcc -c main.c

clean:
	echo "use winclean or unixclean"

winclean:
	del *.o lingo.exe

unixclean:
	rm *.o lingo
