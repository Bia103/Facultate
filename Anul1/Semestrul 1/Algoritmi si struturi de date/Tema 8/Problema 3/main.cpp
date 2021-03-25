#include <iostream>
#include<cstring>
using namespace std;
int ok=1;
struct nod
{
    char info;
    nod *next;
}*prim,*ultim;
int pop()
{
    int x;
    if(prim==NULL)
        {return -1;
        ok=0;ok=0;//cout<<"aici2";
        }
    x=prim->info;
    nod *p=prim;
    prim=prim->next;
    delete p;
    return x;
}
void push(char x)
{
    if(prim==NULL)
    {
        if(x==')')
        {//cout<<x;
            ok=0;//cout<<"aici1 ";
            return;
        }
        prim=ultim=new nod;
        prim->info=x;
        prim->next=NULL;

    }
    else if(x==')')
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
    int i,n=8;
    char x;
    for(i=0;i<n&&ok;i++)
       {
           cin>>x;
           //cout<<x<<" ";
           push(x);
       }
    //cout<<empty()<<" "<<ok<<endl;
    if(empty()==1&&ok==1)
        cout<<"Corect";
    else cout<<"Gresit";
    return 0;
}
