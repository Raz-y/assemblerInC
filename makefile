all: assembler

assembler: assembler.c assembler.h parser.o utils.h utils.o
	gcc -ansi -Wall -pedantic assembler.c parser.o macro_parser.o utils.o -o assembler

parser.o: parser.c parser.h macro_parser.o macro_parser.h
	gcc -ansi -Wall -pedantic -c parser.c -o parser.o

macro_parser.o: macro_parser.c macro_parser.h utils.h
	gcc -ansi -Wall -pedantic -c macro_parser.c -o macro_parser.o

utils.o: utils.c utils.h
	gcc -ansi -Wall -pedantic -c utils.c -o utils.o

clean:
	rm -f *.o assembler