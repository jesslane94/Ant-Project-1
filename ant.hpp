/********************************************************************* ** 
 * Program name: ant.hpp
 * ** Author: Jessica Lane
 * ** Date: April 14, 2019
 * ** Description: This contains the class declaration for Ant. 
 * *********************************************************************/

#ifndef ANT_H
#define ANT_H

class Ant
{
	private:
		int antRow;
		int antColumn;
		enum Direction {UP, DOWN, LEFT, RIGHT}; //enum declaration for which way the ant will face
		Direction antFaces;
	public:
		Ant(int, int);
		int getAntRow();
		int getAntColumn();
		void turnAnt(char);
		void moveAnt();
		void replaceAnt();

};

#endif		
