#ifndef _pbclib_h
#define _pbclib_h

#define tam	50 // tamanho máximo para a matriz do caça palavra

typedef struct coordenada{ //struct para indicar as coordenadas da linha e da coluna
	unsigned int l;
	unsigned int c;
} coordenada;

typedef struct palavra{ // struct para ter os valores do nome, custo, ocorrencias e direção.
	char nome[tam];
	int custo;
	unsigned int ocorrencias;
	coordenada pos[tam];
	char dir[tam];
} palavra;


int funcaoCusto(struct palavra *nome){ // função feita para calcular o custo das palavras.
	if (nome->ocorrencias == 0){
		//se a palavra não aparece, o custo dela é -1
		return -1;	
	}
	else{		
		// se a palavra aparece, o custo dela é esse. o -1 ali é para tirar o "\n"
		return nome->ocorrencias*(strlen(nome->nome)-1);
	}
}

int carregaNaMemoria(FILE *arquivo, char m[tam][tam]){	//função feita para  copiar 
	unsigned int numero,i;
	char tamanho[tam], *ptr; //ptr é um ponteiro qualquer feito para a função strtol funcionar
	
	fgets(tamanho, tam, arquivo);
	numero = (int) strtol(tamanho,&ptr,10);
	for(i = 0; i < numero; i++){
		fgets(&m[i][0],tam,arquivo);
	}
	return numero;
}

int palindromo(char linha[]){ // Função que verifica se a palavra é um palindromo ou não.
	int sim = 0,i = 0,k = 0;
	k = strlen(linha);

	while(i <= k -i -1){
		if(linha[i] == linha[k-i-2]){
			sim = 1;//se sim = 1, logo a palavra é um palíndromo.
		}
		else{
			sim = 0;//caso de não ser um palíndromo
			break;
		}
		i++;
	}
	return sim;
}

void analisa(char matrizCaca[tam][tam], struct palavra *nome, unsigned int tamanho){
	unsigned int l, c, ci = 0, tamanhoDaPalavra;
	tamanhoDaPalavra = strlen(nome->nome);
	//printf("Tamanho da palavra - %i\n",tamanhoDaPalavra-1);
	/*
		A principal ideia dessa função é fazer ela procurar em quatro sentidos diferentes
	para poder dizer como ela está escrita, como, horizontal-esquerda-direita, por exemplo.

	*/
	// ANALISA DA ESQUERDA PARA A DIREITA.
	for(l = 0; l < tamanho; l++){
		for(c = 0; c < tamanho; c++){
			if(tamanho - c >= tamanhoDaPalavra -1){
				while(nome->nome[ci] == matrizCaca[l][c+ci]){
					ci++;
					if(ci == tamanho)
						break;
				} 
				if(ci == tamanhoDaPalavra - 1){ // Menos o \n.
					nome->pos[nome->ocorrencias].l = l;
					nome->pos[nome->ocorrencias].c = c;
					nome->dir[nome->ocorrencias] = 'd'; 
					nome->ocorrencias++;

				}
				ci = 0;
			}
		}
	}
	// ---------------------------------
	// ANALISA DA DIREITA PARA A ESQUERDA
	for(l = 0; l < tamanho; l++){
		for(c = tamanho; c > 0; c--){
			if(c - tamanho >= tamanhoDaPalavra - 1 ){
				while(nome->nome[ci] == matrizCaca[l][c-ci]){
					ci++;
					if(ci == tamanho - 1)
						break;
				} 
				if(ci == tamanhoDaPalavra - 1){ // Menos o \n.
					nome->pos[nome->ocorrencias].l = l;
					nome->pos[nome->ocorrencias].c = c;
					nome->dir[nome->ocorrencias] = 'a';
					nome->ocorrencias++;
					
				}
				ci = 0;
			}
		}
	}
	// -----------------------------
	// ANALISA DE CIMA PARA BAIXO
	for(c = 0; c < tamanho; c++){
		for(l = 0; l < tamanho; l++){
			if(tamanho - l >= tamanhoDaPalavra -1){
				while(nome->nome[ci] == matrizCaca[c+ci][l]){
					ci++;
					if(ci == tamanho)
						break;
				} 
				if(ci == tamanhoDaPalavra - 1){ // Menos o \n.
					nome->pos[nome->ocorrencias].l = c;
					nome->pos[nome->ocorrencias].c = l;
					nome->dir[nome->ocorrencias] = 's';
					nome->ocorrencias++;

				}
				ci = 0;
			}
		}
	}
	// -----------------------------
	// ANALISA DE BAIXO PARA CIMA
	for(c = 0; c < tamanho; c++){
		for(l = tamanho; l > 0; l--){
			if(l - tamanho >= tamanhoDaPalavra -1){
				while(nome->nome[ci] == matrizCaca[l-ci][c]){
					ci++;
					if(ci == tamanho)
						break;
				} 
				if(ci == tamanhoDaPalavra - 1){ // Menos o \n.
					nome->pos[nome->ocorrencias].l = l;
					nome->pos[nome->ocorrencias].c = c;
					nome->dir[nome->ocorrencias] = 'w';
					nome->ocorrencias++;

				}
				ci = 0;
			}
		}
	}
}

void retiraEspacos(char m[tam][tam]){ // função feita para remover os eventuais espaços entre as letras do caça palavra.
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
