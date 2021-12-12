// Funções para manipular lista alterada

#include "lista.h"
#include <stdlib.h>
#include <stdio.h>

// Criar lista vazia
void criarLista(Lista *lst) {
	
	(*lst) = NULL;
}

// Inserir, insere o elemento e evento na posicao
void inserirLista(Lista *lst,int via,int tempo,char tipo,int posicao) {
	
	Lista ant,aux,novo;
	int i;
	
	// Criar novo nó
	novo = (Lista)malloc(sizeof(NoLista));
	
	// Inicializar o novo nó com o elem e evento
	novo->via = via;
	novo->tempoEvento = tempo;
	novo->tipoEvento = tipo;
	
	// Ponteiros auxiliares para percorrer a lista
	ant = NULL;
	aux = (*lst);
	
	// Encontrar posição de inserção
	i = 1;
	while (i < posicao) {
		ant = aux;
		aux = aux->prox;
		i++;
	}
	
	// Insere à cabeça
	if (ant == NULL) {
		(*lst) = novo;
	}
	else {
		ant->prox = novo;
	}
	novo->prox = aux;
}

// ListarElementos - apresentar todos os elementos da lista
void escreverLista(Lista lst) {
	
	while (lst != NULL) {
		printf("[%d,%d,%c] ",lst->via,lst->tempoEvento,lst->tipoEvento);
		lst = lst->prox;
	}
	printf("\n");
}

// Destruir lista
void destruir_Lista(Lista *lst) {
	
	Lista aux1, aux2;
	
	aux1 = (*lst);
	while (aux1 != NULL) {
		aux2 = aux1;
		aux1 = aux1->prox;
		free(aux2);
	}
	(*lst) = NULL;
}

// Retira, remove o elemento da posição "posicao"
void retirarLista(Lista *lst,int posicao) {
	
	Lista ant,aux;
	int i;
	
	// Ponteiros auxiliares para percorrer a lista
	ant = NULL;
	aux = (*lst);
	
	// Encontrar posição para retirar
	i = 1;
	while (i < posicao) {
		ant = aux;
		aux = aux->prox;
		i++;
	}
	
	// Retirar à cabeça
	if (ant == NULL) {
		(*lst) = aux->prox;
	}
	else {
		ant->prox = aux->prox;
	}
	
	// Libertar o espaço
	free(aux);
}

// Devolver, devolve posicao (1..N)= do elemento se existir e -1 c.c
int verLista(Lista lst,int elem) {
	
	int i;
	
	i = 1;
	while (lst != NULL && lst->via<=elem) {
		i++;
		lst = lst->prox;
		
	}
	return i;
}

// Vazia, verifica se a lista está vazia
int vaziaLista(Lista lst) {
	
	int flag;
	
	if (lst == NULL)
		flag = 1;
	else
		flag = 0;
	return flag;
}

// Comprimento da lista
int comprimento_Lista(Lista lst) {
	
	int comp = 0;
	
	while (lst != NULL) {
		comp++;
		lst = lst->prox;
	}
	return comp;
}

// Procurar tempo
int procurar(Lista lst,int valor) {
	
	int pos;
	
	pos = 1;
	while (lst!=NULL && valor>=lst->tempoEvento) {
		pos++;
		lst = lst->prox;
	}
	return pos;
}
