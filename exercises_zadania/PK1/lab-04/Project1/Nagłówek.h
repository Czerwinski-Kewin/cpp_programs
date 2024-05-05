#include <iomanip>

//losowanie
std::default_random_engine silnik(std::chrono::system_clock::now().time_since_epoch().count());
std::uniform_int_distribution<int> rozklad(50, 100);


//funkcja zwracaj¹ca wylosowan¹ liczbê ca³kowit¹
//return liczba ca³kowita
int los()
{
	int losowa = rozklad(silnik);
	return losowa;
}

const int N = 10;
const int a = 2;

int tab1[a][N];
void tablica(int tab1[][N], const int & min1, const int & max1, int a)
{
	int suma = 0;
	for (int j = 0; j < a; j++)
	{
		for (int i = 0; i < N; i++)
		{
			tab1[j][i] = los();
			suma += tab1[j][i];
			std::cout << std::setw(4) << tab1[j][i] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << "sum=" << suma << " " << "min=" << min1 << " " << "max=" << max1;
	
}

void zamiana(int tab1[][N], int a)
{
	int nastepna;
	for (int j = 0; j < a; j++)
	{
		for (int i = 0; i < N; i++)
		{
			tab1[j][i] = los();
			nastepna = tab1[j][i];
			tab1[j][i] = tab1[i][j];
			tab1[i][j] = nastepna;
			std::cout << std::setw(4) << tab1[j][i] << " ";
		}
		nastepna = j;
		a = N;
		//N = nastepna;
		std::cout << std::endl;
	}
	//int c=a
	//a=b
	//b=c
}
