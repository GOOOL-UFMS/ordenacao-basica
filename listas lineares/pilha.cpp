#include <stdio.h>
#include <stdlib.h>

struct celula
{
    int chave;
    struct celula *prox;
};
void empilharI(int , celula *&);
int desempilharI(celula *&);
void desalocarP(celula *&);
void imprimePI(celula *);
int main(){
    celula *pilha = NULL;
    int op,num;
    do{
    printf("1 - empilhar\n");
    printf("2 - desempilhar\n");
    printf("3 - imprimir pilha\n");
    printf("4 - desalocar pilha \n");
    scanf("%d",&op);
    if(op==1){
        printf("Digite um número para ser empilhado: ");
        scanf("%d",&num);
        empilharI(num, pilha);
    }
    else if(op==2){
        printf("O número desempilhado foi %d\n",desempilharI(pilha));
    }else if(op==3){
        imprimePI(pilha);
        printf("\n");
    }else if(op==4){
        desalocarP(pilha);
    }
    }while(op!=5);
}

void empilharI(int x, celula *&lst)
{
    celula *nova;
    nova = (celula *) malloc(sizeof (celula));
    nova->chave = x;
    nova->prox = lst;
    lst = nova;
}

int desempilharI(celula *&lst)
{
    celula *aux;
    int num;

    if(lst == NULL)
        return -1;
    else{
        num = lst->chave;
        aux = lst;
        lst = lst->prox;
        free(aux);
        return num;
    }
}

void imprimePI(celula *lst)
{
    celula *p;

    for (p = lst; p != NULL; p = p->prox)
        printf("%d ", p->chave);
}

void desalocarP(celula *&lst)
{
    celula *aux;
    while(lst)
    {
        aux = lst;
        lst = lst->prox;
        free(aux);
    }
}