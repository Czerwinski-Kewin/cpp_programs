#include <iostream>
#include <memory>
#include <string>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <vector>
#include "Lista.h"
#include "Lista.cpp"
#include "Oferta.h"
//#include "Oferta.cpp"
using namespace std;


void odczyt(Lista<string>& lista, string nazwa_pliku)
{
	ifstream plik_wczytaj;
	plik_wczytaj.open(nazwa_pliku);
	if (plik_wczytaj.is_open())
	{
		string getline_bufor;
		while (plik_wczytaj.good())
		{
			getline(plik_wczytaj, getline_bufor);
			//cout << getline_bufor << endl;
			lista.dodaj(getline_bufor);
		}
		//lista.display();
		plik_wczytaj.close();
	}
	else
		cout << "Blad pliku, nieudany odczyt" << endl;
}

void zapis(Lista<string>& lista, string nazwa_pliku)
{
	ofstream plik_zapisz;
	plik_zapisz.open(nazwa_pliku);
	if (plik_zapisz.is_open())
	{
		int x = 0;
		//lista.display();
		for (string c : lista)
		{
			plik_zapisz << c;
			x++;
			if (x != lista.size())
				plik_zapisz << '\n';
		}
			
		plik_zapisz.close();
	}
	else
		cout << "Blad pliku, nieudany zapis" << endl;
}

void wektor_zapis(vector<Oferta>& oferty, Lista<string>& miasta, Lista<string>& ulice, Lista<string>& metry, Lista<string>& ceny, Lista<string>& sprzedaze)
{
	//vector<Oferta> oferty;
	string miasto_temp;
	string ulica_temp;
	string metry_temp;
	string cena_temp;
	string sprzedaz_temp;
	int indeks = 0;
	for (string c : miasta)
	{
		miasto_temp = miasta.get(indeks);
		ulica_temp = ulice.get(indeks);
		metry_temp = metry.get(indeks);
		cena_temp = ceny.get(indeks);
		sprzedaz_temp = sprzedaze.get(indeks);
		Oferta oferta(miasto_temp, ulica_temp, metry_temp, cena_temp, sprzedaz_temp);
		oferty.push_back(oferta);
		indeks++;
	}
	
	
	for (Oferta c : oferty)
	{
		cout << c.miasto << " " << c.ulica << " " << c.metry << " " << c.cena << " " << c.sprzedaz << endl;
	}
	
}

void wyszukaj_metraz(vector<Oferta>& oferty)
{
	string metraz;
	cout << "Podaj metraz: " << endl;
	getline(cin, metraz);
	for (Oferta c : oferty)
	{
		if(c.metry == metraz)
			cout << c.miasto << " " << c.ulica << " " << c.metry << " " << c.cena << " " << c.sprzedaz << endl;
	}
}

int main()
{
	bool ui_petla = false;
	string ui_wybor;

	string in_miasto;
	string in_ulica;
	string in_metry;
	string in_cena;
	string in_sprzedaz;
	int in_id;
	string in_fraza;
	string in_sortowanie;

	string instrukcja = "System agencji nieruchomosci - wybierz opcje: \n 1 - Wyswietl oferty \n 2 - Dodaj oferte \n "
		"3 - Usun oferte \n 4 - Wyszukaj oferty \n 5 - Posortuj oferty \n 6 - Zamknij program \n 7 - Zadanie";

    
	cout << instrukcja << endl;

	while (ui_petla == false)
	{
		vector<Oferta> oferty;
		Lista<string> miasta;
		Lista<string> ulice;
		Lista<string> metry;
		Lista<string> ceny;
		Lista<string> sprzedaze;

		odczyt(miasta, "miasta.txt");
		odczyt(ulice, "ulice.txt");
		odczyt(metry, "metry.txt");
		odczyt(ceny, "ceny.txt");
		odczyt(sprzedaze, "sprzedaze.txt");

		getline(cin, ui_wybor);
		if (ui_wybor == "1")
		{
			system("cls");
			int licznik = 0;
			cout << "ID" << setw(20) << "Miasto" << setw(20) << "Ulica" << setw(20) << "Metry kwadratowe" << setw(20) << "Cena" << '\t' << "Status sprzedazy" << endl;
			cout << "-------------------------------------------------------------------------------------------------------" << endl;
			for (string c : miasta)
			{
				cout << licznik + 1 << setw(20) << miasta.get(licznik) << setw(20) << ulice.get(licznik) << setw(20) << metry.get(licznik) << setw(20) << ceny.get(licznik) << setw(20) << sprzedaze.get(licznik) << endl;
				licznik++;
			}
			cout << "Rekordy: " << miasta.size() << endl;
			cout << instrukcja << endl;
		}
		else if (ui_wybor == "2")
		{
			system("cls");
			cout << "Dodaj oferte" << endl;
			cout << "Miasto: " << endl;
			cin >> in_miasto;
			cout << "Ulica: " << endl;
			cin >> in_ulica;
			cout << "Metry: " << endl;
			cin >> in_metry;
			cout << "Cena: " << endl;
			cin >> in_cena;
			cout << "Status sprzedazy: " << endl;
			cin >> in_sprzedaz;
			miasta.dodaj(in_miasto);
			ulice.dodaj(in_ulica);
			metry.dodaj(in_metry);
			ceny.dodaj(in_cena);
			sprzedaze.dodaj(in_sprzedaz);
			cout << "Oferta dodana!" << endl;
			cout << instrukcja << endl;
		}
		else if (ui_wybor == "3")
		{
			//podglad z w1
			system("cls");
			int licznik = 0;
			cout << "ID" << setw(20) << "Miasto" << setw(20) << "Ulica" << setw(20) << "Metry kwadratowe" << setw(20) << "Cena" << '\t' << "Status sprzedazy" << endl;
			cout << "-------------------------------------------------------------------------------------------------------" << endl;
			for (string c : miasta)
			{
				cout << licznik + 1 << setw(20) << miasta.get(licznik) << setw(20) << ulice.get(licznik) << setw(20) << metry.get(licznik) << setw(20) << ceny.get(licznik) << setw(20) << sprzedaze.get(licznik) << endl;
				licznik++;
			}

			cout << "Usun oferte" << endl;
			cout << "ID oferty: " << endl;
			cin >> in_id;
			miasta.usun(in_id - 1);
			ulice.usun(in_id - 1);
			metry.usun(in_id - 1);
			ceny.usun(in_id - 1);
			sprzedaze.usun(in_id - 1);
			cout << "Oferta usunieta!" << endl;
			cout << instrukcja << endl;
		}
		else if (ui_wybor == "4")
		{
			cout << "Wyszukaj oferte" << endl;
			cout << "Podaj fraze: " << endl;
			cin >> in_fraza;
			cout << endl;

			vector<int> indeksy = miasta.szukaj(in_fraza);
			int licznik = 0;
			cout << "ID" << setw(20) << "Miasto" << setw(20) << "Ulica" << setw(20) << "Metry kwadratowe" << setw(20) << "Cena" << '\t' << "Status sprzedazy" << endl;
			cout << "-------------------------------------------------------------------------------------------------------" << endl;

			auto tabela = [&](vector<int> indeksy) {
				for (int c : indeksy)
				{
					cout << licznik + 1 << setw(20) << miasta.get(c) << setw(20) << ulice.get(c) << setw(20) << metry.get(c) << setw(20) << ceny.get(c) << setw(20) << sprzedaze.get(c) << endl;
					licznik++;
				}
			};
			tabela(indeksy);
			indeksy = ulice.szukaj(in_fraza);
			tabela(indeksy);
			indeksy = metry.szukaj(in_fraza);
			tabela(indeksy);
			indeksy = ceny.szukaj(in_fraza);
			tabela(indeksy);
			indeksy = sprzedaze.szukaj(in_fraza);
			tabela(indeksy);

			cout << endl;
			cout << instrukcja << endl;
		}
		else if (ui_wybor == "5")
		{
		cout << "Sortuj kategorie" << endl;
		cout << "Nazwa kategorii (Miasta/Ulice/Metry/Ceny/Sprzedaze): " << endl;
		cin >> in_sortowanie;
			if (in_sortowanie == "Miasta")
			{
				miasta.sortuj();
			}
			else if (in_sortowanie == "Ulice")
			{
				ulice.sortuj();
			}
			else if (in_sortowanie == "Metry")
			{
				metry.sortuj();
			}
			else if (in_sortowanie == "Ceny")
			{
				ceny.sortuj();
			}
			else if (in_sortowanie == "Sprzedaze")
			{
				sprzedaze.sortuj();
			}
			cout << "Elementy posortowane!" << endl;
			cout << instrukcja << endl;
		}
		else if (ui_wybor == "6")
		{
			ui_petla = true;
		}
		else if (ui_wybor == "7")
		{
			wektor_zapis(oferty, miasta, ulice, metry, ceny, sprzedaze);
			wyszukaj_metraz(oferty);
			cout << instrukcja << endl;
		}
		zapis(miasta, "miasta.txt");
		zapis(ulice, "ulice.txt");
		zapis(metry, "metry.txt");
		zapis(ceny, "ceny.txt");
		zapis(sprzedaze, "sprzedaze.txt");
	}
	cout << "Zamykanie bazy...";

	return 0;
}