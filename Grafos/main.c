#include <stdio.h>
#include <stdlib.h>
#include "tad_grafo.h"

int main()
{
    Grafo *gr;

    int vertices, gmax, pond;
    int origem, destino, dig;
    int busca;
    float weight;
    int op, teste,i;

    //0 para digrafo
    //1 para nao digrafo

    //0 para ponderado
    //1 para nao ponderado

    scanf("%d", &vertices);
    scanf("%d", &gmax);
    scanf("%d", &pond);

    int ant[vertices];
    float distancia[vertices];

    gr = cria_Grafo(vertices, gmax, pond);
    teste = 1;
    while(teste){
        printf("1 - Inserir Aresta\n");
        printf("2 - Remove Aresta\n");
        printf("3 - Apagar Grafo\n");
        printf("4 - Imprime Grafo\n");
        printf("5 - Busca menor\n");

        scanf("%d",&op);

        switch(op){
            case 1:
                system("cls");

                printf("Origem: \n");
                scanf("%d", &origem);
                printf("\nDestino: \n");
                scanf("%d", &destino);
                printf("0 - Digrafo\t 1 - Nao Digrafo\n");
                scanf("%d", &dig);

                if(pond == 1){
                    printf("Peso: \n");
                    scanf("%f", &weight);
                }

                teste = insere_aresta(gr, origem, destino, dig, weight);
// REMOVER DEPOIS
                if(teste){
                    printf("Sucesso!\n");
                    system("pause");
                }else{
                    printf("Falha!\n");
                    system("pause");
                }
                break;

            case 2:
                system("cls");

                printf("Origem: \n");
                scanf("%d", &origem);
                printf("Destino: \n");
                scanf("%d", &destino);
                printf("0 - Digrafo\t 1 - Nao Digrafo\n");
                scanf("%d", &dig);

                teste = remove_aresta(gr, origem, destino, dig);
// REMOVER DEPOIS
                if(teste){
                    printf("Sucesso!\n");
                    system("pause");
                }else{
                    printf("Falha!\n");
                    system("pause");
                }

                break;

            case 3:
                system("cls");
                libera_grafo(gr);
                printf("Grafo limpo!\n");
                system("pause");
                teste = 0;
                break;

            case 4:
                system("cls");
                imprime_Grafo(gr);

                break;
            case 5:
                printf("Vertice de Inicio\n");
                scanf("%d", &busca);
                busca_grafo(gr, busca, ant, distancia);
                for(i = 0; i < vertices; i++){
                    printf("%d: %d -> %f\n",i,ant[i],distancia[i]);
                }
                break;
        }

    }

    return 0;
}
