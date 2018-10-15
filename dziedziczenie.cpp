/*klasa duza liczba wiecej cyfr niz int, jedna cyfra nie zajmuje wicej niz jeden bajt, zamiana na system 16, albo tablica charow
operator = , + , >> , << */

#include <string.h>
#include<iostream>

using namespace std;

class duza_liczba
{
protected:
    friend istream & operator>>(istream &s, duza_liczba &o1);
    friend ostream & operator<<(ostream &s, duza_liczba &o1);
    char *wsk;
public:
    duza_liczba()
    {
        wsk=NULL;
        cout<<"\nkonstruktor duza liczba bez argumentow\n";
    }
    duza_liczba(string liczba)
    {
        this->wsk = new char [liczba.length()+1];
        strcpy(wsk,liczba.c_str());
        cout<<"\nkonstruktor duza liczba z argumentami\n";
    }
    duza_liczba(duza_liczba &o1)
    {
        if(o1.wsk==NULL)
        {
            wsk=NULL;
        }
        else
        {
            this->wsk=new char [strlen(o1.wsk)+1];
            strcpy(wsk,o1.wsk);
        }
        cout<<"\nkonstruktor duza liczba kopiujacy\n";
    }
    ~duza_liczba()
    {
        if(wsk!=NULL)
        {
            delete [] wsk;
        }
        cout<<"\ndestruktor duza liczba\n";

    }
    char* zwroc_wskaznik()
    {
        return wsk;
    }
    duza_liczba & operator =(const duza_liczba &o1)
    {
        if(this==&o1)return *this;
        this->~duza_liczba();
        this->wsk=new char[strlen(o1.wsk)+1];
        strcpy(this->wsk,o1.wsk);
        return *this;
    }
    duza_liczba operator +(duza_liczba &o1)
    {
        if(o1.wsk==NULL)return *this;
        if(this->wsk==NULL)return o1;

        int dl, i=strlen(this->wsk)-1, j=strlen(o1.wsk)-1, k, tmp=0;
        char *bufor;
        duza_liczba wynik;
        if(strlen(this->wsk) > strlen(o1.wsk))
        {
            dl=strlen(this->wsk)+2;
        }
        else
        {
            dl=strlen(o1.wsk)+2;
        }
        k=dl-2; //ostatnia komorka w tablicy bufor
        bufor = new char [dl];

        while(i>=0 && j>=0)
        {                                                               // -'0' zamienia char na int
            bufor[k]=((this->wsk[i]-'0')+(o1.wsk[j]-'0')+tmp)%10 + 48; //+48 zamienia z powrotem na char
            tmp=((this->wsk[i]-'0')+(o1.wsk[j]-'0')+tmp)/10;
            i--;
            j--;
            k--;
        }
        while(i>=0)
        {
            bufor[k]=((this->wsk[i]-'0')+tmp)%10 + 48;
            tmp=((this->wsk[i]-'0')+tmp)/10;
            i--;
            k--;
        }
        while(j>=0)
        {
            bufor[k]=((o1.wsk[j]-'0')+tmp)%10 + 48;
            tmp=((o1.wsk[j]-'0')+tmp)/10;
            j--;
            k--;
        }
        if(tmp!=0)
        {
            bufor[k]=tmp+48;
            bufor[dl-1]='\0';
            wynik.wsk = new char [dl];
            strcpy(wynik.wsk,bufor);
        }
        else
        {
            bufor[k]='0';
            bufor[dl-1]='\0';
            wynik.wsk = new char [dl-1];
            for(int p=0;p<dl;p++)
            {
                wynik.wsk[p]=bufor[p+1];
            }
        }
        delete [] bufor;
        return wynik;

    }
};

/*klasa pochodna ma miec operatory *,==,!=,<,>*/

class k2 :public duza_liczba
{
public:
    k2()
    {
        wsk=NULL;
    }
    k2(duza_liczba &o1)
    {
        if(o1.zwroc_wskaznik()==NULL)
        {
            wsk=NULL;
        }
        else
        {
            this->wsk=new char [strlen(o1.zwroc_wskaznik())+1];
            strcpy(wsk,o1.zwroc_wskaznik());
        }
        cout<<"\nkonstruktor k2\n";
    }
    ~k2()
    {
        delete [] wsk;
        cout<<"\ndestruktor k2\n";
    }
    k2 operator *(k2 &o1)
    {
        int dl=strlen(o1.wsk)+strlen(this->wsk)+1;
        char wynik[]="0";
        char *bufor;
        bufor = new char [dl];

        delete [] bufor;
    }
};

istream & operator>>(istream &s, duza_liczba &o1)
{
    char bufor[100];
    int dl;
    s>>bufor;
    dl=strlen(bufor)+1;
    o1.wsk=new char [dl];
    strcpy(o1.wsk,bufor);
    return s;
}

ostream & operator<<(ostream &s, duza_liczba &o1)
{
    if(o1.wsk!=NULL)
    {
        s<<o1.wsk;
    }
    return s;
}

int main()
{
    duza_liczba a("666");
    k2 b(a);
    cout<<b;

    return 0;
}
