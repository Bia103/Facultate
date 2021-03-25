#include <iostream>

using namespace std;
struct nod
{
    int info;
    nod *next;
}*prim,*ultim;
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
void push(int x)
{
    //nod *u=prim;
    if(prim==NULL)
    {

        prim=ultim=new nod;
        prim->info=x;
        prim->next=NULL;

    }
    else if(prim->info==x)
    {
       pop();

    }
    else
    {
        nod *p=new nod;
        p->info=x;
        p->next=prim;
        prim=p;
    }
}
int empty()
{
    if(prim==NULL)
        return 1;
    return 0;
}
int main()
{
    int n,i,x;
    cin>>n;
      for(i=0;i<n;i++)
       {
           cin>>x;
           //cout<<x<<" ";
           push(x);
       }
       if(empty()==1)
        cout<<"Corect";
       else cout<<"Imposibil";
    return 0;
}
/*
8
1 2 2 1 3 3 4 4
*/
