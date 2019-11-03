#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>
#define MAX 20

bool buscaBinaria(int x,int *v, int e, int d)
{
    if(e>d)
    {
        return false;
    }
    else
    {
        int m = (e + d)/2;
        if (v[m] == x)
            return true;
        if (v[m] < x)
            return buscaBinaria(x,v,m+1,d);
        else
            return buscaBinaria(x,v,e,m-1);
    }
}

bool quicksort(int *v,int e,int d,int n)
{
    int i,j,m;
    int p;

    i = e;
    j = d;
    m = (e+d)/2;
    p = v[m];

        do
        {
            while((v[i]<p) && i<d )
                i++;

            while(v[j]>p && j>e)
                j--;

            if(i<=j)
            {
                int x = v[i];
                v[i] = v[j];
                v[j] = x;
                i++;
                j--;

            }
        }
        while(i<=j);

    if(e<j)
    {
        quicksort(v,e,j,n);
    }

    if(d>i)
    {
        quicksort(v,i,d,n);
    }

    return buscaBinaria(n,v,0,MAX-1);




}

void clear()
{
    system("pause");
    system("cls");
}

void show(int *v, int i)
{
    clear();
    for(i=0; i<MAX; i++)
    {
        printf("\n%d - [%d]",i,*(v+i));
    }
    printf("\n");
}


int main()
{
    int v[MAX],i,n;
    srand(time(NULL));

    for(i=0; i<MAX; i++)
    {
        v[i] = rand()%100;
    }

    show(v,i);

    clear();

    printf("Digite um numero:\n");
    scanf("%d",&n);

    quicksort(v,0,MAX-1,n) ? printf("\nNumero Encontrado") : printf("\nNumero Nao Encontrado");

    return 0;
}
