#include<iostream>

using namespace std;

void printPointer(int *pInteger)
{
	cout << *pInteger;
}

void printRef(int &refInteger)
{
	cout << refInteger;
}

void printInt(int integer)
{
	cout << integer;
}

int main()
{
	int i = 4;

	// Pointer ce tine adresa lui i.
int *ptr = &i;//nu merge

	// Referinta (sau alias) pentru i.
	int &ref = i;//ref sunt ca niste pointeri const

	//printPointer(i);
	printRef(i);
	printInt(i);

	printPointer(ptr);
	//printRef(ptr);//nu mere din cauza &
	//printInt(ptr);//no

	//printPointer(ref);nope
	printRef(ref);
	printInt(ref);
}
