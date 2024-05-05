#pragma once
#include <iostream>
#include <memory>
#include "SmartPointer.h"
using namespace std;
template <typename T>
struct Item {
	T val;
	SmartPtr<Item<T>> next;
	//unique_ptr<typename Item<T>> next;
};

template <typename T>
class SingleList
{
public:
	~SingleList();
	bool empty() const { return size_ = 0; }
	int size() const { return size_; }
	void prepend(const T& val);
	T& get(int loc);
	SingleList& operator=(SingleList&& r);
	SingleList(const SingleList& obj) = delete;
	static SingleList* getInstance()
	{
		if (instancePtr == NULL)
		{
			instancePtr = new SingleList();
			return instancePtr;
		}
		else
			return instancePtr;
	}
	void setValues(int size_, Item<T> head_)
	{
		this->size_ = size_;
		this->head_ = head_;
	}
	SingleList* SingleList::getInstance() = NULL;
private:
	static SingleList* instancePtr;
	SmartPtr<Item<T>> head_;
	int size_;
	SingleList() { size_ = 0; }
};