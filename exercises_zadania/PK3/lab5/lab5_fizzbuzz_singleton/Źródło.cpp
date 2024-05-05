#include <iostream>
#include <utility>
#include <memory>
#include <chrono>
#include <random>
#include <fstream>
#include <string>
#include "SingleList_Singleton.h"
#include "SmartPointer.h"
using namespace std;

template <typename T>
SingleList<T>::~SingleList()
{
	while (head_)
	{
		head_ = move(head_->next);
	}
}

template <typename T>
void SingleList<T>::prepend(const T& val)
{
	SmartPtr<Item<T>> old_head(move(head_));
	head_ = SmartPtr<Item<T>>();
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
	return temp->val;
}

template <typename T>
SingleList<T>& SingleList<T>::operator=(SingleList<T>&& r)
{
	head_ = r.head_;
	size_ = r.size_;
	return *this;
}



void odczyt(SingleList<int>& lista)
{
	ifstream plik_wczytaj("odczyt.txt");
	if (plik_wczytaj)
	{
		string temp;
		for (int i = 0; i < 10; i++)
		{
			getline(plik_wczytaj, temp);
			int x = stoi(temp);
			lista.prepend(x);
		}
			
	}
	plik_wczytaj.close();
}

void zapis(SingleList<int>& lista)
{
	ofstream plik_zapisz("zapis.txt");
	if (plik_zapisz)
	{
		for (int i = 0; i < 10; i++)
		{
			plik_zapisz << i << " - ";
			if (i % 3 == 0 && i % 5 == 0)
				plik_zapisz << "FizzBuzz";
			else if (i % 3 == 0)
				plik_zapisz << "Fizz";
			else if (i % 5 == 0)
				plik_zapisz << "Buzz";
			plik_zapisz << endl;
		}
		for (int i = 0; i < 100; i++)
			cout << lista.get(i);

	}
	plik_zapisz.close();
}

int main()
{
	SingleList<int>* lista = SingleList<int>::getInstance();
	zapis(lista);
	odczyt(lista);
	cout << endl;

	return 0;
}