/*********************************************************************
 *** Program Filename: instructor.cpp
 * ** Author: Charlene Wang
 * ** Date: 3/20/19
 * ** Description: implementation of the instructor lass contains all logic for the entire assignment that needs more than one line of code
 * ** Input: none
 * ** Output: none
 * *********************************************************************/
#include "instructor.hpp"

using namespace std;

/*********************************************************************
 ** Function: Instructor
 ** Description: constructor
 ** Parameters: none
 ** Pre-Conditions: needs to be called
 ** Post-Conditions: intializes certain variables
 *********************************************************************/
Instructor:: Instructor(){
    col = 0;
    row = 0;
}

/*********************************************************************
 ** Function: Instructor
 ** Description: will set location
 ** Parameters: int _row, int _col
 ** Pre-Conditions: row and col must exist
 ** Post-Conditions: will set a position
 *********************************************************************/
void Instructor :: set_location(int _row, int _col){
    this->col = _col;
    this->row = _row;
}






