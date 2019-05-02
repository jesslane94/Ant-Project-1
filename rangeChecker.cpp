/********************************************************************* ** 
 * Program name: rangeChecker.cpp
 * ** Author: Jessica Lane
 * ** Date: April 14, 2019
 * ** Description: rangeChecker will return true if the input is within the range of the min
 * and max entered. Otherwise, it will return false and an error message will be prompted through main.
 * First parameter is the user's input, then the min, and then the max.
 * *********************************************************************/

#include <iostream>
//adapted from this video: https://www.youtube.com/watch?v=4qw6OYbWXlw

bool rangeChecker(int input, int min, int max)
{
    if (input < min)
    {
        return false;
    }
    if (input > max)
    {
        return false;
    }

    return true;
}
