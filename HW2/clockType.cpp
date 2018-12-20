#include <iostream>
#include <iomanip>
#include "clockType.h"

using namespace std;
using namespace myClock;

clockType::clockType() {

	hrs = 0;
	mins = 0;
	secs = 0;

}

clockType::clockType(int hours, int minutes, int seconds) {

	if(hours >= 0 && hours < 24) hrs = hours;
	else hrs = 0;

	if(minutes >= 0 && minutes < 60) mins = minutes;
	else mins = 0;

	if(seconds >= 0 && seconds < 60) secs = seconds;
	else secs = 0;

}

void clockType::setTime(int hours, int minutes, int seconds) {

	if(hours >= 0 && hours < 24) hrs = hours;
	else hrs = 0;

	if(minutes >= 0 && minutes < 60) mins = minutes;
	else mins = 0;

	if(seconds >= 0 && seconds < 60) secs = seconds;
	else secs = 0;

}

void clockType::getTime(int& hours, int& minutes, int& seconds) const {

	hours = hrs;
	minutes = mins;
	seconds = secs;

}

void clockType::printTime() const {

	cout << "Time: " << setfill('0') << setw(2) << hrs << ":" << setfill('0') << setw(2) << mins << ":" << setfill('0') << setw(2) << secs << scientific << endl;
	// "scientific" unsets/reverts the "fixed"

}

void clockType::incrementSeconds() {

	if(secs == 59) secs = 0;
	else secs++;

}

void clockType::incrementMinutes() {

	if(mins == 59) mins = 0;
	else mins++;

}

void clockType::incrementHours() {

	if(hrs == 23) hrs = 0;
	else hrs++;

}

bool clockType::equalTime(const clockType& otherClock) const {

	if(this->hrs == otherClock.hrs && this->mins == otherClock.mins && this->secs == otherClock.secs) return true;

	return false;
}

