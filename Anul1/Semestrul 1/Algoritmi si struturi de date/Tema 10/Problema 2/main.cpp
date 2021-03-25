#include <iostream>

using namespace std;
struct nod
{
    int info;
    nod *prev;
    nod *next;
}*st,*dr;
void inserare_st(int x)
{
    if(st==NULL)
    {
        st=dr=new nod;
        st->info=x;
        st->next=dr->next=NULL;
    }
    else
    {
        nod *p=new nod;
        p->next=st;
        p->info=x;
        p->prev=NULL;
        st->prev=p;
        st=p;
    }
}
void inserare_dr(int x)
{
    if(st==NULL)
    {
        st=dr=new nod;
        st->info=x;
        st->next=dr->next=NULL;
    }
    else
    {
        nod *p=new nod;
        p->next=NULL;
        p->info=x;
        p->prev=dr;
        dr->next=p;
        dr=p;
    }
}
void ex_st()
{
    if(st==NULL)
        cout<<"Extragere imposibila ";
    else if(st->next==NULL)
    {
        delete st;
        delete dr;
    }
    else
    {
        nod *p=st;
        p=p->next;
        p->prev=NULL;
        st=p;
        //delete st;
    }
}
void ex_dr()
{
    if(dr==NULL)
        cout<<"Extragere imposibila ";
    else if(dr->prev==NULL)
    {
        delete st;
        delete dr;
    }
    else
    {
        nod *p=dr;
        p=p->prev;
        p->next=NULL;
        dr=p;
       // delete st;
    }
}
void afis()
{
    nod *p=st;
    cout<<endl;
    while(p)
    {
        cout<<p->info<<" ";
        p=p->next;
    }
    p=dr;
    cout<<endl;
     while(p)
    {
        cout<<p->info<<" ";
        p=p->prev;
    }
}
int main()
{
    inserare_dr(1);
    inserare_dr(2);
    inserare_dr(3);
    inserare_st(9);
    inserare_st(8);
    afis();
    ex_dr();
    ex_st();
    afis();
    return 0;
}
