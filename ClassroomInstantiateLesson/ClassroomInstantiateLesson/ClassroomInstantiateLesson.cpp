#include <iostream>
#include "Person.h"
#include <stdlib.h>


int main()
{
	Person Mik;												// Create a Person object named Mik from the class
    Person Hugo;
	Person Dean;

	Mik.Name("Mik");										// Set Mik's name
	Mik.Height("188 cm");									// Set Mik's height
	Mik.Age("18");											// Set Mik's age
	Mik.Hobby("Gaming");									// Set Mik's hobby
	Mik.Study("Software Development");						// Set Mik's study
															// This can be done for each person object
	Hugo.Name("Hugo");
	Hugo.Height("175 cm");
	Hugo.Age("17");
	Hugo.Hobby("Gaming");
	Hugo.Study("Software Development");

	Dean.Name("Dean");
	Dean.Height("189 cm");
	Dean.Age("18");
	Dean.Hobby("Gaming");
	Dean.Study("Software Developer");

	Mik.DisplayInfo();										// Display Mik's information with the function

	system("PAUSE");										// Pause the console to view the information
	system("CLS");											// Clear the console

	Hugo.DisplayInfo();

	system("PAUSE");
	system("CLS");

	Dean.DisplayInfo();
	return 0;												// End of the program
}

