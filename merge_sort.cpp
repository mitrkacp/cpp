#include <iostream>

using namespace std;

void merge(int tab[],int left,int mid, int right)
{
    int i=0,j=0,k=left;
    int *l=new int [mid-left+1];
    int *r=new int [right-mid];
    for(i=0;i<=mid-left;i++)
    {
        l[i]=tab[i+left];
    }
    for(i=0;i<=right-mid-1;i++)
    {
        r[i]=tab[i+mid+1];
    }
    i=0;
    while(i<=mid-left && j<right-mid)
    {
        if(l[i]<=r[j])
        {
            tab[k]=l[i];
            i++;
            k++;
        }
        else
        {
            tab[k]=r[j];
            j++;
            k++;
        }
    }
    while(i<=mid-left)
    {
        tab[k]=l[i];
        i++;
        k++;
    }
    while(j<right-mid)
    {
        tab[k]=r[j];
        j++;
        k++;
    }
}

void merge_sort(int tab[],int left,int right)
{
    if(left<right)
    {
        int mid=(right+left)/2;
        merge_sort(tab,left,mid);
        merge_sort(tab,mid+1,right);
        merge(tab,left,mid,right);
    }
}


void print_tab(int tab[],int length)
{
    for(int i=0;i<length;i++)
    {
        cout<<tab[i]<<" ";
    }
}

int main()
{
    int tab[]={5,3,8,1,2,9,7,6,4};
    merge_sort(tab,0,8);
    print_tab(tab,9);


    return 0;
}