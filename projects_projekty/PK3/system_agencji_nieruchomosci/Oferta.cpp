#include "Oferta.h"
#include "Lista.h"

Oferta::Oferta(string src_miasta, string src_ulice, string src_metry, string src_ceny, string src_sprzedaze)
{
	miasto = src_miasta;
	ulica = src_ulice;
	metry = src_metry;
	cena = src_ceny;
	sprzedaz = src_sprzedaze;
}

Oferta::Oferta() {}