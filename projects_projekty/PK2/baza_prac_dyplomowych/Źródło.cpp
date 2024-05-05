#include <string>
#include <memory>
#include <fstream>
#include <iostream>

#include "Nag³ówek.h"

#include "PracaDyplomowa.h"
#include "PracaMagisterska.h"
#include "PracaInzynierska.h"
#include "PracaDoktorska.h"
#include "Przydzial.h"

using namespace std;


int main()
{
    string getline_bufor;
    int ui_id_pracy;
    string ui_ocena;
    string ui_wybor;
    bool ui_petla = false;

    int ui_dzien;
    int ui_miesiac;
    int ui_rok;
    string ui_osoba;
    string ui_typ;
    string ui_przydzial_typ;
    


    PracaDyplomowa dyp;
    PracaMagisterska test;

    while (ui_petla == false)
    {
        cout << "Baza prac magisterskich - wybierz opcje: \n 1 - Wpisz ocene \n 2 - Zarezerwuj temat \n "
            "3 - Usun rezerwacje tematu \n 4 - Przydziel prace \n 5 - Wydrukuj do pliku dostepne prace" << endl;
        getline(cin, ui_wybor);

        if (ui_wybor == "1")
        {
            cout << "Wpisanie oceny - podaj typ (Magister/Inzynier/Doktor)" << endl;
            getline(cin, getline_bufor);
            ui_typ = getline_bufor;
            if (ui_typ == "Magister")
            {
                cout << "Wpisanie oceny - podaj ID pracy" << endl;
                getline(cin, getline_bufor);
                ui_id_pracy = stoi(getline_bufor);

                cout << "Wpisanie oceny - wpisz ocene" << endl;
                getline(cin, getline_bufor);
                ui_ocena = getline_bufor;

                PracaMagisterska o;
                PracaDyplomowa* pd = &o;
                pd->id_pracy = ui_id_pracy;
                pd->ocena = ui_ocena;
                pd->wpisanie_oceny();
            }
            else if (ui_typ == "Inzynier")
            {
                cout << "Wpisanie oceny - podaj ID pracy" << endl;
                getline(cin, getline_bufor);
                ui_id_pracy = stoi(getline_bufor);

                cout << "Wpisanie oceny - wpisz ocene" << endl;
                getline(cin, getline_bufor);
                ui_ocena = getline_bufor;

                PracaInzynierska o;
                PracaDyplomowa* pd = &o;
                pd->id_pracy = ui_id_pracy;
                pd->ocena = ui_ocena;
                pd->wpisanie_oceny();
            }
            else if (ui_typ == "Doktor")
            {
                cout << "Wpisanie oceny - podaj ID pracy" << endl;
                getline(cin, getline_bufor);
                ui_id_pracy = stoi(getline_bufor);

                cout << "Wpisanie oceny - wpisz ocene" << endl;
                getline(cin, getline_bufor);
                ui_ocena = getline_bufor;

                PracaDoktorska o;
                PracaDyplomowa* pd = &o;
                pd->id_pracy = ui_id_pracy;
                pd->ocena = ui_ocena;
                pd->wpisanie_oceny();
            }
        }
        else if (ui_wybor == "2")
        {
            cout << "Rezerwacja tematu - podaj typ (Magister/Inzynier/Doktor)" << endl;
            getline(cin, getline_bufor);
            ui_typ = getline_bufor;
            PracaDyplomowa* pd = nullptr;
            
            

            if (ui_typ == "Magister")
            {
                //cout << "Rezerwacja tematu - podaj ID pracy" << endl;
                //getline(cin, getline_bufor);
                //ui_id_pracy = stoi(getline_bufor);

                PracaMagisterska* o = new PracaMagisterska;
                //PracaDyplomowa* pd = &o;
                pd = o;
                
                
            }
            else if (ui_typ == "Inzynier")
            {
                //cout << "Rezerwacja tematu - podaj ID pracy" << endl;
                //getline(cin, getline_bufor);
                //ui_id_pracy = stoi(getline_bufor);

                PracaInzynierska* o = new PracaInzynierska;
                //PracaDyplomowa* pd = &o;
                pd = o;
                
                //pd->id_pracy = ui_id_pracy;
                //pd->rezerwacja_tematu();
            }
            else if (ui_typ == "Doktor")
            {
                //cout << "Rezerwacja tematu - podaj ID pracy" << endl;
                //getline(cin, getline_bufor);
                //ui_id_pracy = stoi(getline_bufor);

                PracaDoktorska* o = new PracaDoktorska;
                //PracaDyplomowa* pd = &o;
                pd = o;
                
                //pd->id_pracy = ui_id_pracy;
                //pd->rezerwacja_tematu();
            }
            //cout << "Temat zarezerwowany" << endl;
            cout << "Rezerwacja tematu - podaj ID pracy" << endl;
            getline(cin, getline_bufor);
            ui_id_pracy = stoi(getline_bufor);

            pd->id_pracy = ui_id_pracy;
            pd->rezerwacja_tematu();

            delete pd;  //usuniecie wskaznikow na o (pd je przejmuje)
            
        }
        else if (ui_wybor == "3")
        {
            cout << "Usuwanie rezerwacji - podaj typ (Magister/Inzynier/Doktor)" << endl;
            getline(cin, getline_bufor);
            ui_typ = getline_bufor;
            if (ui_typ == "Magister")
            {
                cout << "Usuwanie rezerwacji - podaj ID pracy" << endl;
                getline(cin, getline_bufor);
                ui_id_pracy = stoi(getline_bufor);

                PracaMagisterska o;
                PracaDyplomowa* pd = &o;
                pd->id_pracy = ui_id_pracy;
                pd->usuwanie_rezerwacji();
            }
            else if (ui_typ == "Inzynier")
            {
                cout << "Usuwanie rezerwacji - podaj ID pracy" << endl;
                getline(cin, getline_bufor);
                ui_id_pracy = stoi(getline_bufor);

                PracaInzynierska o;
                PracaDyplomowa* pd = &o;
                pd->id_pracy = ui_id_pracy;
                pd->usuwanie_rezerwacji();
            }
            else if (ui_typ == "Doktor")
            {
                cout << "Usuwanie rezerwacji - podaj ID pracy" << endl;
                getline(cin, getline_bufor);
                ui_id_pracy = stoi(getline_bufor);

                PracaDoktorska o;
                PracaDyplomowa* pd = &o;
                pd->id_pracy = ui_id_pracy;
                pd->usuwanie_rezerwacji();
            }
            //cout << "Rezerwacja usunieta" << endl;

        }
        else if (ui_wybor == "4")
        {
            cout << "Przydzial pracy - podaj ID pracy, date oraz osobe" << endl;
            cout << "ID pracy: ";
            getline(cin, getline_bufor);
            ui_id_pracy = stoi(getline_bufor);

            cout << "Dzien: ";
            getline(cin, getline_bufor);
            ui_dzien = stoi(getline_bufor);

            cout << "Miesiac: ";
            getline(cin, getline_bufor);
            ui_miesiac = stoi(getline_bufor);

            cout << "Rok: ";
            getline(cin, getline_bufor);
            ui_rok = stoi(getline_bufor);

            cout << "Osoba: ";
            getline(cin, getline_bufor);
            ui_osoba = getline_bufor;

            cout << "Typ pracy: ";
            getline(cin, getline_bufor);
            ui_przydzial_typ = getline_bufor;

            Przydzial prz(ui_id_pracy, ui_dzien, ui_miesiac, ui_rok, ui_osoba, ui_przydzial_typ);
            //cout << prz.przydzialy[0];
        }
        else if (ui_wybor == "5")
        {
            cout << "Wydruk dostepnosci prac danego typu - podaj typ (Magister/Inzynier/Doktor)" << endl;
            getline(cin, getline_bufor);
            ui_typ = getline_bufor;
            if (ui_typ == "Magister")
            {
                PracaMagisterska o;
                PracaDyplomowa* pd = &o;
                pd->wydrukuj_opis_pracy();
            }
            else if (ui_typ == "Inzynier")
            {
                PracaInzynierska o;
                PracaDyplomowa* pd = &o;
                pd->wydrukuj_opis_pracy();
            }
            if (ui_typ == "Doktor")
            {
                PracaDoktorska o;
                PracaDyplomowa* pd = &o;
                pd->wydrukuj_opis_pracy();
            }
        }
        cout << "Czy chcesz wprowadzic nowe polecenie? (T/N)" << endl;
        getline(cin, getline_bufor);
        if (getline_bufor == "T")
            ui_petla = false;
        else if (getline_bufor == "N")
            ui_petla = true;
    }
    cout << "Zamykanie bazy..." << endl;
    
	return 0;
}