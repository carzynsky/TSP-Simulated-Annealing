#include <iostream>
#include <stdio.h>
#include "LMatrix.h"
#include "Time_Counter.h"
#include "SimulatedAnnealingNEW.h"
#include "AutomaticTests.h"

int main()
{
	srand(time(NULL));
	LMatrix* lm = new LMatrix();
	Time_Counter tc;
	while (true) {
		system("CLS");
		std::cout << "++++++++++++++++++++++++++++++++++++++++" << std::endl;
		std::cout << "+ Projektowanie efektywnych algorytmow +" << std::endl;
		std::cout << "+ Projekt: Problem Komiwojazera        +" << std::endl;
		std::cout << "+ Algorytmy lokalnego przeszukiwania   +" << std::endl;
		std::cout << "+ Autor: Arkadiusz Carzynski 241335    +" << std::endl;
		std::cout << "++++++++++++++++++++++++++++++++++++++++" << std::endl << std::endl;
		std::cout << "1. Wczytaj macierz" << std::endl;
		std::cout << "2. Liczenie funkcji celu dla permutacji podstawowej" << std::endl;
		std::cout << "3. Symulowane wyzarzanie" << std::endl;
		std::cout << "4. Automatyczne testy" << std::endl;
		std::cout << "5. Kalkulator" << std::endl;
		std::cout << "6. Wyjscie" << std::endl;
		std::cout << "Wybor: ";
		char choice;
		std::cin >> choice;

		switch (choice)
		{
		case '1':
		{
			system("CLS");
			lm = new LMatrix();
			std::string input;
			std::cout << "Podaj nazwe pliku z danymi testowymi: ";
			std::cin >> input;
			(*lm).load_from_file(input + ".txt");
			(*lm).print();
			std::cout << "\nWcisnij przycisk aby powrocic...";
			getchar();
			getchar();
			break;
		}
		case '2': {
			system("CLS");
			if ((*lm).get_problem_size() == 0)
			{
				std::cout << "Nie wczytano macierzy!" << std::endl;
				std::cout << "Wcisnij przycisk aby powrocic...";
				getchar();
				getchar();
			}
			else {
				std::vector<int> permutation;
				for (int i = 0; i < (*lm).get_problem_size(); i++) {
					permutation.push_back(i);
				}
				(*lm).tc_function(permutation);
				std::cout << "Wcisnij przycisk aby powrocic...";
				getchar();
				getchar();
			}
			break;
		}
		
		case '3':
		{
			system("CLS");
			if ((*lm).get_problem_size() == 0)
			{
				std::cout << "Nie wczytano macierzy!" << std::endl;
				std::cout << "Wcisnij przycisk aby powrocic...";
				getchar();
				getchar();
			}
			else {
				std::vector<int> route;
				for (int i = 0; i < (*lm).get_problem_size(); i++)
				{
					route.push_back(i);
				}
				
				SimulatedAnnealingNEW *sa = new SimulatedAnnealingNEW((*lm).get_loaded_matrix(), route, 1000,1, 0.99);
				tc.startTimer();
				sa->findRoute();
				tc.stopTimer();

				std::cout << "Najlepsza sciezka: " << std::endl;
				sa->showShortestRoute();
				std::cout << "Minimalny koszt: " << sa->getMinCost() << std::endl;
				std::cout << "Algorytm symulowanego wyzarzania dla w" << (*lm).get_problem_size() << " wierzcholkow wykonal sie w czasie: " << tc.timePassed() << " [nanoseconds]" << std::endl;
				std::cout << std::endl << "Wcisnij przycisk aby powrocic...";
				getchar();
				getchar();
			}
			break;

		}
		case '4':
		{
			system("CLS");
			std::string cooling;
			std::cout << "Podaj schladzanie: ";
			std::cin >> cooling;

			AutomaticTests *aa = new AutomaticTests(std::stof(cooling));
			aa->startTests(100);
			getchar();
			getchar();
			break;
		}
		case '5':
		{
			system("CLS");
			std::cout << "Obliczenie srednich wartosci dla poszczegolnych parametrow i zapis do plikow tekstowych" << std::endl;
			AutomaticTests* aa = new AutomaticTests(0.99);
			aa->computeAverageResults();
			getchar();
			getchar();
			break;
		}

		case '6':
		{
			exit(0);
			break;
		}
		default: {
			break;
		}
		}
	}

}

