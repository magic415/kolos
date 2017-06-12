#include <stdio.h>

int * add(int* tab, int n, int new_elem)
{
 int *wsk = malloc((n+1)*sizeof(*wsk)),i;

    if(wsk==NULL){
        return NULL;
        }

    if(tab!=NULL){
        for(i=0;i<n;i++)
            wsk[i] = tab[i];}

    wsk[n] = new_elem;
    free(tab);
    return wsk;

}

int main ()
{

int *tablica = NULL,i,a;
    for(i=0;i<11;i++)
        {
        scanf("%d",&a);
        tablica = add(tablica,i,a);
        if(tablica[i]==NULL)
            break;
        }

    for(i = 0;i<11;i++)
        printf("%d ",tablica[i]);
// aaa walne komentarz
return 0;
}
