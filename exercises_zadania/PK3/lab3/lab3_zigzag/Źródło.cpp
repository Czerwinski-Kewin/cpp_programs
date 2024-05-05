#include <iostream>
#include <utility>
#include <memory>
#include <chrono>
#include <random>
#include <fstream>
#include <string>
using namespace std;

int max(int a, int b) 
{
    return (a > b) ? a : b; 
}

int zigzag(const vector<int> &wektor)
{
    int tab[10][2];

    for (int i = 0; i < 5; i++)
        tab[i][0] = tab[i][1] = 1;

    int wynik = 1;

    for (int i = 1; i < 5; i++)
    {
        for (int j = 0; j < i; j++)
        {
			if (wektor[j] < wektor[i] && tab[i][0] < tab[j][1] + 1)
			{
				tab[i][0] = tab[j][1] + 1;
			}
                

			if (wektor[j] > wektor[i] && tab[i][1] < tab[j][0] + 1)
			{
				tab[i][1] = tab[j][0] + 1;
			}
                
        }

		if (wynik < max(tab[i][0], tab[i][1]))
		{
			wynik = max(tab[i][0], tab[i][1]);
		}
            
    }

    return wynik;
}
void odczyt(vector<int>& wektor)
{
	ifstream plik_wczytaj("odczyt.txt");
	if (plik_wczytaj)
	{
		istream_iterator<int> fin(plik_wczytaj);
		istream_iterator<int> eos;
		copy(fin, eos, back_inserter(wektor));
	}
	plik_wczytaj.close();
}

void zapis(vector<int>& wektor)
{
	ofstream plik_zapisz("zapis.txt");
	if (plik_zapisz)
	{
		plik_zapisz << zigzag(wektor);
		ostream_iterator<int> cout_it(cout);
		copy(wektor.begin(), wektor.end(), cout_it);
	}
	plik_zapisz.close();
}

int main()
{
	vector<int> wektor;
	odczyt(wektor);

	zapis(wektor);


	return 0;
}