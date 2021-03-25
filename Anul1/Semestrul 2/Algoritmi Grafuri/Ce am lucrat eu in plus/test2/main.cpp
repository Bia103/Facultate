#include <iostream>
#include <list>
using namespace std;
list<int>L[1001];
int viz[1001];
void DFS(int x)
{
    viz[x]=1;
    for(auto p:L[x])
    {
        if(viz[p]==0)
            {
                cout<<p;
                DFS(p);

            }
    }
}
int main()
{
  int x,y,n,m,st;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>x>>y;
        L[x].push_back(y);
        L[y].push_back(x);
    }
    cin>>st;
    DFS(st);
    return 0;
}
