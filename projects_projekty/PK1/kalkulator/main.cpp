#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <unordered_map>
#include <fstream>

#include "header.h"

using namespace std;



int main(int argc, char* argv[])
{

    //plik pamieci
    const int N = 5;
    string nazwa_pliku;
    string wartosci_pamieci[N];
    string wynik_str;

    //sprawdzanie wejscia
    string zapytanie_wyrazenia;                     //zawiera wyrazenie wpisane przez uzytkownika z przypisaniem pamieci, jesli zadane
    string wyrazenie;
    string pamiec;
    string::difference_type licz_znaki_rownosci;    //typ wymagaany dla uzycia count()
    int znak_rownosci;

    //obliczanie wyniku
    vector<string> symbole;
    float wynik;

    //konwersja liczby dziesietnej na inne systemy
    float calkowita;
    float ulamkowa;
    int calkowita_int;
    const int precyzja = 2;
    
    //zmienne interfejsu
    string odp_konwersja;
    string odp_calosc;
    bool ui_konwersja = false;
    bool ui_wyrazenie = false;
    bool ui_plik = false;
    bool ui_calosc = false;
    bool ui_pytanie_powtorki = false;

    //mapa operacji z priorytetami
    unordered_map<string, int> operacja = {
        { "^", 3},
        { "*", 2},
        { "/", 2},
        { "+", 1},
        { "-", 1},
        { "(", 0},
        { ")", 0},
    };


    cout << "Witaj w kalkulatorze! Podaj nazwe pliku zawierajacego pamiec (np. pamiec.txt)" << endl;
    getline(cin, nazwa_pliku);

    //ifstream - pobierz pamiec
    wczytaj_pamiec(nazwa_pliku, N, wartosci_pamieci, ui_plik);
    if (ui_plik == true)     return 0;      //zamkniecie programu po nieznalezionym pliku

    cout << "Podaj wyrazenie matematyczne (mozliwe znaki: ()+-*/^). Mozesz rowniez uzyc pamieci od M1 do M5 z pliku, "
        "aby pobrac z niej wartosc lub przypisac do niej wynik, dajac znak rownosci miedzy nazwa pamieci a wyrazeniem. "
        "Przyklad: M3=5+3*(4+2*(M5-7))-4/2 dla przypisania, 5+3*(4+2*(M5-7))-4/2 tylko dla wyniku. "
        "Mozna uzywac spacji"<< endl;
    while (ui_calosc == false)
    {
        //reset interfejsu
        wczytaj_pamiec(nazwa_pliku, N, wartosci_pamieci, ui_plik);  //wczytywanie pamieci za kazdym powtorzonym razem
        if (ui_plik == true)     return 0;
        ui_wyrazenie = false;
        ui_konwersja = false;
        ui_pytanie_powtorki = false;
        cout << "Podaj wyrazenie:" << endl;

        while (ui_wyrazenie == false)
        {
            getline(cin, zapytanie_wyrazenia);
            licz_znaki_rownosci = count(zapytanie_wyrazenia.begin(), zapytanie_wyrazenia.end(), '=');
            znak_rownosci = zapytanie_wyrazenia.find("=");      //sprawdza "=" i jego pozycje
            if (znak_rownosci != string::npos)                      //jesli "=" znajduje sie w zapytaniu
            {
                pamiec = zapytanie_wyrazenia.substr(0, znak_rownosci);                  //str do "="
                pamiec.erase(remove(pamiec.begin(), pamiec.end(), ' '), pamiec.end());  //usun spacje z nazwy pamieci
                wyrazenie = zapytanie_wyrazenia.substr(znak_rownosci + 1);              //str po "="
            }
            else wyrazenie = zapytanie_wyrazenia;

            //bledy wprowadzania
            if (licz_znaki_rownosci > 1)        //nadmiar "="
            {
                cout << "Mozna zastosowac jedynie jeden znak rownosci do zapisu pamieci, sprobuj ponownie" << endl;
            }
            else if (pamiec != "" && pamiec != "M1" && pamiec != "M2" && pamiec != "M3" && pamiec != "M4" && pamiec != "M5")
            {
                cout << "Mozna uzywac jedynie pamieci od M1 do M5, sprobuj ponownie" << endl;
            }
            else ui_wyrazenie = true;

        }
        znak_rownosci = 0;
        licz_znaki_rownosci = 0;
        


        //obliczenie wyniku z wyrazenia z wejscia
        symbole = rozbicie(wyrazenie, operacja);                        //rozbicie infiksowe
        symbole = konwersja_na_postfiks(symbole, operacja);             //rozbicie postfiksowe
        wynik = oblicz_wyrazenie(symbole, operacja, wartosci_pamieci);  //obliczenie postfiksu na wynik
        cout << "Wynik: " << wynik << endl;


        //zapisywanie wyniku do pamieci
        wynik_str = to_string(wynik);
        if (pamiec == "M1")
        {
            wartosci_pamieci[0] = wynik_str;
            cout << "Wynik zapisano do M1" << endl;
        }
        else if (pamiec == "M2")
        {
            wartosci_pamieci[1] = wynik_str;
            cout << "Wynik zapisano do M2" << endl;
        }
        else if (pamiec == "M3")
        {
            wartosci_pamieci[2] = wynik_str;
            cout << "Wynik zapisano do M3" << endl;
        }
        else if (pamiec == "M4")
        {
            wartosci_pamieci[3] = wynik_str;
            cout << "Wynik zapisano do M4" << endl;
        }
        else if (pamiec == "M5")
        {
            wartosci_pamieci[4] = wynik_str;
            cout << "Wynik zapisano do M5" << endl;
        }
        pamiec = "";

        //konwersja
        cout << "Czy chcesz przekonwertowac wynik na inne systemy liczbowe? T/N" << endl;
        while (ui_konwersja == false)
        {
            getline(cin, odp_konwersja);
            if (odp_konwersja == "T")
            {
                //rozbicie wyniku na czesc calkowita i ulamkowa
                ulamkowa = modf(wynik, &calkowita);
                calkowita_int = (int)calkowita;

                cout << "Wynik w systemie dwojkowym: ";
                dziesietna_bin(calkowita_int, ulamkowa, precyzja);
                cout << endl;

                cout << "Wynik w systemie osemkowym: ";
                dziesietna_oct(calkowita_int, ulamkowa, precyzja);
                cout << endl;

                cout << "Wynik w systemie szesnastkowym: ";
                dziesietna_hex(calkowita_int, ulamkowa, precyzja);
                cout << endl;
                ui_konwersja = true;
            }
            else if (odp_konwersja == "N")
            {
                ui_konwersja = true;
            }
            else
            {
                cout << "Niewlasciwa odpowiedz, sprobuj ponownie" << endl;
            }
        }
        

        cout << "Czy chcesz wprowadzic nowe wyrazenie? T/N" << endl;
        while (ui_pytanie_powtorki == false)
        {
            getline(cin, odp_calosc);
            if (odp_calosc == "T")
            {
                ui_pytanie_powtorki = true;
            }
            else if (odp_calosc == "N")
            {
                ui_pytanie_powtorki = true;
                ui_calosc = true;
            }
            else
            {
                cout << "Niewlasciwa odpowiedz, sprobuj ponownie" << endl;
            }
        }
        //ofstream - zapisz pamiec
        zapisz_pamiec(nazwa_pliku, N, wartosci_pamieci, ui_plik);
        if (ui_plik == true)     return 0;
    }
    cout << "Zamykanie kalkulatora..." << endl;
    return 0;
}



void wczytaj_pamiec(string& nazwa_pliku, const int& N, string wartosci_pamieci[], bool& ui_plik)
{
    ifstream plik;
    plik.open(nazwa_pliku);
    if (plik.is_open())
    {
        for (int i = 0; i < N; i++)
            getline(plik, wartosci_pamieci[i]);
        plik.close();
    }
    else
    {
        cout << "Blad pliku, sprawdz czy pamiec istnieje lub podaj wlasciwa nazwe" << endl;
        ui_plik = true;
    }
}



void zapisz_pamiec(string& nazwa_pliku, const int& N, string wartosci_pamieci[], bool& ui_plik)
{
    ofstream plik;
    plik.open(nazwa_pliku);
    if (plik.is_open())
    {
        for (int i = 0; i < N; i++)
            plik << wartosci_pamieci[i] << endl;
        plik.close();
    }
    else
    {
        cout << "Blad pliku, nieudany zapis" << endl;
        ui_plik = true;
    }
}



void dziesietna_bin(int& calkowita_int, float& ulamkowa, const int& precyzja)
{
    string zapis_binarny;
    int tmp_calkowita = calkowita_int;
    float tmp_ulamkowa = ulamkowa;
    while (calkowita_int > 0)
    {
        int bit = calkowita_int % 2;
        zapis_binarny.push_back(bit + '0');       //char
        calkowita_int /= 2;
    }
    reverse(zapis_binarny.begin(), zapis_binarny.end());    //odwroc calosc

    zapis_binarny.push_back('.');   //separator ulamkowy

    for (int i = 0; i < precyzja; i++)
    {
        ulamkowa *= 2;                  //metoda obliczania binarnego odpowiednika ulamkow dziesietnych
        int ulamkowa_bit = ulamkowa;    //bit 0 lub 1
        ulamkowa -= ulamkowa_bit;
        zapis_binarny.push_back(ulamkowa_bit + '0');
    }
    cout << zapis_binarny << endl;
    calkowita_int = tmp_calkowita;
    ulamkowa = tmp_ulamkowa;
}



void dziesietna_hex(int& calkowita_int, float& ulamkowa, const int& precyzja)
{
    string zapis_szesnastkowy;
    float tmp_ulamkowa = ulamkowa;
    int tmp = calkowita_int;
    for (int i = 0; i < precyzja; i++)
    {
        ulamkowa *= 16;
        int ulamkowa_bit = ulamkowa;    //bit 0 - 15
        if (ulamkowa_bit >= 0 && ulamkowa_bit <= 9)
        {
            ulamkowa -= ulamkowa_bit;
            zapis_szesnastkowy.push_back(ulamkowa_bit + '0');
        }
        else
        {
            switch (ulamkowa_bit)
            {
            case 10:
                ulamkowa -= ulamkowa_bit;
                zapis_szesnastkowy.push_back('A');
                break;
            case 11:
                ulamkowa -= ulamkowa_bit;
                zapis_szesnastkowy.push_back('B');
                break;
            case 12:
                ulamkowa -= ulamkowa_bit;
                zapis_szesnastkowy.push_back('C');
                break;
            case 13:
                ulamkowa -= ulamkowa_bit;
                zapis_szesnastkowy.push_back('D');
                break;
            case 14:
                ulamkowa -= ulamkowa_bit;
                zapis_szesnastkowy.push_back('E');
                break;
            case 15:
                ulamkowa -= ulamkowa_bit;
                zapis_szesnastkowy.push_back('F');
                break;
            }
        }
    }
    cout << uppercase << hex << calkowita_int << "." << zapis_szesnastkowy << endl;
    ulamkowa = tmp_ulamkowa;
}



void dziesietna_oct(int& calkowita_int, float& ulamkowa, const int& precyzja)
{
    float tmp_ulamkowa = ulamkowa;
    string zapis_osemkowy;
    int tmp;
    for (int i = 0; i < precyzja; i++)
    {
        ulamkowa *= 8;
        int ulamkowa_bit = ulamkowa;    //bit 0 - 7
        ulamkowa -= ulamkowa_bit;
        zapis_osemkowy.push_back(ulamkowa_bit + '0');
    }
    cout << oct << calkowita_int << "." << zapis_osemkowy << endl;
    ulamkowa = tmp_ulamkowa;
}



float oblicz_wyrazenie(vector<string>& zapis_postfiksowy, unordered_map<string, int>& operacja, string wartosci_pamieci[])
{
    //algorytm obliczania wartoœci ONP
    vector<float> dzialanie;
    for (string ity_symbol : zapis_postfiksowy)
    {
        //operator
        if (operacja.find(ity_symbol) != operacja.end())
        {
            float liczba1 = dzialanie[dzialanie.size() - 1];
            float liczba2 = dzialanie[dzialanie.size() - 2];

            switch (ity_symbol[0])
            {
            case '^':
                liczba2 = pow(liczba2, liczba1);
                break;
            case '+':
                liczba2 += liczba1;
                break;
            case '-':
                liczba2 -= liczba1;
                break;
            case '*':
                liczba2 *= liczba1;
                break;
            case '/':
                liczba2 /= liczba1;
                break;
            }
            dzialanie.pop_back();
            dzialanie.pop_back();
            dzialanie.push_back(liczba2);
        }
        //liczba
        else
        {
            if (ity_symbol == "M1")         dzialanie.push_back(atof(wartosci_pamieci[0].c_str()));     //atof laczy sie z c_str
            else if (ity_symbol == "M2")    dzialanie.push_back(atof(wartosci_pamieci[1].c_str()));
            else if (ity_symbol == "M3")    dzialanie.push_back(atof(wartosci_pamieci[2].c_str()));
            else if (ity_symbol == "M4")    dzialanie.push_back(atof(wartosci_pamieci[3].c_str()));
            else if (ity_symbol == "M5")    dzialanie.push_back(atof(wartosci_pamieci[4].c_str()));
            else                            dzialanie.push_back(atof(ity_symbol.c_str()));
        }
    }
    return dzialanie[0];
}



vector<string> konwersja_na_postfiks(vector<string> zapis_infiksowy, unordered_map <string, int>& operacja)
{
    vector<string> zapis_postfiksowy;
    vector<string> stos = { "(" };
    zapis_infiksowy.push_back(")");
    for (string ity_symbol : zapis_infiksowy)
    {
        //cout << token << endl;

        //liczba
        if (operacja.find(ity_symbol) == operacja.end())
            zapis_postfiksowy.push_back(ity_symbol);
        else if (ity_symbol == "(")
            stos.push_back(ity_symbol);
        else if (ity_symbol == ")")
        {
            while (stos.back() != "(")
            {
                zapis_postfiksowy.push_back(stos.back());
                stos.pop_back();
            }
            stos.pop_back();
        }
        //operator
        else
        {
            while (stos.size() > 0 && operacja[ity_symbol] <= operacja[stos.back()])
            {
                zapis_postfiksowy.push_back(stos.back());    //kolejnosc dzialan
                stos.pop_back();
            }
            stos.push_back(ity_symbol);
        }
    }

    return zapis_postfiksowy;
}



vector<string> rozbicie(string& wyrazenie, unordered_map<string, int>& operacja)
{
    vector<string> symbole;    //symbol - liczba lub operator
    string schowek;
    for (char c : wyrazenie)
    {
        if (c == ' ') continue;     //mozliwosc spacji
        //jesli symbol to operator nalezacy do mapy
        else if (operacja.find(string(1, c)) != operacja.end())     //konwersja char na string przez string()
        {
            if (schowek != "")     //pusty schowek psuje nawiasy
                symbole.push_back(schowek);
            schowek = "";
            symbole.push_back(string(1, c));
        }
        else schowek += c;  //wszystko dodane az do znaku operatora (kilkuznakowe liczby)
    }
    if (schowek != "")
        symbole.push_back(schowek);    //ostatnia liczba

    return symbole;
}