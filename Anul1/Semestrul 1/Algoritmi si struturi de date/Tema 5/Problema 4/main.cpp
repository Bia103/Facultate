#include <iostream>

using namespace std;
struct nod
{
    int info;
    nod *next;
}*prim,*ultim,*prim2,*ultim2;
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
void ad_f2(int x)//adaugarea unui nou element in lista la final
{
    if(prim2==NULL)//se verifica daca lista e vida
    {
        prim2=ultim2=new nod;//face alocarea
        prim2->info=x;
        prim2->next=NULL;
    }
    else
    {
        nod *p=new nod;
        p->info=x;
        p->next=NULL;
        ultim2->next=p;
        ultim2=p;
    }
}
/*void interclas()
{
    //nod *p=prim,*p2=prim2,*f=prim->next,*f2=prim2->next,*ul=prim;
        nod *f=prim,*f2=prim2,*ul=prim;
    if(f->info>f2->info)
    {
        f=f->next;
        ul->next=prim;
        f=prim;
        prim=prim2;
        ul=prim;

    }
    while(p!=NULL&&p2!=NULL)
    {
        if(f->info>=f2->info)
        {
            nod *u=f2;
            f2=f2->next;
            ul->next=u;
            u->next=f;
            ul=u;
        }
        else {
            ul=ul->next;
            f=f->next;
        }
    }
    if(p==NULL)
        ultim->next=f2
}*/
void interclas()
{
    nod *p1=prim,*p2=prim2;
    if((p1->info)>(p2->info))
    {
        p2=p2->next;
        prim2->next=prim;
        prim=prim2;
    }
    nod *ul=prim,*c=p2;
    while(p1->next!=NULL&&p2->next!=NULL)
    {
        if((p2->info)<=(p1->info))
        {
            p2=p2->next;
            ul->next=c;
            c->next=p1;
            ul=ul->next;
            c=p2;
        }
        else{
            p1=p1->next;
            ul=ul->next;
        }
    }
    if(p1->next==NULL)
        p1->next=p2;

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
    int n,i,x,m;
cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>x;
        ad_f(x);
    }
    cin>>m;
    for(i=1;i<=m;i++)
    {
        cin>>x;
        ad_f2(x);
    }
    interclas();
    af();
    return 0;
}
/*
3
4 6 8
5
1 2 5 9 9
*/
