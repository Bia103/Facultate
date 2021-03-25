#include <iostream>

using namespace std;
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
int main()
{
    int n,i,x;
    cin>>n;
    for(i=1;i<=n;i++)
    {cin>>x;
    ad_f(x);}
    af();
    return 0;
}
