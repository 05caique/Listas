#include <stdio.h>
#include <stdlib.h>

typedef struct{
	struct elemento *pilha;
	struct celula *proximo;
	struct celula*anterior;
}celula;

typedef struct{
	int valor;
	struct elemento *proximo;
	struct elemento *anterior;
}elemento;

typedef struct{
	struct fila *topo;
	struct fila *fim;
}fila;

typedef struct{
	struct pilha *topo;
}pilha; 

elemento *cria_elemento(int valor){
	elemento *e;
	e = malloc (sizeof(elemento));
	e->valor = valor;
	e->proximo = NULL;
	return e;
}

void inicia_pilha(pilha *p){
	p->topo = NULL;
}

void empilha(pilha *p, elemento *e){
	if (p->topo == NULL){
		e->proximo = p->topo;
		return;
	}
	else{
		p->topo = e->anterior;
		e->proximo = p->topo;
		p->topo = e;
	}

}

void desempilha(pilha *p, elemento *e){
	p->topo = e->proximo;
	free(e);	
}

void exibe_pilha(pilha *p){
	elemento *e;
	for (e=p->topo;e!=NULL;e=e->proximo){
		printf("\n elemento %d", e->valor);
		
	}
}

int main (void){
	elemento *e;
	pilha *p;
	int i;
	inicia_pilha(&p);
	for (i=0;i<10;i++){
		e = cria_elemento(i);
		empilha(&p, e);
	}
	desempilha(&p, e);
	exibe_pilha(&p);
	return 0;
}
