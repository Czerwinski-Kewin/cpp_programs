#include <iostream>
#include <regex>
#include <string>

using namespace std;

int main()
{	
	string oryginal = "Zasadzil dziadek rzepke w ogrodzie,\n"
		"Chodzil te rzepke ogladac co dzien.\n"
		"Wyrosla rzepka jedrna i krzepka,\n"
		"Schrupac by rzepke z kawalkiem chlebka!\n"
		"Wiec ciagnie rzepke dziadek nieboze,\n"
		"Ciagnie i ciagnie, wyciagnac nie moze.\n"
		"\n"
		"Zawolal dziadek na pomoc babcie:\n"
		"\"Ja zlapie rzepke, ty za mnie zlap sie!\"\n"
		"I biedny dziadek z babcia nieboga\n"
		"Ciagna i ciagna, wyciagnac nie moga.\n"
		"Babcia za dziadka,\n"
		"Dziadek za rzepke,\n"
		"Oj, przydalby sie ktos na przyczepke!\n";
	regex slowo("\\srzepk[a-z]+");
	string podmiana;
	podmiana = regex_replace(oryginal, slowo, " drzwi");	//spacja za znak bialy w regex
	cout << podmiana << endl;

	return 0;
}