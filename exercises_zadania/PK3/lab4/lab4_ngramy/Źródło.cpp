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

void odczyt1(vector<double>& procent)
{
    ifstream plik_wczytaj("procent.txt");
    if (plik_wczytaj)
    {
        istream_iterator<double> fin(plik_wczytaj);
        istream_iterator<double> eos;
        copy(fin, eos, back_inserter(procent));
    }
    plik_wczytaj.close();
}

void odczyt2(vector<string>& ngram)
{
    ifstream plik_wczytaj("ngram.txt");
    if (plik_wczytaj)
    {
        istream_iterator<string> fin(plik_wczytaj);
        istream_iterator<string> eos;
        copy(fin, eos, back_inserter(ngram));
    }
    plik_wczytaj.close();
}

int main()
{
    //Map<string, string> mapa;
    map<string, double> mapa;
    vector<double> procent;
    vector<string> ngram;

    odczyt1(procent);
    odczyt2(ngram);

    int i = 0;
    for (string c : ngram)
    {
        //cout << c << " - " << procent[i] << "%" << endl;
        //i++;
        mapa[c] = procent[i];
        i++;
    }

    for (const auto& c : mapa)
    {
        cout << c.first << " - " << c.second << "%" << endl;
    }
    

    auto gen_ngram = [](string slowo, int n) {
        vector<string> ngram;
        int i = 0;
        for (string s : ngram)
        {
            ngram.push_back(slowo.substr(i, n));
            i++;
        }
        return ngram;
    };

    auto v = gen_ngram("ciag wyrazow", 3);
    string wynik;
    //copy(v.begin(), v.end(), wynik);
    cout << wynik;
    

    return 0;
}