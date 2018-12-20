#ifndef CLOCKTYPE_H_
#define CLOCKTYPE_H_

namespace myClock {

	class clockType {

		// Order should be public methods then protected methods and then private methods
		public:

			clockType();

			clockType(int hours, int minutes, int seconds);

			void setTime(int hours, int minutes, int seconds);

			void getTime(int& hours, int& minutes, int& seconds) const;

			void printTime() const;

			void incrementSeconds();

			void incrementMinutes();

			void incrementHours();

			bool equalTime(const clockType& otherClock) const;


		private:

			int hrs, mins, secs;

	};

}

#endif /* CLOCKTYPE_H_ */
