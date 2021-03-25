#include <iostream>
using namespace std;

int varf(int a[], int s, int d, int n)
{

    int m = (d + s)/2;
    if ((m == 0 || a[m - 1] <= a[m]) && (m == n - 1 || a[m + 1] <= a[m]))
        return a[m];
    else if (m > 0 && a[m - 1] > a[m])
        return varf(a, s, (m - 1), n);
    else return varf(a, (m + 1), d, n);
}
int main()
{
    int n;
    cin >> n;
    int *a = new int[n];
    for(int i = 0;i < n;i++)
        cin >> a[i];
    cout << varf(a, 0, n - 1, n);
    return 0;
}

