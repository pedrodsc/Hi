/*
	TRABALHO COMPUTACIONAL 2 - ELÉTRICA 2016/1
	
	ARTHUR LORENCINI BERGAMASCHI
	PEDRO VINICIUS DOS SANTOS CUSTODIO

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pcblib.h"

int main (void) {
	unsigned int n, i,j, qtdDeNomes;
	char matrizCaca[tam][tam], nomesCaca[tam][tam];
	palavra nomes[tam];
	
	FILE *caca;
	FILE *words;
	caca = fopen("palavras.txt", "r");
	words = fopen("words.txt", "r");

	n = carregaNaMemoria(caca,matrizCaca);
	retiraEspacos(matrizCaca);
	
	qtdDeNomes = carregaNaMemoria(words,nomesCaca);
	
	for(i = 0; i < qtdDeNomes; i++){
		for(j = 0; j < tam; j++){
			nomes[i].nome[j] = nomesCaca[i][j];
			
		}
	}
	
	for(i = 0 ; i < 9; i++)
		analisa(matrizCaca,&nomes[i],n);
	for(i = 0; i < 9; i++){
		printf("%s ocorrências:%i\nl = %i e c = %i\n", nomes[i].nome, nomes[i].ocorrencias, nomes[i].pos[0].l,nomes[0].pos[0].c);
		
	}
}