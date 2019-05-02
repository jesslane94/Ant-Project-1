/********************************************************************* ** 
 * Program name: antMain.cpp
 * ** Author: Jessica Lane
 * ** Date: April 14, 2019
 * ** Description: The main for the Langton's Ant simulation. Using the menu function, the user's choice
 * to play the game is recorded. If the user chooses one, then the program will run where the user chooses
 * every aspect of the board, where the ant starts, and how many steps to take. The ant and board objects are 
 * created using this information and then passed through a loop until all steps have been taken. After, the
 * user is asked if they'd like to play the simulation again. If the user chooses option two, a randomized
 * starting position for the ant is determined. Otherwise, it will run just like option 1. Option 3 is quit, and
 * the program will terminate.
 * *********************************************************************/

#include <iostream> 
#include <cstdlib>
#include "menu.hpp"
#include "inputValidation.hpp"
#include "rangeChecker.hpp"
#include "board.hpp"
#include "ant.hpp"
using std::cout;
using std::cin;
using std::endl;

int main()
{

	int userEnteredRows;
	int userEnteredColumns;
	int userAntRow;
	int userAntColumn;
	int antSteps;
	void srand(int seed); //seed of random number generator

	int userOption = menu(); //determine if user wants to play or quit
	while (userOption == 1)
	{
		cout << "Please enter a positive integer from 2 to 100 for the number of rows on the board." << endl;
		userEnteredRows = inputValidation(); 
		while(!(rangeChecker(userEnteredRows, 2, 100)))
		{
			cout << "Please enter an integer in range between 2 to 100." << endl;
			userEnteredRows = inputValidation();
		}

		cout << "Please enter a positive integer from 2 to 100 for the number of columns on the board." << endl;
		userEnteredColumns = inputValidation();
		while(!(rangeChecker(userEnteredColumns, 2, 100)))
		{
			cout << "Please enter an integer in range between 2 to 100." << endl;
			userEnteredColumns = inputValidation();
		}

		cout << "Next, where would you like the ant to start? Enter an integer between 2 and " << userEnteredRows - 1 << " for the row." << endl;
		userAntRow = inputValidation();
		while(!(rangeChecker(userAntRow, 2, userEnteredRows - 1)))
		{
			cout << "Please enter an integer in range between 2 and " << userEnteredRows - 1 << " for the row." << endl;
			userAntRow = inputValidation();
		}

		cout << "Now enter the column where you would like the ant to start. Enter an integer between 2 and " << userEnteredColumns - 1 << " for the column." << endl;
		userAntColumn = inputValidation();
		while(!(rangeChecker(userAntColumn, 2, userEnteredColumns - 1)))
		{
			cout << "Please enter an integer in range between 2 and " << userEnteredColumns - 1 << " for the column." << endl;
			userAntColumn = inputValidation();
		}

		cout << "How many steps would you like your ant to take? Enter a positive integer between 1 and 13000." << endl;
		antSteps = inputValidation();
		while(!(rangeChecker(antSteps, 1, 13000)))
		{
			cout << "Please enter an integer in range between 1 and 13000." << endl;
			antSteps = inputValidation();
		}
		
		//create user specified array to be modified
		//adapted from https://stackoverflow.com/questions/936687/how-do-i-declare-a-2d-array-in-c-using-new
		char **userArray = new char*[userEnteredRows];
		for (int i=0; i < userEnteredRows; i++)
		{
			for (int j=0; j < userEnteredRows; j++)
			{
				userArray[i] = new char[userEnteredColumns];
			}
		}
				
		Ant userAnt = Ant(userAntRow, userAntColumn); //declare ant object 
		Board userBoard = Board(userArray, userEnteredRows, userEnteredColumns, &userAnt); //declare board object
		int stepsTaken = 0; //accumulator
		
		while (stepsTaken < antSteps)
		{
			stepsTaken++;
			userAnt.turnAnt(userBoard.getColor(userAnt.getAntRow(), userAnt.getAntColumn()));
			userBoard.changeColor(userAnt.getAntRow(), userAnt.getAntColumn());
			userAnt.moveAnt();
			if (userBoard.checkForEdge(userAnt.getAntRow(), userAnt.getAntColumn()))
			{
				userAnt.replaceAnt();
			}
			userBoard.printBoard();
			cout << "Your ant is on row " << userAnt.getAntRow() << "." << endl;
			cout << "Your ant is on column " << userAnt.getAntColumn() << "." << endl;
			cout << "We are on step " << stepsTaken << "." << endl;
		}
		
		//free up memory once array is done with
      		for (int i=0; i < userEnteredRows; i++)
        	{
                	delete [] userArray[i];
        	}
        	delete [] userArray;
        	userArray = nullptr;

        	cout << "Would you like to play again?" << endl;
		userOption = menu();
	}

	while (userOption == 2) //option if the user wants a random starting location for the ant
	{
		cout << "Please enter a positive integer from 2 to 100 for the number of rows on the board." << endl;
		userEnteredRows = inputValidation(); 
		while(!(rangeChecker(userEnteredRows, 2, 100)))
		{
			cout << "Please enter an integer in range between 2 to 100." << endl;
			userEnteredRows = inputValidation();
		}

		cout << "Please enter a positive integer from 2 to 100 for the number of columns on the board." << endl;
		userEnteredColumns = inputValidation();
		while(!(rangeChecker(userEnteredColumns, 2, 100)))
		{
			cout << "Please enter an integer in range between 2 to 100." << endl;
			userEnteredColumns = inputValidation();
		}

		cout << "Generating random start for your ant..." << endl;
		userAntRow = rand() % userEnteredRows;
		userAntColumn = rand() % userEnteredColumns;
		cout << "Starting location determined!" << endl;
		cout << "Your ant's row is " << userAntRow << "." << endl;
		cout << "Your ant's column is " << userAntColumn << "." << endl;

		cout << "How many steps would you like your ant to take? Enter a positive integer between 1 and 13000." << endl;
		antSteps = inputValidation();
		while(!(rangeChecker(antSteps, 1, 13000)))
		{
			cout << "Please enter an integer in range between 1 and 13000." << endl;
			antSteps = inputValidation();
		}
		
		//create user specified array to be modified
		//adapted from https://stackoverflow.com/questions/936687/how-do-i-declare-a-2d-array-in-c-using-new
		char **userArray = new char*[userEnteredRows];
		for (int i=0; i < userEnteredRows; i++)
		{
			for (int j=0; j < userEnteredRows; j++)
			{
				userArray[i] = new char[userEnteredColumns];
			}
		}
		
				
		Ant userAnt = Ant(userAntRow, userAntColumn);
		Board userBoard = Board(userArray, userEnteredRows, userEnteredColumns, &userAnt);
		int stepsTaken = 0;
	
		while (stepsTaken < antSteps)
		{
			stepsTaken++;
			userAnt.turnAnt(userBoard.getColor(userAnt.getAntRow(), userAnt.getAntColumn()));
			userBoard.changeColor(userAnt.getAntRow(), userAnt.getAntColumn());
			userAnt.moveAnt();
			if (userBoard.checkForEdge(userAnt.getAntRow(), userAnt.getAntColumn()))
			{
				userAnt.replaceAnt();
			}
			userBoard.printBoard();
			cout << "Your ant is on row " << userAnt.getAntRow() << "." << endl;
			cout << "Your ant is on column " << userAnt.getAntColumn() << "." << endl;
			cout << "We are on step " << stepsTaken << "." << endl;
		}
			
      		for (int i=0; i < userEnteredRows; i++)
        	{
            		delete [] userArray[i];
        	}
        	delete [] userArray;
        	userArray = nullptr;

        	cout << "Would you like to play again?" << endl;
		userOption = menu();
	}
	
	if (userOption == 3) //quit game
	{
		return 0;
	}

}

