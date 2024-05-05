#include <iostream>
#include <regex>
#include <string>
using namespace std;


void podzielnosc()
{
	string liczba;
	cout << "Podaj liczbe:" << endl;
	getline(cin, liczba);
	regex porownanie("(0|5)$");
	bool podzielnosc = regex_search(liczba, porownanie);
	if (podzielnosc)
		cout << "Poprawny - podzielny przez 5" << endl;
	else
		cout << "Niepoprawny - niepodzielny przez 5" << endl;
}

void telefon()
{
	string numer;
	cout << "Podaj numer formatu +ff fffffffff" << endl;
	getline(cin, numer);	//wykrycie spacji
	regex porownanie("\\+\\d{2} \\d{9}");
	bool zgodnosc = regex_match(numer, porownanie);
	if (zgodnosc)
		cout << "Poprawny" << endl;
	else
		cout << "Niepoprawny" << endl;

}

void data()
{
	string data;
	cout << "Wpisz date DD-MM-YYYY" << endl;
	getline(cin, data);	//wykrycie spacji
	regex porownanie("(0[1-9]|[1-2]\\d|3[0-1])-(0[1-9]|1[0-2])-\\d{4}");
	bool zgodnosc = regex_match(data, porownanie);
	if (zgodnosc)
		cout << "Poprawny" << endl;
	else
		cout << "Niepoprawny" << endl;
}

int main() 
{
	podzielnosc();
	telefon();
	data();

	return 0;
}

