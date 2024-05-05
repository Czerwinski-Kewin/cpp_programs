export module Library;
import Book;
import <iostream>;
import <vector>;
//using namespace std;		//nie mozna uzyc calej przestrzeni nazw
using std::string;
using std::cout;
using std::endl;
export class Biblioteka {
public:
	std::vector<Ksiazka> ksiazki;

	void przechwyc_ksiazke(Ksiazka kzap) {
		ksiazki.push_back(kzap);
	}
	void znajdz_tytul(string _tytul) {
		for (Ksiazka c : ksiazki)
		{
			if (c.tytul == _tytul)
				cout << "Znaleziono tytul: " << c.tytul << endl;
		}
	}

	void znajdz_autora(string _autor) {
		for (Ksiazka c : ksiazki)
		{
			if (c.autor == _autor)
				cout << "Znaleziono autora: " << c.autor << endl;
		}
	}

	void wypisz() {
		cout << "Zbior ksiazek: " << endl;
		for (Ksiazka c : ksiazki)
		{
			cout << c.tytul << " " << c.autor << endl;
		}
	}
};