#ifndef _pbclib_h
#define _pbclib_h

#define tam	50

typedef struct{
	unsigned int x;
	unsigned int y;
} coordenada;

typedef struct{
	char nome[tam];
	int custo;
	unsigned int ocorrencias;
	coordenada pos[10];
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