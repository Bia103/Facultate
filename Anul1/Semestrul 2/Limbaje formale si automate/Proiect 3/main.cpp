#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
ifstream f("APD.txt");
char ok=0;
char st[1001],l[1];
struct APD
{
    char afn[255],scot[255],intro[255];

}a[1001][1001];
void bk(int q[],char v[],int x,int k,int n,int top)
{
    int i,j;
    for(i=0;i<=n;i++)
    {
        if(k<strlen(v))
           {//
            if(strchr(a[x][i].afn,v[k])||strchr(a[x][i].afn,l[1]))
            {//cout<<"afn="<<a[x][i].afn<<" ";
                char *p1=strtok(a[x][i].scot," ");
                char *p2=strtok(a[x][i].intro," ");
                char *p3=strtok(a[x][i].afn," ");
                while(p3!=NULL)
               {
                   char *p1=strtok(a[x][i].scot," ");
                char *p2=strtok(a[x][i].intro," ");
               while(p1!=NULL)
                {
                    if(p1[0]==st[top]&&p3[0]==v[k])
                        break;
                    p1=strtok(NULL," ");
                    p2=strtok(NULL," ");
                   //char *p1=strtok(a[x][i].scot," ");
                char *p2=strtok(a[x][i].intro," ");
                }
                 p3=strtok(NULL," ");
                }
                if(p1!=NULL)
                {
                    int d=strlen(p2)-1;
                    st[top]='0';
                   // cout<<" p2="<<p2<<endl;
                    while (d>=0)
                    {
                        //cout<<"Da";
                        st[top]=p2[d];
                        d--;
                        top++;
                    }
                    top--;
                   // for(int y=0;y<10;y++)
                    //    cout<<st[i]<<" ";
                    bk(q,v,i,k+1,n,top);
                }
            }
           }
        else
        {

                if(q[x])
                    {ok=1;}
        }
    }
}

int main()
{
    l[1]='l';
    int i=1,n,q[1001],x,fin,j,m,nr_m,nr_f;//q-vectorul care contine,nr_f-numar de stari finale
    f>>n>>nr_f;//numarul de stari
    // char a[n+1][n+1][255];//matricea care retine corespondenta intre stari
    cout<<"Numar de stari="<<n<<endl;
    cout<<"Numar de stari finale="<<nr_f<<endl;
    for(i=0; i<=n; i++)
        q[i]=0;//initializarea vectorului de stari finale cu 0
    // f>>fin;//numarul de stari finale
    cout<<"Stari finale: ";
    for(i=1; i<=nr_f; i++)
    {
        f>>x;
        cout<<x<<" ";
        q[x]=1;
    }
    f>>m;//numar de muchii
    cout<<endl<<"Numarul de muchii al AFN-ului: "<<m<<endl;
    for(i=1; i<=m; i++)
    {
        int u,p;
        f>>u>>p;
        int nr_c;
        //f>>nr_c;//numar de caractere de pe o muchie
        char c[255];
        f.get();
        cout<<"Muchie "<<u<<","<<p<<endl;//<<"Numar de caractere: "<<nr_c<<endl;
        f.get(c,255);
        cout<<c<<endl;
        f.get();
        strcat(a[u][p].afn,c);
         strcat(a[u][p].afn," ");
        f.get(c,255);
        f.get();
        strcat(a[u][p].scot,c);
        strcat(a[u][p].scot," ");
         f.get(c,255);
        f.get();
        strcat(a[u][p].intro,c);
        strcat(a[u][p].intro," ");
    }
    cout<<"Matricea ce se formeaza: "<<endl;
    for(i=0; i<=n; i++)
    {
        for(j=0; j<=n; j++)
            if(strcmp(a[i][j].afn,"\0"))
                cout<<a[i][j].afn<<" ";
            else
                cout<<"- ";
        cout <<endl;
    }
    cout<<endl;
      for(i=0; i<=n; i++)
    {
        for(j=0; j<=n; j++)
            if(strcmp(a[i][j].scot,"\0"))
                cout<<a[i][j].scot<<" ";
            else
                cout<<"- ";
        cout <<endl;
    }
     cout<<endl;
      for(i=0; i<=n; i++)
    {
        for(j=0; j<=n; j++)
            if(strcmp(a[i][j].intro,"\0"))
                cout<<a[i][j].intro<<" ";
            else
                cout<<"- ";
        cout <<endl;
    }
    char cuv[1001];
   // f.get();
    f.get(cuv,1001);
    cout<<"Cuvantul este: "<<cuv<<endl;
    f.get();
    int fs;
    f>>fs;
    cout<<"Starea initiala este :"<<fs<<endl;
    st[0]='z';
    bk(q,cuv,fs,0,n,0);
    if(ok&&!st[2])
        cout<<"Cuvant acceptat";
    else cout<<"Cuvant incompatibil";
    cout<<endl;
    for(int i=0;i<10;i++)
        cout<<st[i]<<" ";
    return 0;
}
//cabbbbbbbc
//cabbbabbbbc

