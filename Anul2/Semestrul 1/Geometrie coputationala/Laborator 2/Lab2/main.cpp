#include <iostream>
#include <vector>
using namespace std;

struct punct
{
    double x, y;
}A[4];


int orientare(punct a, punct b, punct c)
{
    int val=(b.y-a.y)*(c.x-b.x) - (b.x-a.x)*(c.y-b.y);
    if(val==0) return 0;
    if(val>0) return 1;
    return 2;
}

int main()
{


    int i;
    for(i=0; i<4; i++)
        cin >> A[i].x >> A[i].y;
    vector<int> v;
    int mi=A[0].x, l=0, mx=A[0].x, r=0;
    for(i=1; i<4; i++)
    {
        if(mi>A[i].x)
            mi=A[i].x, l=i;
        if(mx<A[i].x)
            mx=A[i].x, r=i;
    }
    if(l==r)
    {
        mx=A[0].y;
        for(i=1; i<4; i++)
            if(mx<A[i].y)
                mx=A[i].y, r=i;
    }

    int p=l, b;
    do
    {
        v.push_back(p);
        if(p!=0) b=0;
        else b=1;

        for(i=0; i<4; i++)
            if(orientare(A[p], A[b], A[i])==2)
                b=i;

        p=b;
    }while(l!=p);

    int poz;
    if(v.size()==2)
    {
        cout<<"I: ("<<A[l].x<<","<<A[l].y<<"); (";
        cout<<A[r].x<<","<<A[r].y<<")"<<endl;
        cout<<"J: (";
        for(i=0; i<4; i++)
            if(i!=l && i!=r) cout<<A[i].x<<","<<A[i].y<<"); (";
    }
    else if(v.size()==3)
    {
        cout<<"I: ("<<A[l].x<<","<<A[l].y<<"); (";
        poz=v[1];
        cout<<A[poz].x<<","<<A[poz].y<<"); (";
        poz=v[2];
        cout<<A[poz].x<<","<<A[poz].y<<")"<<endl;
        cout<<"J: (";
        for(i=0; i<4; i++)
            if(i!=v[0] && i!=v[1] && i!=v[2]) cout<<A[i].x<<","<<A[i].y<<")"<<endl;
    }
    else
    {
        cout<<"I: (";
        poz=v[0];
        cout<<A[poz].x<<","<<A[poz].y<<"); (";
        poz=v[2];
        cout<<A[poz].x<<","<<A[poz].y<<");"<<endl;
        cout<<"J: (";
        poz=v[1];
        cout<<A[poz].x<<","<<A[poz].y<<"); (";
        poz=v[3];
        cout<<A[poz].x<<","<<A[poz].y<<");"<<endl;
    }


    return 0;
}
