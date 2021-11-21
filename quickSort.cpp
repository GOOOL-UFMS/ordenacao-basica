#include <stdio.h>
//Recebe um inteiro n e um vetor de inteiros de tamanho n e os ordena por meio do metodo de separacao
int separa(int p, int r, int *vet);
void quickSort(int p, int r, int *vet);
void troca(int &a, int &b);

int main()
{
    int n;
    scanf("%d", &n);
    int vet[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &vet[i]);
    }
    quickSort(0, n - 1, vet);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", vet[i]);
    }
}

int separa(int p, int r, int *vet)
{
    int x, i, j;

    x = vet[p];
    i = p - 1;
    j = r + 1;
    while (1)
    {
        do
        {
            j--;
        } while (vet[j] > x);
        do
        {
            i++;
        } while (vet[i] > x);
        if (i < j)
        {
            troca(vet[i], vet[j]);
        }
        else
        {
            return j;
        }
    }
}

void troca(int &a, int &b)
{
    int aux;
    aux = a;
    a = b;
    b = aux;
}

void quickSort(int p, int r, int *vet)
{
    int q;
    
    if (p < r)
    {
        q = separa(p, r, vet);
        quickSort(p, q, vet);
        quickSort(q + 1, r, vet);
    }
}