#include "AutomaticTests.h"
#include <iostream>
#include <fstream>
#include "LMatrix.h"
#include "SimulatedAnnealingNEW.h"
#include "Time_Counter.h"

AutomaticTests::AutomaticTests(float cooling)
{
	this->cooling = cooling;
}

void AutomaticTests::startTests(int N)
{
	int numb = 10;
	LMatrix* lm;
	std::string file_name;
	std::ofstream file_stream;

	while (numb < 444)
	{
		// wczytanie macierzy
		lm = new LMatrix();
		(*lm).load_from_file("data" + std::to_string(numb) + ".txt");

		// zaladowanie sciezki
		std::vector<int> route;
		for (int i = 0; i < (*lm).get_problem_size(); i++)
		{
			route.push_back(i);
		}

		file_stream.open("resultsCosts(" + std::to_string(numb) + ", " + std::to_string(cooling) + ").txt");

		if (file_stream.good())
		{
			for (int i = 0; i < N; i++)
			{
				SimulatedAnnealingNEW* sa;
				sa = new SimulatedAnnealingNEW((*lm).get_loaded_matrix(), route, 1000, 1, cooling);
				sa->findRoute();
				file_stream << sa->getMinCost() << "\n";
			}
		}
		else
		{
			std::cout << "B³ad podczas tworzenia pliku!";
		}
		file_stream.close();
		numb++;
		if (numb >= 19 && numb <= 442)
		{
			switch (numb)
			{
			case 19:
			{
				numb = 21;
				break;
			}
			case 22:
			{
				numb = 24;
				break;
			}
			case 25:
			{
				numb = 26;
				break;
			}
			case 27:
			{
				numb = 29;
				break;
			}
			case 30:
			{
				numb = 34;
				break;
			}
			case 35:
			{
				numb = 36;
				break;
			}
			case 37:
			{
				numb = 39;
				break;
			}
			case 40:
			{
				numb = 42;
				break;
			}
			case 44:
			{
				numb = 45;
				break;
			}
			case 46:
			{
				numb = 48;
				break;
			}
			case 49:
			{
				numb = 53;
				break;
			}
			case 54:
			{
				numb = 56;
				break;
			}
			case 57:
			{
				numb = 58;
				break;
			}
			case 59:
			{
				numb = 65;
				break;
			}
			case 66:
			{
				numb = 70;
				break;
			}
			case 72:
			{
				numb = 100;
				break;
			}
			case 101:
			{
				numb = 120;
				break;
			}
			case 121:
			{
				numb = 171;
				break;
			}
			case 172:
			{
				numb = 323;
				break;
			}
			case 324:
			{
				numb = 358;
				break;
			}
			case 359:
			{
				numb = 403;
				break;
			}
			case 404:
			{
				numb = 443;
				break;
			}

			}

		}
	}
}

void AutomaticTests::computeAverageResults()
{
	std::ofstream file_stream;
	std::ifstream open_file;
	double sum = 0;
	int numb = 10;
	std::string line;
	file_stream.open("averageTime(0.99999).txt");
	if (file_stream.good())
	{
		while (numb < 444)
		{
			int index = 0;
			open_file.open("results(" + std::to_string(numb) + ", 0.999990).txt");
			if (open_file.good())
			{
				while (!open_file.eof())
				{
					open_file >> line;
					sum += std::stoi(line);
					index++;
				}
				
			}
			else
			{
				std::cout << "Wystapil blad podczas tworzenia pliku!" << std::endl;
			}
			file_stream << "SA " + std::to_string(numb) + "wierzcholkow: " + std::to_string(sum / 101) << "\n";
			open_file.close();
			sum = 0;
			numb++;
			if (numb >= 19 && numb <= 442)
			{
				switch (numb)
				{
				case 19:
				{
					numb = 21;
					break;
				}
				case 22:
				{
					numb = 24;
					break;
				}
				case 25:
				{
					numb = 26;
					break;
				}
				case 27:
				{
					numb = 29;
					break;
				}
				case 30:
				{
					numb = 34;
					break;
				}
				case 35:
				{
					numb = 36;
					break;
				}
				case 37:
				{
					numb = 39;
					break;
				}
				case 40:
				{
					numb = 42;
					break;
				}
				case 44:
				{
					numb = 45;
					break;
				}
				case 46:
				{
					numb = 48;
					break;
				}
				case 49:
				{
					numb = 53;
					break;
				}
				case 54:
				{
					numb = 56;
					break;
				}
				case 57:
				{
					numb = 58;
					break;
				}
				case 59:
				{
					numb = 65;
					break;
				}
				case 66:
				{
					numb = 70;
					break;
				}
				case 72:
				{
					numb = 100;
					break;
				}
				case 101:
				{
					numb = 120;
					break;
				}
				case 121:
				{
					numb = 171;
					break;
				}
				case 172:
				{
					numb = 323;
					break;
				}
				case 324:
				{
					numb = 358;
					break;
				}
				case 359:
				{
					numb = 403;
					break;
				}
				case 404:
				{
					numb = 443;
					break;
				}

				}
			}


		}

	}
	else
	{
		std::cout << "Wystapil blad podczas tworzenia pliku!" << std::endl;
	}
	file_stream.close();
}
