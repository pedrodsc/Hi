#ifndef _pbclib_h
#define _pbclib_h

#define tam	50

typedef struct coordenada{
	unsigned int l;
	unsigned int c;
} coordenada;

typedef struct palavra{
	char nome[tam];
	int custo;
	unsigned int ocorrencias;
	coordenada pos[tam];
} palavra;

int carregaNaMemoria(FILE *arquivo, char m[tam][tam]){
	unsigned int numero,i;
	char tamanho[tam], *ptr;
	
	fgets(tamanho, tam, arquivo);
	numero = (int) strtol(tamanho,&ptr,10);
	for(i = 0; i < numero; i++){
		fgets(&m[i][0],tam,arquivo);
	}
	return numero;
}

void analisaEsqDir(char matrizCaca[tam][tam], struct palavra *nome, unsigned int tamanho){
	unsigned int l, c, ci, tamanhoDaPalavra, tempx, tempy, ocorrencias;
	tamanhoDaPalavra = strlen(nome->nome);
	printf("Tamanho da palavra - %i\n",tamanhoDaPalavra);
	/*
	// ANALISA DA ESQUERDA PARA A DIREITA.
	for(l = 0; l < tamanho; l++){
		for(c = 0; c < tamanho; c++){
			printf("Linha: %i, Coluna: %i\n",l,c);
			if(tamanho - c >= tamanhoDaPalavra - 1){
				while(nome->nome[ci] == matrizCaca[l][c+ci]){
					ci++;
					printf("Entrei no loop interno - %i\n",ci);
				} 
				printf("Valor de ci pios loop - %i\n",ci);
				if(ci == tamanhoDaPalavra - 1){ // Menos o \n.
					printf("Comparações feitas\n");
					nome->pos[nome->ocorrencias].l = l;
					nome->pos[nome->ocorrencias].c = c;
					nome->ocorrencias++;
				}
				ci = 0;
			}
		}
	}*/
	// ---------------------------------
	// ANALISA DA DIREITA PARA A ESQUERDA
	/*for(l = 0; l < tamanho; l++){
		for(c = tamanho; c > 0; c--){
			printf("Linha: %i, Coluna: %i\n",l,c);
			if(c - tamanho >= tamanhoDaPalavra - 1){
				while(nome->nome[ci] == matrizCaca[l][c-ci]){
					ci++;
					printf("Entrei no loop interno - %i\n",ci);
				} 
				printf("Valor de ci pios loop - %i\n",ci);
				if(ci == tamanhoDaPalavra - 1){ // Menos o \n.
					printf("Comparações feitas\n");
					nome->pos[nome->ocorrencias].l = l;
					nome->pos[nome->ocorrencias].c = c;
					nome->ocorrencias++;
				}
				ci = 0;
			}
		}
	}*/
	// -----------------------------
	// ANALISA DE CIMA PARA BAIXO
	for(c = 0; c < tamanho; c++){
		for(l = 0; l < tamanho; l++){
			printf("Linha: %i, Coluna: %i\n",l,c);
			if(tamanho - l >= tamanhoDaPalavra - 1){
				while(nome->nome[ci] == matrizCaca[c][c+ci]){
					ci++;
					printf("Entrei no loop interno - %i\n",ci);
				} 
				printf("Valor de ci pios loop - %i\n",ci);
				if(ci == tamanhoDaPalavra - 1){ // Menos o \n.
					printf("Comparações feitas\n");
					nome->pos[nome->ocorrencias].l = l;
					nome->pos[nome->ocorrencias].c = c;
					nome->ocorrencias++;
				}
				ci = 0;
			}
		}
	}
}

void retiraEspacos(char m[tam][tam]){
	char n[tam][tam];
	unsigned int i,j, nj=0;
	for(i = 0; i < tam; i++){
		for(j = 0; j < tam; j++){
			if(m[i][j] != ' '){
				n[i][nj] = m[i][j];
				nj++;
			}
		}
		nj = 0;
	}	
	for(i = 0; i < tam; i++)
		for(j = 0; j < tam; j++)
			m[i][j] = n[i][j];	
}

#endif