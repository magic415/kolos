#include <stdio.h>
#include <stdlib.h>
#define MAX 19


struct lista {
 char imie [MAX];
 char nazwisko [MAX];
 int rok;

};


struct element{
// druga galaz
    struct lista Dane;
    struct element* Nast;

};

struct lista pobranie()
{
    struct lista x;
    gets(x.imie);
    gets(x.nazwisko);
    scanf("%d",&x.rok);
    getchar();
    return x;
}

struct element * dodajelement(struct element* Start, struct lista Nowywpis)
{
    struct element* temp = malloc(sizeof(struct element));
    temp->Dane = Nowywpis;
    temp->Nast = Start;
    struct element * wsk = temp;

    return wsk;

}
void wyswietl(struct element* Start)
{
    struct element* temp;
    printf("\nObecna zawartosc listy:\n");
    for(temp = Start;temp!=NULL;temp=temp->Nast)
        {
            puts(temp->Dane.imie);
            puts(temp->Dane.nazwisko);
            printf("%d\n\n",temp->Dane.rok);
        }
    free(temp);

}





int main()
{
    struct element* Head = NULL;

    struct lista a;

    a = pobranie();
    Head = dodajelement(Head,a);

    a = pobranie();
    Head = dodajelement(Head,a);

    a = pobranie();
    Head = dodajelement(Head,a);

    wyswietl(Head);

    return 0;
}
