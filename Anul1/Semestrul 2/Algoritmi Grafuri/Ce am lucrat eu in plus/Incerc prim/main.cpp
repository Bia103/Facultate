#include <iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<fstream>
#include<list>
#include<set>
using namespace std;
int n, m, p, i, t[100],st,x,y,d[100],viz[1001];
ifstream fin("graf.in");
list <pair<int,int> >L[100];
int main()
{
    cin>>n>>m;
    for(i=0;i<m;i++)
    {
       cin>>x>>y>>p;
        L[x].push_back({p,y});
        L[y].push_back({p,x});//graf neorientat
    }
    for(int i=1;i<=n;i++)
    {
        d[i]=1000;
        t[i]=0;
    }
    cin>>st;//cout<<"Wut";
    d[st]=0;
    set<pair<int,int> >Q;    //setul pastreaza totul ordonat
    Q.insert({d[st],st});
    while(Q.size()>0)
    {
        x=Q.begin()->second;
        viz[x]++;
        Q.erase(Q.begin());  //Q.erase({d[x],x})
        for(pair<int,int>it : L[x])
        {
            y=it.second;
            p=it.first;
            if(d[y]>p&&viz[y]==0)
            {
                Q.erase({d[y],y});//log n
                d[y]=p;
                t[y]=x;
                Q.insert({d[y],y});//log n
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        cout<<i<<" "<<t[i]<<endl;
    }
    return 0;
}
// x: ( , ),( w(x,y)-pondere,x-eticheta ),( , )
