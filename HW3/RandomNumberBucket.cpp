#include "RandomNumberBucket.h"

//using namespace myBucket;
//Uncomment namespace if the use of namespace is required

RandomNumberBucket::RandomNumberBucket() {
	range = 39;
	srand(time(NULL));
}

RandomNumberBucket::RandomNumberBucket(int range) {
	this->range = range;
	srand(time(NULL));
}

int RandomNumberBucket::Random() {

	int lowerBound = 1;
	int upperBound = range;
	int difference = upperBound - lowerBound + 1;
	myNumber = (rand()%difference)+lowerBound;
	return myNumber;

}

int RandomNumberBucket::pop() {

	if(counter<range-1) {
		return poppedNumbers(Random());
	}
	else if(range == 1 && counter == 0) {
		counter++;
		return 1;
	}
	else {
		return -1;
	}
}

int RandomNumberBucket::poppedNumbers(int popThis) {

	if(firstPop == true) {
		popped.insert(popThis);
		firstPop = false;
	}
	else {

		newPop = false;
		while(newPop == false) {

			it = popped.find(popThis);
			if(it == popped.end()){
				popped.insert(popThis);
				newPop = true;
				counter++;
			}
			else popThis = pop();
		}
	}

	return popThis;
}

void RandomNumberBucket::refill() {

	popped.clear();
	counter = 0;
	myNumber = -1;
	firstPop = true;
	newPop = false;

}

int RandomNumberBucket::size() {

	if(range-(counter+1)>=0){
		if(firstPop == true)
			return range-counter;
		else
			return range-(counter+1);
	}

	else return 0;
}

bool RandomNumberBucket::empty() {

	if(RandomNumberBucket::size()>0)
		return false;
	else return true;

}


int RandomNumberBucket::popWithRefill() {

	if(RandomNumberBucket::empty() == true) {
		RandomNumberBucket::refill();
		return pop();
	}
	else {
		return pop();
	}

}


