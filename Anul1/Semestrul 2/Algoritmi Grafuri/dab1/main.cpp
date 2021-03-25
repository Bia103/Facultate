#include <iostream>
#include <list>
#include <utility>
#include <fstream>
#include <queue>
using namespace std;
int d[100],n,m;
list<pair<int,int> >L[100];
queue<int> Q;
list <int> TP;
ifstream fin("graf.in");
int main()
{
    fin>>n>>m;int x,y,c;
   for(int i=1;i<=m;i++)
   {

       fin>>x>>y>>c;
       L[x].push_back({y,c});
       d[y]++;
   }
   for(int i=1;i<=n;i++)
   {
       if(!d[i])
            Q.push(i);
        while(!Q.empty())
        {
            x=Q.front();
            Q.pop();
            TP.push_back(x);
            for(pair<int,int>p:L[x])
            {
                y=p.first;
                d[y]--;
                if(!d[y])
                    Q.push(y);
            }
        }
   }
   for(int x:TP)
    cout<<x<<' ';
// Sortarea topologica
    return 0;
}
