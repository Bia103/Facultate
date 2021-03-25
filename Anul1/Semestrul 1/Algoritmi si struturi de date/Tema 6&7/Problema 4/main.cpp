#include <iostream>

using namespace std;
int v[1001],a[1001],c[1001];
int main()
{
    int n,i,x,mx=0;
   cin>>n;
   for(i=1;i<=n;i++)
   {
       cin>>v[i];
       a[v[i]]++;
       if(v[i]>mx)
        mx=v[i];
   }
 for(i=1;i<=mx+1;i++)
    a[i]=a[i-1]+a[i];
 for(i=1;i<=n;i++)
 {
     c[a[v[i]]]=v[i];
     a[v[i]]--;
 }
    for(i=1;i<=n;i++)
        cout<<c[i]<<" ";
    return 0;
}
/*
7
3 7 3 3 2 5 5
*/
