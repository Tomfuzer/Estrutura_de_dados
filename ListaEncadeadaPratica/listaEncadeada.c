#include <stdio.h>
#include <stdlib.h>

//Exercitando lista encadeada

typedef struct lista
{
    struct noh *inicio; // nome da vari�vel � 'inicio' ela � do tipo ponteiro e aponta pra um struct(vari�vel tipo) 'noh'
    int tamanho;
}lista;

typedef struct noh
{
    int valor;
    struct noh *proximo;
    
}noh;

//Inserindo no inicio da lista!!!
void inserir_inicio(lista *primeiraLista, int valor){ // o parametro 'lista *primeiraLista' deve ser um ponteiro pois eu quero que as informa��es persistam apos a execu��o da funcao
    noh *novo = (noh*)malloc(sizeof(noh));
    novo->valor = valor; // equivalente (*novo).valor = valor;
    novo->proximo = primeiraLista->inicio; // O proximo do noh criado aponta para o primeiro elemento da lista 
    primeiraLista->inicio = novo; // O inicio da lista agora aponta para o novo noh 
    primeiraLista->tamanho++;
}

void inserir_fim(lista *primeiraLista, int valor){
    noh *no, *novo = (noh*)malloc(sizeof(noh));
    novo->valor = valor;
    novo->proximo = NULL;

    if (primeiraLista->inicio == NULL){ // Se o valor a ser inserido (noh) for o primeiro item da minha lista, preciso verificar! 
        primeiraLista->inicio = novo; // o inicio da minha lista agora sera o valor noh criado
        }else{
        no = primeiraLista->inicio; // no vai ser o primeiro elemento da lista
        while(no->proximo != NULL)
            no = no->proximo; //DÚVIDA!!! Quando eu -> no->proximo ele já sabe em qual variavel dentro do no ele deve colocar o valor, nao preciso fazer algo como no->(variavel) = no->proximo???
        no->proximo = novo; // quando no for nulo, ou seja, cheguei no ultimo no da lista, então esse no vai apontar pro no (novo) recem criado!!
    }
    primeiraLista->tamanho++;


}

void imprimir(lista *primeiraLista){
    noh *inicio = primeiraLista->inicio;
    printf("Tamanho da lista: %d -- ", primeiraLista->tamanho);
    while(inicio != NULL){
        printf("%d ", inicio->valor);
        inicio = inicio->proximo;
    }   

printf("\n\n");

}


int main (){

printf("Autor: Tom Fuzer!\n");

lista primeiraLista;
primeiraLista.inicio = NULL;
primeiraLista.tamanho = 0;
int op, valor;

do{
    printf("1 - Inserir no inicio\n2 - Inserir no fim \n3 - Imprimir Lista \n4 - Sair\n");
    scanf("%d", &op);
    switch(op){
        case 1:
        printf("Insira o valor desejado: ");
        scanf("%d", &valor);
        inserir_inicio(&primeiraLista, valor);
        break;
        case 2:
        printf("Insira o valor desejado: ");
        scanf("%d", &valor);
        inserir_fim(&primeiraLista, valor);  
        break;
        case 3:
        imprimir(&primeiraLista); 
        break;
        case 4:
        printf("Finalizando!");  
        default:
            printf("Escolha um opcao valida");
    }



}while(op != 4);

}
