
/*klasa duza liczba wiecej cyfr niz int, jedna cyfra nie zajmuje wicej niz jeden bajt, zamiana na system 16, albo tablica charow
operator = , + , >> , << */

#include <string.h>
#include<iostream>
#include <cstring>

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
        //cout<<"\nkonstruktor bazowy\n";
    }
    duza_liczba(string liczba)
    {
        this->wsk = new char [liczba.length()+1];
        strcpy(wsk,liczba.c_str());
        //cout<<"\nkonstruktor bazowy z argumentem\n";
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
        //cout<<"\nkonstruktor bazowy kopiujacy\n";
    }
    ~duza_liczba()
    {
        if(wsk!=NULL)
        {
            delete [] wsk;
            wsk=0;
        }
        //cout<<"\ndestruktor bazowy\n";

    }
    duza_liczba & operator =(const duza_liczba &o1)
    {
        if(this==&o1)return *this;
        this->~duza_liczba();
        this->wsk=0;
        if(o1.wsk!=NULL){
            this->wsk=new char[strlen(o1.wsk)+1];
            strcpy(this->wsk,o1.wsk);
        }

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
        bufor = 0;
        return wynik;

    }
};

/*klasa pochodna ma miec operatory *,==,!=,<,>*/

class k2 :public duza_liczba
{
public:
    k2()
    {
        //cout<<"konstruktor pochodnej\n";
    }
    k2(k2 &o1);

    ~k2()
    {
        //cout<<"\ndestruktor pochodnej\n";
    }
    k2 & operator =(const duza_liczba &o1);
    k2 operator *(k2 &o1);
    bool operator==(k2 &o1);
    bool operator!=(k2 &o1);
    bool operator>(k2 &o1);
    bool operator<(k2 &o1);

};

k2::k2(k2 &o1)
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
    //cout<<"\nkonstruktor pochodnej kopiujacy\n";
}


k2& k2:: operator =(const duza_liczba &o1)
{
    k2 *wo1;
    wo1=(k2*)(&o1);
    if(this==wo1)return *this;
    this->wsk=0;
    this->wsk=new char[strlen(wo1->wsk)+1];
    strcpy(this->wsk,wo1->wsk);
    return *this;
}

k2 k2::operator *(k2 &o1)
{
    if(o1.wsk==NULL)return *this;
    if(this->wsk==NULL)return o1;
    if(this->wsk=="0")return *this;
    if(o1.wsk=="0")return o1;
    int dl=strlen(o1.wsk)+strlen(this->wsk)+1;
    k2 tmp1,tmp2,bufor,wynik;
    bufor.wsk = new char [dl];
    strcpy(bufor.wsk,"0");
    for(int i=0;i<strlen(o1.wsk);i++)
    {
        tmp1.wsk=new char[2];
        strcpy(tmp1.wsk,"0");
        tmp2.wsk = new char [dl];

        for(int j=0;j<o1.wsk[i]-'0';j++)
        {
            tmp1=tmp1 + *this;
        }
        strcpy(tmp2.wsk,tmp1.wsk);
        for(int k=0;k<strlen(o1.wsk)-1-i;k++)
        {
            strcat(tmp2.wsk,"0");
        }
        tmp2.wsk[strlen(tmp1.wsk)+strlen(o1.wsk)-1-i]='\0';
        bufor=bufor+tmp2;
        delete[] tmp1.wsk;
        delete[] tmp2.wsk;
        tmp1.wsk=0;
        tmp2.wsk=0;
    }
    wynik.wsk = new char [strlen(bufor.wsk)+1];
    strcpy(wynik.wsk,bufor.wsk);
    delete [] bufor.wsk;
    bufor.wsk=0;
    return wynik;
}

bool k2::operator==(k2 &o1)
{
    if(strlen(this->wsk)!=strlen(o1.wsk))return false;
    for(int i=0;i<strlen(this->wsk);i++)
    {
        if(this->wsk[i]!=o1.wsk[i])return false;
    }
    return true;
}
bool k2::operator!=(k2 &o1)
{
    if(*this==o1)return false;
    else return true;
}

bool k2::operator>(k2 &o1)
{
    if(*this==o1)return false;
    if(strlen(this->wsk)>strlen(o1.wsk))return true;
    if(strlen(this->wsk)<strlen(o1.wsk))return false;
    for(int i=0;i<strlen(this->wsk);i++)
    {
        if(this->wsk[i] < o1.wsk[i])return false;
        else if(this->wsk[i] > o1.wsk[i])return true;
    }
}

bool k2::operator<(k2 &o1)
{
    if(*this==o1)return false;
    if(*this>o1)return false;
    return true;
}

istream & operator>>(istream &s, duza_liczba &o1)
{
    string bufor;
    int dl;
    s>>bufor;
    dl=bufor.length()+1;
    o1.wsk=new char [dl];
    strcpy(o1.wsk,bufor.c_str());
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
    k2 a,b,c;
    cin>>a>>b;
    c=a*b;
    cout<<c;

    return 0;
}
