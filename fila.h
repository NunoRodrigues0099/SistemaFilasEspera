// Construção de uma fila alterada

#ifndef FILA_H
#define FILA_H

// Definir a estrutura Nofila
typedef struct noFila {
	
	int tempo;
	struct noFila *prox;
} NoFila;

// Fila, ponteiros para nó inicial e final
typedef struct fila {
	
	NoFila *inicio;
	NoFila *fim;
} Fila;

/*
 * Construir fila vazia
 * ->
 * <- fila vazia (ponteiro nulo)
 */
void criarFila(Fila*);

/*
 * Inserir, insere o elemento "elem" na fila (sempre no final)
 * -> fl,elem;
 * <- fl (alterada com um novo elemento no fim da fila)
 */
void inserirFila (Fila*,int);

/*
 * Retirar, remove o elemento da fila (sempre no inicio)
 * -> fl,posicao
 * <- fl (alterada sem o primeiro elemento)
 */
void retirarFila(Fila*);

/*
 * Ver topo de fila (primeiro elemento)
 * -> fl
 * <- elem (primeiro elemento da fila)
 */
int topoFila(Fila);

/*
 * Verifica se a fila está vazia
 * -> fl
 * <- 1 - fila vazia; 0 - fila não vazia
 */
int vaziaFila(Fila);

#endif
