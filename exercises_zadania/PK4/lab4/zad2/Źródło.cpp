#include <iostream>
#include <string>
#include <ranges>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	int x;
	vector<int> wekt;

	cout << "Ile liczb?" << endl;
	cin >> n;
	cout << "Podaj liczby" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		wekt.push_back(x);
	}

	if(n > 3)
	{
		if (n % 2 == 0)
		{
			auto najmniejszy = ranges::min_element(wekt);
			auto najwiekszy = ranges::max_element(wekt);
			cout << "Najmniejszy element: " << *najmniejszy << endl;
			cout << "Najwiekszy element: " << *najwiekszy << endl;
		}
		else if (n % 2 != 0)
		{
			auto srodkowy = ranges::size(wekt) / 2;
			cout << "Srodkowy element: " << wekt[srodkowy] << endl;
		}
	}
	else
	{
		ranges::sort(wekt);
		cout << "Posortowany wektor: " << endl;
		for (int c : wekt)
			cout << c << " ";
	}

}