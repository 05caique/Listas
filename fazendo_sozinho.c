/*construa uma lista ligada simples onde cada nó armazene um valor inteiro positivo. implemente as seguintes funcionalidades:
// a - obtenha do usuário a quantidade de nós a ser inseridos na lista. cada valor de nó deve variar entre 1 e 10.
// b - calcule e imprima o tamanho da lista.
//c - calcule a soma de todos valores pares da lista.
//d - calcule o produto de todos valores impares.
//e - calcule a média total da lista.
f - gerar uma segunda lista onde cada nó deverá armazenar 2 valores inteiros positivos, um número n e uma quantidade sendo n um 
valor encontrado na 1ª lista e a quantidade o seu número de ocorrências. Detalhe, não deve existir elementos repetidos nesta lista.
*implementar uma função para cada cálculo.*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct{
	int valor;
	struct celula *proximo;
}celula;

typedef struct{
	int elemento;
	int frequencia;
	struct elemento *proximo;
}elemento;

typedef struct{
	struct celula *topo;
}lista;

typedef struct{
	struct elemento *topo;
}lista2;


// lista 1


void inicia_lista(lista *l){
	l->topo = NULL;
}

celula *cria_no(int valor){
	celula *p;
	p = malloc (sizeof(celula));
	p->valor = valor;
	p->proximo = NULL;
	return p;
}

int pedir_usuario(void){
	int n;
	printf("digite qual o tamanho da lista? ");
	scanf("%d", &n);
	return n;
}

void insere_topo(lista *l, celula *p){
	p->proximo = l->topo;
	l->topo = p;
}

void exibe_lista(lista *l){
	celula *p;
	int i=0;
	for (p=l->topo; p != NULL; p = p->proximo)
		printf ("%d \t", p->valor);
}

void tamanho_lista(lista *l){
	celula *p;
	int i=0;
	for (p=l->topo; p != NULL; p = p->proximo)
		i++;
	printf("\ntamanho da lista: %d", i);
}

void soma_pares(lista *l){
	celula *p;
	int soma = 0;
	for (p=l->topo; p!=NULL; p = p->proximo){
		if (p->valor %2 == 0)
			soma = soma + p->valor;
	}
	printf ("\nsoma dos numeros pares: %d", soma);
}

void multiplica_impares(lista *l){
	celula *p;
	int multiplica = 1;
	for (p=l->topo; p!=NULL; p = p->proximo){
		if (p->valor%2 != 0 )
			multiplica = multiplica * p->valor;
	}
	printf ("\nmultiplicacao de todos os impares: %d", multiplica);
}

void media_lista(lista *l){
	celula *p;
	double media = 0;
	int i=0;
	for (p=l->topo; p!=NULL; p=p->proximo){
		media = media + p->valor;
		i++;
	}
	media = media/i;
	printf ("\nmedia de toda a lista: %.1f\n", media);
}

//lista 2

int analisa_lista(lista *l){
	celula *p;
	int i;
	for (p=l->topo;p->proximo=NULL; p=p->proximo){
		i=0;
		for (p=l->topo;p->proximo=NULL; p=p->proximo){
			if (p==p->proximo)
			i++;
		}
	}
	return i;
}

void inicia_lista2(lista2 *l2){
	l2->topo = NULL;
}

elemento *cria_no2(lista *l){
	elemento *c;
	celula *p;
	int i;
	c = malloc(sizeof(elemento));
	for (p=l->topo; p!=NULL;p=p->proximo){
		i=0;
		for (p=l->topo;p->proximo!=NULL; p=p->proximo){
			if (p == p->proximo){
				i++;
			}
		}
		c->elemento = p;
		c->frequencia = i;
		c->proximo=NULL;
	}
	return c;
}

void insere_topo2(lista2 *l2, elemento *c){
	c->proximo = l2->topo;
	l2->topo = c;
}

void exibe_lista2(lista2 *l2){
	elemento *c;
	int i=0;
	for (c=l2->topo; c != NULL; c = c->proximo)
		printf ("elemento:%d \tfrequencia:%d\n", c->elemento, c->frequencia);
}

int main (void){
	lista l;
	lista2 l2;
	celula *p;
	elemento *c;
	int n = 0, i, n2 = 0;
	//srand(time(NULL));
	//no = 1 + rand() %11;
	n = pedir_usuario();
	inicia_lista(&l);
	for (i=0; i<n; i++){
		p = cria_no(i);
		insere_topo(&l, p);
	}
	exibe_lista(&l);
	tamanho_lista(&l);
	soma_pares(&l);
	multiplica_impares(&l);
	media_lista(&l);
	
	
	n2 = analisa_lista(&l);
	inicia_lista2(&l2);	
	c = cria_no2(&l);
	for (i=0;i<n;i++){
		c = cria_no2(&l);
		insere_topo2(&l2, c);
	}
	exibe_lista2(&l2);	
	return 0;
}
