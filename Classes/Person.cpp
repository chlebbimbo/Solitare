#include "person.h"
#include <iostream>

using namespace std;

Person::Person(string name, int age) : name(name), age(age) {}

void Person::sayHello() const
{
    cout << "Hello, my name is " << name << " and I am " << age << " years old." << endl;
}