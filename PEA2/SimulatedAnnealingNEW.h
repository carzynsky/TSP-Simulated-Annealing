#pragma once
#include <vector>
typedef std::vector<std::vector<int>> Mtrx;
class SimulatedAnnealingNEW
{
private:
	double cooling;
	double T;
	double Tmin;
	int problemSize;
	Mtrx m;
	std::vector<int> shortestRoute;
	int minCost;


public:
	SimulatedAnnealingNEW(Mtrx m, std::vector<int> route, double T, double Tmin, double Cooling);
	int tc(std::vector<int> route);
	void findRoute();
	void showShortestRoute();
	int getMinCost();
};

