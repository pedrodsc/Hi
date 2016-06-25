#ifndef _pbclib_h
#define _pbclib_h

#define tam	50

typedef struct coordenada{
	unsigned int x;
	unsigned int y;
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
	unsigned int x, y, xi, tamanhoDaPalavra, tempx, tempy, ocorrencias;
	tamanhoDaPalavra = strlen(nome->nome); 
	for(y = 0; y < tamanho; y++){
		for(x = 0; x < tamanho; x++){
			if(tamanho - x >= tamanhoDaPalavra){
				if(matrizCaca[y][x] == nome->nome[0]){
					tempx = x;
					tempy = y;
					for(xi = 0; xi < tamanhoDaPalavra-2; xi++){
						if(matrizCaca[y][x+xi] == nome->nome[xi])
							continue;
						else
							break;
					}
					
					//if(xi == tamanhoDaPalavra - 1){
						ocorrencias = nome->ocorrencias;
						nome->pos[ocorrencias].x = tempx;
						nome->pos[ocorrencias].y = tempy;
						nome->ocorrencias += 1;
					//}
				}
				else
					break;
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