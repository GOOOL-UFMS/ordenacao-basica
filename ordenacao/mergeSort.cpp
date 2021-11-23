#include <stdio.h>
#define MAX 100
//Recebe um inteiro n e um vetor de inteiros de tamanho n e os ordena por meio do metodo de intercalacao
void intercala(int p, int q, int r, int vet[MAX]);
void mergeSort(int p, int r, int vet[MAX]);

int main()
{
    int n;
    scanf("%d", &n);
    int vet[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &vet[i]);
    }
    mergeSort(0,n,vet);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", vet[i]);
    }
}

void intercala(int p, int q, int r, int vet[MAX])
{
    int i, j, k, w[MAX];
    i = p;
    j = q;
    k = 0;

    while (i < q && j < r)
    {
        if (vet[i] < vet[j])
        {
            w[k] = vet[i];
            i++;
        }
        else
        {
            w[k] = vet[j];
            j++;
        }
        k++;
    }
    while (i < q)
    {
        w[k] = vet[i];
        i++;
        k++;
    }
    while (j < r)
    {
        w[k] = vet[j];
        j++;
        k++;
    }
    for (i = p; i < r; i++)
    {
        vet[i] = w[i - p];
    }
}

void mergeSort(int p, int r, int vet[MAX]){
    int q;

    if(p<r-1){
        q = (p+r)/2;
        mergeSort(p,q,vet);
        mergeSort(q,r,vet);
        intercala(p,q,r,vet);
    }
}