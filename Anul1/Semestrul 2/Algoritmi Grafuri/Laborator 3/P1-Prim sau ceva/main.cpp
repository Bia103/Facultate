#include <iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<fstream>
#include<list>
using namespace std;
ifstream fin("date.in");
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
    //sort(S.begin(),S.end());
    merge(S.begin(),S.begin()+n-d,S.begin()+n-d,S.end(),man.begin());
    for(i=0;i<n;i++)
        S[i]=man[i];
    }
       // for(pair<char,char>p.E)
    for(auto p:S)
        {
           cout<< p.first<<" "<<p.second<<endl;
        }
    /*merge(S.begin(),S.begin()+n-d,S.begin()+n-d,S.end(),man.begin());
    for(i=0;i<n;i++)
        S[i]=man.i;
    for(i=0;i<n;i++)
        cout<<S[i].second<<" "<<S[i].first<<"\n";*/
    return 0;
}
