#include <iostream>
using namespace std;
void SumaCastigatoare(int *a, int n)
{
    int sumi = 0,sump = 0,s;        // se initializeaza suma numerelor impare, respectiv pare cu 0
    for(int i = 0;i < n; i++)       // se face suma numerelor pare si respectiv impare
        if(i % 2 == 0)
            sump = sump + a[i];
        else sumi = sumi + a[i];
    if(sump > sumi)                 // daca suma parelor este mai mare decat cea a imparelor, player 1 va colecta numai numerele pare, altfel numai cea a imparelor
        s = 0;
    else s = 1;
    for (int i = s; i < n; i += 2)
        cout << a[i] << " ";
}
int main()
{
    int n;
    cin >> n;
    int *a = new int[n];
    for(int i = 0; i < n; i++)      // se citeste tabla de joc
        cin >> a[i];
    SumaCastigatoare(a,n);
    return 0;
}
