#include <iostream>
#include "RandomNumberBucket.h"
using namespace std;

int main() {

	int mysize = 10;
	RandomNumberBucket thisBucket(mysize);

	for(int i=0; i<mysize; i++)
	{
		cout << thisBucket.pop() << " Size - " << thisBucket.size() << " Empty: " << thisBucket.empty() << endl;
	}

	thisBucket.refill();

	for(int i=0; i<mysize+1; i++)
	{
		cout << thisBucket.pop() << " Size - " << thisBucket.size() << " Empty: " << thisBucket.empty() << endl;
	}


}


