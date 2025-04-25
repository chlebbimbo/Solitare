// Person.h
#pragma once
#include <string>

class Person {
private:
    std::string name;
    int age;

public:
    Person(std::string name, int age);
    void sayHello() const;
};



