#pragma once
#include <memory>
#include <iterator>
#include <cstddef>

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

	struct Iterator
	{
		using iterator_category = forward_iterator_tag;
		using difference_type = ptrdiff_t;
		using value_type = Item<T>;
		using pointer = Item<T>*;
		using reference = Item<T>&;

		Iterator(pointer ptr) : m_ptr(ptr) {}
		
		reference operator*() const { return *m_ptr; }
		pointer operator->() { return m_ptr; }

		Iterator& operator++() { m_ptr++; return *this; }

		Iterator operator++(int) { Iterator tmp = *this; ++(*this); return tmp; }

		friend bool operator== (const Iterator& a, const Iterator& b) { return a.m_ptr == b.m_ptr; };
		friend bool operator!= (const Iterator& a, const Iterator& b) { return a.m_ptr != b.m_ptr; };
	private:
		pointer m_ptr;
	};

	Iterator begin() { return Iterator(&head_); }
	Iterator end() { return Iterator(nullptr); }
private:
	unique_ptr<Item<T>> head_;
	//unique_ptr<Item<T>> tail_;
	unique_ptr<Item<T>> test;
	int size_;
};

