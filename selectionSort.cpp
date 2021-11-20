#include <stdio.h>
#define MAX 100
void selectionSort(int n, int vet[MAX]);
void troca(int &a, int &b);

int main()
{
    int n;
    scanf("%d", &n);
    int vet[MAX];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &vet[i]);
    }

    selectionSort(n, vet);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", vet[i]);
    }
}

void selectionSort(int n, int vet[MAX])
{
    int i, j, min;

    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
        {
            if (vet[j] < vet[min])
            {
                min = j;
            }
        }
        troca(vet[i], vet[min]);
    }
}

void troca(int &a, int &b)
{
    int aux;
    aux = a;
    a = b;
    b = aux;
}