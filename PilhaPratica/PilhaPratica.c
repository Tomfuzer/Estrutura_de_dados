#include <stdio.h>
#include <stdlib.h>


//PILHA INSERE E REMOVE NO TOPO

typedef struct itensPilha
{
    int valor;
    struct itensPilha *prox_item;

}itensPilha;

typedef struct Pilha
{
    int max_qtd;
    int atual_qtd;
    struct itensPilha *topo;

}Pilha;

Pilha* criar_pilha(int max){
    Pilha *pilha = (Pilha*) malloc(sizeof(Pilha));    
    pilha->max_qtd = max;
    pilha->atual_qtd = 0;    
    pilha->topo = NULL;

    return pilha;
}

void inserir_pilha(Pilha *pilha){
    if(pilha->atual_qtd == pilha->max_qtd){
        printf("Pilha cheia!!!\n");
        return;
    }
    int valor;
    printf("Insira o valor desejado: ");
    scanf("%d", &valor);
        
    itensPilha *itemPilha = (itensPilha*) malloc (sizeof(itensPilha));
    itemPilha->valor = valor; // inserir valor
    itemPilha->prox_item = pilha->topo; // O dado 'prox_item' do item adicionado na pilha aponta para o item do topo da pilha!
    pilha->topo = itemPilha;

    pilha->atual_qtd++;

}

/* Funcao para verificar se uma Pilha eh vazia */
int vazia (Pilha* pilha){
   return (pilha->topo==NULL);
}

void listar_elementos (Pilha* pilha){

   printf("\n\n#### Lista de Elementos da Pilha #####\n\n");
   if(!vazia(pilha)){  
      itensPilha* q;
      for (q=pilha->topo; q!=NULL; q=q->prox_item) // O topo aponta pro anterior a ele na pilha, ou seja, a lista será impressa do topo > primeiro 
          printf("%d\n",q->valor);
   } else printf("Pilha Vazia");
}


int main (){

int max, valor, op;

Pilha *pilha; // criar variavel do tipo pilha que é um ponteiro pra uma estrutura do tipo pilha


printf("Digite o quantidade maxima da pilha: ");
scanf("%d", &max);
pilha = criar_pilha(max); // a funcao criar pilha retorna o endereco da pilha criada

do{
    printf("1 - Inserir valor\n2 - Imprimir Lista \n3 - Sair\n");
    scanf("%d", &op);
    switch(op){
        case 1:
        inserir_pilha(pilha);
        break;
        case 2:
        listar_elementos(pilha); 
        break;
        case 3:
        printf("Finalizando!");  
        default:
        printf("Escolha um opcao valida\n");
    }


    }while(op != 3);
}