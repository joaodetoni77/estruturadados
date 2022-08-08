all:
	gcc -c tad_quicksort.c
	gcc main.c tad_quicksort.o -o main
	./main