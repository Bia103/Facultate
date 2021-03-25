#include <iostream>

using namespace std;

int main()
{
    int m, n;
    //int a[n][m], b[n][m];
    cin >> n >> m;
    int a[n][m], b[n][m];
     for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            b[i][j] = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> a[i][j];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            {
                if(i == 0 && j == 0)
                    b[i][j] = a[0][0];
                else if(i == 0)
                    b[i][j] = a[i][j] + a[i][j-1];
                else if(j == 0)
                    b[i][j] = a[i][j] + a[i-1][j];
                else b[i][j] = a[i][j] + max(a[i-1][j],a[i][j-1]);
            }

    int p = n-1,q = m-1;
    while(p != 0 || q!=0)
    {
        cout << p+1<< " "<<q+1 <<endl;
        if(p-1>=0&&q-1>=0)
        {if(b[p-1][q] > b[p][q-1])
            p--;
        else q--;}
        else if(p-1<0)
            q--;
        else p--;
    }
    cout << p+1<< " "<<q+1 <<endl;
 for(int i = 0; i < n; i++)
        {for(int j = 0; j < m; j++)
        cout<<b[i][j]<<" ";
        cout <<endl;
        }
    return 0;
}
