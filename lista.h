// Construção de uma lista alterada

#ifndef LISTA_H
#define LISTA_H

// Definir a estrutura NoLista
typedef struct noLista {
	
	int via;
	int tempoEvento;
	char tipoEvento;
	struct noLista *prox;
} NoLista;

// Lista, ponteiro para nó
typedef NoLista* Lista;

/*
 * Construir a lista vazia
 * ->
 * <- lista vazia (ponteiro nulo)
 */
void criarLista(Lista*);

/*
 * Inserir
 * -> lista,carro
 * <- lista (alterada com um novo carro na posicao i)
 */
void inserirLista(Lista*,int,int,char,int);

/*
 * ListarElemento - apresentar todos os elementos da lista
 * -> lista
 * <- (como efeito colateral, escrever todos os elemento)
 */
void escreverLista(Lista);

/*
 * Destruir lista (libertar o espaço e defini-la com a lista vazia)
 * -> lista
 * <- lista vazia(e o espaço ocupado é libertado)
 */
void destruirLista(Lista*);

/*
 * Retirar, remove o elemento da posição "posicao"
 * se "posicao" estiver para além do fim da lista não retira nenhum
 * elemento.
 * -> lista,posicao
 * <- lista (com o elemento na posicao retirado)
 */
void retirarLista(Lista*,int);

/*
 * Devolver, devolve o elemento numa dada posição
 * -> lista, posicao
 * <- lista_i (o elemento na posicao 'i')
 */
int verLista(Lista,int);

/*
 * Vazia, verifica se a lista está vazia
 * ->lista
 * <- 1 - lista vazia; 0 - lista não vazia
 */
int vaziaLista(Lista);

/*
 * Comprimento da lista
 * -> lista
 * <- n (número de elementos da lista)
 */
int comprimentoLista(Lista);

/*
 * Procurar elemento na lista
 * -> lista, valor
 * <- posicao (posicao desse valor na lista)
 */
int procurar(Lista,int);

#endif
