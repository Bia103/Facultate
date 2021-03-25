#include <iostream>

using namespace std;
struct arbore
{
    int info;
    arbore *st,*dr;
}*r;
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
void RSD(arbore *r,int niv,int dir)
{
    if(r!=NULL)
    {
        for(int i=0;i<niv;i++)
            cout<<"\t";
        cout<<r->info<<(dir==0?"st":"dr")<<endl;
        RSD(r->st,niv+1,0);
         RSD(r->dr,niv+1,1);
    }
}
int main()
{
inserare(r,3);
    inserare(r,2);
    inserare(r,10);
    inserare(r,101);
    inserare(r,70);
    inserare(r,0);
    inserare(r,1);
    inserare(r,200);
    inserare(r,90);
    //SRD(r);
    RSD(r,0,0);
    return 0;
}
