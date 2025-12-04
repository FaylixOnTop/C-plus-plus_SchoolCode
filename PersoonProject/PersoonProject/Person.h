#pragma once
#include <string>
class Person
{																//Filling class with attributes of each person
	public:
		void setName(std::string name);							//public methods to set each attribute
		void setStudentID(std::string StudentID);
		void setAge(std::string Age);
		void setAddress(std::string Address);
		void setPhoneNumber(std::string PhoneNumber);
		void displayInfo() const;								//public method to display all attributes
private:														//private attributes of each person
		std::string _name;
		std::string _studentID;
		std::string _age;
		std::string _address;
		std::string _phoneNumber;
};

// Its private because we don't want other parts of the program to directly access or modify these attributes. 
// Instead, we provide public setter methods to control how these attributes are set, 
// ensuring data safety.