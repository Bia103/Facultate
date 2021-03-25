#include <iostream>

using namespace std;

struct arbore
{
    int info;
    arbore *st,*dr;
}*r;
int caut(arbore *&r, int x);
void inserare(arbore *&r,int x)
{
    if(r==NULL)
    {
        r=new arbore;
        r->info=x;
        r->st=r->dr=NULL;
    }
    else
    {
        if(r->info<=x)
            inserare(r->dr,x);
        else
            inserare(r->st,x);
    }
}
void sterg_nod(arbore *r,int x)
{
    arbore *t=NULL,*u=NULL;
    if(r==NULL)
    {
        cout<<"Arbore gol";
        return;
    }
    if(caut(r,x))
    while(r!=NULL)
    {

        if(r->info==x)
        {
            if(r->dr==NULL&&r->st==NULL)
              {
                  if(t->dr==r)
                    t->dr=NULL;
                  else t->st=NULL;
              }
            else if(r->dr!=NULL&&r->st==NULL)
            {
                if(t->dr==r)
                {
                    t->dr=r->dr;
                    r=NULL;
                }
                else if(t->st==r)
                {
                    t->st=r->dr;
                    r=NULL;
                }

            }
            else if(r->dr==NULL&&r->st!=NULL)
            {
                if(t->dr==r)
                {
                    t->dr=r->st;
                    r=NULL;
                }
                else if(t->st==r)
                {
                    t->st=r->st;
                    r=NULL;
                }
            }
            else if(r->dr!=NULL&&r->st!=NULL)
            {
                int ok=0;
                arbore *p=r->dr,*p2=r;
                while(p->st!=NULL)
                {
                    p2=p;ok=1;
                    p=p->st;
                }
                if(ok!=0)
                if(p->dr!=NULL)
                    p2->st=p->dr;
              //
                r->info=p->info;
                if(ok==0&&p->dr==NULL)
                    delete p;
                else if(ok==0&&p->dr!=NULL)
                    p2->dr=p->dr;
                return ;
            }

        }
        t=r;
        if(r!=NULL)
            if(r->info>x)
                r=r->st;
            else
                r=r->dr;



    }
    else cout<<"Imposibil";
}
void SRD(arbore *r)
{
 if(r!=NULL)
    {SRD(r->st);

    cout<<r->info<<" ";
    SRD(r->dr);}
}
int caut(arbore *&r, int x)
{
    if(r==NULL)
        return 0;
    if(r->info==x)
        return 1;
    else
    {
        if(r->info<=x)
            return caut(r->dr,x);
        if(r->info>=x)
            return caut(r->st,x);
    }
}
int cautmax(arbore *r)
{
    while(r->dr!=NULL)
    {
        r=r->dr;
    }
    return r->info;
}
void RSD(arbore *r)
{
    if(r!=NULL)
    {
        cout<<r->info<<" ";
        RSD(r->st);
        RSD(r->dr);
    }
}
void SDR(arbore *r)
{
    if(r!=NULL)
    {

        SDR(r->st);
        SDR(r->dr);
        cout<<r->info<<" ";
    }
}
int main()
{
    inserare(r,5);
    inserare(r,2);
    inserare(r,4);
    inserare(r,3);
    inserare(r,8);
    inserare(r,6);
    inserare(r,7);
    //inserare(r,200);
    //inserare(r,90);
   // cout<<caut(r,2)<<" "<<caut(r,1010)<<endl;
   // cout<<cautmax(r)<<endl;
   // arbore *p=r->st,*u=r->dr;
    cout<<endl;
    SRD(r);
    cout<<'\n';
    RSD(r);
     sterg_nod(r,5);
     RSD(r);
     //sterg_nod(r,5);
    cout<<endl;
    SDR(r);
    cout<<endl;
   // sterg_nod(r,101);
   // SRD(r);
    // cout<<p->info<<" "<<u->info;
    return 0;
}
