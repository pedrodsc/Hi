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

int carregaNaMemoria(FILE *arquivo, char *m[][tam]){
	unsigned int numero,i;
	char tamanho[tam], *ptr;
	
	fgets(tamanho, tam, arquivo);
	numero = (int) strtol(tamanho,&ptr,10);
	for(i = 0; i < numero; i++){
		fgets(m[i][0],tam,arquivo)
	}
	return numero;
}
#endif