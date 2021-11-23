#include <stdio.h>
#include <stdlib.h>
//Aloca um vetor dinamicamente e o imprime na ordem original e de alocacao e na ordem inversa
int main()
{

    int i, n, *vetor, *pt;

    scanf("%d", &n);
    vetor = (int *)malloc(n * sizeof(int));
    if (vetor != NULL)
    {
        for (i = 0; i < n; i++)
        {
            scanf("%d", (vetor + i));
        }
        for (pt = vetor; pt < (vetor + n); pt++)
        {
            printf("%d ", *pt);
        }
        printf("\n");
        for (i = n - 1; i >= 0; i--)
        {
            printf("%d ", vetor[i]);
        }
        printf("\n");
        free(vetor);
    }
    else
    {
        printf("Nao e possivel alocar espaco");
    }
}