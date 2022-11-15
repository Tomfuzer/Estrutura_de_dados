#include "pilha.h"

struct pilha{
	int topo;
	int qtd;
	int *elems;
};

Pilha* criar_pilha(int max_elems){

Pilha* p = (Pilha*) malloc (sizeof(Pilha));	
p->qtd=max_elems;
p->topo=-1;
p->elems = (int*) malloc (max_elems * sizeof(int));
p->elems[0] = 10;
//printf("Qtd: %d\n", p->qtd);
//printf("topo: %d\n", p->topo);
printf("Elemento: %d\n", p->elems[0]);

};

/* void push(Pilha* p, int valor){

if (p->topo+1==p->qtd){
	p->qtd = p->qtd * 2; 
	p->elems = (int*) realloc(p->elems, p->qtd * sizeof(int));
}
p->topo++;
printf("Insira o valor desejado: ");
scanf("%d", p->elems[p->topo]);

};  */ 



