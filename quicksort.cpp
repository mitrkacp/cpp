#include <iostream>

using namespace std;

void quicksort(int tab[],int l,int r)
{
    int pivot=tab[(l+r)/2];
    int i=l,j=r;
    while(i<=j)
    {
        while(tab[i]<pivot)
        {
            i++;
        }
        while(tab[j]>pivot)
        {
            j--;
        }
        if(i<=j)
        {
            int tmp;
            tmp=tab[j];
            tab[j]=tab[i];
            tab[i]=tmp;
            i++;
            j--;
        }

    }
    if(l<j)quicksort(tab,l,j);
    if(r>i)quicksort(tab,i,r);

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