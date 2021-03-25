#include <iostream>
#include<list>
using namespace std;

int main()
{
    int x;
    //citirea listei
    list<int>L;
    do
    {

        cin>>x;
        if(x!=0)
            if(x%2==0)
                L.push_back(x);// pune in spate
            else
                L.push_front(x);// pune in fata
    }
    while(x!=0);
    for(list<int>::iterator it=L.begin(); it!=L.end(); it++)
        cout<<*it<<' ';
    return 0;
}
