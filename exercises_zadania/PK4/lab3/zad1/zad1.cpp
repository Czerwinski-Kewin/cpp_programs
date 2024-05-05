#include <filesystem>
#include <string>
#include <fstream>
using namespace std;
int main()
{
	filesystem::path sciezka("folder1\\folder2\\folder3");
	filesystem::create_directories(sciezka);
	ofstream{ sciezka / "plik.txt" };
}