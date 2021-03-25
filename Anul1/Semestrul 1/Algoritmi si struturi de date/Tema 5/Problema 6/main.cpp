#include <iostream>

using namespace std;
int k;
struct nod
{
    int info;
    nod *next;
}*prim,*ultim;
void ad_f(int x)//adaugarea unui nou element in lista la final
{
    if(prim==NULL)//se verifica daca lista e vida
    {
        prim=ultim=new nod;//face alocarea
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
void af()
{
    nod *p=prim;
    while(p!=NULL)
        {cout<<p->info<<" ";
        p=p->next;
        }
}
void multiply()
{
    int t=0,z;
    nod *p=prim;
    while(p!=NULL)
    {
        z=(p->info)*k+t;
        p->info=z%10;
        t=z/10;
        p=p->next;

    }
    if(t!=0)
    {
        nod *l=new nod;
        l->info=t;
        ultim->next=l;
        ultim=l;
    }
}
int main()
{
  int n,i,m,x;
    cin>>n>>k;
    for(i=1; i<=n; i++)
    {
        cin>>x;
        ad_f(x);
    }
    multiply();
    af();
    return 0;
}
/*
3
9
5 8 9
*/
