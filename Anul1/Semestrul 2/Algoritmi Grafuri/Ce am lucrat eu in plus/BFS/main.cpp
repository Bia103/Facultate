#include <iostream>
#include <list>
using namespace std;
list <int>L[1001];
list <int > q;
int viz[1001],n,m,st;
void BFS(int x)
{
    viz[x]=1;
    q.push_back(x);
    while(!q.empty())
    {
        int p=q.front();
        q.pop_front();
        for(int i:L[p])
            if(viz[i]==0)
            {
                cout<<i<<" ";
                viz[i]=1;
                q.push_back(i);
            }
    }
}
int main()
{
    int x,y;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>x>>y;
        L[x].push_back(y);
        L[y].push_back(x);
    }
    cin>>st;
    BFS(st);
    return 0;
}
/*
8
9
1 2
1 3
1 4
2 5
3 5
3 6
5 8
6 7
7 8
1
*/
