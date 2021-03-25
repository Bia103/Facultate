#include <iostream>
#include <vector>
#include <list>
using namespace std;
list <char> NT,T;
vector<int> v;
list<pair<char,char> >E;
int main()
{
    int n,i,s=0;
    cin>>n;
    v.resize(n);
    for(int i=1;i<=n;i++)
    {
        cin>>v[i];
        if(v[i]<=0 || v[i]>=n)
        {
            cout<<" Nu";
            return 0;
        }
        s=s+v[i];
        if(v[i]==1)
            T.push_back('A'+i);
        else NT.push_back('A'+i);
    }//cout<<"Da";
    if(s!=(n-1)*2)
    {
        cout<<"Imposibil";
        return 0;
    }
    while(!NT.empty())
    {
        char x=NT.front();
        char y=T.front();
        T.pop_front();
        v[x-'A']--;
        if(v[x-'A']==1)
        {
            NT.pop_front();
            T.push_back(x);
        }
        E.push_back({x,y});
    }
    char x=T.front();
    T.pop_front();
    char y=T.front();
    E.push_back({x,y});
    for(auto p:E)
        cout<<p.first<<" "<<p.second<<"\n";
    return 0;
}
