#include <iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<fstream>
#include<list>
#include<set>
using namespace std;
int n, m, p, i, t[100],st,x,y,d[100],v[101];
ifstream fin("graf.in");
list <pair<int,int> >L[100];
int main()
{
    fin>>n>>m;
    for(i=0;i<m;i++)
    {
        fin>>x>>y>>p;
        L[x].push_back({p,y});
        L[y].push_back({p,x});//graf neorientat
    }
    for(int i=1;i<=n;i++)
    {
        d[i]=1000;
        t[i]=0;
    }
    int k=0;
    fin>>k;
    for(i=1;i<=k;i++)
        {fin>>v[i];}
    cin>>st;
    //cin>>st;//cout<<"Wut";
    d[st]=0;
    set<pair<int,int> >Q;    //setul pastreaza totul ordonat
    Q.insert({d[st],st});
    int ok=1;
    while(Q.size()>0&&ok)
    {//
        x=Q.begin()->second;
        Q.erase(Q.begin()); //Q.erase({d[x],x})
        for(int i=1;i<=k;i++)
            if(v[i]==x)
                ok=0;


       //cout<<x<<" ";
        for(pair<int,int>it : L[x])
        {//
            y=it.second;
            p=it.first;
            if(d[y]>d[x]+p)
            {//cout<<"Wow";
                Q.erase({d[y],y});//log n
                d[y]=d[x]+p;
                t[y]=x;
                Q.insert({d[y],y});//log n
            }
        }
        //cout<<"ok="<<ok<<endl;
        //cout<<"Q.size()"<<Q.size()<<endl;
    }
    cout<<endl<<x;
   // while()
    for(int i=1;i<=n;i++)
    {
        cout<<d[i]<<" "<<t[i]<<endl;
    }
    return 0;
}
// x: ( , ),( w(x,y)-pondere,x-eticheta ),( , )
