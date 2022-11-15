#include <stdio.h>
#include <stdlib.h>

typedef struct pilha Pilha;

Pilha* criar_pilha(int max_elems); 
void push(Pilha* p, int valor);
int pop(Pilha* p);
void imprimir(Pilha* p);
void liberar_pilha(Pilha* p);
