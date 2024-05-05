#include <filesystem>
#include <string>
#include <fstream>
using namespace std;
int main()
{
	//zad1
	filesystem::path sciezka("folder1\\folder2\\folder3");
	filesystem::create_directories(sciezka);
	ofstream{ sciezka / "plik.txt" };

	//zad2
	filesystem::copy_file("folder1/folder2/folder3/plik.txt", "folder1/folder2/folder3/plik2.txt");
	filesystem::path sciezka2("nowyfolder");
	filesystem::create_directories(sciezka2);
	filesystem::copy("folder1", "nowyfolder", filesystem::copy_options::recursive);

	//zad3
	filesystem::remove_all("folder1");
}