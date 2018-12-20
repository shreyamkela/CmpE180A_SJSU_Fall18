#include <iostream>
#include <bitset>
#include <cmath>
#include <math.h>
#include <iomanip>
#include "RandomNumberSet.h"

using namespace std;
//using namespace myBitset;


RandomNumberSet::RandomNumberSet() {

	this->range = 39;

}

RandomNumberSet::RandomNumberSet(int range) {

	if(range >= 1 && range <= MAXBITSET){
		this->range = range;
	}
	else {
		cerr << "Error: Range should be between 1 and " << MAXBITSET << endl;
		exit(1); // To run no further code after this and exit code entirely
	}
}

bool RandomNumberSet::set(int i) {

	if(i<=0) {
		cerr << "Error: Set for this object can be used from 1 to " << range << " only" << endl;
		return false;
	}


	if(i>range && range>4) {
		cerr << "Error: Range of this object is limited to " << range << endl;
		return false;
	}
	else {

		if(Stored.test(i-1) == 0){
			if(Stored.count()>=5)
				{
				cerr << "Error: The maximum container size is 5" << endl;
				return false;
				//cerr sometimes prints at top of console even if this error occurs somewhere in the middle of runtime. Why?
				}

			else {
				Stored.set(i-1);
				return true;
			}

		}
		else return false;
	}



}

int RandomNumberSet::operator - (RandomNumberSet const &obj) {

	RandomNumberSet overloaded;
	//overloaded.Stored = Stored^obj.Stored;

	int thisStored = Stored.count();
	int thatStored = obj.Stored.count();
	//if this.size i.e a > obj.size i.e b  ==> (a^(~a&b))^b

	overloaded.Stored = thisStored>=thatStored ?(((Stored)^((~(Stored))&(obj.Stored)))^(obj.Stored)):(((obj.Stored)^((~(obj.Stored))&(Stored)))^(Stored));
	//else  overloaded.Stored = (((obj.Stored)^((~(obj.Stored))&(Stored)))^(Stored));


	return overloaded.size();

}

std::ostream& operator << (std::ostream& os, RandomNumberSet const &obj) {

	RandomNumberSet overloaded = obj;
	//long int n;
	int i=0;
	while(overloaded.Stored.any()){ //while there is any set bit in the bitset

//		FINDING LEAST SIGNIFICANT SET BIT IN THE INTEGER N - SO THAT WE DONT HAVE TO CHECK EACH POSITION ITERATIVELY FOR SET OR NOT
//		BUT THIS METHOD DOES NOT WORK IF THE BITSET IS HAS SET BITS AT HIGHER POSITIONS AT LIKE i = 30 AND FORWARDS. WORKS BELOW THAT
//		n = (int)(overloaded.Stored).to_ulong();
//
//		long int leastSig = log2(n & -n) + 1; //WHATS HAPPENING HERE?
//
//		os << std::right << std::setw(3) << leastSig;
//
//		(overloaded.Stored).flip(leastSig-1); //Change this leastSig to 0 so that the next laeatSig could be identified
//
//		cout << "\nx " << overloaded.Stored << " " << overloaded.Stored.any() << endl;

		if(overloaded.Stored.test(i) == true){

			os << std::right << std::setw(3) << (i+1);

			(overloaded.Stored).flip(i); //Change this leastSig to 0 so that the next laeatSig could be identified

			//cout << "\nx " << overloaded.Stored << " " << overloaded.Stored.any() << endl;

		}
		i++;

	}
	return os;
}



void RandomNumberSet::reset() {

	Stored.reset();

}



int RandomNumberSet::size() {
	return Stored.count();
}


