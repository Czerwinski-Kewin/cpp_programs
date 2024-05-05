#pragma once
#include <iostream>
#include <memory>
using namespace std;

template <typename I, typename T>
class Item
{
public:
	I id;
	T val;
	shared_ptr<Item<I, T>> next;
	Item(T);
	Item();
};

template <typename Key, typename T>
class Map
{
	Key key;
	int size_;
	shared_ptr<Item<Key, T>> first;
public:
	Map(Map&&);
	Map();
	~Map();
	Map& operator=(Map&&);
	T operator[](Key);
	void push_back(Key, T);
	void push_back(T);
	int size();
	bool empty();
};
