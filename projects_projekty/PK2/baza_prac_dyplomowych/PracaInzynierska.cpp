#include "PracaInzynierska.h"

void PracaInzynierska::wydrukuj_opis_pracy()
{
    //wczytaj plik
    ifstream plik_wczytaj;
    plik_wczytaj.open("tematy_inzynier.txt");
    if (plik_wczytaj.is_open())
    {
        for (int i = 0; i < n; i++)
            getline(plik_wczytaj, tematy_inzynier[i]);
        plik_wczytaj.close();
    }
    else
    {
        cout << "Blad pliku, nieudany odczyt" << endl;
    }

    //
    //cout << "inzynier" << endl;

    //zapisz plik
    ofstream plik_zapisz;
    plik_zapisz.open("druk.txt");
    if (plik_zapisz.is_open())
    {
        for (int i = 0; i < n; i++)
            plik_zapisz << tematy_inzynier[i] << endl;
        plik_zapisz.close();
    }
    else
        cout << "Blad pliku, nieudany zapis" << endl;
}

void PracaInzynierska::wpisanie_oceny()
{
    //wczytaj plik
    ifstream plik_wczytaj;
    plik_wczytaj.open("oceny_inzynier.txt");
    if (plik_wczytaj.is_open())
    {
        for (int i = 0; i < n; i++)
            getline(plik_wczytaj, oceny_inzynier[i]);
        plik_wczytaj.close();
    }
    else
    {
        cout << "Blad pliku, nieudany odczyt" << endl;
    }

    //przydzial oceny
    oceny_inzynier[id_pracy] = ocena;


    //zapisz plik
    ofstream plik_zapisz;
    plik_zapisz.open("oceny_inzynier.txt");
    if (plik_zapisz.is_open())
    {
        for (int i = 0; i < n; i++)
            plik_zapisz << oceny_inzynier[i] << endl;
        plik_zapisz.close();
    }
    else
        cout << "Blad pliku, nieudany zapis" << endl;
}

void PracaInzynierska::rezerwacja_tematu()
{
    //wczytaj plik
    ifstream plik_wczytaj;
    plik_wczytaj.open("tematy_inzynier.txt");
    if (plik_wczytaj.is_open())
    {
        for (int i = 0; i < n; i++)
            getline(plik_wczytaj, tematy_inzynier[i]);
        plik_wczytaj.close();
    }
    else
    {
        cout << "Blad pliku, nieudany odczyt" << endl;
    }

    //rezerwacja
    string rezerwacja = " - temat zarezerwowany";
    if (tematy_inzynier[id_pracy].length() < 16)
        tematy_inzynier[id_pracy] = tematy_inzynier[id_pracy].append(rezerwacja);
    else
        cout << "Temat jest juz zarezerwowany!" << endl;


    //zapisz plik
    ofstream plik_zapisz;
    plik_zapisz.open("tematy_inzynier.txt");
    if (plik_zapisz.is_open())
    {
        for (int i = 0; i < n; i++)
            plik_zapisz << tematy_inzynier[i] << endl;
        plik_zapisz.close();
    }
    else
        cout << "Blad pliku, nieudany zapis" << endl;
}

void PracaInzynierska::usuwanie_rezerwacji()
{
    //wczytaj plik
    ifstream plik_wczytaj;
    plik_wczytaj.open("tematy_inzynier.txt");
    if (plik_wczytaj.is_open())
    {
        for (int i = 0; i < n; i++)
            getline(plik_wczytaj, tematy_inzynier[i]);
        plik_wczytaj.close();
    }
    else
    {
        cout << "Blad pliku, nieudany odczyt" << endl;
    }

    //usuniecie rezerwacji
    if (tematy_inzynier[id_pracy].length() < 16)
        cout << "Temat nie jest zarezerwowany!" << endl;
    string usuniecie = " - temat zarezerwowany";
    tematy_inzynier[id_pracy] = tematy_inzynier[id_pracy].erase(15, usuniecie.length());
    


    //zapisz plik
    ofstream plik_zapisz;
    plik_zapisz.open("tematy_inzynier.txt");
    if (plik_zapisz.is_open())
    {
        for (int i = 0; i < n; i++)
            plik_zapisz << tematy_inzynier[i] << endl;
        plik_zapisz.close();
    }
    else
        cout << "Blad pliku, nieudany zapis" << endl;
}