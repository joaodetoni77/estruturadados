typedef struct grafo Grafo;

Grafo *cria_Grafo(int num_vertices, int grau_max, int ponderado);
int insere_aresta(Grafo* gr, int origem, int destino, int digrafo, float peso);
int remove_aresta(Grafo* gr, int origem, int destino, int digrafo);
void libera_grafo(Grafo* gr);

//busca largura
void buscaLargura(Grafo *gr, int inicio, int *visitado, FILE *file);

//busca profundidade
void buscaProfundidade(Grafo *gr, int inicio, int *visitado, FILE *file);
void buscaProfundidade_aux(Grafo *gr, int inicio, int *visitado, int cont);

//busac menor
void busca_grafo(Grafo *gr, int inicio, int *anterior, float *distancia);
int procura_menor(float *distancia, int *visitado, int novo);





void imprime_Grafo(Grafo *gr, FILE *file);
