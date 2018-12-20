#include "RandomNumberSet.h"
//#include <iostream>

//using namespace std;

#include <iostream>

using namespace std;


int main() {


	RandomNumberSet a(4);
	RandomNumberSet b(5);
	RandomNumberSet c;
	RandomNumberSet d(999);

	cout << a.set(1);
	cout << a.set(2);
	cout << a.set(3);
	cout << a.set(4);
	cout << a.set(5);
	//cout << a.set(6);

	//cout << a.set();
	cout << b.set(2);
	cout << b.set(3);
	cout << b.set(4);
	cout << b.set(5);

	//cout << a.set(6);

	cout<< a << endl;
	cout << b << endl;
	cout << a-b << endl;

	a.reset();
	cout<< a << endl;
		cout << b << endl;
		cout << a-b << endl;


		cout << c.set(10);
		cout << c.set(20);
		cout << c.set(39);
		cout << c.set(40);

		cout << d.set(10);
		cout << d.set(100);
		cout << d.set(999);
		cout << d.set(1000);

		cout<< c << endl;
		cout << d << endl;
		cout << d-c << c <<  endl;
		cout<< a.size() << " " << b.size() << " " << c.size() << " " << d.size() << endl;


}


