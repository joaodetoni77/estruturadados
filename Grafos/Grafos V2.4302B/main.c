#include <stdio.h>
#include <stdlib.h>
#include "tad_grafo.h"

int main()
{
    int vertices, gmax, pond;
    int origem, destino, dig;
    int busca;
    float weight;
    int op, teste,i;

    FILE *file;

    file = fopen("saida.txt", "w");
    //0 para digrafo
    //1 para nao digrafo

    //0 para nao ponderado
    //1 para ponderado

    printf("Informe o número de vértices: ");
    scanf("%d", &vertices);
    printf("\nInforme o grau máximo do grafo: ");
    scanf("%d", &gmax);
    printf("\nO grafo é ponderado?(1 para SIM e 0 para NAO) ");
    scanf("%d", &pond);

    int ant[vertices];
    float distancia[vertices];
    int visitados[vertices], visitados1[vertices];
    Grafo *gr;

    gr = cria_Grafo(vertices, gmax, pond);
    teste = 1;


    while(teste != -1)
    {
        printf("1 - Inserir Aresta\n");
        printf("2 - Remove Aresta\n");
        printf("3 - Apagar Grafo\n");
        printf("4 - Imprime Grafo\n");
        printf("5 - Busca menor\n");
        printf("6 - Busca em Profundidade\n");
        printf("7 - Busca em Largura\n");

        scanf("%d",&op);

        switch(op)
        {
        case 1:
            system("clear");

            printf("Origem: \n");
            scanf("%d", &origem);
            printf("\nDestino: \n");
            scanf("%d", &destino);
            printf("0 - Digrafo\t 1 - Nao Digrafo\n");
            scanf("%d", &dig);

            if(pond == 1)
            {
                printf("Peso: \n");
                scanf("%f", &weight);
            }

            teste = insere_aresta(gr, origem, destino, dig, weight);
// REMOVER DEPOIS
            if(teste)
            {
                printf("Sucesso!\n");
                getchar();
            }
            else
            {
                printf("Falha!\n");
                getchar();
            }
            break;

        case 2:
            system("clear");
            printf("Origem: \n");
            scanf("%d", &origem);
            printf("Destino: \n");
            scanf("%d", &destino);
            printf("0 - Digrafo\t 1 - Nao Digrafo\n");
            scanf("%d", &dig);

            teste = remove_aresta(gr, origem, destino, dig);
// REMOVER DEPOIS
            if(teste)
            {
                file = fopen("saida.txt", "a");
                fprintf(file,"SUCESSO AO DELETAR\n");
                printf("Sucesso!\n");
                getchar();
                fclose(file);
            }
            else
            {
                file = fopen("saida.txt", "a");
                fprintf(file,"FALHA AO DELETAR\n");
                printf("Falha!\n");
                getchar();
                fclose(file);
            }

            break;

        case 3:
            system("clear");
            libera_grafo(gr);
            printf("Grafo limpo!\n");
            getchar();
            teste = 0;
            break;

        case 4:
            system("clear");
            imprime_Grafo(gr, file);

            break;

        case 5:
            if(pond == 1)
            {
                printf("Vertice de Inicio\n");
                scanf("%d", &busca);
                busca_grafo(gr, busca, ant, distancia);

                file = fopen("saida.txt", "a");
                fprintf(file,"BUSCA MENOR DISTANCIA\n");
                for(i = 0; i < vertices; i++)
                {
                    printf("%d: %d -> %f\n",i,ant[i],distancia[i]);
                    fprintf(file,"%d: %d -> %f\n",i,ant[i],distancia[i]);
                }
                fprintf(file,"\n");
                fclose(file);
            }
            else
            {
                file = fopen("saida.txt", "a");
                printf("GRAFO NAO PONDERADO\n");
                fprintf(file,"GRAFO NAO PONDERADO\n");
                fprintf(file,"\n");
                fclose(file);
            }
            break;

        case 6:
            printf("Vertice de Inicio\n");
            scanf("%d", &busca);
            buscaLargura(gr, busca, visitados1, file);
            break;

        case 7:
            printf("Vertice de Inicio\n");
            scanf("%d", &busca);
            buscaProfundidade(gr, busca, visitados, file);
            break;

        case 0:
            teste = -1;
            fclose(file);
            break;

        }

    }

    return 0;
}
