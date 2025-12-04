#pragma once
#include <string>
class Person
{
	public:
		void Name(std::string name);					//Setters for each attribute
		void Height(std::string StudentID);
		void Age(std::string Age);
		void Hobby(std::string Address);
		void Study(std::string PhoneNumber);
		void DisplayInfo() const;
		//public methods are accessible outside the class
	private:
		std::string _name;								//Attributes of the Person class
		std::string _height;
		std::string _age;
		std::string _hobby;
		std::string _study;
		//private attributes are not accessible outside the class
};

