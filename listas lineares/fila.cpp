#include<stdio.h>
#include<stdlib.h>

 struct celula{
    int chave;
    struct celula *prox;
};

void enfileirar(int x, celula *&i, celula *&f);
int desenfileirar(celula *&i, celula *&f);
void desalocar(celula *&L);
void imprime(celula *p);

int main(){
    celula *i,*f;
    i = NULL;
    f = NULL;
    int op,num;
    do{
    printf("1 - enfileirar\n");
    printf("2 - desenfileirar\n");
    printf("3 - imprimir fila\n");
    printf("4 - desalocar fila \n");
    scanf("%d",&op);
    if(op==1){
        printf("Digite um número para ser enfileirado: ");
        scanf("%d",&num);
        enfileirar(num,i,f);
    }
    else if(op==2){
        printf("O número desenfileirado foi %d\n",desenfileirar(i,f));
    }else if(op==3){
        imprime(i);
        printf("\n");
    }else if(op==4){
        desalocar(i);
    }
    }while(op!=5);
}

void enfileirar(int x, celula *&i, celula *&f)
{
    celula *nova;

    nova = (celula *) malloc(sizeof (celula));
    nova->chave = x;
    nova->prox = NULL;

    if(i == NULL)
        i = f = nova;
    else{
    	f->prox = nova;
    	f = nova;
    }
}

int desenfileirar(celula *&i, celula *&f)
{
    celula *aux;
    int num;

    if(i == NULL)
        return 0;
    else{
        num = i->chave;
        aux = i;
        i = i->prox;
        if(i == NULL)
            f = NULL;
        free(aux);
        return num;
    }
}

void desalocar(celula *&L)
{
    celula *aux;

    while(L != NULL)
    {
        aux = L;
        L = L->prox;
        free(aux);
    }
}

void imprime(celula *L)
{
    celula *p;
    for(p = L; p != NULL; p = p->prox)
        printf("%d ", p->chave);

}
