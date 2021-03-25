#include <iostream>

using namespace std;
struct nod
{
    int info;
    nod *next;
}*prim,*ultim;
void stergere(int x)//cauta primul nod cu val x ca pentru a-l sterge
{
    nod *p=prim;
    nod *last=NULL;
    while(p!=NULL&&p->info!=x)// conditiile trebuie scrise in ordinea asta pt ca altfel crapa!!!
    {
        last=p;//tine minte penultimul nod
        p=p->next;

    }
    //ori p=NULL ori p->info=x
    if(p==NULL)
    {
        cout<<"Nu";
        return;//e ca un break in void;
    }
    if(p==prim)
    {
        prim=prim->next;
        if(prim==ultim)
            ultim=NULL;
        delete p;
        return;
    }
    if(ultim==p)
    {
        last->next=NULL;
        ultim =last;
        delete p;
        return;
    }
    last->next=p->next;
    delete p;
}
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
    {
        cout<<p->info<<" ";
        p=p->next;
    }
}
int main()
{
    int n,i,x;
    cin>>n;
    for(i=1; i<=n; i++)
    {
        cin>>x;
        ad_f(x);
    }
    stergere(5);
    stergere(1);
    stergere(3);
    af();
    return 0;
}
