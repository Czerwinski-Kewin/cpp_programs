#include "Lista.h"
using namespace std;

template<typename T>
Lista<T>::Lista() : head(nullptr) {}

template<typename T>
Lista<T>::Lista(const Lista& src) 
{
    if (src.head)
    {
        head = make_unique<Element>(src.head->dane);
        Element* cur = head.get();
        Element* src_cur = src.head->nastepny.get();
        while (src_cur)
        {
            cur->nastepny = make_unique<Element>(src_cur->dane);
            cur = cur->nastepny.get();
            src_cur = src_cur->nastepny.get();
        }
    }
}

template<typename T>
Lista<T>::Lista(Lista&& src) noexcept : head(move(src.head)) 
{
    src.head = nullptr;
}

template<typename T>
Lista<T>& Lista<T>::operator=(const Lista& src)
{
    if (this != &src) {
        Lista temp(src);
        swap(head, temp.head);
    }
    return *this;
}

template<typename T>
Lista<T>& Lista<T>::operator=(Lista&& src) noexcept 
{
    if (this != &src) {
        head = move(src.head);
        src.head = nullptr;
    }
    return *this;
}

template<typename T>
void Lista<T>::dodaj(const T& wartosc)
{
    if (!head)
    {
        head = make_unique<Element>(wartosc);
        return;
    }
    Element* cur = head.get();
    while (cur->nastepny)
    {
        cur = cur->nastepny.get();
    }
    cur->nastepny = make_unique<Element>(wartosc);
}

template<typename T>
void Lista<T>::usun(int indeks)
{
    if (indeks < 0 || !head)
    {
        return;
    }
    if (indeks == 0)
    {
        head = move(head->nastepny);
        return;
    }
    Element* cur = head.get();
    int i = 0;
    while (cur && i < indeks - 1)
    {
        cur = cur->nastepny.get();
        i++;
    }
    if (!cur || !cur->nastepny)
    {
        return;
    }
    cur->nastepny = move(cur->nastepny->nastepny);
}

template<typename T>
T& Lista<T>::get(int indeks)
{
    Element* cur = head.get();
    for (int i = 0; i < indeks && cur; i++)
    {
        cur = cur->nastepny.get();
    }
    if (!cur)
    {
        throw out_of_range("Indeks poza zakresem!");
    }
    return cur->dane;
}

template<typename T>
void Lista<T>::wyswietl()
{
    Element* cur = head.get();
    while (cur) {
        cout << cur->dane << " ";
        cur = cur->nastepny.get();
    }
    cout << endl;
}

template<typename T>
size_t Lista<T>::size() const {
    size_t licz = 0;
    Element* cur = head.get();
    while (cur)
    {
        licz++;
        cur = cur->nastepny.get();
    }
    return licz;
}

template<typename T>
vector<int> Lista<T>::szukaj(const T& fraza) const {
    vector<int> indeksy;
    Element* cur = head.get();
    int indeks = 0;
    while (cur) {
        int loc = 0;
        int dane_loc = 0;
        while (cur && loc < fraza.size() && dane_loc < cur->dane.size()) {
            if (cur->dane[dane_loc] == fraza[loc]) {
                loc++;
            }
            dane_loc++;
        }
        if (loc == fraza.size()) {
            indeksy.push_back(indeks);
        }
        cur = cur->nastepny.get();
        indeks++;
    }
    return indeksy;
}

template<typename T>
void Lista<T>::sortuj() {
    if (!head || !head->nastepny) {
        return;
    }

    unique_ptr<Element> posortowana_lista = nullptr;
    while (head) {
        auto cur = move(head);
        head = move(cur->nastepny);
        sortuj_przylacz_element(posortowana_lista, move(cur));
    }

    head = move(posortowana_lista);
}

template<typename T>
void Lista<T>::sortuj_przylacz_element(unique_ptr<Element>& posortowana_lista, unique_ptr<Element> element) {
    if (!posortowana_lista || element->dane < posortowana_lista->dane) {
        element->nastepny = move(posortowana_lista);
        posortowana_lista = move(element);
    }
    else {
        Element* cur = posortowana_lista.get();
        while (cur->nastepny && element->dane > cur->nastepny->dane) {
            cur = cur->nastepny.get();
        }
        element->nastepny = move(cur->nastepny);
        cur->nastepny = move(element);
    }
}

template<typename T>
class Lista<T>::Iterator 
{
private:
    Element* cur;

public:
    Iterator(Element* element) : cur(element) {}

    T& operator*() const
    {
        return cur->dane;
    }

    Iterator& operator++() 
    {
        if (cur)
            cur = cur->nastepny.get();
        return *this;
    }

    bool operator!=(const Iterator& src) const {
        return cur != src.cur;
    }
};

template<typename T>
typename Lista<T>::Iterator Lista<T>::begin() const 
{
    return Iterator(head.get());
}

template<typename T>
typename Lista<T>::Iterator Lista<T>::end() const 
{
    return Iterator(nullptr);
}
