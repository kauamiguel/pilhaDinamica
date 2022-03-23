#include <stdio.h>
#include <stdlib.h>

typedef struct noitem{
    int info;        // informação a ser colocada;
    struct nodeitem *next;  //apontar para o proximo membro;
}no;


typedef struct{
    no *topo; // unico parametro para acessar a pilha é o ponteiro topo;
}stack;



stack *newStack ();
void push(stack *s, int value);
int pop(stack *s);
int top(stack *s);
int IsStackEmpty(stack *s);
int IsStackFull (stack *s); // NUNCA FICARA FULL POIS SO ADICIONA O QUE QUER;
no *NewNo(int value); // criar um novo no;



int main(){

stack *p = newStack();
push(p,20);
push(p,30);
if (IsStackEmpty(p)){
    printf("pilha se encontra vazia \n");
}
printf("topo: %d",top(p));



}

stack *newStack (){
    stack *p = (stack *) malloc(sizeof(stack));
    p->topo = NULL;
    return p;
}

int IsStackEmpty(stack *s){
    if (s->topo == NULL){
        return 1;
    }else{
        return 0;
    }
}

no *NewNo(int value){
    no *n = (no *) malloc(sizeof(no)); //cria espaço na memoria pro novo no;
    n->info = value; // informação desejada
    n->next = NULL; // novo no nao aponta pra ninguem;
    return n;  
}

void push(stack *s, int value){
    no *n = NewNo(value);  //recebo o entedeço do no criado em (newno());
    n->next = s->topo;  // o ponteiro do novo elemento aponta pro elemento anterior;
    s->topo = n;    //  topo vai apontar pro novo elemento;
}


int top(stack *s){
    if (IsStackEmpty(s)){
        return 1;
    }
    return s->topo->info;
    
}


int pop(stack *s){
    if (IsStackEmpty(s)){
        return 1;
    }

    int aux;
    no *n;  //cria-se uma variavel do tipo no para armazenar a info e liberar memoria;

    n = s->topo;  //variavel recebe o endereço do topo
    aux = n->info;  //aux armazena o valor contido no NO anterior
    s->topo = n->next;   // topo aponta pro topo anterior;
    free(n);  //libera memoria;

    return aux;  //retorna o valor que estava contido no NOVO NO;
}