#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include "tad_quicksort.h"


//
//O Algoritmo se baseia na ordena��o em sucessivas execu��es de particionamento,
//Escolhendo um pivo e o posiciona no array, para que os
//Elementos menores ou iguais ao pivo fiquem � esquerda e os maiores � direita.
//Um arquivo Saida.txt � gerado na pasta local do programa, com os valores informados e ordenados.
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
        printf("Informe o %d� valor: ", i + 1);
        scanf("%d", & vetor_numeros[i]);
    }

    //Manipual�ao dos arquivos e chama da fun��o de ordena��o
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
