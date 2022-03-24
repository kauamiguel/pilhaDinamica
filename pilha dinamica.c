#include <stdio.h>
#include <stdlib.h>

typedef struct noitem{
    int info;       
    struct nodeitem *next;  
}no;


typedef struct{
    no *topo;
}stack;



stack *newStack ();
void push(stack *s, int value);
int pop(stack *s);
int top(stack *s);
int IsStackEmpty(stack *s);
int IsStackFull (stack *s); 
no *NewNo(int value); ;



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
    no *n = (no *) malloc(sizeof(no)); 
    n->info = value; 
    n->next = NULL; 
    return n;  
}

void push(stack *s, int value){
    no *n = NewNo(value); 
    n->next = s->topo; 
    s->topo = n;   
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
    no *n;  

    n = s->topo; 
    aux = n->info; 
    s->topo = n->next;  
    free(n);  

    return aux;  
}
