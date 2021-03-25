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
    nod *in;
    nod *out;
}*af;
coada *C_Noua()  //Creare Coada Noua
{
    coada *q=new coada;
    q->in=q->out=NULL;
    return q;
}
int empty1(coada *c)
{
    if(c->in==NULL)
        return 1;
    return 0;
}

int prima(coada *a[], int k)
{
    for(int i=0; i<k; i++)
        if (empty1(a[i]))
            return i;
    return -1;
}
void afisare()
{
    if(af->in==NULL)
    {
        //cout<<"Stiva vida"<<endl;
        return;
    }
    else
    {
        nod *p=af->in;
        while(p)
        {
            cout<<p->info<<" ";
            p=p->next;
        }

    }
}
nod *nod_nou(int x)  //Creare Nod Nou
{
    nod *n= new nod;
    n->info=x;
    n->next=NULL;
    return n;
}
/*void push(coada *z,int x)
{
    if(z==NULL)
    {
        coada *z=new coada;
        z->in->info=x;cout<<"Da ";
        z->in->next=NULL;
        z->out=z->in;

    }
    else
    {
        nod *p=new nod;
        p->info=x;
        z->out->next=p;
        z->out=p;
    }

}*/
void push(coada *q, int x) //Adaugare Nod x in Coada
{
    nod *n = nod_nou(x);
    if(empty1(q))         //Daca Coada e Vida
       {
           q->in=q->out=n;cout<<"Da";
       }
    else     //Daca avem cel putin un nod in Coada
    {
        q->out->next=n;
        q->out=n;
    }
}
int pop(coada *z)
{
    int r;
    if(empty1(z))
        return -1;
    r=z->in->info;
    nod *p=z->in;
    z->in=z->in->next;
    if(z->in==NULL)
        z->out=NULL;
    delete p;
    return r;
}
void centru_de_comanda(int x,int k,coada *a[])
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


            if(empty1(a[i])==0&&a[i]->out->info<x )
                {cout<<"intra";
                push(a[i],x);

            }

        }
        if(ok==0)
        {
            int y=prima(a,k);
            if(y!=-1)
            {
                a[y]->in=a[y]->out=new nod;
                a[y]->in->info=x;

            }
            else
            {
                cont=0;
                return;
            }

            }
            for(i=0; i<k; i++)
            {
                if(a[i]->out->info==l)
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
    coada *a[101];
    for(i=0;i<k;i++)
    {
        a[i]=C_Noua();
        push(a[i],0);
    }
    coada *af=C_Noua();
    for(i=0; i<n&&cont; i++)
    {
        cin>>x;
        centru_de_comanda(x,k,a);
    }
   // if(cont)
    afisare();
   // else cout<<"Imposibil";
    return 0;
}
/*
9 3
5 8 1 7 4 2 9 6 3
*/
/*
3 4
1 2 3
*/
