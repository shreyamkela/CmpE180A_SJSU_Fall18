#include <iostream>
#include <iomanip>
#include "clockType.h"

using namespace std;
using namespace myClock;

int main() {

	int hours1, minutes1, seconds1, hours2, minutes2, seconds2;
	clockType thisClock;

	hours1 = 12;
	minutes1 = 11;
	seconds1 = 59;

	thisClock.setTime(hours1, minutes1, seconds1);
	cout << "Clock1 set to time - Hours: " << setfill('0') << setw(2) << hours1 << ", Minutes: " << setfill('0') << setw(2) << minutes1 << ", Seconds: " << setfill('0') << setw(2) << seconds1 << endl;
	cout << endl;

	cout << "Function getTime is used" << endl;
	thisClock.getTime(hours1, minutes1, seconds1);
	cout << "Function printTime is used" << endl;
	thisClock.printTime();
	cout << endl;

	cout << "Function incrementSeconds, incrementMinutes, incrementHours is used" << endl;
	thisClock.incrementSeconds();
	thisClock.incrementMinutes();
	thisClock.incrementHours();
	thisClock.printTime();
	cout << endl;

	hours2 = 13;
	minutes2 = 12;
	seconds2 = 0;

	clockType thatClock(hours2, minutes2, seconds2);
	cout << "Clock2 initialized with time - Hours: " << setfill('0') << setw(2) << hours2 << ", Minutes: " << setfill('0') << setw(2) << minutes2 << ", Seconds: " << setfill('0') << setw(2) << seconds2 << endl;
	cout << "Function equalTime is used" << endl;
	if(thisClock.equalTime(thatClock)) cout << "The clocks have equal time" << endl;
	else cout << "The clocks have unequal time" << endl;

}
