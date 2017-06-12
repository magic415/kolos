#include <stdio.h>

#include <stdlib.h>

void fillMatrix(int** tab, int n){
    int i,j,k = 1;
    for(i = 0;i<n;i++)
        for(j = 0;j<n;j++)
            tab[i][j] = k++;
}

void deleteMatrix(int*** ptab, int n){
    int i;
    for(i = 0;i<n;i++)
        free((*ptab)[i]);
    free(*ptab);
    *ptab = NULL;

}
int** createMatrix(int n){
    int i,**point = (int**)malloc(n*sizeof(int*));
    if(point!=NULL)
        for(i = 0;i<n;i++){
            point[i] = (int*)malloc(n*sizeof(int));
            if(point[i] == NULL)
                {
                    deleteMatrix(&point,i);
                    break;
                }
        }
    return point;
}

    void copyMatrix(int*** pdest, int** src, int n){
    int **dest=createMatrix(n),i,j;
    if(dest!=NULL)
        for(i = 0;i<n;i++)
            for(j = 0;j<n;j++)
                dest[i][j] = src[i][j];
    *pdest = dest;
}
void displMatrix(int** tab,int n){
    int i,j;
    for(i = 0;i<n;i++){
        for(j = 0;j<n;j++)
            printf("%3d ",tab[i][j]);
        putchar('\n');}
    printf("\n");
}

int main(){

    int a, **tab,i,j,**tab2;
    printf("podaj rozmiar tablicy\n");
    scanf("%d",&a);
    tab = createMatrix(a);
    if(tab==NULL)
        return 0;
    fillMatrix(tab,a);
    copyMatrix(&tab2,tab,a);
    if(tab2==NULL)
        return 0;

    displMatrix(tab,a);
    displMatrix(tab2,a);

    deleteMatrix(&tab,a);
    deleteMatrix(&tab2,a);


return 0;
}