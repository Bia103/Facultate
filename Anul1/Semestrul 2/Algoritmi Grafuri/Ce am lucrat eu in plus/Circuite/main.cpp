#include <iostream>
#include <list>
using namespace std;
list<int>L[100];
int ok=0,n,m,viz[1001];
void DFS(int x)
{
    viz[x]=1;
    for(int p:L[x])
    {
        if(viz[p]==0)
        {
            for(int u:L[p])
                if(viz[u]==1&&u!=x)
                    ok=1;
            DFS(p);
        }
    }
}
int main()
{
    cin>>n>>m;
    int x,y,st;
    for(int i=1;i<=m;i++)
    {
        cin>>x>>y;
        L[x].push_back(y);
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            viz[i]=0;
        DFS(i);

    }
    if(ok)
        cout<<"Circuit";
    else cout<<"Nu";
    return 0;
}
/*
8
10
6 5
1 2
2 7
7 6
5 4
4 1
1 3
2 3
5 3
7 8
*/
