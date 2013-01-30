#include <iostream>

using namespace std;

#include "Array.h"
#include "Exception.h"

int main()
{
	cout << "Array testing" << endl;
	Array a1(4);
	
	cout << "\nTest: set(n,value) - sets value of array with index n" << endl;

	a1.set(0, 1);
	a1.set(1, 21);
	a1.set(2, 200);
	a1.set(3, 3);

	cout << "\nTest: size() - outputs first testing array, initialized with size of 4"<< endl;
	cout << a1.size() << endl;
	cout << "\nTest: get(n) - get the content from index 2" << endl;
	cout << a1.get(2) << endl;

	a1.resize(7);
	cout << "\nTest: resize(n) n > array_size - testing array a1 is resized to 7" << endl;
	cout << a1.size() << endl;
	cout << a1.get(5) << endl;

	a1.resize(7);
	cout << "\nTest: resize(n) n = array_size - resizing array a1 to 7 again" << endl;
	cout << a1.size() << endl;
	a1.resize(2);
	cout << "\nTest: resize(n) n < array_size - resizing array a1 to 2 \n" << endl;
	cout << a1.size() << endl;

	try {
		a1.get(5);
	} catch (ArrayBoundsException e) {
		cout << "\nException! (get) " << endl;
	}

	try {
		a1.set(6, 20);
	} catch (ArrayBoundsException e) {
		cout << "Exception! (set) " << endl;
	}

	cout << "\nTest: get(n) with n > array_size - throws exception" << endl;

	cout << "\nBONUS: print() method for printing all the values inside a1 array" << endl;
	a1.print();

	cin.get();
}
