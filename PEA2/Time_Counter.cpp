#include "Time_Counter.h"

Time_Counter::Time_Counter()
{
}


Time_Counter::~Time_Counter()
{
}

void Time_Counter::startTimer()
{
	start = std::chrono::steady_clock::now();
}

void Time_Counter::stopTimer()
{
	end = std::chrono::steady_clock::now();
}

long Time_Counter::timePassed()
{
	return  std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
}

