#include<iostream>
#include<stdio.h>
#include<string.h>

using namespace std;

class lista;

class element
{
    friend istream & operator>>(istream &s1, lista &o1);
    friend ostream & operator<<(ostream &s1, lista &o1);
    friend class lista;
    element *next;
    int data;
public:
    element()
    {
        data = 0;
        next=NULL;
    }

};

class lista
{
    friend istream & operator>>(istream &s1, lista &o1);
    friend ostream & operator<<(ostream &s1, lista &o1);
    friend class element;
    element *head;
public:
    lista()
    {
        head=NULL;
    }
    lista(lista &o1)
    {
        if(o1.head!=NULL)
        {
            element *nowy=new element;
            nowy->data=o1.head->data;
            nowy->next=NULL;
            head=nowy;
            element *tmp=o1.head;
            element *tmp2=head;
            while(tmp->next!=NULL)
            {
                element *nowy=new element;
                nowy->data=tmp->next->data;
                tmp2->next=nowy;
                tmp=tmp->next;
                tmp2=tmp2->next;
            }
            tmp2->next=NULL;
        }

    }
    ~lista()
    {
        element *tmp;
        while(head!=NULL)
        {
            tmp=head;
            head=head->next;
            delete tmp;
        }
    }
    lista & operator =(const lista &o1)
    {
        if(this==&o1)return *this;
        //czyszczenie listy
        element *tmp;
        while(this->head!=NULL)
        {
            tmp=this->head;
            this->head=this->head->next;
            delete tmp;
        }
        //koniec czyszczenia
        this->head = NULL;
        this->head = new element;
        if(o1.head!=NULL)
        {
            element *nowy=new element;
            nowy->data=o1.head->data;
            nowy->next=NULL;
            this->head=nowy;
            element *tmp=o1.head;
            element *tmp2=this->head;
            while(tmp->next!=NULL)
            {
                element *nowy=new element;
                nowy->data=tmp->next->data;
                tmp2->next=nowy;
                tmp=tmp->next;
                tmp2=tmp2->next;
            }
            tmp2->next=NULL;
        }
        return *this;
    }
    lista operator+(lista &p2)
    {
        if(p2.head==NULL)return *this;
        if(this->head==NULL)return p2;

        element *tmp=this->head;
        while (tmp->next!=NULL)
        {
            tmp=tmp->next;
        }
        tmp->next=p2.head;
        return *this;
    }

    bool operator==(lista &o1)
    {
        element *tmp1,*tmp2;
        tmp1=this->head;
        tmp2=o1.head;
        while(tmp1!=NULL || tmp2!=NULL)
        {
            if(tmp1->data!=tmp2->data)return false;
            if(tmp1==NULL && tmp2!=NULL)return false;
            if(tmp2==NULL && tmp1!=NULL)return false;
            tmp1=tmp1->next;
            tmp2=tmp2->next;
        }
        return true;
    }
    bool operator!=(lista &o1)
    {
        if(o1==*this)
            return false;
        else return true;

    }
};

istream & operator>>(istream &s1, lista &o1)
{
    element *nowy;
    nowy = new element;
    nowy->next=NULL;
    s1>>nowy->data;
    if(o1.head==NULL)
    {
        o1.head=nowy;
    }
    else
    {
        element *n=o1.head;
        while(n->next!=NULL)
        {
            n=n->next;
        }
        n->next=nowy;
    }
    return s1;

}
ostream & operator<<(ostream &s1, lista &o1)
{
    if(o1.head!=NULL)
    {
        element *n=o1.head;
        while(n!=NULL)
        {
            cout<<n->data<<" ";
            n=n->next;
        }
    }
    return s1;
}

int main()
{
    lista a,b,c;
    cin>>a>>a>>a;
    cin>>b>>b;
    c=a+b;
    cout<<c;
    if(a==b)cout<<"takie same\n";
    else cout<<"nie takie same \n";
    if(a!=b)cout<<"rozne\n";
    else cout<<"nie rozne\n";
    /*cout<<a<<endl;
    lista b(a);
    cout<<b;
    cout<<"przypisanie: \n";
    lista c;
    cout<<"wprowadz 3 elementy listy: \n";
    cin>>c>>c>>c;
    a=c;
    cout<<a;*/

    return 0;
}
