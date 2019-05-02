/********************************************************************* ** 
 * Program name: menu.cpp
 * ** Author: Jessica Lane
 * ** Date: April 14th, 2019
 * ** Description: This contains the menu function definition. It will prompt the user to choose one of
 * three options: 1) start Langton's ant with a random starting point, 2) Start it with a location of
 * their choosing, or 3) quit the program. It will then ask for the number of rows and columns composing
 * the board the ant is on, the number of steps they wish the ant to take, and the starting row and column
 * of the ant (if they chose option 2). It will also make sure the user doesn't enter invalid input such 
 * as a letter or whole word. 
 * *********************************************************************/

#include <iostream>
#include <cstdlib>
#include "inputValidation.hpp"
using std::cout;
using std::cin;
using std::endl;

int menu() 
{
	int userChoice;
		
	cout << "Choose an option below: " << endl;
	cout << "1. Start Langton's Ant with a location of your choosing." << endl;
	cout << "2. EXTRA CREDIT Option! Start Langton's Ant with a random starting location." << endl;
	cout << "3. Quit Program." << endl;
	userChoice = inputValidation();

	if (userChoice == 1 || userChoice == 2 || userChoice == 3)	
		{
			return userChoice;
		}
	else
		{ 
			cout << "Please choose an option between 1 and 3." << endl;
			userChoice = inputValidation();
		}

}
