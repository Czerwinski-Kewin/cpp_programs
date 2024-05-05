#include <iostream>
#include "Nag³ówek.h"
#include "OsLiczbowa.h"
#include "ZbiorOsi.h"
#include "Wykres.h"
#include "Series.h"
#include <memory>
using namespace std;


void auxFun(OsLiczbowa osarg)
{
	OsLiczbowa os3(osarg, osarg, osarg);
	OsLiczbowa* ptr = new OsLiczbowa(osarg);
	delete ptr;
}

void przyklad()
{
	//Wykres wyk;
	//cout << wyk;
	Wykres wyk2(7, "wyk2", Typ::Sunburst);
	Wykres wyk;
	//wyk = wyk2;
	wyk2 = move(wyk);
	cout << wyk;
	ZbiorOsi zbior = ZbiorOsi(3);
	//zbior++;
}

void auxFun_4(Wykres& obj)
{
	cout << "---------------------------" << endl;
	obj.draw();
	((Column&)obj).draw();
}

void auxFun_4_DC(Wykres* ptr)
{
	cout << "---------------------------" << endl;
	ptr->draw();
	//(dynamic_cast<Column*>(ptr)).draw();
	dynamic_cast<Column*>(ptr);
	if (ptr == nullptr)
		cout << "Wskaznik jest nullptr";
	else
		ptr->draw();
}

int main()
{
	//OsLiczbowa os;
	//OsLiczbowa os2;
	//OsLiczbowa::wypLicznik();
	//OsLiczbowa os3;
	//OsLiczbowa os2(5, 10);
	//OsLiczbowa os3(os, os, os2);
	//auxFun(os2);
	//os.set(4, 28, 2);
	//os.write();
	//cout << os;		//friend ostream zamiast write

	/*
	cout << "Lewe argumenty przed: " << endl;
	ZbiorOsi zbior = ZbiorOsi(3);
	ZbiorOsi zbior2 = ZbiorOsi(3);

	zbior = move(zbior2);

	//cout << zbior;
	cout << "Lewe argumenty po: " << endl;
	*/

	//OsLiczbowa test;
	//test.set(1, 3, 100);
	//test *= 2;
	//cout << test;
	//ZbiorOsi zbior3 = ZbiorOsi(3) + test;
	//przyklad();
	//wyk.draw();

	/*
	Column col(5, "col");
	col.Wykres::draw();
	col.draw();

	Treemap tre(5, "tree");
	tre.Wykres::draw();
	tre.draw();

	Wykres wyk;
	auxFun_4(wyk);
	auxFun_4(col);

	Wykres* ptr = &tre;
	auxFun_4_DC(ptr);
	*/

	Series ser;
	cout << ser;

	return 0;
}