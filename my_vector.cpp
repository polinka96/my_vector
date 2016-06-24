// my_vector.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include "my_vector.h"
#include "Student.h"

using namespace std;


int main()
{
	Student st1("Ivan", 20);
	Student st2("Petur", 20);

	Vector <Student> students;
	students.push_back(st1);
	students.push_back(st2);

	Vector <int>v1;
	v1.push_back(1);
	v1.push_back(13);
	v1.push_back(37);
	v1.push_back(73);
	v1.push_back(121);
	v1.push_back(181);
	v1.push_back(253);
	cout << v1.back() << endl;
	v1.pop_back();
	cout << v1.back() << endl;
	cout << v1[4] << endl;
	v1.push_back(777);
	for (int i = 0; i < v1.size(); i++)
	{
		cout << v1[i] << " ";
	}
	cout << endl;

	Vector <string>v2;
	v2.push_back("Aut viam");
	v2.push_back("inveniam");
	v2.push_back("aut faciam");
	for (int i = 0; i < v2.size(); i++)
	{
		cout << v2[i] << " ";
	}
	cout << endl;

	Vector<string> v3;
	v3.push_back("Aut");
	v3.push_back("vincere");
	v3.push_back("mori");
	v3.insert(2, "aut");
	for (int i = 0; i < v3.size(); i++)
	{
		cout << v3[i] << " ";
	}
	cout << endl;
	v3.erase(0);
	for (int i = 0; i < v3.size(); i++)
	{
		cout << v3[i] << " ";
	}

	system("pause");
	return 0;
}



