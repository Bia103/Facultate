#include <iostream>
#include <float.h>
#include <stdlib.h>
#include <math.h>
using namespace std;
struct Punct
{
	int x, y;
}m,u;
int compareX(const void* a, const void* b)
{
	Punct *p1 = (Punct *)a, *p2 = (Punct *)b;
	return (p1->x - p2->x);
}
int compareY(const void* a, const void* b)
{
	Punct *p1 = (Punct *)a, *p2 = (Punct *)b;
	return (p1->y - p2->y);
}
float dist(Punct p1, Punct p2)
{
	return sqrt( (p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y));
}
float z = FLT_MAX;
float testare(Punct P[], int n)
{
	float min = FLT_MAX;

	for (int i = 0; i < n; ++i)
		for (int j = i+1; j < n; ++j)
			if (dist(P[i], P[j]) < min)
				{
				    min = dist(P[i], P[j]);
                    if(dist(P[i], P[j]) < z)
                    {
                        m = P[i];u = P[j];
                        z = dist(P[i], P[j]);
                    }
				}

	return min;
}
float mini(float x, float y)
{
	return (x < y)? x : y;
}
float axaApropiate(Punct axa[], int size, float d)
{
	float min = d;
	Punct m,n;
	for (int i = 0; i < size; ++i)
		for (int j = i+1; j < size && (axa[j].y - axa[i].y) < min; ++j)
			if (dist(axa[i],axa[j]) < min)
				{
				     if(dist(axa[i],axa[j]) < z)
                    {
                        m = axa[i];
                        u = axa[j];
                        z = dist(axa[i],axa[j]);
                    }

				    //cout << axa[i].y;
				    min = dist(axa[i], axa[j]);
				}

	return min;
}
float apropiateDivide(Punct Px[], Punct Py[], int n)
{
	if (n <= 3)
		return testare(Px, n);
	int mij = n/2;
	Punct mijPunct = Px[mij];
	Punct Pyl[mij+1];
	Punct Pyr[n-mij-1];
	int li = 0, ri = 0;
	for (int i = 0; i < n; i++)
	{
	if (Py[i].x <= mijPunct.x)
		Pyl[li++] = Py[i];
	else
		Pyr[ri++] = Py[i];
	}
	float dl = apropiateDivide(Px, Pyl, mij);
	float dr = apropiateDivide(Px + mij, Pyr, n-mij);
	float d = mini(dl, dr);
	Punct axa[n];
	int j = 0;
	for (int i = 0; i < n; i++)
		if (abs(Py[i].x - mijPunct.x) < d)
			axa[j] = Py[i], j++;
	return mini(d, axaApropiate(axa, j, d) );
}
float apropiate(Punct P[], int n)
{
	Punct Px[n];
	Punct Py[n];
	for (int i = 0; i < n; i++)
	{
		Px[i] = P[i];
		Py[i] = P[i];
	}
	qsort(Px, n, sizeof(Punct), compareX);
	qsort(Py, n, sizeof(Punct), compareY);
	return apropiateDivide(Px, Py, n);
}
int main()
{

	int n;
	cin >> n;
	Punct P[n];
	for(int i = 0; i < n; i++)
        cin >> P[i].x >> P[i].y;
	cout  << apropiate(P, n);
	cout << "Punctele sunt :(" << m.x << "," <<m.y<<") si (" << u.x << "," <<u.y<<")";
	return 0;
}
