#include <iostream>
#include "MyArray.h"
using namespace std;
int main() {
	MyArray<> a;
	MyArray<> b;
	MyArray<> c;
	a.SetSize(2);
	for (int i = 0; i < a.GetSize(); i++) {
		a[i] = i+2;
		//cin.get();
	}
	b.SetSize(2);
	for (int i = 0; i < b.GetSize(); i++) {
		b[i] = i+5;
		//cin.get();
	}
	printf("\n-----------------------------------\n");
	c = a.Append(b);
	cout << "\n" << c << "\n";
	auto* ptr = c.GetData();
	cout << *ptr << "\n";
	c.InsertAt(0, 99, 2);
	cout << c << endl;
	c.RemoveAt(0);
}