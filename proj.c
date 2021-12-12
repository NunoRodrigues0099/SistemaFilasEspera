/*
 * proj.c
 * 
 * Copyright 2019 NunoRodrigues <nunorodrigues@nunorodrigues-VirtualBox>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fila.h"
#include "lista.h"
#include "simulacao.h"

int main() {

	srand(time(NULL));

	//Variáveis
	Lista eventos;		
	Fila f1, f2, f3, f4;
	char tipo;
	float taxa_chegada, taxa_saida;
	int ta, tf, s13, taux, total_time;
	int Nr1, Nr2, Nr3, Nr4, aux, tnextf, fnr, i;
	int Tmedio1, Tmedio2, Tmedio3, Tmedio4;
	int Tmin1,Tmax1,Tmin2,Tmax2,Tmin3,Tmax3,Tmin4,Tmax4;
	Nr1 = 0; Nr2 = 0; Tmedio1 = 0; Tmedio2 = 0; Nr3 = 0; Nr4 = 0; 
	Tmedio3 = 0; Tmedio4 = 0;
	Tmin1 = 0; Tmax1 = 0; Tmin2 = 0; Tmax2 = 0; Tmin3 = 0; Tmax3 = 0;
	Tmin4 = 0; Tmax4 = 0;
	
	total_time = 86400;
	
	FILE *f = fopen("relatorio.csv", "w");
	
	printf("Taxa de chegada: ");
	scanf("%f", &taxa_chegada);
	printf("Taxa de saida: ");
	scanf("%f", &taxa_saida);
	printf("Tempo de abertura: ");
	scanf("%d", &ta);
	printf("Tempo de fecho: ");
	scanf("%d", &tf);
	
	fprintf(f,"Taxa de chegada: %.2f\n",taxa_chegada);
	fprintf(f,"Taxa de saida: %.2f\n",taxa_saida);
	fprintf(f,"Tempo de abertura: %d\n",ta);
	fprintf(f,"Tempo de fecho: %d\n",tf);

	//Inicializar lista e filas
	criarLista(&eventos);
	criarFila(&f1);
	criarFila(&f2);
	criarFila(&f3);
	criarFila(&f4);
	
	//Gerar evento chegada de carros
	gerarChegadaCarros(&eventos,taxa_chegada,'c',total_time);	
	
	//Gerar evento semáforo (abertura e fecho)
	gerarSemaforos(&eventos,ta,tf,total_time);
	
	
	//escreverLista(eventos);

	//!Processar eventos------------------------------------------------	

	//Inicializar pista	
	s13 = 0;
	while(eventos!=NULL) {

		//Ler primeiro evento da lista
		tipo = eventos->tipoEvento;
		taux = eventos->tempoEvento;
		fnr  = eventos->via;

		//!-----------------------------------------------------------------
		//Se 'g' abre fila 1 e 3
		if(tipo=='g') {

			s13 = 1;
			tnextf = taux + ta; //Tempo de fecho

			//Se f1 não vazia
			if(!vaziaFila(f1)) {

				//Tempo para processar
				aux = taux + gerarAleatorio(taxa_saida);
				
				//Processar fila 1: enquanto não vazia e tempo menor que tempo de fecho
				while(!vaziaFila(f1) && aux<tnextf) {

					//Gera evento saída e mete na lista
					//Procurar posição
					i = procurar(eventos, aux);
					//Inserir na posição "i"
					inserirLista(&eventos,1,aux,'s',i);					
					//Remover nó
					
					Tmedio1 = Tmedio1 + aux-topoFila(f1);
					
					Tmax1 = aux-topoFila(f1);
					Tmin1 = aux-topoFila(f1);
					
					Tmax1 = maximo_2_elems(aux-topoFila(f1),Tmax1);
					Tmin1 = minimo_2_elems(aux-topoFila(f1),Tmin1);

					retirarFila(&f1);
					if(!vaziaFila(f1)) {
						aux = aux + gerarAleatorio(taxa_saida);						
					}
				}
			}

			//Se f3 não vazia
			if(!vaziaFila(f3)) {

				//Tempo para processar
				aux = taux + gerarAleatorio(taxa_saida);

				//Processar fila 3: enquanto não vazia e tempo menor que tempo de fecho
				while(!vaziaFila(f3) && aux<tnextf) {

					//Gera evento saída e mete na lista
					//Procurar posição
					i = procurar(eventos, aux);
					//Inserir na posição "i"
					inserirLista(&eventos,3,aux,'s',i);					
					//Remover nó
					
					Tmedio3 = Tmedio3 + aux-topoFila(f3);
					
					Tmax3 = aux-topoFila(f3);
					Tmin3 = aux-topoFila(f3);
					
					Tmax3 = maximo_2_elems(aux-topoFila(f3),Tmax3);
					Tmin3 = minimo_2_elems(aux-topoFila(f3),Tmin3);

					retirarFila(&f3);
					if(!vaziaFila(f3)) {
						aux = aux + gerarAleatorio(taxa_saida);						
					}
				}
			}
			//Se filas vazias passa para evento seguinte
		}
		//!-----------------------------------------------------------------

		//Se 'r' abre fila 2 e 4
		if(tipo=='r') {

			s13 = 0;
			tnextf = taux + tf; //Tempo de fecho

			//Se f2 não vazia
			if(!vaziaFila(f2)) {

				//Tempo para processar
				aux = taux + gerarAleatorio(taxa_saida);
				
				//Processar fila 2: enquanto não vazia e tempo menor que tempo de fecho
				while(!vaziaFila(f2) && aux<tnextf) {

					//Gera evento saída e mete na lista
					//Procurar posição
					i = procurar(eventos, aux);
					//Inserir na posição "i"
					inserirLista(&eventos,2,aux,'s',i);					
					//Remover nó
					
					Tmedio2 = Tmedio2 + aux-topoFila(f2);
					
					Tmax2 = aux-topoFila(f2);
					Tmin2 = aux-topoFila(f2);
					
					Tmax2 = maximo_2_elems(aux-topoFila(f2),Tmax2);
					Tmin2 = minimo_2_elems(aux-topoFila(f2),Tmin2);
					

					retirarFila(&f2);
					if(!vaziaFila(f2)) {
						aux = aux + gerarAleatorio(taxa_saida);						
					}
				}
			}

			//Se f4 não vazia
			if(!vaziaFila(f4)) {

				//Tempo para processar
				aux = taux + gerarAleatorio(taxa_saida); 
				
				//Processar fila 4: enquanto não vazia e tempo menor que tempo de fecho
				while(!vaziaFila(f4) && aux<tnextf) {

					//Gera evento saída e mete na lista
					//Procurar posição
					i = procurar(eventos, aux);
					//Inserir na posição "i"
					inserirLista(&eventos,4,aux,'s',i);					
					//Remover nó
					
					Tmedio4 = Tmedio4 + aux-topoFila(f4);
					
					Tmax4 = aux-topoFila(f4);
					Tmin4 = aux-topoFila(f4);
					
					Tmax4 = maximo_2_elems(aux-topoFila(f4),Tmax4);
					Tmin4 = minimo_2_elems(aux-topoFila(f4),Tmin4);

					retirarFila(&f4);
					if(!vaziaFila(f4)) {
						aux = aux + gerarAleatorio(taxa_saida);						
					}
				}
			}
			//Se filas vazias passa para evento seguinte
		}
		//!-----------------------------------------------------------------


		//Se 'c' processa ou mete na fila
		if(tipo=='c') {

			//S13 aberto
			if(fnr==1 && s13==1) {

				//Se f1 não vazia: insere na fila
				if(!vaziaFila(f1)) {

					fprintf(f,"%d; chegada de um carro; fila 1; aguarda\n", taux);
					inserirFila(&f1, taux);
				} else { //Processa

					fprintf(f,"%d; chegada de um carro; fila 1; não esperou\n", taux);
					Nr1 = Nr1 + 1;
				}
			}
			if(fnr==3 && s13==1) {

				//Se f3 não vazia: insere na fila
				if(!vaziaFila(f3)) {

					fprintf(f,"%d; chegada de um carro; fila 3; aguarda\n", taux);
					inserirFila(&f3, taux);
				} else { //Processa

					fprintf(f,"%d; chegada de um carro; fila 3; não esperou\n", taux);
					Nr3 = Nr3 + 1;
				}
			}
			if(fnr==1 && s13==0) {

				//Insere na fila
				inserirFila(&f1, taux);
			}
			if(fnr==3 && s13==0) {

				//Insere na fila
				inserirFila(&f3, taux);
			}

			//S13 Fechado
			if(fnr==2 && s13==0) {

				//Se f2 não vazia: insere na fila
				if(!vaziaFila(f2)) {

					fprintf(f,"%d; chegada de um carro; fila 2; aguarda\n", taux);
					inserirFila(&f2, taux);
				} else { //Processa

					fprintf(f,"%d; chegada de um carro; fila 2; não esperou\n", taux);
					Nr2 = Nr2 + 1;
				}
			}
			if(fnr==4 && s13==0) {

				//Se f4 não vazia: insere na fila
				if(!vaziaFila(f4)) {

					fprintf(f,"%d; chegada de um carro; fila 4; aguarda\n", taux);
					inserirFila(&f4, taux);
				} else { //Processa

					fprintf(f,"%d; chegada de um carro; fila 4; não esperou\n", taux);
					Nr4 = Nr4 + 1;
				}
			}
			if(fnr==2 && s13==1) {

				//Insere na fila
				inserirFila(&f2, taux);
			}
			if(fnr==4 && s13==1) {

				//Insere na fila
				inserirFila(&f4, taux);
			}
		}
		//!-----------------------------------------------------------------
		//Se 's' processa
		if(tipo=='s') {

			if(fnr==1) {

				Nr1 = Nr1+1;
			}
			if(fnr==2) {

				Nr2 = Nr2+1;
			}
			if(fnr==3) {

				Nr3 = Nr3+1;
			}
			if(fnr==4) {

				Nr4 = Nr4+1;
			}
		}

		//Remover evento
		retirarLista(&eventos,1);

	}
	fprintf(f,"Número de carros. Fila 1: %d; Fila 2: %d; Fila 3: %d; Fila 4: %d\n", Nr1, Nr2, Nr3, Nr4);
	fprintf(f,"Tempo médio de espera. Fila 1: %.3f; Fila 2: %.3f; Fila 3: %.3f; Fila 4: %.3f\n", (float)Tmedio1/Nr1, (float)Tmedio2/Nr2, (float)Tmedio3/Nr3, (float)Tmedio4/Nr4);
	fprintf(f,"Tempo médio de espera: %.3f\n", (((float)Tmedio1 + (float)Tmedio2 + (float)Tmedio3 + (float)Tmedio4) / (Nr1 + Nr2 + Nr3 + Nr4)));
	fprintf(f,"Tempo minimo de espera: %d\n",minimo(Tmin1,Tmin2,Tmin3,Tmin4));
	fprintf(f,"Tempo maximo de espera: %d\n",maximo(Tmax1,Tmax2,Tmax3,Tmax4));

	fclose(f);
	
	printf("\n\n");
	acerca();

	return 0;
}
