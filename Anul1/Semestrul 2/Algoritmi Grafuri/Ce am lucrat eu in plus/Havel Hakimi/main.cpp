/*#include <iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<fstream>
#include<list>
using namespace std;
ifstream fin("hakimi.in");
int n,i,j,x;
vector <pair<int,char> >S,man;
list<pair<char,char > > E;
int main()
{
    fin>>n;
    S.resize(n);
    for(i=0;i<n;i++)
    {
        fin>>x;
        if(x<0||x>=n)
        {
            cout<<"Nu";
            return 0;
        }
        S[i]={x,'A'+i};
    }
    sort(S.begin(),S.end());
    for(i=0;i<n;i++)
        cout<<S[i].second<<" "<<S[i].first<<"\n";
    cout<<endl;
    while(S[n-1].first>0)
    {
        int d=S[n-1].first;
        char et=S[n-1].second;
        S.pop_back();
        n--;
        for(i=1;i<=d;i++)
        {
            S[n-i].first--;
            E.push_back({et,S[n-i].second});
            if(S[n-i].first<0)
            {
                cout<<"Nu";
                return 0;
            }
        }
    sort(S.begin(),S.end());cout<<"Da";
    //merge(S.begin(),S.begin()+n-d,S.begin()+n-d,S.end(),man.begin());
   // for(i=0;i<n;i++)
    //    S[i]=man[i];
    }
       // for(pair<char,char>p.E)
       //cout<<"Da";
    cout<<endl;
    for(auto p:E)
        {
           cout<< p.first<<" "<<p.second<<endl;
        }
    /*merge(S.begin(),S.begin()+n-d,S.begin()+n-d,S.end(),man.begin());
    for(i=0;i<n;i++)
        S[i]=man.i;
    for(i=0;i<n;i++)
        cout<<S[i].second<<" "<<S[i].first<<"\n";
    return 0;
}
*/
#include<iostream>
#include<utility>
#include<algorithm>
#include<list>
#include<fstream>
using namespace std;
list <pair<char,char> >E;
vector<pair<int,char > >S;
int i,n,x;
ifstream fin("hakimi.in");
int main()
{
    fin>>n;
    S.resize(n);
    for(i=0;i<n;i++)
    {
        fin>>x;
        if(x<0 || x>=n)
        {
            cout<<"Imposibil";
            return 0;
        }
        S[i]={x,i+'A'};
    }
    sort(S.begin(),S.end());
    for(auto p:S)
        cout<<p.first<<" "<<p.second<<"\n";
    while(S[n-1].first>0)
    {
        int y = S[n-1].first,i;
        char c = S[n-1].second;
        n--;
        for(i=1; i <=y; i++)
        {
            S[n-i].first--;
            E.push_back({c,S[n-i].second});
            if(S[n-i].first<0)
            {
                cout<<" Imposibil";
                return 0;
            }
        }
        sort(S.begin(),S.end());
    }
    cout<<endl;
    for(auto p:E)
        cout<<p.first<<" "<<p.second<<"\n";
    return 0;
}
