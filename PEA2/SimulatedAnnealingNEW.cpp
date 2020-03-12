#include "SimulatedAnnealingNEW.h"
#include <time.h>
#include <iostream>

SimulatedAnnealingNEW::SimulatedAnnealingNEW(Mtrx m, std::vector<int> route, double T, double Tmin, double cooling)
{
	this->m = m;
	this->T = T;
	this->Tmin = Tmin;
	this->cooling = cooling;
	problemSize = m.size();
	shortestRoute = route;
	minCost = tc(shortestRoute);
}

int SimulatedAnnealingNEW::tc(std::vector<int> route)
{
	int i = 0, sum = 0;
	for (i = 0; i < route.size() - 1; i++)
	{
		sum += m[route[i]][route[i + 1]];
	}
	sum += m[route[i]][route[0]];
	return sum;
}

void SimulatedAnnealingNEW::findRoute()
{
	std::vector<int> newRoute, route = shortestRoute;
	int index1 = 0, index2 = 0;
	while (T > Tmin)
	{

		do
		{
			index1 = rand() % problemSize;
			index2 = rand() % problemSize;
		} while (index1 == index2);

		newRoute = route;
		std::swap(newRoute.at(index1), newRoute.at(index2));
		
		if (tc(route) < minCost)
		{
			shortestRoute = route;
			minCost = tc(shortestRoute);
		}
		else if (exp(-(tc(newRoute) - tc(route)) / T) >= (double)rand() / RAND_MAX)
		{
			route = newRoute;
		}
		T *= cooling;
	}
}

void SimulatedAnnealingNEW::showShortestRoute()
{
	int i = 0;
	std::cout << "[";
	for (i = 0; i < problemSize - 1; i++)
	{
		std::cout << shortestRoute[i] << " -> ";
	}
	std::cout << shortestRoute[i] << "]" << std::endl;
}

int SimulatedAnnealingNEW::getMinCost()
{
	return minCost;
}
