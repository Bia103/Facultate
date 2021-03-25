#include <iostream>

using namespace std;
int n,v[1001],aux;
void sorte(int p,int u)
{
    if(v[p]>v[u])
    {
        aux=v[p];
        v[p]=v[u];
        v[u]=aux;
    }
}
void interclas(int p,int u,int m)
{
    int i,j,a[1000],k=0;
    i=p;
    j=m+1;
    while(i<=m && j<=u)
        if(v[i]<v[j])
        {
            k++;
            a[k]=v[i];
            i++;
        }
        else
        {
            k++;
            a[k]=v[j];
            j++;
        }
        while(i<=m)
        {
            k++;
            a[k]=v[i];

        while(j<=u)
        {
            k++;
            a[k]=v[j];
            j++;
        }
         i++;
        }
    for(i=1; i<=k; i++)
        v[p+i-1]=a[i];
}
void mergeS(int p,int u)
{
    int m;
    if(u-p<=1)
        sorte(p,u);
   else{m=(p+u)/2;
    mergeS(p,m);
    mergeS(m+1,u);
    interclas(p,u,m);}

}
int main()
{
    int i;
    cin>>n;
    for(i=1;i<=n;i++)
        cin>>v[i];
    mergeS(1,n);

    for(i=1;i<=n;i++)
        cout<<v[i]<<" ";
    return 0;
}
/*
5
12 3 45 2 45
*/
