all:
	gcc -c tad_grafo.c
	gcc main.c tad_grafo.o -o main
	./main