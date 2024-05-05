#pragma once
using namespace std;
/// Funkcja rozbijajaca podane wyrazenie na pojedyncze symbole
/// 
/// Funkcja pobiera wyrazenie matematyczne podane przez uzytkownika i rozbija je na pojedyncze symbole w wektorze
/// umozliwiajac zastosowanie odwrotnej notacji polskiej przez funkcje konwersja_na_postfiks().
/// @param wyrazenie Wyrazenie matematyczne wydobyte z wejscia
/// @param operacja Mapa zawierajaca operacje matematyczne
/// @returns Wektor typu string z pojedynczymi symbolami (liczby lub znaki)
vector<string>rozbicie(string& wyrazenie, unordered_map<string, int>& operacja);

/// Funkcja zamieniajaca zapis infiksowy wyrazenia na zapis postfiksowy
/// 
/// Funkcja pobiera wektor z symbolami w zapisie infiksowym (domyslnym) i zmienia ich kolejnosc na postfiks
/// (znak operacji wystepuje po liczbach), co umozliwia obliczanie wyrazen z wykorzystaniem stosu
/// @param zapis_infiksowy Wektor typu string, jako ktory podajemy wektor poddany funkcji rozbicie()
/// @param operacja Mapa zawierajaca operacje matematyczne
/// @returns Wektor z pojedynczymi symbolami w kolejnosci postfiksowej
vector<string>konwersja_na_postfiks(vector<string> zapis_infiksowy, unordered_map <string, int>& operacja);

/// Funkcja obliczajaca wyrazenie z zapisu postfiksowego
/// 
/// Funkcja pobiera wektor symboli w zapisie postfiksowym i oblicza wlasciwy wynik wykorzystujac operacje stosu
/// @param zapis_postfiksowy Wektor typu string, jako ktory podajemy wektor poddany funkcji konwersja_na_postfiks()
/// @param operacja Mapa zawierajaca operacje matematyczne
/// @param wartosci_pamieci Tablica przechowujaca wartosci pamieci, z ktorych funkcja odczytuje wartosci
/// @returns Wynik wyrazenia matematycznego
float oblicz_wyrazenie(vector<string>& zapis_postfiksowy, unordered_map<string, int>& operacja, string wartosci_pamieci[]);

/// Funkcja konwertujaca liczbe dziesiatna na binarna
/// 
/// Funkcja pobiera osobno czesc calkowita i ulamkowa wyniku, a nastepnie zamienia je w zapis binarny
/// @param calkowita_int Czesc calkowita wyniku wyrazenia
/// @param ulamkowa Czesc ulamkowa wyniku wyrazenia
/// @param precyzja Stala decydujaca o ilosci cyfr po przecinku
void dziesietna_bin(int& calkowita_int, float& ulamkowa, const int& precyzja);

/// Funkcja konwertujaca liczbe dziesietna na szesnastkowa
/// 
/// Funkcja pobiera osobno czesc calkowita i ulamkowa wyniku, a nastepnie zamienia je w zapis szesnastkowy
/// @param calkowita_int Czesc calkowita wyniku wyrazenia
/// @param ulamkowa Czesc ulamkowa wyniku wyrazenia
/// @param precyzja Stala decydujaca o ilosci cyfr po przecinku
void dziesietna_hex(int& calkowita_int, float& ulamkowa, const int& precyzja);

/// Funkcja konwertujaca liczbe dziesiatna na osemkowa
/// 
/// Funkcja pobiera osobno czesc calkowita i ulamkowa wyniku, a nastepnie zamienia je w zapis osemkowy
/// @param calkowita_int Czesc calkowita wyniku wyrazenia
/// @param ulamkowa Czesc ulamkowa wyniku wyrazenia
/// @param precyzja Stala decydujaca o ilosci cyfr po przecinku
void dziesietna_oct(int& calkowita_int, float& ulamkowa, const int& precyzja);

/// Funkcja zapisujaca wartosci pamieci do pliku
/// 
/// Funkcja otwiera plik o podanej nazwie i zapisuje do pliku wartosci pamieci przechowywane w tablicy
/// @param nazwa_pliku Nazwa pliku podana na wejsciu
/// @param N Stala okreslajaca rozmiar tablicy wartosci pamieci
/// @param wartosci_pamieci Tablica przechowujaca wartosci pamieci do zapisu
/// @param ui_plik Zmienna zamykajaca program przy niepowodzeniu otwarcia pliku
void zapisz_pamiec(string& nazwa_pliku, const int& N, string wartosci_pamieci[], bool& ui_plik);

/// Funkcja wczytujaca wartosci pamieci z pliku
///
/// Funkcja otwiera plik o podanej nazwie i pobiera wartosci pamieci z pliku do tablicy, umozliwiajac ich odczyt
/// @param nazwa_pliku Nazwa pliku podana na wejsciu
/// @param N Stala okreslajaca rozmiar tablicy wartosci pamieci
/// @param wartosci_pamieci Tablica przechowujaca pobrane wartosci pamieci
/// @param ui_plik Zmienna zamykajaca program przy niepowodzeniu otwarcia pliku
void wczytaj_pamiec(string& nazwa_pliku, const int& N, string wartosci_pamieci[], bool& ui_plik);