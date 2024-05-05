#include <future>
#include <iostream>
#include <random>
#include <string>
using namespace std;

mt19937 los(time(nullptr));
uniform_int_distribution<> zakres(10, 20);

int dane(int godz) 
{
    int tem = zakres(los) + godz/2;
    return tem;
}

int main() {
    promise<int> obietnica1, obietnica2, obietnica3;

    auto watek1 = async(launch::async, [&obietnica1]() {
        obietnica1.set_value(dane(10));
        });
    auto watek2 = async(launch::async, [&obietnica2]() {
        obietnica2.set_value(dane(12));
        });
    auto watek3 = async(launch::async, [&obietnica3]() {
        obietnica3.set_value(dane(14));
        });

    future<int> przyszlosc1 = obietnica1.get_future();
    future<int> przyszlosc2 = obietnica2.get_future();
    future<int> przyszlosc3 = obietnica3.get_future();

    przyszlosc1.wait();
    przyszlosc2.wait();
    przyszlosc3.wait();

    int wyn1 = przyszlosc1.get();
    int wyn2 = przyszlosc2.get();
    int wyn3 = przyszlosc3.get();

    for (int i = 10; i <= 20; i++) 
    {
        cout << "Godzina: " << i << ":00" << endl;

        cout << "Gliwice: " << wyn1 << " C" << endl;
        cout << "Warszawa: " << wyn2 << " C" << endl;
        cout << "Gdansk: " << wyn3 << " C" << endl;

        cout << endl;
    }

    return 0;
}

