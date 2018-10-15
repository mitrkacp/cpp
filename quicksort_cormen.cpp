#include <iostream>

using namespace std;

int partition(int tab[],int l,int r)
{

    int pivot=tab[(r+l)/2];
    int i=l , j=r , tmp;
    while(i<j)
    {
        while(tab[i]<pivot)i++;
        while(tab[j]>pivot)j--;
        if(i<j)
        {
            tmp=tab[i];
            tab[i]=tab[j];
            tab[j]=tmp;
        }

    }
    return i;

}

void quicksort(int tab[],int l,int r)
{
    if(l<r)
    {
        int s = partition(tab, l, r);
        if(s>l)quicksort(tab, l, s - 1);
        if(s<r)quicksort(tab, s + 1, r);
    }
}

void printab(int tab[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<tab[i]<<" ";
    }
}
int main()
{
    int tab[]={5,3,7,2,1,8,6,4,9};
    quicksort(tab,0,8);
    printab(tab,9);

    return 0;
}