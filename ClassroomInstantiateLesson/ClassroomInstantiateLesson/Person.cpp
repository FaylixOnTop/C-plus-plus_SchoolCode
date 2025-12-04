#include "Person.h"
#include <string>
#include <iostream>

void Person::Name(std::string name)						// Set the name of the person
{
	_name = name;
}

void Person::Height(std::string height)					// Set the height of the person
{
	_height = height;
}

void Person::Age(std::string age)						// Set the age of the person
{
	_age = age;
}

void Person::Hobby(std::string hobby)					// Set the hobby of the person
{
	_hobby = hobby;
}

void Person::Study(std::string study)					// Set the study of the person
{
	_study = study;
}

void Person::DisplayInfo() const						// Display the information of the person to the console
{
	std::cout << "Name: " << _name << std::endl;
	std::cout << "Height: " << _height << std::endl;
	std::cout << "Age: " << _age << std::endl;
	std::cout << "Hobby: " << _hobby << std::endl;
	std::cout << "Study: " << _study << std::endl;
}

