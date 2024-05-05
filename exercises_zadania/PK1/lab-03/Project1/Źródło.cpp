#include <random>
#include <chrono>
#include <iostream>
#include <time.h>
#include <string>
using namespace std;

//losowanie
std::default_random_engine silnik(std::chrono::system_clock::now().time_since_epoch().count());
std::normal_distribution<double> rozklad(100, 20);
std::uniform_int_distribution<int> rozklad2(50, 150);


double losowa = rozklad(silnik);

const int N = 20;

int main()
{
	int losowa2 = rozklad(silnik);
	int tab[N];

	for (int i = 0; i < N; i++)
	{
		losowa2 = rozklad(silnik);
		tab[i] = losowa2;
		std::cout << tab[i] << std::endl;
	}

	int odp;
	std::cout << "Jaka operacja?" << std::endl;
	std::cout << "1 - sumowanie" << std::endl;
	std::cout << "2 - mnozenie" << std::endl;
	std::cout << "3 - znajdowanie minimum" << std::endl;
	std::cout << "4 - wyszukiwanie" << std::endl;
	cin >> odp;
	switch(odp) 
	{
		case 1:
		{
			//do{}
			int suma = 0;
			for (int i = 0; i < N; i++)
			{
				suma += tab[i];
			}
			cout << "Suma: " << suma << endl;

			string odp;
			cout << "Zakonczyc? T/N" << endl;
			cin >> odp;
			//if (odp == "T")	break;
			//else if (odp == "N");
			//test
		}
		case 2:
		{
			long iloczyn = 1;
			for (int i = 0; i < N; i++)
			{
				iloczyn *= tab[i];
			}
			cout << "Iloczyn: " << iloczyn << endl;
			break;
		}
		case 3:
		{
			int min = tab[0];
			for (int i = 0; i < N; i++)
			{
				if (tab[i] < min)
				{
					tab[i] = min;
				}
			}
			cout << "Minimum: " << min << endl;
			break;
		}
		case 4:
		{
			int wieksze = 0;
			int mniejsze = 0;
			int rowne = 0;
			int liczba;
			
			do
			{
				cin.clear();
				cin.ignore(10000, '\n');
				cout << "Podaj liczbe do porownania: " << endl;
				cin >> liczba;
			} 
			while (!cin);

			for (int i = 0; i < N; i++)
			{
				if (tab[i] < liczba)
				{
					mniejsze++;
				}
				else if (tab[i] > liczba)
				{
					wieksze++;
				}
				else if (tab[i] > liczba)
				{
					rowne++;
				}
			}
			cout << "Ilosc wiekszych liczb: " << wieksze << endl;
			cout << "Ilosc mniejszych liczb: " << mniejsze << endl;
			cout << "Ilosc rownych liczb: " << rowne << endl;
			break;
		}

	}
}