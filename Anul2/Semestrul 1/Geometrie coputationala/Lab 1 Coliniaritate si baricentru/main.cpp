#include <iostream>
using namespace std;
struct punct
{
    float xi, yi, zi;
};
int egalitate(punct a, punct b)
{
    if(a.xi == b.xi && a.yi == b.yi && a.zi == b.zi) return 1;
    return 0;
}
punct vect (punct a, punct b)
{
    punct c;
    c.xi = b.xi - a.xi;
    c.yi = b.yi - a.yi;
    c.zi = b.zi - a.zi;
    return c;
}
int main()
{
    float a;
    punct A1, A2, A3, A1A3, A1A2;
    cout << "Coordonatele punctului 1"<< endl;
    cin >> A1.xi >> A1.yi >> A1.zi;
    cout << "Coordonatele punctului 2"<< endl;
    cin >> A2.xi >> A2.yi >> A2.zi;
    cout << "Coordonatele punctului 3"<< endl;
    cin >> A3.xi >> A3.yi >> A3.zi;
    A1A3 = vect(A1, A3);
    A1A2 = vect(A1, A2);
    if(egalitate(A1, A2))
        cout << "Punctele sunt coliniare si A2 = 1*A1 + 0*A3";
    else
        if(egalitate(A1, A3))
        cout << "Punctele sunt coliniare si A1 = 1*A3 + 0*A2";
    else
        if(egalitate(A2, A3))
        cout << "Punctele sunt coliniare si A2 = 1*A3 + 0*A1";
    else
    {
        if(A1A2.xi)
           {
                a = A1A3.xi / A1A2.xi;
                if(A1A3.yi == a*A1A2.yi && A1A3.zi == a*A1A2.zi)
                    cout << "Punctele sunt coliniare si A3 = " << 1-a << "*A1 +" << a << "A2";
                else cout << "Punctele nu sunt coliniare.";
           }
        else
        if(A1A2.yi)
           {
                a = A1A3.yi / A1A2.yi;
                if(A1A3.xi == a*A1A2.xi && A1A3.zi == a*A1A2.zi)
                    cout << "Punctele sunt coliniare si A3 = " << 1-a << "*A1 +" << a << " A2";
                else cout << "Punctele nu sunt coliniare.";
           }
        else
        if(A1A2.zi)
           {
                a = A1A3.zi / A1A2.zi;
                if(A1A3.xi == a*A1A2.xi && A1A3.yi == a*A1A2.yi)
                    cout << "Punctele sunt coliniare si A3 = " << 1-a << "*A1 +" << a << " A2";
                else cout << "Punctele nu sunt coliniare.";
           }
    }
    return 0;
}

/*#include <iostream>

using namespace std;

int main()
{
    float a[3],b[3],c[3];
    float r;
    cin >> a[0] >> a[1] >> a[2];
    cin >> b[0] >> b[1] >> b[2];
    cin >> c[0] >> c[1] >> c[2];
    if(a[0]==b[0] && a[1]== b[1] && a[2] == b[2])
    {
        cout << "Coliniare, iar o combinatie afina este A2=A1" ;
        return 0;
    }
    if(a[0]==c[0] && a[1]== c[1] && a[2] == c[2])
    {
        cout << "Coliniare, iar o combinatie afina este A2=A1" ;
        return 0;
    }
    if(c[0]==b[0] && c[1]== b[1] && c[2] == b[2])
    {
        cout << "Coliniare, iar o combinatie afina este A2=A1" ;
        return 0;
    }

    //if(b[1]-a[1] != 0 && b[2]-a[2] != 0 && b[0]-a[0] != 0)
   // { //cout<<(c[1]-a[1])/(b[1]-a[1])<<" "<< ((c[2]-a[2])/(b[2]-a[2])) <<" " << (c[0]-a[0])/(b[0]-a[0]);
    float x=0,y=0,z=0;
    if(b[0]-a[0]!=0)
        x=(c[0]-a[0])/(b[0]-a[0]);
     if(b[1]-a[1]!=0)
        y=(c[1]-a[1])/(b[1]-a[1]);
     if(b[2]-a[2]!=0)
        z=(c[2]-a[2])/(b[2]-a[2]);
    cout<<x<<" "<<y<<" "<<z;
    if(x!=0 &&y!=0&&z!=0)
   {

     if(x==y&&y==z)
       {
        r =  (c[1]-a[1])/(b[1]-a[1]);
      cout<< "\nColiniare";
       }
    else cout<<"Nu";
       }
    else if(x!=0&&y!=0)
       {
           if(x==y)
           {r =  (c[1]-a[1])/(b[1]-a[1]); cout<< "\nColiniare";}
           else cout<<"Nu";
       }
     else if(x!=0&&z!=0)
       {
           if(x==z)
           {r =  (c[0]-a[0])/(b[0]-a[0]); cout<< "\nColiniare";}
           else cout<<"Nu";
       }
    else if(y!=0&&z!=0)
       {
           if(z==y)
           {r =  (c[2]-a[2])/(b[2]-a[2]); cout<< "\nColiniare";}
           else cout<<"Nu";
       }
    else if(x!=0)
        {r =  (c[0]-a[0])/(b[0]-a[0]);  cout<< "\nColiniare";}
    else if(y!=0)
        { r =  (c[1]-a[1])/(b[1]-a[1]); cout<< "\nColiniare";}
     else if(z!=0)
        {
            r =  (c[2]-a[2])/(b[2]-a[2]);  cout<< "\nColiniare";
        }

    else{
        cout<<"Nu";
        return 0;
    }
    cout<<"\nAlpha = "<<  r << "\nB = "<< 1-r;
    /*    if(b[1]-a[1] == 0  )
    {
        if(b[2]-a[2] == 0)
            {
                if(b[0]-a[0] == 0)
                    cout << "??? Nu cred ca sunt coliniare";
                else cout<<"Coliniare";
            }
         else if(b[0]-a[0] == 0)
          {
              if(b[2]-a[2] == 0)
                    cout << "??? Nu cred ca sunt coliniare";
                else {cout<<"Coliniare";
               r= (c[1]-a[1])/(b[1]-a[1])
                }
          }
        else if(((c[1]-a[1])/(b[1]-a[1])) == ((c[0]-a[0])/(b[0]-a[0])))
               {
                   cout<<"Coliniare";
                   r=(c[1]-a[1])/(b[1]-a[1]);
               }


        return 0;
1 2 3
2 4 6
4 8 12
0 2 0
0 3 0
0 4 0
    }*/
//    return 0;
//}
