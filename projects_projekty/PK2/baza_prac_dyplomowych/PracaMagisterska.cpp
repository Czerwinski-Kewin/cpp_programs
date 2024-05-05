#include "PracaMagisterska.h"

void PracaMagisterska::wpisanie_oceny()
{
    //wczytaj plik
    ifstream plik_wczytaj;
    plik_wczytaj.open("oceny_magister.txt");
    if (plik_wczytaj.is_open())
    {
        for (int i = 0; i < n; i++)
            getline(plik_wczytaj, oceny_magister[i]);
        plik_wczytaj.close();
    }
    else
    {
        cout << "Blad pliku, nieudany odczyt" << endl;
    }

    //przydzial oceny
    oceny_magister[id_pracy] = ocena;
   
    
    //zapisz plik
    ofstream plik_zapisz;
    plik_zapisz.open("oceny_magister.txt");
    if (plik_zapisz.is_open())
    {
        for (int i = 0; i < n; i++)
            plik_zapisz << oceny_magister[i] << endl;  
        plik_zapisz.close();
    }
    else
        cout << "Blad pliku, nieudany zapis" << endl;
    
}

void PracaMagisterska::wydrukuj_opis_pracy()
{
    //wczytaj plik
    ifstream plik_wczytaj;
    plik_wczytaj.open("tematy_magister.txt");
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

    //
    //cout << "magister" << endl;
    //zapisz plik
    ofstream plik_zapisz;
    plik_zapisz.open("druk.txt");
    if (plik_zapisz.is_open())
    {
        for (int i = 0; i < n; i++)
            plik_zapisz << tematy_magister[i] << endl;
        plik_zapisz.close();
    }
    else
        cout << "Blad pliku, nieudany zapis" << endl;
}

void PracaMagisterska::rezerwacja_tematu()
{
    //wczytaj plik
    ifstream plik_wczytaj;
    plik_wczytaj.open("tematy_magister.txt");
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
    string rezerwacja = " - temat zarezerwowany";
    if (tematy_magister[id_pracy].length() < 16)
        tematy_magister[id_pracy] = tematy_magister[id_pracy].append(rezerwacja);
    else
        cout << "Temat jest juz zarezerwowany!" << endl;


    //zapisz plik
    ofstream plik_zapisz;
    plik_zapisz.open("tematy_magister.txt");
    if (plik_zapisz.is_open())
    {
        for (int i = 0; i < n; i++)
            plik_zapisz << tematy_magister[i] << endl;
        plik_zapisz.close();
    }
    else
        cout << "Blad pliku, nieudany zapis" << endl;
}

void PracaMagisterska::usuwanie_rezerwacji()
{
    //wczytaj plik
    ifstream plik_wczytaj;
    plik_wczytaj.open("tematy_magister.txt");
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
    if (tematy_magister[id_pracy].length() < 16)
        cout << "Temat nie jest zarezerwowany!" << endl;

    string usuniecie = " - temat zarezerwowany";
    tematy_magister[id_pracy] = tematy_magister[id_pracy].erase(15, usuniecie.length());
    


    //zapisz plik
    ofstream plik_zapisz;
    plik_zapisz.open("tematy_magister.txt");
    if (plik_zapisz.is_open())
    {
        for (int i = 0; i < n; i++)
            plik_zapisz << tematy_magister[i] << endl;
        plik_zapisz.close();
    }
    else
        cout << "Blad pliku, nieudany zapis" << endl;
}




PracaMagisterska::PracaMagisterska(){}
PracaMagisterska::~PracaMagisterska(){}

PracaMagisterska::PracaMagisterska(const PracaMagisterska& r)
{
    temat = r.temat;
    literatura_przedmiotu = r.literatura_przedmiotu;
}
