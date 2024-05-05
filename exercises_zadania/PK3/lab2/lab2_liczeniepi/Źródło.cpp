#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
using namespace std;

mt19937 gen{ random_device{}() };
uniform_real_distribution<double> los{ -1,1 };

int main()
{
	int pkt = 10000;
	vector<double> punkty(pkt);
	double x;
	double y;
	int kolo = 0;
	
		
	generate(punkty.begin(), punkty.end(),
		[]() {
			double liczba = los(gen);
			return liczba;
		}
	);
	for (double c : punkty)	//foreach
	{
		x = c;
		y = los(gen);

		if (x * x + y * y <= 1)
			kolo++;
	}
	double pi = 4. * kolo / pkt;
	cout << "Pi: " << pi << endl;
}