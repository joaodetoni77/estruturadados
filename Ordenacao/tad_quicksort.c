#include <stdio.h>
#include <stdlib.h>
#include "tad_quicksort.h"


//Fun��o respons�vel por fazer a troca entre dois valores
void troca_valores(int vetor_numeros[], int i, int j) {
	int aux = vetor_numeros[i];
	vetor_numeros[i] = vetor_numeros[j];
	vetor_numeros[j] = aux;
}

// particiona e retorna o �ndice do piv�
int particiona(int vetor_numeros[], int inicio, int fim) {
	int pivo, pivo_indice, i;

	pivo = vetor_numeros[fim]; // o piv� � sempre o �ltimo elemento
	pivo_indice = inicio;

	for(i = inicio; i < fim; i++) {
		// verifica se o elemento � <= ao piv�
		if(vetor_numeros[i] <= pivo)
		{
			// realiza a troca
			troca_valores(vetor_numeros, i, pivo_indice);
			// incrementa o pivo_indice
			pivo_indice++;
		}
	}

	// troca o piv�
	troca_valores(vetor_numeros, pivo_indice, fim);

	// retorna o �ndice do piv�
	return pivo_indice;
}

//Fun��o que escolhe um piv� aleat�rio para evitar o pior caso do quicksort
int particiona_random(int vet[], int inicio, int fim) {
	int pivo_indice = (rand() % (fim - inicio + 1)) + inicio;

	//Troca para colocar o piv� no fim
	troca_valores(vet, pivo_indice, fim);
	//Particionamento
	return particiona(vet, inicio, fim);
}

void quick_sort(int vet[], int inicio, int fim) {
	if(inicio < fim) {
		// fun��o particionar retorna o �ndice do piv�
		int pivo_indice = particiona_random(vet, inicio, fim);

		// chamadas recursivas quick_sort
		quick_sort(vet, inicio, pivo_indice - 1);
		quick_sort(vet, pivo_indice + 1, fim);
	}
}

