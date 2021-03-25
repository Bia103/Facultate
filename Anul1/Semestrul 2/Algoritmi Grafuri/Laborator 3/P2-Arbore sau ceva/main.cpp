#include <iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<fstream>
#include<list>
#include<queue>
using namespace std;

int main()
{
    int n,i,j;
    char x,y;
    ifstream fin("date.in");
    vector<int>v;
    queue <char> T,NT;
    list<pair<char,char > > E;
    fin>>n;
    v.resize(n);
    int S=0;
    for(i=0;i<n;i++)
    {
        fin>>v[i];
        S+=v[i];
        if(v[i]<1)
        {
            cout<<"Nu";
            return 0;
        }
        else if(v[i]==1)
            T.push('A'+i);
        else NT.push('A'+i);
    }
    if(S!=2*(n-1))
    {
        cout<<"Nu";
        return 0;
    }
    if(!NT.empty())
    {
        x=NT.front();
        y=T.front();
        T.pop();
        v[x-'A']--;
        if(v[x-'A']==1)
        {
            NT.pop();
            T.push(x);
        }
        E.push_back({x,y});
    }
    x=T.front();
    T.pop();
    y=T.front();
    E.push_back({x,y});
    return 0;
}
