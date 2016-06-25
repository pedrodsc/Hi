#ifndef _pbclib_h
#define _pbclib_h

#define tam	50;
#define arquivo1 palavras.txt
#define arquivo2 words.txt

typedef struct{
	unsigned int x;
	unsigned int y;
} coordenada;

typedef struct{
	char[tam] nome;
	int custo;
	unsigned int ocorrencias;
	coordenada pos[10];
} palavra;

void carregaNaMemoria(FILE *arquivo, char *m[][tam]){
	FILE *caca;
	caca = fopen(arquivo1, 'r');
	
	
}
#endif