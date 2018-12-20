#ifndef RANDOMNUMBERBUCKET_H_
#define RANDOMNUMBERBUCKET_H_

//namespace myBucket{
//Uncomment if use of namespace is required
#include <iostream>
#include <set>
using namespace std;


	class RandomNumberBucket {

		public:

			RandomNumberBucket();
			RandomNumberBucket(int range);
			int pop();
			void refill();
		    int size();
		    bool empty();
		    int popWithRefill();

		protected:

			int Random();
			int poppedNumbers(int popThis);
			long int count = 0;

		private:

			int range;
			int myNumber = -1;
			int counter = 0;
			bool firstPop = true;
			bool newPop = false;
			std::set <int> popped;
			std::set <int>::iterator it;

	};


//}
// Uncomment if use of namespace is required


#endif /* RANDOMNUMBERBUCKET_H_ */
