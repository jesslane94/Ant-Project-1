/********************************************************************* **
 *  * Program name: board.cpp
  * ** Author: Jessica Lane
 ** ** Date: April 14, 2019
 ** ** Description: These are the definitions for the Board class. The board made by the user inputs is constructed, and an Ant object is passed that will mingle with the board. The board is originally initialized to be all white spaces. This class also holds the functions to check for an edge of the board, change the color of a square of the board, and to print the current state of the board for the user to see.
 * * *********************************************************************/

#include <iostream>
#include "board.hpp"
#include "ant.hpp"

/* this constructs the user's board by taking in the 2D array made in main and initializing its elements to whitespaces. it also initializes the ant object. */
Board::Board(char** inputBoard, int rowNumber, int columnNumber, Ant *userAnt)
{
	ant = userAnt;
	board = inputBoard;
	rows = rowNumber;
	columns = columnNumber;
	
	//initialize board
	for (int r=0; r < rows; r++)
	{
		for(int c=0; c < columns; c++)
		{
			board[r][c] = ' ';
		}
	}

}

int Board::getRows()
{
	return rows;
}

int Board::getColumns()
{
	return columns;
}

char Board::getColor(int xCalled, int yCalled)
{
	char colorCalled = board[xCalled][yCalled];
	return colorCalled;
}

/* if an edge is detected, this bool function will return true. an edge is indicated by 0 or the max row/column decremented by 1 due to the way array elements are called. otherwise, it will return false and the ant will continue moving as normal. */
bool Board:: checkForEdge (int xCalled, int yCalled)
{
	if (xCalled < 0)
	{
		return true;
	}
	if (xCalled > rows - 1)
	{
		return true;
	} 
	if (yCalled < 0) 
	{
		return true;
	}
	if (yCalled > columns - 1)
	{
		return true;
	}

	return false;
}

/* the color of the current square will be inverted depending on its color state. */
void Board::changeColor(int xCalled, int yCalled)
{
	char currentColor = getColor(xCalled, yCalled);
	if (currentColor == ' ')
	{
		board[xCalled][yCalled] = '#'; 
	}
	else
	{
		board[xCalled][yCalled] = ' ';
	}
	
}

/* this is called to display the board to the user after each step is completed. They can see what is white square, what is black, and where the ant is currently located. it calls on functions from the Ant class to place the ant, and also refers to the getColor function in this class.*/
void Board::printBoard()
{
        for (int r=0; r < rows; r++)
        {
                for (int c=0; c < columns; c++)
                {
                        if (r == ant->getAntRow() && c == ant->getAntColumn())
                        {
                                std::cout << '@';
                        }
                        else
                        {
                                std::cout << getColor(r,c);
                        }
                }
                std::cout << std::endl;
        }
}




