#include <iostream>
#include <cstring>
using namespace std;
char v[101][50];
void inserare(char v[][50],char s[])
{
    int ok=0,i=1;

    while(ok==0)
    {
        if(strlen(v[i])==0)
           {//cout<<"Da";
               strcpy(v[i],s);
               ok=1;
           }
        else if(strcmp(v[i],s)<0)
        {
            i=2*i+1;
        }
        else i=i*2;
    }
}
void SRD(char v[][50],int i)
{
 if(strlen(v[i])!=0)
    {SRD(v,i*2);

    cout<<v[i]<<" ";
    SRD(v,i*2+1);}
}
int main()
{
    char s[50];
    int n;
    cin>>n;
    cin.get();
    /* for(int i=1;i<=n;i++)
        strcpy(v[i],NULL);*/
    for(int i=1;i<=n;i++)
    {
        cin.get(s,50);
        cin.get();
        inserare(v,s);
    }
    SRD(v,1);
   /* for(int i=1;i<n;i++)
    {
        cout<<v[i]<<" ";
    }
    //cout<<v[7];*/
    return 0;
}
/*
4
portocaliu
rosu
albastru
verde

*/
