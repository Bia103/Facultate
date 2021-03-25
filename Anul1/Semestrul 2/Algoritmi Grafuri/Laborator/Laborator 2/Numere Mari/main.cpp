#include <iostream>
#include <cstring>
using namespace std;
class BigInt
{
    int *a,n;
    BigInt *next;
public:
    BigInt(char s[])
    {
        int i=0;
        n=strlen(s);
        a=new int[strlen(s)+1];
        for(i=0;i<strlen(s);i++)
            a[i]=s[strlen(s)-i-1]-'0';
    }
    Show()
    {
        for(int i=0;i<n;i++)
            cout<<a[i]<<" ";
    }
    int Suma()
    {
        int s=0;
        for(int i=0;i<n;i++)
            s=s+a[i];
        return s;
    }
};

int main()
{

    BigInt p("12345");
    p.Show();
    cout<<endl;
    cout<<p.Suma();
    return 0;
}
