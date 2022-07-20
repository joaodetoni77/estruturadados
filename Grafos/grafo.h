typedef struct grafo Grafo;

Grafo *cria_Grafo(int num_vertices, int grau_max, int ponderado);
int insere_aresta(Grafo* gr, int origem, int destino, int digrafo, float peso);
int remove_aresta(Grafo* gr, int origem, int destino, int digrafo);
int procura_menor(float *distancia, int *visitado, int novo);
void imprime_Grafo(Grafo *gr);
void busca_grafo(Grafo *gr, int inicio, int *anterior, float *distancia);
void libera_grafo(Grafo* gr);
