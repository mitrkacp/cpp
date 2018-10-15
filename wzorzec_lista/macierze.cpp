#include<iostream>
#include<stdio.h>
#include<string.h>

using namespace std;


class macierze
{
        friend istream & operator>>(istream &s1, macierze &o1);
        friend ostream & operator<<(ostream &s1, macierze &o1);

        double *ws;
        int wymiar;
        public:
        macierze()
        {
                ws = NULL;
                wymiar = 0;
        }
        macierze(int wym)
        {
                wymiar = wym;
                this->ws = new double [wymiar*wymiar];
                for(int i=0;i<wymiar*wymiar;i++)
                {
                        this->ws[i]=0;
                }
        }
        macierze(macierze &o1)
        {
                ws = new double [o1.wymiar * o1.wymiar];
                wymiar = o1.wymiar;
                for(int i=0;i<o1.wymiar*o1.wymiar; i++)
                {
                        ws[i]=o1.ws[i];
                }
        }
        ~macierze()
        {
                if(ws!=NULL)
                {
                        delete [] ws;
                        ws = NULL;
                }
        }
        macierze & operator=(const macierze &o1)
        {
                if(this==&o1)return *this;
                delete [] this->ws;
                this->ws = new double [o1.wymiar * o1.wymiar];
                this->wymiar = o1.wymiar;
                for(int i=0;i<o1.wymiar*o1.wymiar; i++)
                {
                        this->ws[i]=o1.ws[i];
                }
                return *this;
        }
        macierze operator+(macierze &p2)
        {
                if(p2.wymiar!=this->wymiar)
                {
                        cout<<"blad";
                        return *this;
                }
                macierze wynik;
                wynik.ws = new double [p2.wymiar * p2.wymiar];
                wynik.wymiar = p2.wymiar;
                for(int i=0;i<p2.wymiar*p2.wymiar;i++)
                {
                        wynik.ws[i]=this->ws[i]+p2.ws[i];
                }
                return wynik;
        }
        macierze operator-(macierze &p2)
        {
                if(p2.wymiar!=this->wymiar)
                {
                        cout<<"blad";
                        return *this;
                }
                macierze wynik;
                wynik.ws = new double [p2.wymiar * p2.wymiar];
                wynik.wymiar = p2.wymiar;
                for(int i=0;i<p2.wymiar*p2.wymiar;i++)
                {
                        wynik.ws[i]=this->ws[i]-p2.ws[i];
                }
                return wynik;
        }
        macierze operator*(macierze &p2)
        {
                if(p2.wymiar!=this->wymiar)
                {
                        cout<<"blad";
                        return *this;
                }
                macierze wynik;
                int k;
                wynik.ws = new double [p2.wymiar * p2.wymiar];
                wynik.wymiar = p2.wymiar;
                for(int i=0;i<p2.wymiar* p2.wymiar;i++)
                {
                        k=i%p2.wymiar;
                        for(int j=(i/p2.wymiar)*p2.wymiar;k<p2.wymiar*p2.wymiar;j++)
                        {
                                wynik.ws[i]+=this->ws[j]*p2.ws[k];
                                k+=p2.wymiar;
                        }
                }
                return wynik;
        }
        bool operator==(macierze &p2)
        {
                if(p2.wymiar!=this->wymiar)
                {
                        return false;
                }
                for(int i=0;i<p2.wymiar*p2.wymiar;i++)
                {
                        if(this->ws[i]!=p2.ws[i])
                        {
                            return false;
                        }
                }
                return true;
        }
        bool operator!=(macierze &p2)
        {
                if(p2==*this)
                    return false;
                else return true;
        }
        bool operator>(macierze &p2)
        {
                if(p2.wymiar!=this->wymiar)
                {
                        return false;
                }
                for(int i=0;i<p2.wymiar*p2.wymiar;i++)
                {
                        if(this->ws[i]<p2.ws[i])
                        {
                            return false;
                        }
                }
                return true;
        }
        bool operator<(macierze &p2)
        {
                if(p2.wymiar!=this->wymiar)
                {
                        return false;
                }
                for(int i=0;i<p2.wymiar*p2.wymiar;i++)
                {
                        if(this->ws[i]>p2.ws[i])
                        {
                            return false;
                        }
                }
                return true;
        }
};

istream & operator>>(istream &s1, macierze &o1)
{
        if(o1.ws!=NULL)
        {
                delete [] o1.ws;
                o1.ws = NULL;
        }
        s1>>o1.wymiar;
        if(o1.wymiar<1)
        {
                o1.wymiar = 0;
        }
        o1.ws = new double [o1.wymiar * o1.wymiar];
        for(int i=0; i<o1.wymiar*o1.wymiar; i++)
        {
                s1>>o1.ws[i];
        }
        return s1;
}
ostream & operator<<(ostream &s1, macierze &o1)
{
        if(o1.ws!=NULL)
        {
                for(int i=0; i<o1.wymiar*o1.wymiar; i++)
                {
                        if(i%o1.wymiar==0)s1<<endl;
                        s1<<o1.ws[i];
                }
        }
        return s1;
}
