#include <iostream>
#include<list>
#include<fstream>
#include<list>
#include<utility>
#include<queue>
using namespace std;
ifstream fin("graf.in");
int M[1001][1001],pred[1001],d[50],check[1011];
int main()
{
    int m,n,x,y,i;
    list<pair<int,int> >E;
    list<int>L[50];
    fin>>n>>m;
    for(i=0; i<m; i++)
    {
        fin>>x>>y;
        E.push_back({x,y});//{} = make pair

    }
    cout<<"Muchiile sunt:\n";
    for(pair<int,int>p:E)
        cout<<p.first<<" "<<p.second<<endl;
    for(pair<int,int>p:E)
    {
        x=p.first;
        y=p.second;
        M[x][y]=M[y][x]=1;
        L[x].push_back(y);
        L[y].push_back(x);
    }
    cout<<"\n Liste:\n";
    for(i=1;i<=n;i++)
    {
        cout<<i<<": ";
        for(int p:L[i])
            cout<<p<<" ";
        cout<<endl;
    }
    cout<<" \nMatrice: \n";
    for(i=1;i<=n;i++)
    {for(int j=1;j<=n;j++)
        cout<<M[i][j]<<" ";
        cout<<endl;
    }
    int st;
    cin>>st;
    queue<int>Q;
    d[st]=0;
    pred[st]=-1;
    Q.push(st);
    while(fin>>x)
            check[x]=1;

    while(!Q.empty())//coada nu e vida
    {
        x=Q.front();//extrage primul element din coada
        Q.pop();
        cout<<x<<" ";
        if(check[x])
            break;
        //sterge ptimul elem din coada si nu returneaza nimic
        for(int y:L[x])
            if(!pred[y])
            {
                pred[y]=x;
                d[y]=1+d[x];
            Q.push(y);
            }
    }
    cout<<endl;
    cout<<"Punct de control: "<<x<<endl;
    cout<<"distanta de la "<<st<<" la "<<x<<" este "<<d[x]<<endl;
    while(x!=-1)
    {
        cout<<x<<" ";
        x=pred[x];
    }
    //BFS
  /* for(i=1;i<=n;i++)
        cout<<d[i]<<" ";*/

    return 0;
}
