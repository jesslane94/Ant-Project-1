/********************************************************************* ** 
 * Program name: inputValidation.cpp
 * ** Author: Jessica Lane
 * ** Date: April 14, 2019
 * ** Description: This function takes the user's input as a string and determines if it is an integer or not. It also will help filter out negative inputs. 
 * *********************************************************************/
#include "inputValidation.hpp"
#include <iostream>
#include <cstdlib>
#include <limits>
using std::cin;
using std::cout;
using std::endl;

int inputValidation()
{
	std::string userInput;
	int userInputAsInt;

	std::getline(cin, userInput);

	//the following code is adapted from: https://stackoverflow.com/questions/18728754/checking-cin-input-stream-produces-an-integer
	while (cin.fail() || cin.eof() || userInput.find_first_not_of("0123456789") != std::string::npos) //check for integerst
	{
		cout << "Please choose a valid option." << endl;
		if(userInput.find_first_not_of("0123456789") == std::string::npos)
		{
			cin.clear();
			cin.ignore(256, '\n');
		}
		
		std::getline(cin, userInput);
	}
	
	std::string::size_type st;
	userInputAsInt = std::stoi(userInput, &st); //convert the string to an int
	return userInputAsInt;

}
	
