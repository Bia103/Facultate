#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include<set>
using namespace std;
list <pair<int,int> > L;
vector <pair<int,pair<int,int> > >E;
int t[1001],h[1001];
int fin(int x)
{
    if(x==t[x])
        return x;
    fin(t[x]);
}
void ini(int n)
{
    for(int i=1;i<=n;i++)
    {
        t[i]=i;
        h[i]=0;
    }
}
void uni(int x,int y)
{
    int a=fin(x);
    int b=fin(y);
    if(h[a]>h[b])
        t[b]=a;
    else
    {
        t[a]=b;
        if(h[a]==h[b])
            h[b]++;
    }
}
int main()
{
    int m,n,x,y,p;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        cin>>x>>y>>p;
        E[i]={p,{x,y}};
    }
    ini(n);
    int nrc=0,i=0;
    sort(E.begin(),E.end());
    while(nrc<n-1)
    {
        x=E[i].second.first;
        y=E[i].second.second;
        p=E[i].first;
        if(fin(x)!=fin(y))
        {
            L.push_back({x,y});
            uni(x,y);
        }
    }
    set<pair<int,int> >Q;
    while(!Q.empty())
    {

    }
    return 0;
}
