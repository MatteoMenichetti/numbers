main : alg.o main.c
	cc alg.o main.c -o main

alg.o : alg.c alg.h
	cc -c alg.c

install :

	mkdir src
	mkdir bin
	mv alg.c src
	mv alg.h src
	mv main.c src
	mv main bin
	mkdir tmp 
	mv *.o tmp

clean : 

	mv ./src/alg.c .
	mv ./src/alg.h .
	mv ./src/main.c .
	rm -r bin
	rm -r tmp
	rm -r src

