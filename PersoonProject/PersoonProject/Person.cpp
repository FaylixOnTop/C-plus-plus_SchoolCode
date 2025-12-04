#include "Person.h"
#include <string>
#include <iostream>

void Person::setName(std::string personName)						//Setting name attribute
{
	_name = personName;
}

void Person::setStudentID(std::string StudentID)					//Setting studentID attribute
{
	_studentID = StudentID;
}

void Person::setAge(std::string Age)								//Setting age attribute
{
	_age = Age;
}

void Person::setAddress(std::string Address)						//Setting address attribute
{
	_address = Address;
}

void Person::setPhoneNumber(std::string PhoneNumber)				//Setting phone number attribute
{
	_phoneNumber = PhoneNumber;
}

void Person::displayInfo() const									//Displaying all attributes of the person
{
	std::cout << "Name: " << _name << std::endl;
	std::cout << "Student ID: " << _studentID << std::endl;
	std::cout << "Age: " << _age << std::endl;
	std::cout << "Address: " << _address << std::endl;
	std::cout << "Phone Number: " << _phoneNumber << std::endl;
}

//we set the private variables using public setter methods to ensure safety.