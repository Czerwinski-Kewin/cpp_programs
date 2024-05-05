#include <iostream>
using namespace std;

int main()
{
	char znak;
	int suma = 0;
	int iloczyn = 1;
	cin >> znak;
	int liczba = znak-48;
	int bin;
	//cout << liczba;

	if (liczba % 2 == 0)
	{
		for (int i=0; i <= liczba; i+=2)
		{
			cout << i << " ";
			suma += i;
		}
		cout << endl;
		cout << suma;
	}
	else if (liczba % 2 != 0)
	{
		cout << 0 << " ";
		for (int i = 1; i <= liczba; i++)
		{
			cout << i << " ";
			iloczyn *= i;
		}
		cout << endl;
		cout << iloczyn;
	}
	cout << endl;
	
	/*for (int i = 0; i < 10; i++)
	{
		cout << i;
	}
	*/
	return 0;
}
