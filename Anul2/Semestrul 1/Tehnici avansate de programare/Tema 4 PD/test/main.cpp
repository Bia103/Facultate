#include <iostream>
#include<vector>
using namespace std;

int main()
{
    vector< pair<int,int> >  piese;
    int** lant;
    int n,i,j,l,x,y;

    cin>>n;
    lant = new int*[n];
    for( i = 0; i < n; i++)
    {
        lant[i] = new int[n];

        cin>>x>>y;
        piese.push_back(make_pair(x,y));
    }

    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            lant[i][j] = 1;

    for( j=0; j<n-1; j++)
        for(i=j+1; i<n; i++)
            for(l=j; l<i; l++)
                if(piese[l].second == piese[i].first)
                    lant[i][j] = max(lant[i][j], lant[l][j]+1);
    int mx = 0,i1,j1,nr = 0;
    for(i=0; i<n; i++)
    {
        for(j=0; j<=i; j++)
        {

            if(lant[i][j] > mx)
            {
                mx = lant[i][j];
                i1 = i;
                j1 = j;
                nr = 1;
            }
            else if(lant[i][j] == mx && j==0)
                nr++;
        }
    }
    cout<<endl;
    for(int p = 0; p < n;p++)
    {
        for(int u = 0; u < n;u++)
            cout << lant[p][u] <<" ";
        cout<<endl;
    }
    while(mx)
    {
        if(mx == lant[i1][0])
        {
            cout << piese[i1].first <<" "<< piese[i1].second<<endl;
            mx--;
        }
        for(i = i1 - 1; i >= 0; i--)
        {
            if(piese[i].second == piese[i1].first && mx == lant[i][0])
            {
                i1 = i;
                break;
            }
        }
    }
    cout << "\nNumarul de lanturi de lungime maxima = " << nr;

}
