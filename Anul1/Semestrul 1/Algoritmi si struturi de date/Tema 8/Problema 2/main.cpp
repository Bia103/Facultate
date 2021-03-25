#include <iostream>

using namespace std;
struct nod
{
    int info;
    nod *next;
}*prim,*ultim;
void push(int x)
{
    if(prim==NULL)
    {
        prim=ultim=new nod;
        prim->info=x;
        prim->next=NULL;
    }
    else
    {
        nod *p=new nod;
        p->info=x;
        p->next=NULL;
        ultim->next=p;
        ultim=p;
    }
}
void afisare()
{
    if(prim==NULL)
    {
        cout<<"Coada vida"<<endl;
        return;
    }
    else
    {
        cout<<"out ";
        nod *p=prim;
        while(p)
        {
            cout<<p->info<<" ";
            p=p->next;
        }
        cout<<"in"<<endl;
    }
}
int cautare(int x)
{
    nod *p=prim;
    int nr=1;
    if(prim==NULL)
        return -1;
    while(p!=ultim&&p->info!=x)
    {
        p=p->next;
        nr++;
    }

    if(p->info==x)
        return nr;
    else
        return -1;
}
int empty()
{
    if(prim==NULL)
        return 1;
    return 0;
}
int pop()
{
    int x;
    if(prim==NULL)
        return -1;
    x=prim->info;
    nod *p=prim;
    prim=prim->next;
    delete p;
    return x;
}
int peak()
{
    if(prim!=NULL)
        return prim->info;
    return -1;
}
int main()
{
     afisare();
     push(1);
    push(2);
    push(3);
    afisare();
    cout<<cautare(2)<<endl;
    cout<<cautare(4)<<endl;
    cout<<empty()<<endl;
    cout<<pop()<<endl;
    afisare();
    cout<<peak()<<endl;
    afisare();
    pop();
    pop();
    afisare();
    cout<<pop()<<endl;
    cout<<empty()<<endl;
    return 0;
}
