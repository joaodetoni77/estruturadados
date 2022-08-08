#include <stdio.h>
#include <stdlib.h>
#include "tad_quicksort.h"


//Função responsável por fazer a troca entre dois valores
void troca_valores(int vetor_numeros[], int i, int j) {
	int aux = vetor_numeros[i];
	vetor_numeros[i] = vetor_numeros[j];
	vetor_numeros[j] = aux;
}

// particiona e retorna o índice do pivô
int particiona(int vetor_numeros[], int inicio, int fim) {
	int pivo, pivo_indice, i;

	pivo = vetor_numeros[fim]; // o pivô é sempre o último elemento
	pivo_indice = inicio;

	for(i = inicio; i < fim; i++) {
		// verifica se o elemento é <= ao pivô
		if(vetor_numeros[i] <= pivo)
		{
			// realiza a troca
			troca_valores(vetor_numeros, i, pivo_indice);
			// incrementa o pivo_indice
			pivo_indice++;
		}
	}

	// troca o pivô
	troca_valores(vetor_numeros, pivo_indice, fim);

	// retorna o índice do pivô
	return pivo_indice;
}

//Função que escolhe um pivô aleatário para evitar o pior caso do quicksort
int particiona_random(int vet[], int inicio, int fim) {
	int pivo_indice = (rand() % (fim - inicio + 1)) + inicio;

	//Troca para colocar o pivô no fim
	troca_valores(vet, pivo_indice, fim);
	//Particionamento
	return particiona(vet, inicio, fim);
}

void quick_sort(int vet[], int inicio, int fim) {
	if(inicio < fim) {
		// função particionar retorna o índice do pivô
		int pivo_indice = particiona_random(vet, inicio, fim);

		// chamadas recursivas quick_sort
		quick_sort(vet, inicio, pivo_indice - 1);
		quick_sort(vet, pivo_indice + 1, fim);
	}
}

