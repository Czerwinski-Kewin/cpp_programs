#include <iostream>
#include <utility>
#include <memory>
#include <chrono>
#include <random>
#include <fstream>
#include <string>
#include "SingleList.h"
using namespace std;

template <typename T>
SingleList<T>::~SingleList()
{
	while (head_)
	{
		head_ = move(head_->next);
	}
	//tail_ = nullptr;
}

template <typename T>
void SingleList<T>::prepend(const T& val)
{
	unique_ptr<Item<T>> old_head(move(head_));
	head_ = make_unique<Item<T>>();
	head_->val = val;
	head_->next = move(old_head);
	size_++;
}

template <typename T>
T& SingleList<T>::get(int loc)
{
	Item<T>* temp = head_.get();
	while (temp && loc != 0)
	{
		temp = temp->next.get();
		loc--;
	}
	test = Item::next;
	return temp->val;
}

void odczyt(SingleList<int>& lista)
{
	ifstream plik_wczytaj("odczyt.txt");
	if (plik_wczytaj)
	{
		istream_iterator<int> fin(plik_wczytaj);
		istream_iterator<int> eos;
		copy(fin, eos, back_inserter(lista));
	}
	plik_wczytaj.close();
}

void zapis(SingleList<int>& lista)
{
	ofstream plik_zapisz("zapis.txt");
	if (plik_zapisz)
	{
		for (Item<int> c : lista)
		{
			plik_zapisz << c;
			int m = 2;
			int x, y, z = 0;
			while (z < c)
			{
				for (int n = 1; n < m; ++n)
				{
					x = m * m - n * n;
					y = 2 * m * n;
					z = m * m + n * n;
					if (z > c) break;
					plik_zapisz << x, y, z;
				}
			}
		}
		ostream_iterator<int> cout_it(cout);
		copy(lista.begin(), lista.end(), cout_it);
	}
	plik_zapisz.close();
}

int main()
{

	SingleList<int> lista;
	odczyt(lista);
	
	zapis(lista);


	return 0;
}