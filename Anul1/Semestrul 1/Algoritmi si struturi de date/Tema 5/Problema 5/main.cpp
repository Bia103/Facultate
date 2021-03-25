#include <iostream>

using namespace std;
struct nod
{
    int info;
    nod *next;
}*prim1,*ultim1,*prim2,*ultim2;
void af1()
{
    nod *p=prim1;
    while(p!=NULL)
    {
        cout<<p->info<<" ";
        p=p->next;
    }
}
void af2()
{
    nod *p=prim2;
    while(p!=NULL)
    {
        cout<<p->info<<" ";
        p=p->next;
    }
}
void ad_f1(int x)//adaugarea unui nou element in lista la final
{
    if(prim1==NULL)//se verifica daca lista e vida
    {
        prim1=ultim1=new nod;//face alocarea
        prim1->info=x;
        prim1->next=NULL;
    }
    else
    {
        nod *p=new nod;
        p->info=x;
        p->next=NULL;
        ultim1->next=p;
        ultim1=p;
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
void ad()
{
    nod *p=prim1,*u=prim2;
    int t=0,z;
    while(p!=NULL&&u!=NULL)
    {
        z=(p->info)+(u->info)+t;
        p->info=z%10;
        t=z/10;
        p=p->next;
        u=u->next;
    }
    while(u!=NULL)
    {
        nod *l=new nod;
        l->info=(u->info+t)%10;
        ultim1->next=l;
        t=(u->info+t)/10;
        ultim1=l;
        u=u->next;
    }
    while(t!=0)
    {


        if(p!=NULL)
        {
            z=(p->info+t);
            p->info=(p->info+t)%10;
            p=p->next;t=z/10;

        }
        else
        {
            nod *l=new nod;
            l->info=t;
            l->next=NULL;
            ultim1->next=l;
            ultim1=l;
            t=0;
            return;
        }

    }
}
int main()
{
    int n,i,m,x;
    cin>>n;
    for(i=1; i<=n; i++)
    {
        cin>>x;
        ad_f1(x);
    }
    cin>>m;
    for(i=1; i<=m; i++)
    {
        cin>>x;
        ad_f2(x);
    }
    ad();
    af1();
    // af2();
    return 0;
}
/*
3
2 4 5
2
4 3
*/
/*
3
9 9 9
1
1
*/
