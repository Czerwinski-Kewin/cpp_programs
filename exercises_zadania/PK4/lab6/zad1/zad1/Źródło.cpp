#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <mutex>

using namespace std;
mutex mtx;

void purchase(string name)
{
	mtx.lock();
	cout << name << " is buying things..." << endl;
	this_thread::sleep_for(chrono::seconds(3));
	cout << name << " bought everything" << endl;
	this_thread::sleep_for(chrono::seconds(2));
	mtx.unlock();
}

int main()
{
	thread David(purchase, "David");
	thread Alan(purchase, "Alan");

	David.join();
	Alan.join();
}