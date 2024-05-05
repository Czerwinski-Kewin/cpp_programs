#include "PracaDoktorska.h"

void PracaDoktorska::wydrukuj_opis_pracy()
{
    //wczytaj plik
    ifstream plik_wczytaj;
    plik_wczytaj.open("tematy_doktor.txt");
    if (plik_wczytaj.is_open())
    {
        for (int i = 0; i < n; i++)
            getline(plik_wczytaj, tematy_doktor[i]);
        plik_wczytaj.close();
    }
    else
    {
        cout << "Blad pliku, nieudany odczyt" << endl;
    }

    //
    //cout << "doktor" << endl;

    //zapisz plik
    ofstream plik_zapisz;
    plik_zapisz.open("druk.txt");
    if (plik_zapisz.is_open())
    {
        for (int i = 0; i < n; i++)
            plik_zapisz << tematy_doktor[i] << endl;
        plik_zapisz.close();
    }
    else
        cout << "Blad pliku, nieudany zapis" << endl;
}

void PracaDoktorska::wpisanie_oceny()
{
    //wczytaj plik
    ifstream plik_wczytaj;
    plik_wczytaj.open("oceny_doktor.txt");
    if (plik_wczytaj.is_open())
    {
        for (int i = 0; i < n; i++)
            getline(plik_wczytaj, oceny_doktor[i]);
        plik_wczytaj.close();
    }
    else
    {
        cout << "Blad pliku, nieudany odczyt" << endl;
    }

    //przydzial oceny
    oceny_doktor[id_pracy] = ocena;


    //zapisz plik
    ofstream plik_zapisz;
    plik_zapisz.open("oceny_doktor.txt");
    if (plik_zapisz.is_open())
    {
        for (int i = 0; i < n; i++)
            plik_zapisz << oceny_doktor[i] << endl;
        plik_zapisz.close();
    }
    else
        cout << "Blad pliku, nieudany zapis" << endl;
}

void PracaDoktorska::rezerwacja_tematu()
{
    //wczytaj plik
    ifstream plik_wczytaj;
    plik_wczytaj.open("tematy_doktor.txt");
    if (plik_wczytaj.is_open())
    {
        for (int i = 0; i < n; i++)
            getline(plik_wczytaj, tematy_doktor[i]);
        plik_wczytaj.close();
    }
    else
    {
        cout << "Blad pliku, nieudany odczyt" << endl;
    }

    //rezerwacja
    string rezerwacja = " - temat zarezerwowany";
    if (tematy_doktor[id_pracy].length() < 16)
        tematy_doktor[id_pracy] = tematy_doktor[id_pracy].append(rezerwacja);
    else
        cout << "Temat jest juz zarezerwowany!" << endl;


    //zapisz plik
    ofstream plik_zapisz;
    plik_zapisz.open("tematy_doktor.txt");
    if (plik_zapisz.is_open())
    {
        for (int i = 0; i < n; i++)
            plik_zapisz << tematy_doktor[i] << endl;
        plik_zapisz.close();
    }
    else
        cout << "Blad pliku, nieudany zapis" << endl;
}

void PracaDoktorska::usuwanie_rezerwacji()
{
    //wczytaj plik
    ifstream plik_wczytaj;
    plik_wczytaj.open("tematy_doktor.txt");
    if (plik_wczytaj.is_open())
    {
        for (int i = 0; i < n; i++)
            getline(plik_wczytaj, tematy_doktor[i]);
        plik_wczytaj.close();
    }
    else
    {
        cout << "Blad pliku, nieudany odczyt" << endl;
    }

    //usuniecie rezerwacji
    if (tematy_doktor[id_pracy].length() < 16)
        cout << "Temat nie jest zarezerwowany!" << endl;

    string usuniecie = " - temat zarezerwowany";
    tematy_doktor[id_pracy] = tematy_doktor[id_pracy].erase(15, usuniecie.length());
    


    //zapisz plik
    ofstream plik_zapisz;
    plik_zapisz.open("tematy_doktor.txt");
    if (plik_zapisz.is_open())
    {
        for (int i = 0; i < n; i++)
            plik_zapisz << tematy_doktor[i] << endl;
        plik_zapisz.close();
    }
    else
        cout << "Blad pliku, nieudany zapis" << endl;
}