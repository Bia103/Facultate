#include <iostream>

using namespace std;
struct nod
{
    int info;
    nod *urm;
};
struct coada
{
    nod* Front, *End;
}Input,Output;
int isEmpty(coada c)
{
    if (c.Front == NULL )
        return 1;
    return 0;
}
void push(coada &z,int x)
{
    if(z.Front==NULL)
    {
        z.Front=z.End=new nod;
        z.Front->info=x;
        z.Front->urm=NULL;
    }
    else
    {
        nod *p=new nod;
        p->info=x;
        z.End->urm=p;
        z.End=p;
    }

}
/*int prima_coada_vida(coada aux[], int k)
{
    for(int i=0; i<k; i++)
        if (isEmpty(aux[i]))
            return i;
    return -1;
}
int pozitie_minima(coada aux[], int k)
{
    int poz_min = 0;
    while(poz_min < k && isEmpty(aux[poz_min]))
        poz_min++;
    if (poz_min == k)
        return -1;
    for(int i = poz_min+1; i<k; i++)
        if ((!(isEmpty(aux[i]))) && aux[poz_min].Front->info > aux[i].Front->info)
            poz_min = i;
    return poz_min;
}
void Nu()
{
    cout<<"din coada initiala ";
    pop(Input,val);
    if (val == pozOutput)
    {
        int p = prima_coada_vida(aux,k);
        if (p!=-1)
        {
            cout<<"adaugata in coada "<<p<<"--->";
            push(aux[p],val);
            pop(aux[p],val);
            cout<<"adaugata in coada finala\n";
            push(Output,val);
            pozOutput++;
        }
        else
            posibil = 0;
    }
    else
    {
        for(i = 0; i<k; i++)
            if (isEmpty(aux[i]) || (!(isEmpty(aux[i])) && val>aux[i].End->info))
            {
                cout<<"adaugata in coada "<<i<<"\n";
                push(aux[i],val);
                break;
            }
        if (i==k)
            posibil = 0;
    }
}
void golire_cozi(coada aux[],int k, coada& Output)
{
    while(pozitie_minima(aux,k)!=-1)
    {
        int x;
        cout<<"din coada auxiliara "<<pozitie_minima(aux,k)<<" ";
        pop(aux[pozitie_minima(aux,k)],x);
        cout<<" adaugata in coada finala\n";
        push(Output, x);
        pozOutput++;
    }
}*/
void afisare()
{
    if(Input.Front==NULL)
    {
        //cout<<"Stiva vida"<<endl;
        return;
    }
    else
    {
        nod *p=Input.Front;
        while(p)
        {
            cout<<p->info<<" ";
            p=p->urm;
        }

    }
}
int pop(coada &z)
{
    int r;
    if(z.Front==NULL)
        return -1;

    nod *p=z.Front;
    r=p->info;
    cout<<r<<" trtyetr";
    z.Front=z.Front->urm;
    delete p;
    return r;
}
int main()
{
    int n,i,k,x;
    cin>>n>>k;
    for(i=0; i<n; i++)
    {
        cin>>x;
        push(Input,x);
    }
    afisare();
    cout<<pop(Input)<<endl;
    afisare();
    return 0;
}
