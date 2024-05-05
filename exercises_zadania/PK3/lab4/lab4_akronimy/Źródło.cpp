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
    mapa["AGD"] = "artykuly gospodarstwa domowego";
    mapa["AZS"] = "Akademicki Zwiazek Sportowy";
    mapa["NBP"] = "Narodowy Bank Polski";
    mapa["PZU"] = "Powszechny Zaklad Ubezpieczen";
    mapa["RP"] = "Rzeczpospolita Polska";
    
    cout << "AGD AZS NBP PZU RP" << endl;
    string in;
    cin >> in;

    auto req = [](map<string, string> &mapa, string &in)
    {
        return mapa[in];
    };

    
    cout << req(mapa, in);


    return 0;
}