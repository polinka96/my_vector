#pragma once
#include <string>

class Student {
public:
	Student() : m_name("Georgi"), m_age(19) {}
	Student(string name, int age) : m_name(name), m_age(age) {}

private:
	string m_name;
	int m_age;
	
};

