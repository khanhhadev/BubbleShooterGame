#pragma once
#include <iostream>
#include <string>
#include <set>
using namespace std;

class Student
{
private:
	string m_id, m_name;
	int m_age;
public:
	Student();
	Student(string ID);
	Student(string ID, string Name, int Age);

	//return student ID
	string getID();

	//return student Name
	string getName();

	//return student Age
	int getAge();

	//swap 2 student information
	static void swap(Student& Obj1, Student& Obj2);

	//assignment operator = overloading
	Student& operator = (Student& Obj);
	Student& operator = (const Student& Obj);

	//logical operator == overloading
	bool operator == (const Student& Obj);

	//logical operator != overloading
	bool operator != (const Student& Obj);

	//logical operator > overloading
	bool operator > (const Student& Obj);

	//logical operator < overloading
	bool operator < (const Student& Obj);

	//operator << overloading
	friend ostream& operator << (ostream& output, const Student& Obj);

	//operator >> overloading
	friend istream& operator >> (istream& input, Student& Obj);
};

//default constructor
Student::Student() {};

//constructor using parameter
Student::Student(string ID)
{
	while (ID.length() < 8)
	{
		ID = "0" + ID;
	}
	m_id = ID;
};

//constructor using parameter
Student::Student(string ID, string Name, int Age):m_id(ID), m_name(Name), m_age(Age)
{
	while (ID.length() < 8)
	{
		ID = "0" + ID;
	}
	m_id = ID;
};

//return student ID
string Student::getID()
{
	return m_id;
};

//return student name
string Student::getName()
{
	return m_name;
};

//return student age
int Student::getAge()
{
	return m_age;
};

//swap 2 student information
void Student::swap(Student& Obj1, Student& Obj2)
{
	Student temp = Obj1;
	Obj1 = Obj2;
	Obj2 = temp;
};

//assignment operator = overloading
Student& Student::operator = (Student& Obj)
{
	m_id = Obj.m_id;
	m_name = Obj.m_name;
	m_age = Obj.m_age;
	return *this;
};

//assignment operator = overloading
Student& Student::operator = (const Student& Obj)
{
	m_id = Obj.m_id;
	m_name = Obj.m_name;
	m_age = Obj.m_age;
	return *this;
};

//logical operator == overloading
bool Student::operator == (const Student& Obj)
{
	return (this->m_id == Obj.m_id);
};

//logical operator > overloading
bool Student::operator > (const Student& Obj)
{
	for (int i = 0; i < m_id.length(); i++)
	{
		if (m_id[i] > Obj.m_id[i]) return true;
		if (m_id[i] < Obj.m_id[i]) return false;
	}

};

//logical operator < overloading
bool Student::operator < (const Student& Obj)
{
	for (int i = 0; i < m_id.length(); i++)
	{
		if (m_id[i] < Obj.m_id[i]) return true;
		if (m_id[i] > Obj.m_id[i]) return false;
	}
};

//logical operator != overloading
bool Student::operator != (const Student& Obj)
{
	return (this->m_id != Obj.m_id);
};

//operator << overloading
ostream& operator << (ostream& output,const Student& Obj)
{
	output << "\nStudent ID: " << Obj.m_id;
	output << "\nStudent name: " << Obj.m_name;
	output << "\nStudent age: " << Obj.m_age;
	output << "\n";
	return output;
};

//operator >> overloading
istream& operator >> (istream& input, Student& Obj)
{
	cout << "\nEnter student ID: "; 
	getline(input, Obj.m_id);
	cout << "\nEnter student name: ";
	getline(input, Obj.m_name);
	cout << "\nEnter student age: ";
	input >> Obj.m_age;
	return input;
};
