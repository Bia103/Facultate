#include<iostream>
#include<algorithm>
#include <vector>
using namespace std;
/*
Corectitudinea
    Demonstrăm prin inducție, după n, că algoritmul construiește o soluție optimă.
    Un algoritm optim gaseste numarul minim de sali de care este nevoie prin gasirea unui interval comun ce este inclus in numarul de multimi date.
Cu cat mai multe sunt acele multimi cu un interval comun, cu atat creste si numarul de sali de care este nevoie.
    Algoritmul greedy sorteaza salile in functie de ora la care incepe activitatea si incearca sa determine un punct comun in toate intervalele, iar
acesta va coincide cu numarul salilor de care este nevoie.
*/
int main()
{
	vector <pair<int,pair<int,int> > >v;
	int n;
	cin >> n;
	for (int i = 1;i < n; i++)
    {
        int x,y;
        cin >> x >> y;
        v.push_back({x,{y,i}});
        //v[i].first = i;
    }
    int s = 0,sf = 0;
    sort(v.begin(),v.end());
    int i = 1, j = 0;
    while(i < n && j < n)
    {
        if(v[i].first <= v[j].second.first)
        {
            s++;
            i++; v[i].second.second=s;
            if(s>sf)
                sf = s;
        }
        else
        {
            s--;
            j++;
        }
    }
    cout << sf<<endl;
    for(i=0;i<n-1;i++)
        cout<< v[i].first <<" "<< v[i].second.first<<" "<<v[i].second.second<<endl;
	return 0;
}
/*
4
10 14
12 16
15 18
*/
