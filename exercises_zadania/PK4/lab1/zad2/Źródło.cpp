//import std;
import Book;
import Library;

using namespace std;

int main()
{
	Ksiazka ks1("nazwa1", "autor1");
	Ksiazka ks2("nazwa2", "autor2");
	Ksiazka ks3("nazwa3", "autor3");

	Biblioteka bibl;
	bibl.przechwyc_ksiazke(ks1);
	bibl.przechwyc_ksiazke(ks2);
	bibl.przechwyc_ksiazke(ks3);

	string tytul;
	string autor;

	cout << "Wpisz tytul: " << endl;
	cin >> tytul;
	bibl.znajdz_tytul(tytul);

	cout << "Wpisz autora: " << endl;
	cin >> autor;
	bibl.znajdz_autora(autor);

	bibl.wypisz();
}