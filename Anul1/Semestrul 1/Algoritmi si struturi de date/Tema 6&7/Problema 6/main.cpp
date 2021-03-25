#include <iostream>

using namespace std;
int a[1001];
void heap(int n,int i)
{
    int mx=i,st=2*i+1,dr=2*i+2;
    if(st<n &&a[st]>a[mx])
        mx=st;
    if(dr<n&&a[dr]>a[mx])
        mx=dr;
    if(i!=mx)
    {
        swap(a[i],a[mx]);
        heap(n,mx);
    }
}
void sortare(int n)
{
    int i;
    for(i=n/2-1; i>=0; i--)
        heap(n,i);
    for(i=n-1; i>=0; i--)
    {
        swap(a[i],a[0]);
        heap(i,0);
    }
}
int main()
{
    int n,i;
    cin>>n;
    for(i=0; i<n; i++)
        cin>>a[i];
    sortare(n);
    for(i=0; i<n; i++)
        cout<<a[i]<<" ";
    return 0;
}
/*
5
12 4 3 15 1
*/
