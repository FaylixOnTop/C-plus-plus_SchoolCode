#include <iostream>
#include "Person.h"
#include <stdlib.h>

int main()
{
	Person Gurt; //Creating an object of the Person class
	
	std::cout << "What is your name?" << std::endl;				//Prompting user for name input
	std::string inputName;										//Variable to store user input for name
	std::getline(std::cin, inputName);							//Getting the full name input from user
	Gurt.setName(inputName);									//Setting the name attribute of person1 object
	system("CLS");												//Clearing the console after each input

	std::cout << "What is your studentID?" << std::endl;
	std::string inputStudentID;
	std::getline(std::cin, inputStudentID);
	Gurt.setStudentID(inputStudentID);
	system("CLS");

	std::cout << "What is your age?" << std::endl;
	std::string inputAge;
	std::getline(std::cin, inputAge);
	Gurt.setAge(inputAge);
	system("CLS");

	std::cout << "What is your address?" << std::endl;
	std::string inputAddress;
	std::getline(std::cin, inputAddress);
	Gurt.setAddress(inputAddress);
	system("CLS");

	std::cout << "What is your phone number?" << std::endl;
	std::string inputPhoneNumber;
	std::getline(std::cin, inputPhoneNumber);
	Gurt.setPhoneNumber(inputPhoneNumber);
	system("CLS");

	Gurt.displayInfo();
	return 0;
}

// In this code, we create a Person object named Gurt and prompt the user to input their 
// name, 
// student ID, 
// age, 
// address, 
// and phone number.