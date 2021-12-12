// Construção de uma simulacao

#ifndef SIMULACAO_H
#define SIMULACAO_H

#include "lista.h"
#include "fila.h"

// Definir estrutura para OUTPUT
typedef struct dadosSaida {
	int tempo_simulacao,n_via,n_carro;
	double media_chegada,media_saida;
} DadosSaida;

/*
 * Função usada para gerar um número aleatório entre 0 e RAND_MAX
 * com uma distribuição uniforme, e ajusta-se esse valor para o
 * intervalo entre 0 e 1
 * -> valor (double)
 * <- inteiro gerado aleatóriamente
 */
int gerarAleatorio(double);

/*
 * Função usada para gerar chegada de carros
 * -> lista, taxa_entrada,carater c,tempo da simulacao
 * <-
 */
void gerarChegadaCarros(Lista*,double,char,int);

/*
 * Função usada para gerar eventos dos semáforos
 * -> lista, tempo de abertura, tempo de fecho, tempo da simulacao
 * <-
 */
void gerarSemaforos(Lista*,int,int,int);

/*
 * Função que retorna um máximo entre 2 elementos
 */
int maximo_2_elems(int,int);

/*
 * Função que retorna um minimo entre 2 elementos
 */
int minimo_2_elems(int,int);

/*
 * Função que retorna um maximo entre 4 elementos
 */
int maximo(int,int,int,int);

/*
 * Função que retorna um minimo entre 4 elementos
 */
int minimo(int,int,int,int);

void acerca();

#endif
