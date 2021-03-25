#include <iostream>

using namespace std;
struct nod
{
    int info;
    nod *next;
};
struct vagon
{
    nod *in,*out;
};
int isEmpty(vagon *q)
{
    return q->in==NULL;
}
void push(vagon *q, int x)
{
    nod *n =new nod;
    n->info=x;
    n->next=NULL;

    if(isEmpty(q))
        q->in=q->out=n;
    else
    {
        q->in->next=n;
        q->in=n;
    }
}
int pop(vagon *q)
{
    if(isEmpty(q))
        return -1;
    nod *n=q->out;
    q->out=q->out->next;
    if(q->out==NULL)
        q->in = NULL;
    return n->info;
}
vagon *coada()
{
    vagon *q=new vagon;
    q->in=q->out=NULL;
    return q;
}
void afisare(vagon *q)  //Afisare Coada
{
    if(isEmpty(q))
        cout<<"Coada Vida"<<endl;
    else
    {
        nod *p=q->out;
        cout<<"Out: ";
        while(p!=NULL)
        {
            cout<<p->info<<" ";
            p=p->next;
        }
        cout<<":In"<<endl;
    }
}
int main()
{
    int n,k,x,ok=1;
    cin>>n>>k;
    vagon *vi=coada();
    vagon *a[101];
    for(int i=1;i<=k;i++)
    {
        a[i]=coada();
        push(a[i],0);
    }
    vagon *vf=coada();
    for(int i=1; i<=n; i++)
    {
        cin>>x;
        push(vi,x);
    }
    int l=1;
    for(int i=1; i<=n; i++)
    {
        x=pop(vi);
        int j=1;
        while(j<=k && a[j]->in->info>x)
            j++;//cout<<ok<<endl;
        if(j>k)
        {

        ok=0;//cout<<ok<<endl;
        break;
        }
        else push(a[j],x);

    }

    if(ok==0)
        cout<<"Imposibil";
    else
    {
        int i,nr=0;;
        for(i=1;i<=k;i++)
            if(a[i]->out==a[i]->in)
                    nr++;
       k=k-nr;;
      //cout<<nr;
        for(i=1;i<=k;i++)
          a[i]->out=a[i]->out->next;
        for(i=1;i<=n;i++)
        {
            for(int j=1;j<=k;j++)
                if(a[j]->out->info==l)
                {
//cout<<"aici";
                    pop(a[j]);
                    push(vf,l);l++;
                    break;
                }

        }
afisare(vf);
    }

    return 0;
}
/*
9 3
3 6 9 2 4 7 1 5 8
*/
