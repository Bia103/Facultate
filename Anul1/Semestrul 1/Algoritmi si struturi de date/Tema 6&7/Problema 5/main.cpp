#include <iostream>

using namespace std;
int n,a[3],v[1001],c[1001],m,mx;
/*void numarare()
{
    int i;
    cout<<a[0]<<" "<<a[1]<<endl;
    a[1]=a[1]+a[0];

    for(i=1; i<=n; i++)
    {
        if((v[i]&m))
        {
            c[a[1]]=v[i];
            a[1]--;
        }
        else
        {
            c[a[0]]=v[i] ;
            a[0]--;
        }
        // a[v[i]]--;
    }

    for(i=1; i<=n; i++)
        v[i]=c[i];
}*/
void radix()
{
    int i,j,i0,i1,a0[1001],a1[1001];
    for(i=1; i<=30; i++)
    {

        i0=0;
        i1=0;
        for(j=1;j<=n;j++)
        {
            a0[j]=0;
            a1[j]=0;
        }
        //cout<<m<<endl;
        for(j=1; j<=n; j++)
        {

   //   int x=(v[j]&&m);
     // cout<<v[j]<<" ";
            if((v[j]&m)==0)
            {
                i0++;
                a0[i0]=v[j];
            }
            else
            {
                i1++;
                a1[i1]=v[j];
                //cout<<"Da0";
            }  }
           // cout<<endl;
       // numarare();
        m=(m<<1);
        int p=1;

        for(j=1;j<=i0;j++)
           {
               v[p]=a0[j];
               p++;
           }
        for(j=1;j<=i1;j++)
            {v[p]=a1[j];p++;}
       /* for(j=1;j<=n;j++)
            cout<<v[j]<<" ";
        cout<<endl;*/
    }
}
int main()
{
    int i;
    cin>>n;
    m=1;
    for(i=1; i<=n; i++)
    {
        cin>>v[i];
    if(v[i]>mx)
        mx=v[i];
    }
    radix();
    for(i=1; i<=n; i++)
        cout<<v[i]<<" ";
    return 0;
}
/*
3
17 3 12
*/
