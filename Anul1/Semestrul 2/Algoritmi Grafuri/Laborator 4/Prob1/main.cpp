//Kruskal
#include <iostream>
#include <vector>
#include<fstream>
#include<algorithm>
#include<list>
using namespace std;
int t[100],h[100];
int find(int x);
void init(int n)//initializarea tatilor si inaltimii
{
    for(int i=1;i<=n;i++)
    {
        t[i]=i;//la inceput nodul i se are ca tata deoarece componentele au gradul 0
        h[i]=0;
    }
}
void union1(int x,int y)//reuneste multimea de noduri in care se afla x cu multimea de noduri in care se afla y
{
    int a=find(x);
    int b=find(y);
    if(h[b]>h[a])//daca inaltimea arborelui b
        t[a]=b;
    else if(h[b]<h[a])
            t[b]=a;
    else
    {   if(a!=b)
        {
            t[b]=a;
            h[a]++;//daca arborii au inaltimi egale, atunci inaltimea creste cu 1
        }
    }
}
int find(int x)
{
    if(x==t[x])
        return x;
    else find(t[x]);
}
int main()
{
    int n,m,i,j,x,y,p,s=0;
    ifstream fin("graf.in");
    vector <pair<int,pair<int,int> > >E;
    list <pair<int,int> >T;
    fin>>n>>m;
    init(n);
    E.resize(m);
    for(i=0;i<m;i++)
    {
        fin>>x>>y>>p;
        E[i]={p,{x,y}};

    }
    sort(E.begin(),E.end());
    for(pair<int,pair<int,int> >p:E)
        cout<<p.first<<" "<<p.second.first<<" "<<p.second.second<<endl;
    cout<<endl;
    for(i=0;i<m;i++)
    {
        p=E[i].first;
        x=E[i].second.first;
        y=E[i].second.second;
        if(find(x)!=find(y))
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
