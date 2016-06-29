/*
	TRABALHO COMPUTACIONAL 2 - ELÉTRICA 2016/1
	
	ARTHUR LORENCINI BERGAMASCHI
	PEDRO VINICIUS DOS SANTOS CUSTODIO

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pcblib.h"


//favor colocar em ordem alfabéticas os valores no final conforme o pdf da titia boeres.


int main (void) {
	unsigned int n, i,j, qtdDeNomes,c;
	char matrizCaca[tam][tam], nomesCaca[tam][tam];
	palavra nomes[tam];
	
	FILE *caca; 
	FILE *words;
	FILE *saida;
	caca = fopen("arquivo-texto1.txt", "r");//atribuição feita para abrir o arquivo que contem o caça palavra
	words = fopen("arquivo-texto2.txt", "r");//atribuição feita para abrir o arquivo que contem as palavras para serem procuradas
	saida = fopen("saida.txt", "w");//atribuição feita para escrever no arquivo a saida do programa.
	
	n = carregaNaMemoria(caca,matrizCaca);
	retiraEspacos(matrizCaca);//função para tirar os eventuais espaços entre as letras
	
	qtdDeNomes = carregaNaMemoria(words,nomesCaca);//chamada da função para copiar a quantidade de nomes
	
	for(i = 0; i < qtdDeNomes; i++){
		for(j = 0; j < tam; j++){
			nomes[i].nome[j] = nomesCaca[i][j];
			
		}		
	}
	
	for(i = 0 ; i < qtdDeNomes; i++)
		analisa(matrizCaca,&nomes[i],n);	
	

	fprintf (saida,"Inicio do texto\nCustos\n\n");
	
	for (i = 0; i < qtdDeNomes; i++){ //loop para imprimir os custos
				
		fprintf (saida,"%s %i\n",nomes[i].nome,funcaoCusto(&nomes[i]));
	}
	fprintf(saida,"\n\n");

	fprintf (saida,"d = horizontal-esquerda-direita\na = horizontal-direita-esquerda\ns = vertical-topo-base\nw = vertical-base-topo\n"); 

	fprintf(saida,"\n\n");

	for(i = 0; i < qtdDeNomes; i++){
		fprintf(saida,"%i - %s ocorrencias:%i\n", i, nomes[i].nome, nomes[i].ocorrencias);
	
		for(j = 0; j < nomes[i].ocorrencias; j++)
			fprintf(saida,"(%i,%i) direcao e sentido = %c\n",nomes[i].pos[j].l, nomes[i].pos[j].c,nomes[i].dir[j]);
	
	}
	fprintf (saida,"\nFim do texto\n");
}
