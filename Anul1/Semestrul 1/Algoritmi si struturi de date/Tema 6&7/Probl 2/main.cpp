#include <iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;
int v[1001];
int part(int v[],int p,int u)
{
    srand(time(NULL));
    // srand(time(NULL));
    int nim=p+rand()%(u-p);
    // swap(v[nim],v[p]);
    //cout<<nim<<endl;
    return nim;
}
void quickSort(int v[], int p, int u)
{

    int i=p, j=u;
    int aux;
    int pivot=v[part(v,p,u)];
    while(i<=j)
    {
        while (v[i]<pivot)
            i++;
        while (v[j]>pivot)
            j--;

        if (i <= j)
        {
            aux=v[i];
            v[i]=v[j];
            v[j]=aux;
            i++;
            j--;
            }
        }
    if (p<j)
        quickSort(v,p,j);
    if (i<u)
        quickSort(v,i,u);

}


int main()
{
    int n,i;
    cin>>n;
    for(i=0; i<n; i++)
        cin>>v[i];
    quickSort(v,0,n-1);
    for(i=0; i<n; i++)
        cout<<v[i]<<" ";
    return 0;

}
/*
7
34 5 2 1 89 105 40
*/
