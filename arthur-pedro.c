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
	unsigned int n,i;
	char matrizCaca[tam][tam], nomesCaca;
	
	FILE *caca;
	FILE *words;
	caca = fopen("palavras.txt", "r");
	words = fopen("words.txt", "r");
	
	n = carregaNaMemoria(caca,matrizCaca);
	retiraEspacos(matrizCaca);
	for(i = 0; i < n; i++)
		printf("%s\n", matrizCaca[i]);
	
}