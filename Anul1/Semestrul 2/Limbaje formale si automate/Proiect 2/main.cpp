#include <iostream>
#include<fstream>
#include <cstring>
using namespace std;
ifstream f("AFN.txt");
char a[1001][1001][225],z[255],afd[1001][1001][225],coada[101][255];
int u1;
void afn_afd(int st,int m,int jm)
{
    int p;
    p=0;
    u1=0;
    coada[0][0]=st+'0';
    u1++;
    for(int i=0; i<jm; i++)
    {
        strcpy(afd[0][i],a[st][i]);
        int ok=1;
        for(int j=0; j<=u1; j++)
            if(strcmp(coada[j],a[st][i])==0)
                ok=0;
        if(ok)
        {
            strcpy(coada[u1],a[st][i]);
            u1++;
        }
    }
    /*for(int i=0;i<u;i++)
        cout<<coada[i]<<" ";*/
    p++;
    while(p<u1)
    {
       // ok1=1;
        //cout<<endl<<coada[p]<<" ";
        for(int i=0; i<strlen(coada[p]); i++)
        {
//cout<<"DWA ";
cout<<coada[p][i]<<" ";
            for(int k=0; k<strlen(z); k++)
            {
                //if(afd[p][k]==NULL)
                cout<<z[k]<<" ";
                cout<<k<<endl;
               // cout<<strlen(z);
                int ok1=1;
                for(int t=0; t<strlen(afd[p][k]); t++)
                    for(int r=0; r<strlen(a[coada[p][i]-'0'][k]); r++)
                        if(afd[p][k][t]==a[coada[p][i]-'0'][k][r])
                            ok1=0;
                if(ok1)
                    strcat(afd[p][k],a[coada[p][i]-'0'][k]);
                int ok2=1;
                if(strlen(a[coada[p][i]-'0'][k]))
                    do
                    {
                        ok2=1;
                        for(int t=0; t<strlen(afd[p][k])-1; t++)
                            if(afd[p][k][t]>afd[p][k][t+1])
                            {
                                char aux=afd[p][k][t];
                                afd[p][k][t]=afd[p][k][t+1];
                                afd[p][k][t+1]=aux;
                                ok2=0;//cout<<"Zbam";
                            }
                    }
                    while(ok2==0);
              //  else
                //    break;
//cout<<"afd["<<p<<"]"<<"["<<k<<"]="<<afd[p][k]<<endl;
                int ok=1;
                for(int t=0; t<u1; t++)
                {
                    if(strcmp(coada[t],afd[p][k])==0)
                        ok=0;
                }
                if(ok)
                {
                    strcpy(coada[u1],afd[p][k]);
                    u1++;
                }
            }

        }
        p++;
    }
    cout<<endl;
    cout<<"Coada:";
    for(int i=0; i<u1; i++)
        cout<<coada[i]<<" ";
}
int main()
{

    int n,q[101],i,nr_f,m;
    f>>n>>nr_f;//numarul de stari si numarul de stari finale
    cout<<"Stari finale: ";
    for(i=1; i<=nr_f; i++)
    {
        int x;
        f>>x;
        cout<<x<<" ";
        q[x]=1;
    }
    cout<<endl;
    // char z[255];
    f.get();
    f.get(z,255);
    f.get();
    char v[1001];
    for(int i=1; i<=strlen(z); i++)
        v[i]=z[i-1];
    f>>m;//numar de muchii
    char u[255],p[255],c[255];
    cout<<z;
    for(int i=0; i<m; i++)
    {
        //  char
        f>>u>>p>>c;
        //cout<<u<<" "<<p<<" "<<c<<endl;
        for(int j=0; j<strlen(z); j++)
            if(c[0]==z[j])
            {
                //int r=u[0]-'0';
                strcat(a[u[0]-'0'][j],p);
                break;
            }

    }
    cout<<endl<<" ";
   /* for(int j=1; j<=strlen(z); j++)
        cout<<v[j]<<" ";*/
    cout<<endl;
    for(i=0; i<n; i++)
    {
        cout<<i<<" ";
        for(int j=0; j<strlen(z); j++)
            if(strcmp(a[i][j],"\0"))
                cout<<a[i][j]<<" ";
            else
                cout<<"- ";
        cout <<endl;
    }
    int st;
    f>>st;
    cout<<"Starea initiala este :"<<st<<endl;
    afn_afd(st,m,strlen(z));
    int j=0;
    cout<<endl<<"     ";
    for(int j=1; j<=strlen(z); j++)
        cout<<v[j]<<"     ";
cout<<endl;int ok=0;
    for( i=0;i<u1;i++)
    {ok=0;
        cout<<coada[j];
        if(coada[j])
            ok=1;
        if(ok==1)
        {for(int t=0;t<5-strlen(coada[j]);t++)
            cout<<" ";
        j++;
        for(int t=0;t<strlen(z);t++)
          {
              if(strlen(afd[i][t]))
              {cout<<afd[i][t];
              for(int t=0;t<5-strlen(afd[i][t]);t++)
                    cout<<" ";
              }
              else cout<<"-    ";
          }
        cout<<endl;}
    }
    return 0;
}
