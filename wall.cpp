/*********************************************************************
*** Program Filename: wall.cpp
* ** Author: Charlene Wang
* ** Date: 3/20/19
* ** Description: implementation of the wall class contains all initializing for the wall class
* ** Input: none
* ** Output: none
* *********************************************************************/
#include "wall.hpp"

using namespace std;

/*********************************************************************
 ** Function: Wall
 ** Descripti on: constructor
 ** Parameters: none
 ** Pre-Conditions: needs to be called
 ** Post-Conditions: intializes certain variables
 *********************************************************************/
Wall :: Wall(){
    this->occupiable = false;
    this->display = '#';
    this->has_student = false;
    this->has_ta = false;
    this->has_instructor = false;
    this->has_ladder = false;
    this->has_skill = false;
    this->start = false;
    this->end = false;
}
