#include <iostream>

using namespace std;
struct nod
{
    int info;
    nod *next;
}*prim,*ultim,*u;

void af()
{
    nod *p=prim;
    if(p==NULL)
        cout<<"Lista vida"<<endl;
    while(p!=NULL)
    {
        cout<<p->info<<" ";
        p=p->next;
    }
    cout<<endl;
}
void sortat(int x)
{
    if(prim==NULL)
    {
        ultim=prim=new nod;
        prim->info=x;
        prim->next=NULL;
    }
    else if(prim->info>=x)
    {
        nod *p=new nod;
        p->info=x;
        p->next=prim;
        prim=p;

    }
    else
    {
        if(ultim->info<x)
        {
            nod *la=new nod;
            la->info=x;
            la->next=NULL;
            ultim->next=la;
            ultim=la;
        }
       else{ nod *p=prim, *last=NULL;
        while(p->next!=NULL&&p->info<x)
        {
            last=p;
            p=p->next;
        }


            nod *la=new nod;
            la->info=x;
            la->next=p;
            last->next=la;


    }}
    af();
}
int main()
{
    int i,n;
    int x;
    cin>>n;

    for(i=1; i<=n; i++)
    {
        cin>>x;
        sortat(x);
    }

    return 0;
}
/*
6
4 2 5 4 4 1
*/

