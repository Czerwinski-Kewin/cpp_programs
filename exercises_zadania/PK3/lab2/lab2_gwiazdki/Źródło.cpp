#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
using namespace std;

int main()
{
	mt19937 gen{ random_device{}() };
	uniform_real_distribution<double> los{ 500,1000 };
	vector<char> v(los(gen));


	fill(v.begin(), v.end(), '*');

	for (char c : v)	//foreach wyswietl
	{
		cout << c;
	}

}