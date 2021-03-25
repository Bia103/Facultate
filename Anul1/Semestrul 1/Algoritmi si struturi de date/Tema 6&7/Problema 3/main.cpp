#include <iostream>

using namespace std;
int mij,v[1001];
/*int pivot(int v[], int l, int r)
{
    int x = v[r], i = l;
    for (int j = l; j <= r - 1; j++) {
        if (v[j] <= x) {
            swap(v[i],v[j]);
            i++;
        }
    }
    swap(v[i],v[r]);
    return i;
}*/
int pivot (int v[], int p, int u)
{
    int x=v[u];
    int i=(p-1);

    for (int j=p;j<=u-1;j++)
    {

        if(v[j]<=x)
        {
            i++;
            swap(v[i],v[j]);
        }
    }
    swap(v[i+1],v[u]);
    return i+1;
}
int k_element(int v[],int p,int u)
{
    if(u==p)
        return v[u];
   int q=pivot(v,p,u);
    int k=q-p+1;
    if(mij==k)
        return v[k];
    else if(k>mij)
            return k_element(v,p,q-1);
    else return k_element(v,q+1,u);
}
int main()
{
    int n,i;
    cin>>n;
    for(i=0;i<n;i++)
        cin>>v[i];
    mij=(n-1)/2;
    cout<<k_element(v,0,n-1);
    return 0;
}
/*
6
20 10 30 40 9 1
*/
