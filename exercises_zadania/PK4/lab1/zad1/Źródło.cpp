import std;
import math;

using namespace std;

int main()
{
	double a;
	double b;
	cout << "Pierwsza liczba:" << endl;
	cin >> a;
	cout << "Druga liczba:" << endl;
	cin >> b;
	cout << "Dodawanie: " << dodawanie(a, b) << endl;
	cout << "Odejmowanie: " << odejmowanie(a, b) << endl;
	cout << "Mnozenie: " << mnozenie(a, b) << endl;
	cout << "Dzielenie: " << dzielenie(a, b) << endl;
}