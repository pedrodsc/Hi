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
	unsigned int n, i,j, qtdDeNomes;
	char matrizCaca[tam][tam], nomesCaca[tam][tam];
	palavra nomes[tam];
	
	FILE *caca;
	FILE *words;
	FILE *saida;
	caca = fopen("palavras.txt", "r");
	words = fopen("words.txt", "r");
	saida = fopen("saida.txt", "w");
	
	n = carregaNaMemoria(caca,matrizCaca);
	retiraEspacos(matrizCaca);
	
	qtdDeNomes = carregaNaMemoria(words,nomesCaca);
	
	for(i = 0; i < qtdDeNomes; i++){
		for(j = 0; j < tam; j++){
			nomes[i].nome[j] = nomesCaca[i][j];
			
		}		
	}
	
	for(i = 0 ; i < qtdDeNomes; i++)
		analisa(matrizCaca,&nomes[i],n);	
	for(i = 0; i < qtdDeNomes; i++){
		printf("%i - %s ocorrências:%i\n", i, nomes[i].nome, nomes[i].ocorrencias);
		//if(nomes[i].ocorrencias > 1)
		for(j = 0; j < nomes[i].ocorrencias; j++)
			printf("l = %i c = %i dir = %c\n",nomes[i].pos[j].l, nomes[i].pos[j].c,nomes[i].dir[j]);
		printf("é palindromo????? %i\n",palindromo(nomes[i].nome));	
	}
	
	for (i = 0; i < qtdDeNomes; i++) 
		funcaoCusto(&nomes[i]);
	
	//printf("é palindromo????? %i\n",palindromo(nomes[0].nome));
	
	
	
}
