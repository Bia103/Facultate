#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <math.h>
using namespace std;

int main()
{
    ifstream f1("f1.txt");
    ifstream f2("f2.txt");
    vector<pair<char*,int> > v1, v2;
    char s1[255],s2[255];
    f1.get(s1,255);
    f2.get(s2,255);
    //cout<<s1<<" * "<<s2;
    char *p1 = strtok(s1," ");
    // char *p2 = strtok(s2," ");
    int n=0;
    float s=0,sum1=0,sum2=0;
    while (p1)
    {

        int i=0,ok=1;
        while(i<n)
        {
            if(strcmp(v1[i].first,p1)==0)
            {
                ok=0;
                v1[i].second++;
            }
            i++;
        }
        if(ok)
        {
            n++;
            v1.resize(n);
            v1[i].first= new char(255);
            strcpy(v1[i].first,p1);//cout<<"Nu iar...";
            v1[i].second++;
        }
        p1 = strtok(NULL," ");
    }
    for(int i=0; i<n; i++)
       {
           cout<<v1[i].first<<" "<<v1[i].second<<endl;
           sum1 = sum1 + v1[i].second*v1[i].second;

       }
    int m=0;
          char *p2 = strtok(s2," ");
    while (p2)
    {

        int i=0,ok=1;
        while(i<m)
        {
            if(strcmp(v2[i].first,p2)==0)
            {
                ok=0;
                v2[i].second++;
            }
            i++;
        }
        if(ok)
        {
            m++;
            v2.resize(m);
            v2[i].first= new char(255);
            strcpy(v2[i].first,p2);//cout<<"Nu iar...";
            v2[i].second++;
        }
        p2 = strtok(NULL," ");
    }
    cout<<endl;
    for(int i=0; i<m; i++)
        {
            cout<<v2[i].first<<" "<<v2[i].second<<endl;
            sum2 = sum2 + v2[i].second*v2[i].second;
        }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m;j++)
            if (strcmp(v1[i].first,v2[j].first)==0)
                s = s + v1[i].second*v2[j].second;

    }
    cout<<endl<<s/((sqrt(sum1))*sqrt(sum2));
    return 0;
}
