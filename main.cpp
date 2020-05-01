#include <iostream>
#include "Tablica.h"
using namespace std;
int main() {
	Tablica<int> t;
	for (int i = 0; i < 10; i++) t.PushBack(i);
	cout << t.Front() << endl;
	cout << t.Back() << endl;
	t.Print();
	t.Reverse();
	t.Print();
	cout << t.Count() << endl;
	t.PopBack();

	system("pause");
	return 0;
}