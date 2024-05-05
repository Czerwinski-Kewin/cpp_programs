#include "Przydzial.h"

Przydzial::Przydzial(){}

Przydzial::Przydzial(int _id_pracy, int _dzien, int _miesiac, int _rok, string _osoba, string _typ)
{
	id_pracy = _id_pracy;
	dzien = _dzien;
	miesiac = _miesiac;
	rok = _rok;
	osoba = _osoba;
    typ = _typ;

    //wczytaj plik
    ifstream plik_wczytaj;
    plik_wczytaj.open("przydzialy.txt");
    if (plik_wczytaj.is_open())
    {
        for (int i = 0; i < n; i++)
            getline(plik_wczytaj, przydzialy[i]);
        plik_wczytaj.close();
    }
    else
    {
        cout << "Blad pliku, nieudany odczyt" << endl;
    }

    //zapis przydzialu
    stringstream ss;
    ss << *this;
    przydzialy[id_pracy] = ss.str();


    //zapisz plik
    ofstream plik_zapisz;
    plik_zapisz.open("przydzialy.txt");
    if (plik_zapisz.is_open())
    {
        for (int i = 0; i < n; i++)
            plik_zapisz << przydzialy[i] << endl;
        plik_zapisz.close();
    }
    else
        cout << "Blad pliku, nieudany zapis" << endl;
}

ostream& operator <<(ostream& ostr, const Przydzial& obj)
{
    ostr << obj.id_pracy << " " << obj.dzien << " " << obj.miesiac << " " << obj.rok << " " << obj.osoba << " " << obj.typ << endl;
    return ostr;
}