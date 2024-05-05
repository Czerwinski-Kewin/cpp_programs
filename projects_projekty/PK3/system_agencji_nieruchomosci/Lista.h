#pragma once
#include <iostream>
#include <memory>
#include <stdexcept>
#include <vector>
using namespace std;

template<typename T>
class Lista {
private:
    struct Element {
        T dane;
        unique_ptr<Element> nastepny;

        Element(const T& wartosc) : dane(wartosc), nastepny(nullptr) {}
    };

    unique_ptr<Element> head;

public:
    Lista();
    Lista(const Lista& src);
    Lista(Lista&& src) noexcept;
    Lista& operator=(const Lista& src);
    Lista& operator=(Lista&& src) noexcept;
    ~Lista() = default;

    void dodaj(const T& wartosc);
    void usun(int indeks);
    T& get(int indeks);
    void wyswietl();
    size_t size() const;
    vector<int> szukaj(const T& fraza) const;
    void sortuj_przylacz_element(unique_ptr<Element>& posortowana_lista, unique_ptr<Element> element);
    void sortuj();

    class Iterator;
    Iterator begin() const;
    Iterator end() const;
};
