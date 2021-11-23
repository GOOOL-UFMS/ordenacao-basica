#include <stdio.h>
//Recebe um inteiro n e um vetor de inteiros de tamanho n e os ordena por meio do metodo de insercao
void insertionSort(int n, int *vet);

int main()
{
    int n;
    scanf("%d", &n);
    int vet[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &vet[i]);
    }

    insertionSort(n, vet);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", vet[i]);
    }
}

void insertionSort(int n, int *vet)
{
    int i, j, x;
    for (i = 1; i < n; i++)
    {
        x = vet[i];
        for (j = i - 1; j >= 0 && vet[j] > x; j--)
        {
            vet[j + 1] = vet[j];
        }
        vet[j + 1] = x;
    }
}