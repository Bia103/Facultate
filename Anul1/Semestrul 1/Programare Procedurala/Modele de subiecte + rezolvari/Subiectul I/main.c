#include <stdio.h>
#include <stdlib.h>
void vector_par(int v[],int n,int **p,int *m)
{
    //*p
    int l=0;
    *m=0;

    (*p)=(int*)malloc(sizeof(int));
    for(int i=0;i<n;i++)
        if(v[i]%2==0)
        {//printf("%d",v[i]);
            int *aux=(int *)realloc((*p),(l+1)*sizeof(int));
            aux[l]=v[i];//printf("Da");
            *p=aux;
            l++;
        }

*m=l;

}
void add(int *v,int n,int x)
{
    for(int i=0;i<n;i++)
        v[i]=v[i]+x;
}
void multiply(int *v,int n,int x)
{
     for(int i=0;i<n;i++)
        v[i]=v[i]*x;
}
void sort(int *v,int n)
{
    int ok=0;
    do
    {
        ok=1;
        for(int i=0;i<n-1;i++)
            if(v[i]>v[i+1])
            {
            ok=0;
           int  aux=v[i];
            v[i]=v[i+1];
            v[i+1]=aux;
        }
    }while(ok==0);
}
void display(int *v,int n)
{
    for(int i=0;i<n;i++)
        printf("%d ",v[i]);
}
int main()
{
    int *p,m;
    int v[]={7,10,12,3,5,4,2};
    //vector_par(v,7,&p,&m);
   //
  // add(v,7,1);
  multiply(v,7,-1);
  sort(v,7);
  multiply(v,7,-1);
  add(v,7,1);
    vector_par(v,7,&p,&m);
    add(p,m,-1); display(p,m);
   // display(v,7);
    return 0;
}
