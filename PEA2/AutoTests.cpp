#include "AutoTests.h"
#include <iostream>
#include <fstream>
#include "SimulatedAnnealingNEW.h"
#include "Time_Counter.h"
#include "LMatrix.h"
AutoTests::AutoTests(float cooling)
{
	this->cooling = cooling;
}

void AutoTests::makeTests()
{
	int tmp = 10;
	LMatrix *m;
	std::ofstream fileStream;
	while (tmp <= 19)
	{
		std::string file_name = "data" + tmp;
		m = new LMatrix();
		std::cout << "Test " + file_name+ " dla schladzania  " << cooling << std::endl;
		std::vector<int> route;
		for (int i = 0; i < (*m).get_problem_size(); i++)
		{
			route.push_back(i);
		}
		
		for (int i = 0; i < 10; i++)
		{
			Time_Counter *tc = new Time_Counter();
			SimulatedAnnealingNEW* sa = new SimulatedAnnealingNEW((*m).get_loaded_matrix(), route, 1000, 1, cooling);
			tc->startTimer();
			sa->findRoute();
			tc->stopTimer();

			std::string file_name2 = "results(" + (*m).get_problem_size();
			fileStream.open(file_name2 + ", " + std::to_string(cooling) + ").txt");
			if (fileStream.good())
			{
				fileStream << tc->timePassed() + "\n";
			}
			else
			{
				std::cout << "Nie uda³o siê otworzyæ pliku!" << std::endl;
			}

		}
		std::cout << std::endl;
		tmp++;
	}

}
