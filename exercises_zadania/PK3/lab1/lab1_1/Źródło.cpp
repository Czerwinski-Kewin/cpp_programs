#include <iostream>
#include <utility>
#include <memory>
#include <chrono>
#include <random>
#include "SingleList.h"
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
	return temp->val;
}


int main()
{
	//losowanie
	default_random_engine silnik(chrono::system_clock::now().time_since_epoch().count());
	uniform_int_distribution<int> rozklad(500, 1000);
	int losowa = rozklad(silnik);

	SingleList<char> lista;
	for (int i = 0; i < losowa; i++)
		lista.prepend('*');

	for (int i = 0; i < losowa; i++)
		cout << lista.get(i);

	cout << endl;
	cout << "Gwiazdki: " << lista.size() << endl;


	return 0;
}