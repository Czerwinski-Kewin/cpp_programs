#include "PracaDyplomowa.h"

void PracaDyplomowa::rezerwacja_tematu()
{
    //wczytaj plik
    ifstream plik_wczytaj;
    plik_wczytaj.open("tematy.txt");
    if (plik_wczytaj.is_open())
    {
        for (int i = 0; i < n; i++)
            getline(plik_wczytaj, tematy_magister[i]);
        plik_wczytaj.close();
    }
    else
    {
        cout << "Blad pliku, nieudany odczyt" << endl;
    }

    //rezerwacja
    string rezerwacja = " - temat zarezerwowany:";
    if (tematy_magister[id_pracy].length() < 15)
        tematy_magister[id_pracy] = tematy_magister[id_pracy].append(rezerwacja);
    else
        cout << "Temat jest juz zarezerwowany!" << endl;


    //zapisz plik
    ofstream plik_zapisz;
    plik_zapisz.open("tematy.txt");
    if (plik_zapisz.is_open())
    {
        for (int i = 0; i < n; i++)
            plik_zapisz << tematy_magister[i] << endl;
        plik_zapisz.close();
    }
    else
        cout << "Blad pliku, nieudany zapis" << endl;
}

void PracaDyplomowa::usuwanie_rezerwacji()
{
    //wczytaj plik
    ifstream plik_wczytaj;
    plik_wczytaj.open("tematy.txt");
    if (plik_wczytaj.is_open())
    {
        for (int i = 0; i < n; i++)
            getline(plik_wczytaj, tematy_magister[i]);
        plik_wczytaj.close();
    }
    else
    {
        cout << "Blad pliku, nieudany odczyt" << endl;
    }

    //usuniecie rezerwacji
    string usuniecie = " - temat zarezerwowany";
    tematy_magister[id_pracy] = tematy_magister[id_pracy].erase(15, usuniecie.length());


    //zapisz plik
    ofstream plik_zapisz;
    plik_zapisz.open("tematy.txt");
    if (plik_zapisz.is_open())
    {
        for (int i = 0; i < n; i++)
            plik_zapisz << tematy_magister[i] << endl;
        plik_zapisz.close();
    }
    else
        cout << "Blad pliku, nieudany zapis" << endl;
}

void PracaDyplomowa::wpisanie_oceny(){}
void PracaDyplomowa::wydrukuj_opis_pracy(){}

PracaDyplomowa::PracaDyplomowa(){}
PracaDyplomowa::~PracaDyplomowa(){}

/*
PracaDyplomowa::PracaDyplomowa(const PracaDyplomowa& r)
{
	//n = r.n;
	id_pracy = r.id_pracy;
	temat = r.temat;
	promotor = r.promotor;
	for(int i=0; i<n; i++)
		oceny[n] = r.oceny[n];
	liczba_recenzentow = r.liczba_recenzentow;
}
*/