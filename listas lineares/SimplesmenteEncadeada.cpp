#include <stdio.h>
#include <stdlib.h>

struct celula
{
    int chave;
    struct celula *prox;
};

void imprime_lista(celula *lst);
void inserir_inicio(int n, celula *&lst);
void inserir_fim(int n, celula *&lst);
void busca_remove(int n, celula *&lst);
void desalocar(celula *&lst);
void inserir_aposI(int x, int i, celula *&lst);
void removerPares(celula *&lst);
celula *concatenar(celula *lst1, celula *lst2);

int main()
{
    //iniciando uma lista vazia
    celula *lista = NULL;
}

void imprime_lista(celula *lst)
{
    celula *p;

    for (p = lst; p != NULL; p = p->prox)
    {
        printf("%d ", p->chave);
    }
}

void inserir_inicio(int n, celula *&lst)
{
    celula *novo;

    novo = (celula *)calloc(1, sizeof(celula));
    novo->chave = n;
    novo->prox = lst;
    lst = novo;
}

void inserir_fim(int n, celula *&lst)
{
    celula *novo, *p;

    novo = (celula *)malloc(sizeof(celula));
    novo->chave = n;
    novo->prox = NULL;

    if (lst == NULL)
        lst = novo;
    else
    {
        p = lst;
        while (p->prox != NULL)
            p = p->prox;

        p->prox = novo;
    }
}

void busca_remove(int n, celula *&lst)
{
    celula *p, *q;
    p = NULL;
    q = lst;
    while (q != NULL && q->chave != n)
    {
        p = q;
        q = q->prox;
    }
    if (q != NULL)
    {
        if (p != NULL)
        {
            p->prox = q->prox;
            free(q);
        }
        else
        {
            lst = q->prox;
            free(q);
        }
    }
}

void desalocar(celula *&lst)
{
    celula *aux;
    while (lst != NULL)
    {
        aux = lst;
        lst = aux->prox;
        free(aux);
    }
}

void inserir_aposI(int x, int i, celula *&lst)
{
    celula *novo = (celula *)calloc(1, sizeof(celula));

    novo->chave = x;

    if (lst == NULL)
        lst = novo;
    else
    {
        int cont = 1;
        celula *p = lst;
        while (cont < i && p->prox != NULL)
        {
            p = p->prox;
            cont++;
        }
        novo->prox = p->prox;
        p->prox = novo;
    }
}

void removerPares(celula *&lst)
{
    celula *p, *q;

    p = NULL;
    q = lst;

    while (q != NULL)
    {
        if (q->chave % 2 == 0)
        {
            if (p == NULL)
            {
                lst = lst->prox; 
                free(q);
                q = lst;
            }
            else
            { 
                p->prox = q->prox;
                free(q);
                q = p->prox;
            }
        }
        else
        {
            p = q;
            q = q->prox;
        }
    }
}

celula *concatenar(celula *lst1, celula *lst2)
{
    celula *p;
    if (lst1 == NULL)
    {
        lst1 = lst2;
    }
    else
    {
        p = lst1;
        while (p->prox != NULL)
        {
            p = p->prox;
        }
        p->prox = lst2;
        lst2 = NULL;
        return lst1;
    }
}
