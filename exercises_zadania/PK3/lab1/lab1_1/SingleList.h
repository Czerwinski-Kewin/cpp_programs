#pragma once
#include <memory>
using namespace std;
template <typename T>
struct Item {
	T val;
	unique_ptr<Item<T>> next;
	//unique_ptr<typename Item<T>> next;
};

template <typename T>
class SingleList
{
public:
	SingleList() { size_ = 0; }
	~SingleList();
	bool empty() const { return size_ = 0; }
	int size() const { return size_; }
	void prepend(const T& val);
	T& get(int loc);
private:
	unique_ptr<Item<T>> head_;
	int size_;
};
