#include <iostream>

using namespace std;
int st=1,a[1001],n;
void heap(int n,int i)
{
    int mi=i,st=2*i+1,dr=2*i+2;
    if(st<n &&a[st]<a[mi])
        mi=st;
    if(dr<n&&a[dr]<a[mi])
        mi=dr;
    if(i!=mi)
    {
        swap(a[i],a[mi]);
        heap(n,mi);
    }
}
int sterg_min()
{
    if(n==0)
           return a[0];
    else
    {
        int x=a[0];
        a[0]=a[n-1];
        n--;
        heap(n,0);
        return x;
    }

}
void ins(int &n,int x)
{
    int i=n;
    a[i]=x;
    n++;

    //if(st==1)
    while(i!=0&&a[(i-1)/2]>a[i])
    {
        swap(a[i],a[(i-1)/2]);
        i=(i-1)/2;
    }
}
int main()
{
    int i,x,y;
//cout<<INT_MAX;
   do
   {    cin>>y;
       if(y==1)
        {
            cin>>x;
            ins(n,x);

        }
     /*  if(y==2)
        {

            cout<<"A fost sters:"<<sterg_min();
        }
*/
   }while(y!=0);
   for(i=0;i<=n-1;i++)
    cout<<a[i]<<" ";
    cout<<endl;
    cout<<sterg_min();
   /*  for(i=0;i<=n-1;i++)
    cout<<a[i]<<" ";cout<<endl;
    cout<<sterg_min();
     for(i=0;i<=n-1;i++)
    cout<<a[i]<<" ";cout<<endl;
    cout<<sterg_min();
     for(i=0;i<=n-1;i++)
    cout<<a[i]<<" ";cout<<endl;*/
    return 0;
}
/*
1 1
1 9
1 0
1 2
1 8
1 3
1 12
0
*/
