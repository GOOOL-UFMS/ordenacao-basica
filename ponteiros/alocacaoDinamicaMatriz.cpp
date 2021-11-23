#include <stdio.h>
#include <stdlib.h>
//Aloca uma matriz dinamicamente e faz a impressao dela
int main()
{
    int i, j, m, n, **matriz, **pt;
    scanf("%d %d", &m, &n);
    matriz = (int **)malloc(m * sizeof(int *));
    if(matriz==NULL){
        return 0;
    }else{
    for(i=0;i<m;i++){
        matriz[i] = (int *) malloc (n*sizeof(int));
        if(matriz==NULL){
            return 0;
        }
    }
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            scanf("%d", &matriz[i][j]);
        }
    }
    pt = matriz;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            printf("%d ", *(*(pt+i)+j));
        }
        printf("\n");
    }
    }
}