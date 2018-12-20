#include "RandomNumberSet.h"
#include <iostream>

using namespace std;

int main() {


	RandomNumberSet a(4);
	RandomNumberSet b(5);

	cout << "BITSET a " << a.Stored.to_string() << endl;
	cout << "Size after constructor " << a.size() << endl;
	cout << "Set 10 after constructor " << a.set(6) << endl;
	cout << a.Stored.to_string() << endl;
	cout << "Set 10 after constructor " << a.set(7) << endl;
	cout << a.Stored.to_string() << endl;
	cout << "Set 10 after constructor " << a.set(8) << endl;
	cout << a.Stored.to_string() << endl;
	cout << "Set 10 after constructor " << a.set(9) << endl;
	cout << a.Stored.to_string() << endl;
	cout << "Set 10 after constructor " << a.set(10) << endl;
	cout << a.Stored.to_string() << endl;
//	cout << "Size now " << a.size() << endl;
//	a.reset();
//	cout << a.Stored.to_string() << endl;
//	cout << "Size after reset " << a.size() << endl;
//	cout << "Set 9 " << a.set(19) << endl;
//	cout << a.Stored.to_string() << endl;
//	cout << "Size after set 9  " << a.size() << endl;
//	cout << "Set 20 " << a.set(20) << endl;
//	cout << "a "<< a.Stored.to_string() << endl;
//	cout << "Size after set 20 " << a.size() << endl;
//	cout << "Set 30 " << a.set(30) << endl;
//	cout << "a "<< a.Stored.to_string() << endl;
//	cout << "Size after set 30 " << a.size() << endl;
//	cout << "Set 40 " << a.set(40) << endl;
//	cout << "a "<< a.Stored.to_string() << endl;
//	cout << "Size after set 40 " << a.size() << endl;
//	cout << "Set 100 " << a.set(100) << endl;
//	cout << "a "<< a.Stored.to_string() << endl;
//	cout << "Size after set 100 " << a.size() << endl;
//	cout << "Set 70 " << a.set(70) << endl;
//	cout << "a "<< a.Stored.to_string() << endl;
//	cout << "Size after set 70 " << a.size() << endl;

	cout << b.Stored.to_string() << endl;
	cout << "Set 9 in 10 " << b.set(1) << endl;
	cout << "b " << b.Stored.to_string() << endl;
	cout << "Set 9 in 10 " << b.set(2) << endl;
	cout << "b " << b.Stored.to_string() << endl;
	cout << "Set 9 in 10 " << b.set(3) << endl;
	cout << "b " << b.Stored.to_string() << endl;
	cout << "Set 9 in 10 " << b.set(4) << endl;
	cout << "b " << b.Stored.to_string() << endl;
	cout << "Set 9 in 10 " << b.set(5) << endl;
	cout << "b " << b.Stored.to_string() << endl;

	cout << (a-b) << endl;
	cout << "a  " << a.Stored.to_string() << endl;
	cout << a << endl;

}


