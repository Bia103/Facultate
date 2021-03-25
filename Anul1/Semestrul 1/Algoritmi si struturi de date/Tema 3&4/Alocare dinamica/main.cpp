#include <iostream>

using namespace std;
struct nod
{
    int info;
    nod *next;
}*prim,*ultim;
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
    if(p==NULL)
        cout<<"Lista vida"<<endl;
    while(p!=NULL)
    {
        cout<<p->info<<" ";
        p=p->next;
    }
    cout<<endl;
}
void ad_i(int x)// se adauga la inceputul listei un element
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
        p->next=prim;
        prim =p;
    }
}
int caut_val(int x)
{
    int poz=1;
    nod *p=prim;
    while(p!=NULL&&p->info!=x)
    {
        poz++;
        p=p->next;
    }
    if(p==NULL)
        {cout<<endl<<"In lista alocata dinamic nu exista nici un element cu valoarea "<<x;
        return -1;
        }
    else
        {cout<<endl<<"Elementul "<<x<<" Se afla pe pozitia "<<poz;
        return 0;
        }
}
int caut_poz(int x)
{
    nod *p=prim;
    int i=1;
    while(p!=NULL&&i<x)
    {
        p=p->next;
        i++;

    }
    //cout<<p->info;
    if(p==NULL)
        return -1;
    else return p->info;
}
void ins_d_v(int x,int y)
{
    nod *p=prim,*u;

    while(p!=NULL&&p->info!=x)
        {p=p->next;
        //cout<<"crapa aici?";
        }
        //cout<<"Da?";
    if(p==NULL)
        cout<<"Nu s-a gasit valoarea dupa care ar trebui inserat numarul";
    else if(p==ultim)
    {
        p=new nod;
        ultim->next=p;
        p->info=y;
        p->next=NULL;
        ultim=p;

    }
    else
    {
        u=new nod;
        u->next=p->next;
        p->next=u;
        u->info=y;
    }
}
void ins_d_p(int x,int y)
{
    nod *p=prim,*u=NULL,*l;
    int i=1;
    while(p!=NULL&&i<x)
        {u=p;
            p=p->next;i++;
        //cout<<"crapa aici?";
        }
        //cout<<"Da?";
    if(p==NULL)
        cout<<"Nu se poate insera";
    else if(p==prim)
    {
        p=new nod;
        p->next=prim;
        p->info=y;
        prim=p;
    }
    else
    {
        l=new nod;
        l->next=p;
        l->info=y;
        u->next=l;
    }
}
void stergere(int x)//cauta primul nod cu val x ca pentru a-l sterge
{

    nod *p=prim;
    nod *last=NULL;
    while(p!=NULL&&p->info!=x)// conditiile trebuie scrise in ordinea asta pt ca altfel crapa!!!
    {
        last=p;//tine minte penultimul nod
        p=p->next;
        //i++;

    }

     if(prim==ultim &&p->info==x)
     {
         prim=NULL;
         ultim=NULL;
         return;
     }
    //ori p=NULL ori p->info=x
    if(p==NULL)
    {
        cout<<"Nu s-a gasit valoarea.";
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
void stergere_p(int x)//cauta primul nod cu val x ca pentru a-l sterge
{
    int i;
  i=1;
    nod *p=prim;
    nod *last=NULL;
    while(p!=NULL&&i!=x)// conditiile trebuie scrise in ordinea asta pt ca altfel crapa!!!
    {
        last=p;//tine minte penultimul nod
        p=p->next;
        i++;

    }

     if(prim==ultim &&x==1)
     {
         prim=NULL;
         ultim=NULL;
         return;
     }
    //ori p=NULL ori p->info=x
    if(p==NULL)
    {
        cout<<"Nu s-a gasit pozitia.";
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
int main()
{
    cout<<"Selectati una dintre urmatoarele instructiuni:"<<endl<<"Apasati 1 pentru inserarea la inceputul listei alocate dinamic o valoare si introduceti numarul respectiv."<<endl<<"Apasati 2 pentru inserarea la sfarsitul listei alocate dinamic o valoare si introduceti numarul respectiv."<<endl<<"Apasati 3 pentru afisarea listei alocate dinamic."<<endl<<"Apasati 4 si introduceti o valoare care va fi ulterior cautata in lista alocata dinamic"<<endl<<"Apasati 5 pentru aflarea valorii de pe o pozitie pe care o sa o introduceti ulterior la tastatura"<<endl<<"Apasati 6 pentru inserarea unui nou nod dupa o valoare citita"<<endl<<"Apasati 7 pentru inserarea unui nou nod pe o anumita pozitie"<<endl<<"Apasati 8 pentru stergerea unei valori din liste";
    int x,y,z;
    do
    {
        cin>>x;
        if(x==1)
        {
            cin>>y;
            ad_i(y);
        }
        if(x==2)
        {
            cin>>y;
            ad_f(y);
        }
        if(x==3)
        {
            af();
        }
        if(x==4)
        {
            cin>>y;
            z=caut_val(y);
            if(z==-1)
                cout<<" "<<z<<endl;

        }
        if(x==5)
        {
            cin>>y;
            z=caut_poz(y);
            if(z==-1)
                cout<<" "<<z<<endl;
                else cout<<"Valoarea de pe pozitia "<<y<<" este "<<z<<endl;
        }
        if(x==6)
        {
            cin>>y>>z;
            ins_d_v(y,z);
        }
        if(x==7)
        {
            cin>>y>>z;
            ins_d_p(y,z);
        }
        if(x==8)
        {
            cin>>y;
            stergere(y);
        }
        if(x==9)
        {
            cin>>y;
            stergere_p(y);
        }
    }
    while(x!=0);
    af();
    return 0;
}
/*
2 1 2 2 2 3 2 4 2 5 2 6
6 3 89
*/
