#include <iostream>

using namespace std;

template <class T,class E>
class el;

template <class T,class E>
class mapa
{

    friend class el<T,E>;
    el<T,E> *pier;
public:
    mapa()
    {
        pier=NULL;
        cout<<"konstruktor mapy\n";

    }
    ~mapa()
    {
        if(pier!=NULL)
        {
            el<T,E> *tmp;
            while(pier!=NULL)
            {
                tmp=pier;
                pier=pier->next;
                delete tmp;
            }
        }

        cout<<"destruktor mapy\n";
    }
    class iterator
    {

        friend class mapa<T,E>;
        friend class el<T,E>;
        el<T,E> *ws;
    public:
        iterator()
        {
            ws=NULL;
            //cout<<"konstruktor iteratora\n";
        }
        ~iterator()
        {

            //cout<<"destruktor iteratora\n";
        }
        int operator!=(const iterator &o1)
        {
            if(ws!=o1.ws)return 1;
            return 0;
        }
        iterator operator++(int)
        {
            iterator tmp;
            tmp.ws=new el<T,E>;
            tmp.ws=ws;
            ws=ws->next;
            return tmp;
        }
        el<T,E> * operator->(void)
        {
            return ws;
        }

    };
    iterator begin(void)
    {
        iterator i1;
        i1.ws=pier;
        return i1;
    }
    iterator end(void)
    {
        iterator i2;
        i2.ws=NULL;
        return i2;
    }
    E & operator[](const T &o1)
    {
        el<T,E>*w,*wp,*wn;
        for(w=pier,wp=0;w!=0 && w->first<=o1;w=w->next)
        {
            if(w->first==o1)return w->second;
            wp=w;
        }
        wn=new el<T,E>;
        wn->first=o1;
        if(wp==0)
        {
            pier = wn;
            wn->next=w;
        }
        else {
            wn->next=wp->next;
            wp->next = wn;
        }
        return wn->second;
    }
    void wypisz();
};

template <class T,class E>
class el
{

    friend class mapa<T,E>;
    friend class mapa<T,E>::iterator;
    T first;
    E second;
    el<T,E> *next;
public:
    el()
    {

        next=NULL;
    }
    ~el()
    {

    }


};

template<class T,class E> void mapa<T,E>::wypisz()
{
    for(mapa<string,string>::iterator i=begin();i!=end();i++)
    {
        cout<<i->first<<" "<<i->second<<endl;
    }
}

int main()
{
    mapa<string,string> m;

    m["cc"]="dd";
    m["aa"]="bb";
    m["ee"]="ff";
    m["ac"]="bd";
    string s1=m["co"];
    m.wypisz();

    return 0;
}