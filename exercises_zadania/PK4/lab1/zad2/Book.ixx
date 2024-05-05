export module Book;
import <iostream>;
//using namespace std;		//nie mozna uzyc calej przestrzeni nazw
using std::string;
export class Ksiazka {
public:
	string tytul;
	string autor;
	Ksiazka(string tytul_, string autor_) {
		tytul = tytul_;
		autor = autor_;
	}

	Ksiazka();
	~Ksiazka() {};
};