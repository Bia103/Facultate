#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
ifstream f("AFN.txt");
char a[1001][1001][255],ok=0;
void bk(int q[],char v[],int x,int k,int n)
{
    int i,j;
    for(i=0;i<=n;i++)
    {
        if(k<strlen(v))
           {
            if(strchr(a[x][i],v[k]))
                bk(q,v,i,k+1,n);
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
        strcpy(a[u][p],c);
    }
    cout<<"Matricea ce se formeaza: "<<endl;
    for(i=0; i<=n; i++)
    {
        for(j=0; j<=m; j++)
            if(strcmp(a[i][j],"\0"))
                cout<<a[i][j]<<" ";
            else
                cout<<"0 ";
        cout <<endl;
    }
    char cuv[1001];
   // f.get();
    f.get(cuv,1001);
    cout<<"Cuvantul este: "<<cuv<<endl;
    f.get();
    int st;
    f>>st;
    cout<<"Starea initiala este :"<<st<<endl;
    bk(q,cuv,st,0,n);
    if(ok)
        cout<<"Cuvant acceptat";
    else cout<<"Cuvant incompatibil";
    return 0;
}
//cabbbbbbbc
//cabbbabbbbc
