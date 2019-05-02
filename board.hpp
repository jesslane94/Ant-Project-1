/********************************************************************* ** 
 * Program name: board.hpp
 * ** Author: Jessica Lane
 * ** Date: April 14, 2019
 * ** Description: Header file for the board class.
 * *********************************************************************/
#ifndef BOARD_H
#define BOARD_H
#include "ant.hpp"

class Board
{
        private:
		Ant *ant; //pointer to an ant object
                int rows;
                int columns;
                char **board;

        public:
		Board(char**, int, int, Ant*);
		int getRows();
		int getColumns();
                char getColor(int, int);
                void changeColor(int, int);
		bool checkForEdge (int, int);
		void printBoard();
};

#endif
