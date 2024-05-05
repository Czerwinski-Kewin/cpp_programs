#include <iostream>
#include <utility>
#include <memory>
#include <chrono>
#include <random>
#include <string>
#include "FizzBuzz.h"
using namespace std;

template <typename T>
FizzBuzz<T>::FizzBuzz(int _n)
{
	n = _n;
	tab = make_unique<T[]>(n);
	for (int i = 1; i < n; i++)
	{
		if (i % 3 == 0 && i % 5 == 0)
			tab[i] = "FizzBuzz";
		else if (i % 3 == 0)
			tab[i] = "Fizz";
		else if (i % 5 == 0)
			tab[i] = "Buzz";
		else
		{
			string str = to_string(i);
			tab[i] = str;
		}
	}

}

template <typename T>
void FizzBuzz<T>::print()
{
	for (int i = 0; i < n; i++)
		cout << tab[i] << endl;
}

template <typename T>
FizzBuzz<T>::FizzBuzz() {}


int main()
{
	FizzBuzz<string> fizz(100);
	fizz.print();
	return 0;
}