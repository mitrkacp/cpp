#include <iostream>

using namespace std;

int left(int i)
{
    if(i==0)return 1;
    return 2*i+1;
}

int right(int i)
{
    if(i==0)return 2;
    return 2*i+2;
}

int parent(int i)
{
    return i/2;
}

void max_heapify(int tab[],int i,int heapsize)
{
    int l,r,largest,tmp;
    l=left(i);
    r=right(i);
    if(l<=heapsize && tab[l]>tab[i])
    {
        largest=l;
    }
    else
    {
        largest=i;
    }
    if(r<=heapsize && tab[r]>tab[largest])
    {
        largest=r;
    }
    if(largest!=i)
    {
        tmp=tab[i];
        tab[i]=tab[largest];
        tab[largest]=tmp;
        max_heapify(tab,largest,heapsize);
    }

}

void build_max_heap(int tab[],int heapsize)
{
    for(int i=heapsize/2-1;i>=0;i--)
    {
        max_heapify(tab,i,heapsize);
    }
}

void heap_sort(int tab[],int &heapsize)
{
    int tmp;
    build_max_heap(tab,heapsize);
    for(int i=heapsize;i>0;i--)
    {
        tmp=tab[i];
        tab[i]=tab[0];
        tab[0]=tmp;
        heapsize--;
        max_heapify(tab,0,heapsize);
    }
}

void print_heap(int tab[],int length)
{
    for(int i=0;i<length;i++)
    {
        cout<<tab[i]<<" ";
    }
}

int main()
{
    int tab[]={5,3,8,1,2,9,7,6,4};
    int heapsize=8;
    heap_sort(tab,heapsize);
    print_heap(tab,9);


    return 0;
}