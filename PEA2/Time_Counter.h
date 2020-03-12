#pragma once

#include <chrono>
class Time_Counter
{
public:
	std::chrono::high_resolution_clock::time_point start;
	std::chrono::high_resolution_clock::time_point end;
	Time_Counter();
	~Time_Counter();
	void startTimer();
	void stopTimer();
	long timePassed();
};

