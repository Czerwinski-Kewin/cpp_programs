#include <iostream>
#include <string>
#include <ranges>
#include <vector>
using namespace std;

int main()
{
	int n;
	int x;
	vector<int> wekt;

	cout << "Ile liczb?" << endl;
	cin >> n;
	if (n > 3)
	{
		cout << "Podaj liczby" << endl;
		for (int i = 0; i < n; i++)
		{
			cin >> x;
			wekt.push_back(x);
		}
	}
	else
		cout << "Za malo liczb, podaj przynajmniej 4" << endl;


	if (n > 3)
	{
		auto drugi = ranges::begin(wekt);
		auto przedostatni = ranges::end(wekt);
		drugi++;
		przedostatni -= 2;
		cout << "Drugi element: " << *drugi << endl;
		cout << "Przedostatni element: " << *przedostatni << endl;
	}
	else if (ranges::empty(wekt))
		cout << "Wektor pusty!" << endl;

}