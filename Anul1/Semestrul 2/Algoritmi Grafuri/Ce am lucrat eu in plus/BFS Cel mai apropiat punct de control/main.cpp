#include <iostream>
#include <list>
using namespace std;
list <int>L[1001];
list <int > q;
int viz[1001],n,m,st,c[1001],tata[1001];
int BFS(int x)
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
                tata[i]=p;
                viz[i]=1;
                q.push_back(i);
                if(c[i]==1)
                {
                    return i;
                }
            }
    }
    return 0;
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
    for(int i=1;i<=st;i++)
    {
        cin>>x;
        c[x]=1;
    }
    cin>>st;
    //cout<<BFS(st);
    int i=BFS(st);
    cout<<i;
    cout<<endl;
    while(tata[i]!=0)
    {
        cout<<i;
        i=tata[i];
    }
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
8
*/
