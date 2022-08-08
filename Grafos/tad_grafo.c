#include <stdio.h>
#include <stdlib.h>
#include "tad_grafo.h"

struct grafo {
    int ponderado;
    int num_vertices;
    int grau_max;
    int** arestas;
    float** pesos;
    int* grau;
};

int remove_aresta(Grafo* gr, int origem, int destino, int digrafo) {
   if(gr == NULL)
        return -1;
    if(origem < 0 || origem >= gr->num_vertices)
        return 0;
    if(destino < 0 || destino >= gr->num_vertices)
        return 0;

    int i = 0;

    while(i < gr->grau[origem] && gr->arestas[origem][i] != destino) {
        i++;
    }

    if(i == gr->grau[origem]) {
        return 0;
    }

    gr->grau[origem]--;
    gr->arestas[origem][i] = gr->arestas[origem][gr->grau[origem]];

    if(gr->ponderado) {
        gr->pesos[origem][i] = gr->pesos[origem][gr->grau[origem]];
    }
    if(digrafo == 0) {
        remove_aresta(gr, destino, origem, 1);
    }

    return 1;
}

int insere_aresta(Grafo* gr, int origem, int destino, int digrafo, float pesos) {
    if(gr == NULL)
        return -1;
    if(origem < 0 || origem >= gr->num_vertices)
        return 0;
    if(destino < 0 || destino >= gr->num_vertices)
        return 0;

    gr->arestas[origem][gr->grau[origem]] = destino;

    if(gr->ponderado) {
        gr->pesos[origem][gr->grau[origem]] = pesos;
    }

    gr->grau[origem]++;

    if(digrafo == 0) {
        insere_aresta(gr,destino,origem,1,pesos);
    }
    return 1;
}

void libera_grafo(Grafo* gr) {
    if(gr != NULL){
        int i;
        for(i = 0; i < gr->num_vertices; i++) {
            free(gr->arestas[i]);
        }
        free(gr->arestas);

        if(gr->ponderado) {
            for(i = 0; i < gr->num_vertices; i++){
                free(gr->pesos[i]);
            }
            free(gr->pesos);
        }
        free(gr->grau);
        free(gr);
    }
}

Grafo *cria_Grafo(int num_vertices, int grau_max, int ponderado) {
    Grafo *gr = (Grafo*) malloc(sizeof(struct grafo));

    if(gr != NULL) {

        int i;

        gr->num_vertices = num_vertices;
        gr->grau_max = grau_max;
        gr->ponderado = (ponderado != 0)?1:0;

        gr->grau = (int*) calloc(num_vertices,sizeof(int));
        gr->arestas = (int**)malloc(num_vertices*sizeof(int));

        for(i = 0; i < num_vertices; i++) {
            gr->arestas[i] = (int*)malloc(grau_max*sizeof(int));
        }
        if(gr->ponderado) {
            gr->pesos=(float**)malloc(num_vertices*sizeof(float*));
            for(i = 0; i < num_vertices; i++)
                gr->pesos[i] = (float*)malloc(grau_max*sizeof(float));
        }

    }
    return gr;
}

void busca_grafo(Grafo *gr, int inciocio, int *anterior, float *distancia) {
    int i, cont, ind, *visitado, menor, novo;
    cont = novo = gr->num_vertices;
    visitado = (int*) malloc(novo * sizeof(int));

    for(i = 0; i < novo; i++) {
        anterior[i] = -1;
        distancia[i] = -1;
        visitado[i] = 0;
    }

    distancia[inciocio] = 0;

    while(cont > 0) {
        menor = procura_menor(distancia, visitado, novo);
        if(menor == -1) {
            break;
        }

        visitado[menor] = 1;
        cont--;
        for(i = 0; i < gr->grau[menor]; i++) {
            ind = gr->arestas[menor][i];
            if(distancia[ind] < 0) {
                //distancia[ind] = distancia[menor] + 1;
                distancia[ind] = distancia[menor] + gr->pesos[menor][i];
                anterior[ind] = menor;
            } else {
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

int procura_menor(float *distancia, int *visitado, int novo) {
    int i, menor = -1, primeiro = 1;

    for(i = 0; i < novo; i++) {
        if(distancia[i] >= 0 && visitado[i] == 0) {
            if(primeiro) {
                menor = i;
                primeiro = 0;
            } else {
                if(distancia[menor] > distancia[i]) {
                    menor = i;
                }
            }
        }
    }


    return menor;
}

void imprime_Grafo(Grafo *gr, FILE *file) {
    int i, j;
    file = fopen("saida.txt", "a");
    fprintf(file,"GRAFO:\n");

    for(i = 0; i < gr->num_vertices; i++) {
        fprintf(file,"%d: ", i);
        printf("%d: ", i);
        for(j = 0; j < gr->grau[i]; j++) {
            if(gr->ponderado) {
                fprintf(file,"%d(%.2f), ", gr->arestas[i][j], gr->pesos[i][j]);
                printf("%d(%.2f), ", gr->arestas[i][j], gr->pesos[i][j]);
            } else {
                fprintf(file,"%d, ", gr->arestas[i][j]);
                printf("%d, ", gr->arestas[i][j]);
            }
        }
        fprintf(file,"\n");
        printf("\n");
    }

    fprintf(file,"\n");
    fclose(file);
}

void buscaLargura(Grafo *gr, int incio, int *visitado, FILE *file) {
    int i, vert, novo, cont = 1;
    int *fila, iniciocio_fila = 0, final_fila = 0;
    //marca todos os vertices como nao visitado
    for(i=0; i<gr->num_vertices; i++)
        visitado[i] = 0;

    //cria fila Visita e insere "incio" no incio
    novo = gr->num_vertices;
    fila = (int*) malloc(novo * sizeof(int));
    final_fila++;
    fila[final_fila] = incio;
    visitado[incio] = cont;
    while(iniciocio_fila != final_fila) {
        iniciocio_fila = (iniciocio_fila + 1) % novo;
        vert = fila[iniciocio_fila];
        cont++;
        //coloca todos os vizinhos nao visitados na fila
        for(i=0; i<gr->grau[vert]; i++) {
            if(!visitado[gr->arestas[vert][i]]) {
                final_fila = (final_fila + 1) % novo;
                fila[final_fila] = gr->arestas[vert][i];
                visitado[gr->arestas[vert][i]] = cont;
            }
        }
    }
    free(fila);

    file = fopen("saida.txt", "a");
    fprintf(file,"BUSCA LARGURA: \n");
    for(i=0; i < gr->num_vertices; i++){
        printf("%d -> %d\n",i,visitado[i]);
        fprintf(file,"%d -> %d\n",i,visitado[i]);
    }
    fprintf(file,"\n");
    fclose(file);
}


void buscaProfundidade_aux(Grafo *gr, int inicio, int *visitado, int cont) {
    int i;
    visitado[inicio] = cont;
    for(i=0; i<gr->grau[inicio]; i++){
        if(!visitado[gr->arestas[inicio][i]])
            buscaProfundidade_aux(gr,gr->arestas[inicio][i],visitado,cont+1);
    }
}

void buscaProfundidade(Grafo *gr, int inicio, int *visitado, FILE *file) {
    int i, cont = 1;
    for(i=0; i<gr->num_vertices; i++)
        visitado[i] = 0;
    buscaProfundidade_aux(gr,inicio,visitado,cont);

    file = fopen("saida.txt", "a");
    fprintf(file,"BUSCA PROFUNDIDADE: \n");
    for(i=0; i < gr->num_vertices; i++) {
        printf("%d -> %d\n",i,visitado[i]);
        fprintf(file,"%d -> %d\n",i,visitado[i]);
    }
    fprintf(file,"\n");
    fclose(file);
}