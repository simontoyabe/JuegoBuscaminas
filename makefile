testfile: mainmod.c frasesconsuelo.c frasesbuenas.c colocarbombas.c tablero.c modular.h
	gcc -o testfile mainmod.c frasesconsuelo.c frasesbuenas.c colocarbombas.c tablero.c
	
clean:
	rm -f testfile *.o
