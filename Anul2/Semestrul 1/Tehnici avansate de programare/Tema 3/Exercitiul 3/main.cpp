#include <bits/stdc++.h>
using namespace std;

int merge1(int a[], int v[], int s, int d);
int merge(int a[], int v[], int s, int mij, int d);
int mergeSort(int a[], int m)
{
	int v[m];
	return merge1(a, v, 0, m - 1);
}

int merge1(int a[], int v[], int s, int d)
{
	int mij, contor = 0;
	if (d > s) {
		mij = (d + s) / 2;
		contor = merge1(a, v, s, mij);
		contor += merge1(a, v, mij + 1, d);
		contor += merge(a, v, s, mij + 1, d);
	}
	return contor;
}
int merge(int a[], int v[], int s, int mij, int d)
{
	int i, j, k;
	int contor = 0;
	i = s;
	j = mij;
	k = s;
	while ((i <= mij - 1) && (j <= d)) {
		if (a[i] > 2 * a[j]) {
			contor += (mij - i);
			j++;
		}
		else {
			i++;
		}
	}
	i = s;
	j = mij;
	k = s;
	while ((i <= mij - 1) && (j <= d)) {
		if (a[i] <= a[j]) {
			v[k++] = a[i++];
		}
		else {
			v[k++] = a[j++];
		}
	}
	while (i <= mij - 1)
		v[k++] = a[i++];
	while (j <= d)
		v[k++] = a[j++];
	for (i = s; i <= d; i++)
		{a[i] = v[i];

		}
		//cout << endl;
	return contor;
}

int main()
{

	int n ;
    cin >> n;
    int *a = new int[n];
    for(int i = 0;i < n;i++)
        cin >> a[i];
	cout << mergeSort(a, n);
	return 0;
}
