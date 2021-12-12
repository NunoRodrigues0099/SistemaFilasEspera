// Funções para manipular fila alterada

#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

// Criar fila vazia
void criarFila(Fila *fl) {
	
	fl->inicio = NULL;
	fl->fim = NULL;
}

// Inserir, insere elemento sempre no final 
void inserirFila(Fila *fl,int tempo) {
	
	NoFila *novo;
	
	// Criar um nó
	novo = (NoFila*)malloc(sizeof(NoFila));
	
	// Mensagem de erro
	if (fl == NULL) {
		printf("ERRO");
		exit(1);
	}
	
	// Introduzir elem no nó
	novo->tempo = tempo;
	novo->prox = NULL;
	
	// Se fila estiver vazia
	if(fl->inicio == NULL && fl->fim == NULL) {
		
		// Fim e início apontam para novo nó
		fl->fim = novo;
		fl->inicio = novo;
	}
	else {
		
		// Nó prox no último nó aponta para novo nó
		fl->fim->prox = novo;
		fl->fim = novo;
	}
}

// Remover, remove sempre no inicio 
void retirarFila(Fila *fl) {
	
	NoFila *aux;
	
	// Criar ponteiro auxiliar (aux) para o nó a remover(1º nó)
	aux = fl->inicio;
	
	// Atualizar inicio (passa para nó seguinte)
	fl->inicio = fl->inicio->prox;
	
	// Se a fila ficou vazia atualizar inicio 
	if(fl->inicio == NULL) {
		fl->fim = NULL;
	}
	
	// Remover primeiro nó
	free(aux);
}

// Ver topo Via(ver primeiro elemento)
int topoFila(Fila fl) {
	
	// Devolve o elemento do topo
	return(fl.inicio->tempo);
}

// Verificar se a fila está vazia: devolve 1 se fila vazia, 0 c.c
int vaziaFila(Fila fl) {
	
	int flag;
	
	// Se a lista estiver vazia --> flag = 1
	if (fl.inicio == NULL && fl.fim == NULL) {
		flag = 1;
	}
	
	// Se a lista não estiver vazia --> flag = 0
	else {
		flag = 0;
	}
	return flag;
}
