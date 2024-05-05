#include <iostream>
#include <vector>
using namespace std;
int main()
{
	auto wynik = [](int kapital, int lata, int procent, int kapitalizacja)
	{
		return kapital * pow(1 + (procent / (100 * kapitalizacja)), lata * kapitalizacja);
	};

	cout << wynik(10000, 5, 2, 12);
}