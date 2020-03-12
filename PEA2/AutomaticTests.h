#pragma once
class AutomaticTests
{
private:
	float cooling;
public:
	AutomaticTests(float cooling);
	void startTests(int N);
	void computeAverageResults();
};

