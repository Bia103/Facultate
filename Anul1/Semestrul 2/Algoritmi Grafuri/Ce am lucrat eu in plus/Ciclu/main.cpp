#include <iostream>
#include <list>
using namespace std;
int viz[100];
int m,n,ok=0,nr;
list<int >L[100];
void DFS(int x)
{
    viz[x]=1;
    for(int p:L[x])
        if(viz[p]==0)
           {
               for(int u:L[p])
               {
                   if(viz[u]==1&&u!=x)
                   {

                       ok=1;
                   }
               }
                DFS(p);
           }

}
int main()
{

    int x,y,i,st;
    // citirea unei liste de muchii
    cin>>n>>m;
    for(i=1;i<=m;i++)
    {
        cin>>x >> y;
        L[x].push_back(y);
        L[y].push_back(x);
    }
    // afisarea listei de muchii
    cout<<"Afisarea listei de muchii:\n";
  /* for(int i=1;i<=n;i++)
    {
        for(int p:L[i])
            cout<<p<<" ";
        cout<<endl;
    }*/
    cin>>st;
   // cout<<"Parcurgerea DFS: \n";
    cout<<st<<" ";
    for ( i=1;i<=n;i++)
    DFS(i);
    if(ok)
    {
        cout<<"Exista cicluri ";
    }
    else cout<<"Nu";

    return 0;
}
/*
8
9
1 2
1 3
1 4
2 3
2 7
3 5
5 4
5 6
6 7
1
*/
