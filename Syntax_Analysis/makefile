all: pasc200

parser.tab.c parser.tab.h: parser.y
	bison -v -d parser.y

lex.yy.c: lexer.l parser.tab.h
	flex lexer.l

pasc200: lex.yy.c parser.tab.c parser.tab.h hashtbl.o
	gcc -o exe parser.tab.c lex.yy.c hashtbl.o -lm

hashtbl.o: hashtbl.c hashtbl.h
	gcc -o hashtbl.o -c hashtbl.c
clean:
	rm exe parser.tab.c lex.yy.c parser.tab.h hashtbl.o 
	rm parser.output
