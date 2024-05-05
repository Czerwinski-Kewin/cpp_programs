#pragma once
#include <iostream>
using namespace std;

template <typename T>
class MyVector
{
	T* arr;
	int capacity;
	int current;
public:
	MyVector();
	~MyVector();
	void push(T data);
	void push(T data, int index);
	T get(int index);
	void pop();
	int size();
	int getCapacity();
	void print();
	MyVector& operator=(MyVector&& r);
};