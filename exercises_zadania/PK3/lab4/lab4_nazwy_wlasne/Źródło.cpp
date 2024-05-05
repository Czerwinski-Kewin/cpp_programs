#include <iostream>
#include <utility>
#include <memory>
#include <chrono>
#include <random>
#include <fstream>
#include <string>
#include <map>
#include "Map.h"
using namespace std;

template <typename I, typename T>
Item<I, T>::Item(T val_)
{
    val = val_;
    next = nullptr;
};

template <typename I, typename T>
Item<I, T>::Item()
{
    next = nullptr;
};

template <typename Key, typename T>
Map<Key, T>::Map(Map&& rhs) : first(nullptr), size(0)
{
    size_ = rhs.size_;
    first = rhs.first;
    rhs.size_ = 0;
    rhs.first = nullptr;
};

template <typename Key, typename T>
Map<Key, T>::Map()
{
    first = nullptr;
    size_ = 0;
};

template <typename Key, typename T>
Map<Key, T>::~Map()
{
    first = nullptr;
    size_ = 0;
};

template <typename Key, typename T>
Map<Key, T>& Map<Key, T>::operator=(Map&& rhs)
{
    if (*this != rhs)
    {
        size_ = rhs.size_;
        first = rhs.first;
        rhs.size_ = 0;
        rhs.first = nullptr;
    }
    return *this;
};

template <typename Key, typename T>
T Map<Key, T>::operator[](Key key)
{
    shared_ptr<Item<Key, T>> tmp;
    tmp = first;

    while (tmp->next != nullptr)
    {
        if (tmp->id == key)
        {
            return tmp->val;
        }
        else
        {
            tmp = tmp->next;
        }
    }
    return tmp->val;
};

template <typename Key, typename T>
void Map<Key, T>::push_back(Key key, T val_)
{
    shared_ptr<Item<Key, T>> it(new Item<Key, T>());
    it->val = val_;
    it->id = key;

    if (first == nullptr)
    {
        first = it;
    }
    else
    {
        shared_ptr<Item<Key, T>> tmp;
        tmp = first;

        while (tmp->next != nullptr)
            tmp = tmp->next;

        tmp->next = it;
        it->next = nullptr;
    }
    size_++;
};

template <typename Key, typename T>
int Map<Key, T>::size()
{
    return size_;
};

template <typename Key, typename T>
bool Map<Key, T>::empty()
{
    if (size_ == 0)
        return true;
    else
        return false;
};

template <typename Key, typename T>
void Map<Key, T>::push_back(T val_)
{
    shared_ptr<Item<Key, T>> it(new Item<Key, T>());
    it->val = val_;

    if (first == nullptr)
    {
        first = it;
    }
    else
    {
        shared_ptr<Item<Key, T>> tmp;
        tmp = first;

        while (tmp->next != nullptr)
            tmp = tmp->next;

        tmp->next = it;
        it->next = nullptr;
    }
    size_++;
};


int main()
{
    //Map<string, string> mapa;
    map<string, string> mapa;
    vector<double> procent;
    vector<string> ngram;
    string zdanie = "Aaaaaa NW1 bbbbb NW2 ccccccc NW3.";
    cout << zdanie << endl;
    
    mapa["NW1"] = "Nazwa wlasna 1";
    mapa["NW2"] = "Nazwa wlasna 2";
    mapa["NW3"] = "Nazwa wlasna 3";
    mapa["NW4"] = "Nazwa wlasna 4";
    
    string::size_type is1 = zdanie.find("NW1");
    string::size_type is2 = zdanie.find("NW2");
    string::size_type is3 = zdanie.find("NW3");
    string::size_type is4 = zdanie.find("NW4");
    if (is1 != string::npos)
    {
        cout << "Znaleziono NW1 - " << mapa["NW1"] << endl;
    }
    if (is2 != string::npos)
    {
        cout << "Znaleziono NW2 - " << mapa["NW2"] << endl;
    }
    if (is3 != string::npos)
    {
        cout << "Znaleziono NW3 - " << mapa["NW3"] << endl;
    }
    if (is4 != string::npos)
    {
        cout << "Znaleziono NW4 - " << mapa["NW4"] << endl;
    }

    return 0;
}