#include <iostream>
#include<list>
#include<utility>
#include<fstream>
using namespace std;
int time,status[101],dt[101],low[101],tata[101],crit[101];
list <int> L[101];
list<pair <int,int>> E;
ifstream f("graf.in");
int DFS(int x)
{
    int nrc=0;
    status[x]=1;
    time++;
    dt[x]=low[x]=time;
    for(int y:L[x])
    {
        if(status[y]==0)
        {
            nrc++;
            tata[y]=x;
            DFS(y);
            low[x]=min(low[x],low[y]);

        if(dt[x]<=low[y])
            crit[x]=1;
         if (dt[x]<low[y])
         {
             E.push_back({x,y});cout<<endl;
         }
            //cout <<x<<"-"<<y<<endl;
        }

        if(status[y]==1)
        {
            if(y!=tata[x])
            {
                low[x]=min(low[x], dt[y]);
            }
        }
       // if(status[y]==2)

    }cout<<x<<" ";
    status[x]=2;
    return nrc;
}
int main()
{
    int n,m,i,x,y;
    f>>n>>m;
    for(i=0;i<m;i++)
    {
        f>>x>>y;
        L[x].push_back(y);
        L[y].push_back(x);

            }
    int st;
    cin>>st;
    if(DFS(st)>1)
        crit[st]=1;
    else crit[st]=0;
    for(i=1;i<=n;i++)
        if(crit[i]==1)
            cout<<i<<" ";
    cout<<endl;
    for(pair<int,int>p:E)
        cout<<p.first<<"-"<<p.second<<"\n";
    /*int time,status[101],dt[101],low[101],tata[101],crit[101];
    list <int> L[101];*/
    return 0;
}
