#include <iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<fstream>
#include<list>
#include<set>
using namespace std;

int main()
{
    int m, n;
    list <int>L[100];
    cin >> n >> m;                      // se cinteste numarul de noduri si cel de muchii
    set<pair<int,int> >Q;               // de creeaza un set in care se va pune numarul de vecini ai unui nod si eticheta acestuia
    set<int>S;                          // se concepe un set in care o sa fie solutia
    for(int i = 0; i < m; i++)          // se citesc muchiile si se face o lista de vecini petru fiecare nod
    {
        int x, y;
        cin >> x >> y;
        L[x].push_back(y);
        L[y].push_back(x);
    }
    for(int i = 1; i <= n;i++)
        Q.insert({L[i].size(),i});      // se insereaza in Q numarul de vecini si eticheta pentru fiecare nod
    while(Q.size() > 0)
    {
        S.insert(Q.begin()->second);    // se insereaza in lista solutiilor primul nod, deoarece acesta are cei mai putini vecini si nu a fost sters pana acum
        int x = Q.begin()->second, y = L[Q.begin()->second].size(); // se retine in x eticheta nodului ce este solutie
        Q.erase(Q.begin());             // se sterge inceputul setului deorece l-am inserat deja in lista de solutii corecte, deci e inutil
        for(auto it : L[x])             // se parcurge lista vecinilor nodului care a fost sters si sunt eliminati din lista vecinii acestuia
            Q.erase({L[it].size(),it});

    }
    for(auto it : S)                    // se afiseaza liata solutiilor corecte
        cout << it <<" ";
    return 0;
}
/*
8 7 1 2 1 3 2 4 2 5 3 6 3 7 5 8
*/
