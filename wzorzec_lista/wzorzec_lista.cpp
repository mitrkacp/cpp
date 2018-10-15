#include<iostream>
#include"macierze.cpp"

using namespace std;
/* zrobic operator = + wyjscia wejscia
wymagania dla klasy na ktorej mozna uzyc wzorca np = + itp
do wzorca klasy zaprzyjaznic wzorzec funkcji (pola x y nie maja byc w public)*/

template <class T>
class lista;

template <class T>
class element;

template<class T>
istream & operator>>(istream &s1, lista<T> &o1)
{
    element<T> *nowy;
    nowy = new element<T>;
    nowy->next=NULL;
    s1>>nowy->data;
    if(o1.head==NULL)
    {
        o1.head=nowy;
    }
    else
    {
        element<T> *n=o1.head;
        while(n->next!=NULL)
        {
            n=n->next;
        }
        n->next=nowy;
    }
    return s1;

}
template <class T>
ostream & operator<<(ostream &s1, lista<T> &o1)
{
    if(o1.head!=NULL)
    {
        element<T> *n=o1.head;
        while(n!=NULL)
        {
            cout<<n->data<<" ";
            n=n->next;
        }
    }
    return s1;
}

template <class T>
class element
{
    friend class lista<T>;
    friend istream & operator>> <T>(istream &s1, lista<T> &o1);
    friend ostream & operator<< <T>(ostream &s1, lista<T> &o1);

    T data;
    element <T>*next;

public:
    element()
    {
        next=NULL;
    }

};



template <class T>
class lista
{
    friend istream & operator>> <T>(istream &s1, lista<T> &o1);
    friend ostream & operator<< <T>(ostream &s1, lista<T> &o1);
    friend class element<T>;

    element <T> *head;

public:
    lista()
    {
        head=NULL;
    }
    lista(lista<T> &o1)
    {
        if(o1.head!=NULL)
        {
            element<T> *nowy=new element<T>;
            nowy->data=o1.head->data;
            nowy->next=NULL;
            head=nowy;
            element<T> *tmp=o1.head;
            element<T> *tmp2=head;
            while(tmp->next!=NULL)
            {
                element<T> *nowy=new element<T>;
                nowy->data=tmp->next->data;
                tmp2->next=nowy;
                tmp=tmp->next;
                tmp2=tmp2->next;
            }
            tmp2->next=NULL;
        }
        else
        {head=NULL;}

    }
    ~lista()
    {
        element<T> *tmp;
        while(head!=NULL)
        {
            tmp=head;
            head=head->next;
            delete tmp;
        }
    }
    lista <T> & operator =(const lista<T> &o1)
    {
        if(this==&o1)return *this;
        //czyszczenie listy
        element<T> *tmp;
        while(this->head!=NULL)
        {
            tmp=this->head;
            this->head=this->head->next;
            delete tmp;
        }
        //koniec czyszczenia


        if(o1.head!=NULL)
        {
            element<T> *nowy=new element<T>;
            nowy->data=o1.head->data;
            nowy->next=NULL;
            this->head=nowy;
            element<T> *tmp=o1.head;
            element<T> *tmp2=this->head;
            while(tmp->next!=NULL)
            {
                element<T> *nowy=new element<T>;
                nowy->data=tmp->next->data;
                tmp2->next=nowy;
                tmp=tmp->next;
                tmp2=tmp2->next;
            }
            tmp2->next=NULL;
        }
        return *this;
    }
    lista <T> operator+(lista<T> &p2)
    {
        if(p2.head==NULL)return *this;
        if(this->head==NULL)return p2;

        lista<T> wynik1,wynik2;

        wynik1=*this;
        wynik2=p2;
        element<T> *tmp=wynik1.head;
        while (tmp->next!=NULL)
        {
            tmp=tmp->next;
        }
        tmp->next=wynik2.head;
        wynik2.head=NULL;
        return wynik1;
    }
    bool operator==(lista<T> &o1)
    {
        element<T> *tmp1,*tmp2;
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
    bool operator!=(lista<T> &o1)
    {
        if(o1==*this)
            return false;
        else return true;

    }
    int lista_length(lista<T> &o1)
    {
        int l=0;
        if(o1.head!=NULL)
        {
            element<T> *tmp=o1.head;
            while(tmp!=NULL)
            {
                l++;
                tmp=tmp->next;
            }
        }
        return l;

    }
    bool operator >(lista<T> &o1)
    {
        if(lista_length(*this)>lista_length(o1))
        {
            return true;
        }
    }
    bool operator <(lista<T> &o1)
    {
        if(lista_length(*this)<lista_length(o1))
        {
            return true;
        }
    }
};



int main()
{
    lista <macierze> a,b,c;
    cin>>a>>a>>a;
    cin>>b>>b;

    c=a+b;
    c=a+b;
    cout<<c;

    return 0;
}
