/*#include <iostream>
#include<list>
using namespace std;

int main()
{
    int x;
    //citirea listei
    list<int>L;
    do
    {
        cin>>x;
        L.push_back(x);
    }while(x!=0);
    //afisarea listei
   /* for(int p:L)
        cout<<p<<' ';
    //afisare mai buna
  for(list<int>::iterator it=L.begin();it!=L.end();it++)
        cout<<*it<<' ';
    return 0;
}*/

#include <iostream>
#include <fstream>
#include <list>
#include <utility>
using namespace std;

int m, n, status[100], dt[100], tata[100], low[100], crit[100];
list<int> L[100];
list <pair <int, int> > MC;

int times;

int dfs(int x)
{
    int nrc = 0;
    times ++;
    status[x]= 1;
    dt[x] = low[x] = times;
    for (int y:L[x])
    {
        if (status[y]==0)
        {
            tata[y] = x;
            nrc ++ ;
            dfs(y);
            low[x] = min(low[x], low[y]);
             if (dt[x]<=low[y])
        {
            crit[x] = 1;
        }
        if (dt[x]<low[y])
            cout <<x<<"-"<<y<<"\n";
        }
        if (status[y]==1)
        {
            if (y!=tata[x]) /// xy <- muchie de intoarcere
            {
                low[x]=min(low[x], dt[y]);
            }
        }

    }
    status[x]= 2;
    return nrc;
}

int main()
{
    ifstream f1 ("date.in");

    int i, j, x, y, st;
    cin >>n>>m;
    for (i=0;i<m;i++){
        cin>>x>>y;
        L[x].push_back(y);
        L[y].push_back(x);
    }
    for (i=1;i<=n;i++)
    {
        for (int p:L[i])
            cout <<p<<" ";
        cout<<"\n";
    }
    cin >>st;
    if (dfs(st)>1)
        crit[st]=1;
    else
        crit[st] = 0;
        for (int i=0;i<100;i++)
            if (crit[i]==1)
            cout <<i<<" ";
            cout<<endl;
            for (i=1;i<=n;i++)
                cout <<dt[i]<<" ";
            cout <<endl;
            for (i=1;i<=n;i++)
                cout <<low[i]<<" ";
            cout <<endl;
    f1.close();
    return 0;
}
/*
8
10
1 2
1 3
1 4
2 3
2 7
3 5
5 4
5 6
6 7
7 8
1
*/
