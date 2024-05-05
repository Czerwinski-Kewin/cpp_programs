#include "Name.h"

Name::Name(string aName)
{
	cout << "Name - konstruktor jednoargumentowy" << endl;
	objectName = aName;
}

Name::Name() : Name("nazwa name")
{
	cout << "Name - konstruktor bezargumentowy" << endl;
}

Name::~Name()
{
	cout << "Name - destruktor" << endl;
}