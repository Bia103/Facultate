#include <iostream>
#include <cstdlib>
#include<stdlib.h>
#include<time.h>
using namespace std;
int v[1001];
int pivot(int v[],int p,int q,int nim)
{
    int i,j;
    int x=v[nim];
    i=p-1;
    j=q+1;
    while(i<j)
    {
        do
        {
            i++;
        }
        while(v[i]<x);
        do
        {
            j--;
        }
        while(v[j]>x);

        if(i>=j)
            return j;
        swap(v[i],v[j]);

    }


}

int part(int v[],int p,int u)
{
    srand(time(NULL));
    // srand(time(NULL));
    int nim=p+rand()%(u-p);
   // swap(v[nim],v[p]);
    return pivot(v,u,p,nim);
}
void quick(int v[],int p,int u)
{
    if(p>=u)
        return;
    else
    {
        int q=part(v,p,u);
//cout<<"Da mai";
        quick(v,p,q);
        quick(v,q+1,u);
    }
}
int main()
{
    int n,i;
    cin>>n;
    for(i=0; i<n; i++)
        cin>>v[i];
    quick(v,0,n-1);
    for(i=0; i<n; i++)
        cout<<v[i]<<" ";
    return 0;
}
/*
7
1 89 2 22 3 34 105
*/
