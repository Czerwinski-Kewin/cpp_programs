#include <iostream>
#include <string>
#include <fstream>
#include "Vector.h"
#include "SmartPointer.h"
using namespace std;

template <typename T>
MyVector<T>::MyVector()
{
    arr = new T[1];
    capacity = 1;
    current = 0;
}

template <typename T>
MyVector<T>::~MyVector()
{ 
    delete[] arr;
}

template <typename T>
void MyVector<T>::push(T data)
{
    if (current == capacity)
    {
        T* temp = new T[2 * capacity];
        for (int i = 0; i < capacity; i++)
        {
            temp[i] = arr[i];
        }

        delete[] arr;
        capacity *= 2;
        arr = temp;
    }

    arr[current] = data;
    current++;

    }

template <typename T>
void MyVector<T>::push(T data, int index)
{

    if (index == capacity)
        push(data);
    else
        arr[index] = data;
}

template <typename T>
T MyVector<T>::get(int index)
{
    if (index < current)
        return arr[index];
    return -1;
}

template <typename T>
void MyVector<T>::pop()
{ 
    current--;
}

template <typename T>
int MyVector<T>::size() 
{ 
    return current;
}

template <typename T>
int MyVector<T>::getCapacity()
{ 
    return capacity;
}

template <typename T>
void MyVector<T>::print()
{
    for (int i = 0; i < current; i++) 
    {
        cout << arr[i] << " ";
    }
        cout << endl;
}

template <typename T>
MyVector<T>& MyVector<T>::operator=(MyVector<T>&& r)    //op
{
    arr = r.arr;
    capacity = r.capacity;
    current = r.current;
    return *this;
}

void odczyt(MyVector<int>& wektor)
{
    ifstream plik_wczytaj("odczyt.txt");
    if (plik_wczytaj)
    {
        string t;
        int a;
        for (int i = 0; i < 10; i++)
        {
            getline(plik_wczytaj, t);
            a = stoi(t);
            wektor.push(a);
        }
    }
    plik_wczytaj.close();
}

void zapis(MyVector<int>& wektor)
{
    ofstream plik_zapisz("zapis.txt");
    if (plik_zapisz)
    {
        int c = 0;
        int a = 0;
        for (int i = 0; i < wektor.size(); i++)
        {
            c = wektor.get(i);
            while (c > 0)
            {
                a = a * 10 + c % 10;
                c = c / 10;
            } 
            plik_zapisz << a << endl;
        }
    }
    plik_zapisz.close();
}

int main()
{
    MyVector<int> wektor;
    odczyt(wektor);
    zapis(wektor);
    wektor.print();
}
