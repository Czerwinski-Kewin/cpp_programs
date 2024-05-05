#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
using namespace std;

int main()
{
	vector<int> v(10);


	generate(v.begin(), v.end(),
		[]() {
			static int liczba = 1;
			return liczba++;
		}
	);

	for (double c : v)	//foreach wyswietl
	{
		cout << c << endl;
	}

}