/********************************************************************* ** 
 * Program name: ant.cpp
 * ** Author: Jessica Lane
 * ** Date: April 14, 2019
 * ** Description: This file contains the constructor and functions of the 
 * ant class. The ant object is created by taking in the row and column for the
 * ant entered by the user to initialize its coordinates. The ant starts facing down and is turned and moved by functions in this class. 
 * *********************************************************************/
#include <iostream>
#include "ant.hpp"
#include "board.hpp"

/*constructor for the ant object takes the user entered row for the ant and the column. they are used to initialize its coordinates. the ant will always start facing down. */
Ant::Ant(int r, int c)
{
   	antRow = r;
	antColumn = c;
	antFaces = DOWN;
}

int Ant::getAntRow()
{
	return antRow;
}

int Ant::getAntColumn()
{
	return antColumn;
}

/* this function turns the ant depending on the color of square it is on. The current color is passed in as a parameter. if it is a white square, the ant will turn right, and if it is a black square (represented by #) it will turn left. */
void Ant::turnAnt(char color)
{
	if (color == ' ')
	{
		if (antFaces == DOWN)
		{
			antFaces = LEFT;
		}
		else if (antFaces == UP)
		{
			antFaces = RIGHT;
		}
		else if (antFaces == LEFT)
		{
			antFaces = UP;
		}
		else if (antFaces == RIGHT)
		{
			antFaces = DOWN;
		}
	}

	if (color == '#')
	{
		if (antFaces == DOWN)
		{
			antFaces = RIGHT;
		}
		else if (antFaces == UP)
		{
			antFaces = LEFT;
		}
		else if (antFaces == LEFT)
		{
			antFaces = DOWN;
		}
		else if (antFaces == RIGHT)
		{
			antFaces = UP;
		}
	}
}

/*moves the ant forward just one space depending on its direction. if up/down the row will be decremented/incremented, and moving left/right will be done by decrementing/incrementing the column. */
void Ant::moveAnt()
{
        if (antFaces == DOWN)
        {
                antRow++;
        }
        else if (antFaces == UP)
        {
                antRow--;
        }
        else if (antFaces == LEFT)
        {
                antColumn--;
        }
        else if (antFaces == RIGHT)
        {
                antColumn++;
        }
}

/*This function is called in the event that the ant hits the edge of the board. to keep it from going out of bounds, the ant is turned 180 degrees and sent two steps back in the opposite direction. */
void Ant::replaceAnt()
{
	if (antFaces == DOWN)
	{
		antFaces == UP;
		antRow -= 2;
	}
	else if (antFaces == UP)
	{
		antFaces == DOWN;
		antRow += 2;
	}
	else if (antFaces == RIGHT)
	{
		antFaces == LEFT;
		antColumn -= 2;
	}
	else if (antFaces == LEFT)
	{
		antFaces == RIGHT;
		antColumn += 2;
	}
}	
