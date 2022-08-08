#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include "tad_quicksort.h"


//
//O Algoritmo se baseia na ordenação em sucessivas execuções de particionamento,
//Escolhendo um pivo e o posiciona no array, para que os
//Elementos menores ou iguais ao pivo fiquem a esquerda e os maiores a direita.
//Um arquivo Saida.txt é gerado na pasta local do programa, com os valores informados e ordenados.
//

int main() {
	setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));
	FILE *file;

    int quantidade_valores;


    printf("Informe a quantidade de valores a serem ordenados: ");
    scanf("%d", & quantidade_valores);

    int i, vetor_numeros[quantidade_valores];
    for(i = 0; i < quantidade_valores; i++) {
        printf("Informe o valor %d: ", i + 1);
        scanf("%d", & vetor_numeros[i]);
    }

    //Manipualção dos arquivos e chamada da função de ordenação
    file = fopen("saida.txt", "w");
    fprintf(file,"Dados inseridos:\n");
    for(i = 0; i < quantidade_valores; i++){
        fprintf(file,"%d ",vetor_numeros[i]);
    }

	quick_sort(vetor_numeros, 0 , quantidade_valores - 1);

    fprintf(file,"\n\nDados Ordenados:\n");
    for(i = 0; i < quantidade_valores; i++) {
        fprintf(file,"%d ", vetor_numeros[i]);
    }

    fclose(file);
    return 0;
}
