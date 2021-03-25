#include <iostream>

using namespace std;
struct Punct
{
    float x, y;
};
bool apartine(Punct a, Punct A, Punct B)
{
    if( a.x <= max(A.x, B.x) && a.x >= min(A.x, B.x) && a.y <= max(A.y, B.y) && a.y >= min(A.y, B.y) )
        return true;
    return false;

}
int main()
{
    Punct *a = new Punct[5];
    for(int i = 0; i <= 3; i++)
        cin >> a[i].x >> a[i].y;
    float a1, b1, c1, a2, b2, c2;

    a1 = a[0].y - a[1].y;
    b1 = a[1].x - a[0].x;
    c1 = a[0].x*a[1].y - a[1].x*a[0].y;

    a2 = a[2].y - a[3].y;
    b2 = a[3].x - a[2].x;
    c2 = a[2].x * a[3].y - a[3].x * a[2].y;

    float l = a1 * b2 - a2 * b1;

    if(l != 0)
    {
        int x, y;
        x = ((-c1) * b2 + c2 * b1) / l;
        y = ((-c2) * a1 + c1 * a2) / l;
        Punct p;
        p.x = x;
        p.y = y;
        if(apartine(p,a[0],a[1]) && apartine(p,a[2],a[3]))
            cout << "Segmentele se intersecteaza in: (" << p.x << " , " << p.y << ")/n";
        else cout << "Segmentele nu se intersecteaza";
        return 0;

    }
    else
    {
        if((a1 * c2 - a2 * c1 == 0) && (a1 * c2 - a2 * c1 == 0))
        {
            if(apartine(a[2],a[0],a[1]))
                  cout << "Segmentele se intersecteaza in: (" << a[2].x << " , " << a[2].y <<")(" << a[1].x << " , " << a[1].y << ")\n";
            else if(apartine(a[3],a[0],a[1]))
                  cout << "Segmentele se intersecteaza in: (" << a[3].x << " , " << a[3].y << ")" << a[1].x << " , " << a[1].y << "\n";
            else if(apartine(a[0],a[2],a[3]))
                  cout << "Segmentele se intersecteaza in: (" << a[0].x << " , " << a[0].y << ")("<< a[3].x << " , " << a[3].y << "\n";
            else if(apartine(a[1],a[2],a[3]))
                  cout << "Segmentele se intersecteaza in: (" << a[2].x << " , " << a[2].y << ")("<< a[1].x << " , " << a[1].y << "\n";
            else cout << "Segmentele nu se intersecteaza";
        }
        else cout << "Segmentele nu se intersecteaza";
    }

    return 0;
}
