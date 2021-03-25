#include <iostream>

using namespace std;
class Nod
{
    int info;
    Nod *next;
public:
    Nod(int,Nod*);
    setInfo(int);
    int getInfo();
    setNext(Nod*);
    Nod* getNext();
   // ~Nod();
};
Nod::Nod(int x=0,Nod *p=NULL)
{
    info=x;
    next=p;
}
Nod::setInfo(int x=0)
{
    info=x;
}
int Nod::getInfo()
{
    return info;
}
Nod::setNext(Nod *a)
{
    next=a;
}
Nod * Nod::getNext()
{
    return next;
}
class Lista
{
    Nod *st,*en;
    unsigned int l;
public:
    Lista(int );
    Lista(int,int);
    ins(int);
    afi();
};
Lista::Lista(int x=0)
{
    l=1;
    (*st).setInfo(x);
    en=st;
}
Lista::Lista(int x=0,int y=0)
{
    Nod *p,*u;
    int i=1;
    while(i<=x)
    {
        (*p).setInfo(y);
        if(i==1)
        {
             (*st).setNext(p);
             en=p;
        }
        else
        {
            (*p).setNext(st);
            st=p;
        }
    }
    l=i;
}
Lista::ins(int x)
{
     Nod *p;
     (*p).setInfo(x);
    (*en).setNext(p);
    en=p;
}
Lista::afi()
{
     Nod *p=st;
     while(p)
     {
         cout<<(*p).getInfo()<<" ";
         (*p).getNext();
     }
}
int main()
{
    //Nod a(5,NULL),b(7,NULL);
   // a.setInfo(3);
    //cout<<a.getInfo()<<endl;
   // a.setNext(b);
   // cout<<a.getInfo()<<endl;
   Lista l(1,1);
   l.ins(2);

    return 0;
}
