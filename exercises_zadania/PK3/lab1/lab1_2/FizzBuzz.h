#pragma once
#include <iostream>
#include <memory>
using namespace std;

template <typename T>
class FizzBuzz
{
public:
	int n;
	//T tab[size];
	unique_ptr<T[]> tab;
	FizzBuzz();
	FizzBuzz(int _n);
	void print();
};
