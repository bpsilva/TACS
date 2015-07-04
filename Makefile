target: all

all: hash.o  y.tab.o lex.yy.o decompiler.o semantics.o tac.o
	gcc -o etapa5  hash.o lex.yy.o y.tab.o decompiler.o semantics.o tac.o

hash.o: hash.c
	gcc -c hash.c -Wall

semantics.o: semantics.c
	gcc -c semantics.c -Wall

decompiler.o: decompiler.c
	gcc -c decompiler.c -Wall

lex.yy.o: lex.yy.c
	gcc -c lex.yy.c

lex.yy.c: scanner.l
	lex scanner.l 

y.tab.o: y.tab.c
	gcc -c y.tab.c 

y.tab.c: parser.y
	yacc -d -v parser.y 

tac.o: tac.c
	gcc -c tac.c -Wall

clean: 
	rm *.o
	rm etapa5
	rm lex.yy.c
	rm y.tab.c
	rm y.tab.h

