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
    else if(prim->info!=x)
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
int main()
{
    int n,i,x,v[1001];
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>v[i];
        push(v[i]);
    }
    if(prim!=NULL)
   {
       x=prim->info;//cout<<"DAPZ ";
       int c=0;
       for(i=1;i<=n;i++)
       {
           if(v[i]==x)
            c++;
       }
      // cout<<c;
       if(c>=n/2+1)
        cout<<"Elementul majoritar: "<<x;
       else cout<<"Nu exista element majoritar";
   }
   else cout<<"Nu exista element majoritar";;
    return 0;
}
/*
6
1 2 2 2 2 3
*/
