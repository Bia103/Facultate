#include <iostream>

using namespace std;
struct nod
{
    float info;
    nod *next;
}*prim,*ultim,*u;
void ad_f(float x)
{

    if(prim==NULL)
    {

        prim=ultim=new nod;
        prim->info=x;
        prim->next=NULL;
        u=ultim;
    }
    else
    {
        nod *p=new nod,*l=new nod;
        p->info=x;
        p->next=NULL;
        l->info=(p->info+ultim->info)/2;
       ultim->next=l;
        l->next=p;
       // u=p;
        ultim->next=l;
        ultim=p;
    }
}
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
int main()
{
    int i,n;
    float x;
    cin>>n;

    for(i=1;i<=n;i++)
    {cin>>x;
    ad_f(x);}
    af();
    return 0;
}
/*
4
1 2 3 4
*/
