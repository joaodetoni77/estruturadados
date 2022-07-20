#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

struct grafo{
    int ponderado;
    int num_vertices;
    int grau_max;
    int** arestas;
    float** pesos;
    int* grau;
};


int remove_aresta(Grafo* gr, int origem, int destino, int digrafo){
   if(gr == NULL)
        return;
    if(origem < 0 || origem >= gr->num_vertices)
        return 0;
    if(destino < 0 || destino >= gr->num_vertices)
        return 0;

    int i = 0;

    while(i < gr->grau[origem] && gr->arestas[origem][i] != destino){
        i++;
    }

    if(i == gr->grau[origem]){
        return 0;
    }

    gr->grau[origem]--;
    gr->arestas[origem][i] = gr->arestas[origem][gr->grau[origem]];

    if(gr->ponderado){
        gr->pesos[origem][i] = gr->pesos[origem][gr->grau[origem]];
    }
    if(digrafo == 0){
        remove_aresta(gr, destino, origem, 1);
    }

    return 1;
}

int insere_aresta(Grafo* gr, int origem, int destino, int digrafo, float pesos){
    if(gr == NULL)
        return;
    if(origem < 0 || origem >= gr->num_vertices)
        return 0;
    if(destino < 0 || destino >= gr->num_vertices)
        return 0;

    gr->arestas[origem][gr->grau[origem]] = destino;

    if(gr->ponderado){
        gr->pesos[origem][gr->grau[origem]] = pesos;
    }

    gr->grau[origem]++;

    if(digrafo == 0){
        insere_aresta(gr,destino,origem,1,pesos);
    }
    return 1;
}

void libera_grafo(Grafo* gr){
    if(gr != NULL){
        int i;
        for(i = 0; i < gr->num_vertices; i++){
            free(gr->arestas[i]);
        }
        free(gr->arestas);

        if(gr->ponderado){
            for(i = 0; i < gr->num_vertices; i++){
                free(gr->pesos[i]);
            }
            free(gr->pesos[i]);
        }
        free(gr->grau);
        free(gr);
    }
}

Grafo *cria_Grafo(int num_vertices, int grau_max, int ponderado){
    Grafo *gr = (Grafo*) malloc(sizeof(struct grafo));

    if(gr != NULL){

        int i;

        gr->num_vertices = num_vertices;
        gr->grau_max = grau_max;
        gr->ponderado = (ponderado != 0)?1:0;

        gr->grau = (int*) calloc(num_vertices,sizeof(int));
        gr->arestas = (int**)malloc(num_vertices*sizeof(int));

        for(i = 0; i < num_vertices; i++){
            gr->arestas[i] = (int*)malloc(grau_max*sizeof(int));
        }
        if(gr->ponderado){
            gr->pesos=(float**)malloc(num_vertices*sizeof(float*));
        }
        for(i = 0; i < num_vertices; i++){
            gr->pesos[i] = (float*)malloc(grau_max*sizeof(float));
        }

    }
    return gr;
}

void busca_grafo(Grafo *gr, int inicio, int *anterior, float *distancia){
    int i, cont, ind, *visitado, menor, novo;
    cont = novo = gr->num_vertices;
    visitado = (int*) malloc(novo * sizeof(int));

    for(i = 0; i < novo; i++){
        anterior[i] = -1;
        distancia[i] = -1;
        visitado[i] = 0;
    }

    distancia[inicio] = 0;

    while(cont > 0){
        menor = procura_menor(distancia, visitado, novo);
        if(menor == -1){
            break;
        }

        visitado[menor] = 1;
        cont--;
        for(i = 0; i < gr->grau[menor]; i++){
            ind = gr->arestas[menor][i];
            if(distancia[ind] < 0){
                //distancia[ind] = distancia[menor] + 1;
                distancia[ind] = distancia[menor] + gr->pesos[menor][i];
                anterior[ind] = menor;
            }else{
                if(distancia[ind] > distancia[menor] + 1){
                    //dist[ind] = dist[u] + 1;
                    distancia[ind] = distancia[menor] + gr->pesos[menor][i];
                    anterior[ind] = menor;
                }
            }
        }
    }
    free(visitado);
}

int procura_menor(float *distancia, int *visitado, int novo){
    int i, menor = -1, primeiro = 1;

    for(i = 0; i < novo; i++){
        if(distancia[i] >= 0 && visitado[i] == 0){
            if(primeiro){
                menor = i;
                primeiro = 0;
            }else{
                if(distancia[menor] > distancia[i]){
                    menor = i;
                }
            }
        }
    }


    return menor;
}


void imprime_Grafo(Grafo *gr){
    if(gr == NULL){
        return 0;
    }

    int i, j;

    for(i = 0; i < gr->num_vertices; i++){
        printf("%d: ", i);
        for(j = 0; j < gr->grau[i]; j++){
            if(gr->ponderado){
                printf("%d(%.2f), ", gr->arestas[i][j], gr->pesos[i][j]);
            }else{
                printf("%d, ", gr->arestas[i][j]);
            }
        }
        printf("\n");
    }

}
