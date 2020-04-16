/*********************************************************************
 *** Program Filename: opespace.cpp
 * ** Author: Charlene Wang
 * ** Date: 3/20/19
 * ** Description: implementation of the openspace class initializes all variables
 * ** Input: none
 * ** Output: none
 * *********************************************************************/
#include "openspace.hpp"

using namespace std;

/*********************************************************************
 ** Function: Openspace
 ** Description: constructor
 ** Parameters: none
 ** Pre-Conditions: needs to be called
 ** Post-Conditions: intializes certain variables
 *********************************************************************/
Openspace :: Openspace(){
    this->occupiable = true;
    this->display = ' ';
    this->has_student = false;
    this->has_ta = false;
    this->has_instructor = false;
    this->has_ladder = false;
    this->has_skill = false;
    this->start = false;
    this->end = false;
}


