#include <iostream>

using namespace std;
int l=1,cont=1;
struct nod
{
    int info;
    nod *next;
};
struct coada
{
    nod *in, *out;
}a[101],af;
int empty1(coada c)
{
    if(c.in==NULL)
        return 1;
    return 0;
}

int prima(coada a[], int k)
{
    for(int i=0; i<k; i++)
        if (empty1(a[i]))
            return i;
    return -1;
}
void afisare()
{
    if(af.in==NULL)
    {
        //cout<<"Stiva vida"<<endl;
        return;
    }
    else
    {
        nod *p=af.in;
        while(p)
        {
            cout<<p->info<<" ";
            p=p->next;
        }

    }
}
void push(coada &z,int x)
{
    if(z.in==NULL)
    {
        z.in=z.out=new nod;
        z.in->info=x;
        z.in->next=NULL;
    }
    else
    {
        nod *p=new nod;
        p->info=x;
        z.out->next=p;
        z.out=p;
    }

}
int pop(coada &z)
{
    int r;
    if(z.in==NULL)
        return -1;
    r=z.in->info;
    nod *p=z.in;
    z.in=z.in->next;
    delete p;
    return r;
}
void centru_de_comanda(coada a[],int x,int k)
{
    int ok=0,i;
    if(x==l)
    {
        push(af,x);
        l++;ok=1;
    }
    else
    {
        for(i=0; i<k; i++)
        {
            //coada z=a[i];


            if(empty1(a[i])==0&&a[i].in->info<x )
                {//cout<<"Da";
                push(a[i],x);
                break;
            }

        }
        if(ok==0)
        {
            int y=prima(a,k);
            if(y!=-1)
            {
                a[y].in=a[y].out=new nod;
                a[y].in->info=x;

            }
            else
            {
                cont=0;
                return;
            }

            }
            for(i=0; i<k; i++)
            {
                if(a[i].out->info==l)
                {
                    l++;
                    int y=pop(a[i]);
                    push(af,x);
                }
        }
    }
}
int main()
{
    int n,i,k,x;
    cin>>n>>k;
    for(i=0; i<n&&cont; i++)
    {
        cin>>x;
        centru_de_comanda(a,x,k);
    }
    if(cont)
    afisare();
    else cout<<"Imposibil";
    return 0;
}
/*
9 3
5 8 1 7 4 2 9 6 3
*/
