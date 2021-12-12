// Funções para manipular a simulacao

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "fila.h"
#include "lista.h"
#include "simulacao.h"

int gerarAleatorio(double n) {
	
	double u;
	int x;
	
	// Gerar um número aleatório entre 0 e RAND_MAX com uma
	// distribuição uniforme, e ajusta-se esse valor para o intervalo
	// entre 0 e 1
	u = (double)rand()/(double)RAND_MAX;
	
	// Arredondamento ás unidades
	x = (int)round((-1.0)*log(1.0-u)*(1.0/n));
	return x;
}

// Gera a chegada de carros
void gerarChegadaCarros(Lista *lst,double prob,char c,int tempo_sim) {
	
	int posicao,tempoEvento,x,via;
	double u;
	
	c = 'c';
	
	//Inicializar variáveis
	tempoEvento = 0;
	posicao = 1;
	
	// Ciclo que funciona até que o tempo de simulacao termine)
	while (tempoEvento <= tempo_sim) {
		
		// Gera um número aleatório entre 0 e 1
		u = (double)rand()/((double)RAND_MAX+1);
		
		// Calcula o tempo que demora o novo carro a chegar
		x = (int)round((-1.0)*log(1.0-u)*(1/prob));
		
		// Atualiza o tempo para o instante a que o carro chgou á via
		tempoEvento += x;
		
		if (tempoEvento <= tempo_sim) {
			
			// Determina a que via chega o carro
			via = (rand()%4)+1;
			inserirLista(&(*lst),via,tempoEvento,c,posicao);
			posicao++;
		}
	}
}

// Gera os tempos de abertura dos semáforos
void gerarSemaforos(Lista *lst,int tempoAberto,int tempoFechado,int tempo_sim) {
	
	int tempoEvento,pos;
	char tipoEvento;
	
	// Inicializar o tempo
	tempoEvento = 0;
	
	// Gerar tempos em que o semaforo abre
	while (tempoEvento <= tempo_sim) {
		tipoEvento = 'g';
		
		// Gravar dados
		pos = procurar(*lst,tempoEvento);
		inserirLista(&(*lst),-1,tempoEvento,tipoEvento,pos);
			
		// Atualiza o tempo para o instante em  que o semáforo volta a abrir
		tempoEvento = tempoEvento + tempoAberto + tempoFechado;
	}
	
	// Inicializar tempo em que abre
	tempoEvento = tempoAberto;
	
	// Gerar tempos em que o semaforo fecha
	while (tempoEvento <= tempo_sim) {
		tipoEvento = 'r';
		
		// Gravar dados
		pos = procurar(*lst,tempoEvento);
		inserirLista(&(*lst),-1,tempoEvento,tipoEvento,pos);
			
		// Atualiza o tempo para o instante em  que o semáforo volta a fechar
		tempoEvento = tempoEvento + tempoAberto + tempoFechado;
	}
}

// Função que calcula o maximo de dois elementos
int maximo_2_elems(int a,int b) {
	
	int aux;
	
	if (a > b)
		aux = a;
	else
		aux = b;
		
	return aux;
}

// Função que calcula o minimo de dois elementos
int minimo_2_elems(int a,int b) {
	
	int aux;
	
	if (a > b)
		aux = b;
	else
		aux = a;
		
	return aux;
}

int maximo(int a,int b,int c,int d) {
	
	int aux;
	
	aux = a;
	
	if (a > aux)
		aux = a;
	else
		aux = aux;
	if (b > aux)
		aux = b;
	else
		aux = aux;
	if (c > aux)
		aux = c;
	else
		aux = aux;
	if (d > aux)
		aux = d;
	else
		aux = aux;
	
	return aux;
}

int minimo(int a,int b,int c,int d) {
	
	int aux;
	
	aux = a;
	
	if (a < aux)
		aux = a;
	else
		aux = aux;
	if (b < aux)
		aux = b;
	else
		aux = aux;
	if (c < aux)
		aux = c;
	else
		aux = aux;
	if (d < aux)
		aux = d;
	else
		aux = aux;
	
	return aux;
}

void acerca() {
	
	printf("                 SIMULADOR DE UM SISTEMA DE FILAS DE ESPERA\n");
	printf("                          |              |\n");
	printf("                          |Via 3         |                                     TRABALHO REALIZADO POR:\n");
	printf("                          |              |                                       - Alice Conceicao\n");
	printf("                          |              |                                       - Nuno Rodrigues\n");
	printf("                          |              |\n");
	printf("                          |              |\n");
	printf("                          |              |                                     LICENCIATURA EM MATEMÁTICA\n");
	printf("                          |              |                                     FCTUC\n");
	printf("                          |              |                                     METODOS DE PROGRAMACAO II\n");
	printf("                          |              |\n");
	printf("__________________________                __________________________\n");
	printf("Via 4 \n");
	printf("                  ______ \n");
	printf("                 |      |\n");
	printf("                 |  BUS |\n");
	printf("                 |______|\n");
	printf("                 O      O                                      Via 2\n");
	printf("__________________________                __________________________\n");
	printf("                          |              |\n");
	printf("                          |              |\n");
	printf("                          |              |\n");
	printf("                          |              |\n");
	printf("                          |              |\n");
	printf("                          |              |\n");
	printf("                          |              |\n");
	printf("                          |              |\n");
	printf("                          |        Via 1 |                                     10.01.2020\n");
}
