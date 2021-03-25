#include <iostream>

using namespace std;
int a[1001][1001],n;
void color(int c,int i,int j)
{
    a[i][j]=c;
    if(a[i+1][j]==1&&i+1<n+1)
        color(c,i+1,j);
    if(a[i-1][j]==1&&i-1>0)
        color(c,i-1,j);
    if(a[i][j+1]==1&&j+1<n+1)
        color(c,i,j+1);
    if(a[i][j-1]==1&&j-1>0)
        color(c,i,j-1);
}
int main()
{
    int c,i,j;
    cin>>n;
    c=2;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            cin>>a[i][j];
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            if(a[i][j]==1)
                {color(c,i,j);c++;}
    for(i=1;i<=n;i++)
        {for(j=1;j<=n;j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
        }
    return 0;
}
/*
7
0 0 1 0 0 0 0
0 0 1 1 0 0 0
0 0 0 0 1 0 0
0 0 0 1 1 0 0
0 1 0 0 1 0 1
1 1 1 0 0 0 1
1 1 1 0 0 1 1
*/
