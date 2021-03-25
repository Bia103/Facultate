#include <iostream>

using namespace std;
struct arbore
{
    int info;
    arbore *st,*dr;
}*r;
//int caut(arbore *&r, int x);
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
void SRD(arbore *r)
{
 if(r!=NULL)
    {SRD(r->st);

    cout<<r->info<<" ";
    SRD(r->dr);}
}
void chei(int k1,int k2,arbore *r)
{

    if(r==NULL)
        return;
    if(r->info>k1)
        {

            chei(k1,k2,r->st);
        }
    if (r->info>=k1&&r->info<=k2)
       {
           cout<<r->info<<" ";
       }
    if(r->info<k2)
     { //cout<<"Da";
     chei(k1,k2,r->dr);

     }
}
int main()
{
    int k1,k2;
    inserare(r,3);
    inserare(r,2);
    inserare(r,10);
    inserare(r,101);
    inserare(r,70);
    inserare(r,0);
    inserare(r,1);
    inserare(r,200);
    inserare(r,90);
    cin>>k1>>k2;
    //SRD(r);
    chei(k1,k2,r);
    return 0;
}
