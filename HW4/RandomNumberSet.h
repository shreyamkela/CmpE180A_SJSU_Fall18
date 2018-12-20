#ifndef RANDOMNUMBERSET_H_
#define RANDOMNUMBERSET_H_

	#include <iostream>
	#include <bitset>
	using namespace std;

	#define MAXBITSET 1000

	class RandomNumberSet {

		public:

			RandomNumberSet();
			RandomNumberSet(int range);
		    int size();
		    void reset();
		    bool set(int i);

		    //SHOULD BE IN private
		    std::bitset<MAXBITSET> Stored;

			int operator - (RandomNumberSet const &obj);
			friend std::ostream& operator << (std::ostream& os, RandomNumberSet const &obj);
			//WHY friend?


		private:

			int range;
	};

#endif /* RANDOMNUMBERSET_H_ */
