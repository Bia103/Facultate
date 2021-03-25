#include <iostream>
#include<list>
#include <queue>
using namespace std;
int viz[1001];
list <int > L[1001],Q;
queue <int >Q1;
int main()
{
    int m,n,x,y,st;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        cin>>x>>y;
        L[x].push_back(y);
        L[y].push_back(x);
    }
    cin>>st;
    Q.push_back(st);
    viz[st]=1;
    while(!Q.empty())
    {
        x=Q.front();
        Q.pop_front();
        cout<<x<<" ";
        for(auto p:L[x])
            if(viz[p]==0)
            {
                viz[p]=1;
                Q.push_back(p);
            }
    }
    return 0;
}
