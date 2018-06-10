#ifndef GLOBAL_H // header guards
#define GLOBAL_H

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

int add(int x, int y);
using namespace std;
string getName();
//string* getNamePointer();

extern int g_nValue;

namespace global {
// extern tells the compiler this variable is declared elsewhere

class Cents {
private:
	int m_nCents;

public:
	Cents(int nCents) {
		m_nCents = nCents;
	}

	// Add Cents + Cents
	friend Cents operator+(const Cents &c1, const Cents &c2);

	int getCents() {
		return m_nCents;
	}
};

// note: this function is not a member function!
Cents operator+(const Cents &c1, const Cents &c2) {
	// use the Cents constructor and operator+(int, int)
	return Cents(c1.m_nCents + c2.m_nCents);
}

class Base {

private:
	int int_value;

public:
	Base(int nValue = 0) :
			int_value(nValue) {
	}

	int getIntValue() {
		return int_value;
	}
};

class Derived: public Base {

private:
	double double_value;

public:

	Derived(double dValue = 0.0, int nValue = 0) :
			Base(nValue), double_value(dValue) {
	}

	int getDoubleValue() {
		return double_value;
	}

};

template<typename Type> // this is the template parameter declaration
Type max(Type tX, Type tY) {
	return (tX > tY) ? tX : tY;
}

using namespace std;
class Person {

public:
	std::string firstName;
	std::string lastName;
	int age;

public:

	Person() {
	}
	;

	Person(const string& firstName, const string& lastName, const int& age) {
		this->firstName = firstName;
		this->lastName = lastName;
		this->age = age;
	}
	;

	Person(const Person& person) {
		cout << "Invoking copy constructor for Person object" << endl;
		this->firstName = person.firstName;
		this->lastName = person.lastName; // TODO: why we cannot use person->lastName
		this->age = person.age;
	}
};

using namespace std;
Person* getPersonRef(const string& firstName, const string& lastName,
		const int& age) {
	Person* someOne = new Person(firstName, lastName, age);
	return someOne;
}
;

/**
 * This will return some garbage object as the object is created in the stack
 */
Person* getPerson2(const string& firstName, const string& lastName,
		const int& age) {
	Person stackObject(firstName, lastName, age);
	return &stackObject;
}
;

template<typename Type>
Type findmax(Type x, Type y) {
	return x > y ? x : y;
}

}

#endif
