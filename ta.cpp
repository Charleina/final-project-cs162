/*********************************************************************
 *** Program Filename: ta.cpp
 * ** Author: Charlene Wang
 * ** Date: 3/20/19
 * ** Description: implementation of the Ta class contains functions of ta classmthat needs more than one line of code
 * ** Input: none
 * ** Output: none
 * *********************************************************************/
#include "ta.hpp"

using namespace std;

/*********************************************************************
 ** Function: Ta
 ** Description: constructor
 ** Parameters: none
 ** Pre-Conditions: needs to be called
 ** Post-Conditions: intializes certain variables
 *********************************************************************/
Ta :: Ta(){
    this->row = 0;
    this->col = 0;
}

/*********************************************************************
 ** Function: get_move
 ** Description: returns random move
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: changes nothing
 *********************************************************************/
char Ta :: get_move(){
    int move = rand() % 4;
    if(move == 0)
        return 'w';
    else if(move == 1)
        return 'a';
    else if(move == 2)
        return 'd';
    else
        return 's';
}

/*********************************************************************
 ** Function: set_location
 ** Description: will change the location of ta
 ** Parameters: int _row, int _col
 ** Pre-Conditions: variables need to exist
 ** Post-Conditions: alters the class row and col
 *********************************************************************/
void Ta :: set_location(int _row, int _col){
    this->row = _row;
    this->col = _col;
}
