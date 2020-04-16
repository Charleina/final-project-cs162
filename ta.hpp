
/*********************************************************************
 *** Program Filename: ta.hpp
 * ** Author: Charlene Wang
 * ** Date: 3/20/19
 * ** Description: holds the code for the ta class inherits from mazeperson
 * ** Input: none
 * ** Output: none
 * *********************************************************************/
#ifndef TA_HPP
#define TA_HPP
#include <iostream>
#include <stdlib.h>

#include "mazeperson.hpp"

using namespace std;

class Ta : public MazePerson{
public:
    Ta();
    char get_move();
    
    void set_location(int _row, int _col);
    int get_row() {return this->row;}
    int get_col() {return this->col;}
    int return_type() {return 1;}
    
    //does nothing in this class
    int get_skills() {return 0;}
    void set_skills(int x) {}
    
};

#endif

