#include <iostream>
#include<cmath>
using namespace std;
class Punct
{
    int x,y;
public:
    Punct(int,int);
    Punctc(Punct &);
    float distanta(Punct);
    float dis_centru();
    int cadran();
};
Punct::Punct(int x=0,int y=0)
{
    cout<<"Punctul a fost construit"<<endl;
    this->x=x;
    this->y=y;
}
Punct::Punct(Punct &a)
{
    cout<<"Punctul a fost copiat"<<endl;
    x=a.x;//practic avem a si b si daca vrem sa copiam din a in b apelam pt b.punct(a) gen
    y=a.y;
}
float Punct::distanta(Punct p)
{
    float xp=pow(x-p.x,2);//practic e un punct diferit, gen daca avem a si b si apelam pentru a, atunci la apel intre() va fi b si p.x=b.x
    float yp=pow(y-p.y,2);
    return sqrt(xp+yp);
}
int Punct::cadran()
{
    if(x>0&&y>0)
        return 1;
    if(x<0&&y>0)
        return 2;
    if(x<0&&y<0)
        return 3;
    if(x>0&&y<0)
        return 4;
    return -1;
}
int main()
{
    Punct a(3, 3),b;

    //a.Punct(3,3);
    return 0;
}
