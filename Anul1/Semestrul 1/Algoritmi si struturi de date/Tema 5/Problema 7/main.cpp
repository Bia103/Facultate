#include <iostream>

using namespace std;
struct nod
{
    int info;
    nod *next;
}*prim1,*ultim1,*prim2,*ultim2,*prim3,*ultim3,*prim0,*ultim0;
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
void ad_fU()//adaugarea unui nou element in lista la final
{
    if(prim0==NULL)//se verifica daca lista e vida
    {
        prim0=ultim0=new nod;//face alocarea
        prim0->info=0;
        prim0->next=NULL;
    }
    else
    {
        nod *p=new nod;
        p->info=0;
        p->next=NULL;
        ultim0->next=p;
        ultim0=p;
    }
}
void af()
{
    nod *p=prim0;
    while(p!=NULL)
    {
        cout<<p->info<<" ";
        p=p->next;
    }
}
/*void multiply()
{
    int t=0,z,c=0;
    nod *p1=prim1;
    while(p2!=NULL)
    {
        nod *u=prim1;
        int i=0;
        while(i<c)
        {
            u=u->next;
            i++;
        }
        c++;

    while(p1!=NULL)
    {//if(u->next=NULL)
        z=(p1->info)*(p2->info)+t;
        u->info=z%10;
        t=z/10;
        p1=p1->next;
        u=u->next;


    }
    if(t!=0)
    {
        nod *l=new nod;
        l->info=t;
        ultim->next=l;
        ultim=l;
    } }/
}*/
void multi()
{
    nod *p1=prim1,*p2=prim2,*u=prim0;
    int t=0,c=0,z;
    while(p1!=NULL)
    {nod *u=prim0,*p2=prim2;

        int i=0;
        while(i<c)
        {
            i++;
            u=u->next;
        }
        c++;
        while(p2!=NULL)
        {
            z=(p1->info)*(p2->info)+t;
            u->info=u->info+z%10;
            t=u->info/10;
            while(u->info>9)
               {
                    u->info=u->info%10;
                    //t++;
               }
            u=u->next;
            p2=p2->next;
        }
        if(t)
        {
            u->info=u->info+t;
        }
        p1=p1->next;
    }
}
int main()
{
    int n,i,m,x,j=0;
    cin>>n;
    for(i=1; i<=n; i++)
    {
        cin>>x;
        ad_f1(x);ad_fU();
    }
    cin>>m;
    for(i=1; i<=m; i++)
    {
        cin>>x;
        ad_f2(x);ad_fU();
    }
    multi();
    af();
    return 0;
}
/*
3
4 3 2
2
1 2
*/
/*
3
3 2 1
3
3 2 1
*/
