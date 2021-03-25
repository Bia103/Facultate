//Kruskal
#include <iostream>
#include <vector>
#include<fstream>
#include<algorithm>
#include<list>
#include <cmath>
#include <math.h>
using namespace std;
int t[100],h[100];
int Find(int x);
void init(int N,int M)//initializarea tatilor si inaltimii
{
    for(int i=1;i<=N;i++)
    {
        t[i]=1;//la inceput nodul i se are ca tata deoarece componentele au gradul 0

    }
    for(int i=N+1;i<=N+M;i++)
        t[i]=i;
}
void union1(int x,int y)//reuneste multimea de noduri in care se afla x cu multimea de noduri in care se afla y
{
    int a=Find(x);
    int b=Find(y);
    t[b]=a;
}
int Find(int x)
{
    if(x==t[x])
        return x;
    else t[x]=Find(t[x]);
}
int main()
{
    int n,m,i,j,x,y,p,N,M,e;
    ifstream fin("graf.in");
    fin>>N>>M;
    vector <pair<double,pair<int,int> > >E;
    vector <pair <int,int> >V,T;
    init(N,M);
    T.resize(e);
    E.resize(e);
    V.resize(N+M+1);
    for(i=1;i<=N+M;i++)
    {
        fin>>x>>y>>p;
        V[i]={x,y};

    }
    for(i=0;i<e;i++)
    {
        fin>>x>>y;
        double p=sqrt(pow(V[x].first-V[y].first,2)+pow(V[x].second-V[y].second,2));
         E[i]={p,{x,y}};

    }
    double s=0.0;
    init(N,M);
    sort(E.begin(),E.end());
    for(pair<int,pair<int,int> >p:E)
        cout<<p.first<<" "<<p.second.first<<" "<<p.second.second<<endl;
    cout<<endl;
    for(i=0;i<m;i++)
    {
        p=E[i].first;
        x=E[i].second.first;
        y=E[i].second.second;
        if(Find(x)!=Find(y))
        {
            T.push_back({x,y});
            s+=p;
           union1(x,y);
        }
    }
    for(pair<int,int >p:T)
        cout<<p.first<<" "<<p.second<<endl;
    return 0;
}
