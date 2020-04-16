/*********************************************************************
 *** Program Filename: instructor.hpp
 * ** Author: Charlene Wang
 * ** Date: 3/20/19
 * ** Description: holds the code for the instructor class inherits from mazeperson
 * ** Input: none
 * ** Output: none
 * *********************************************************************/
#ifndef INSTRUCTOR_HPP
#define INSTRUCTOR_HPP
#include <iostream>

#include "mazeperson.hpp"

using namespace std;

class Instructor : public MazePerson {    
public:
    Instructor();
    
    void set_location(int _row, int _col);
    int get_row() {return this->row;}
    int get_col() {return this->col;}
    int return_type() {return 3;}
    
    //does nothing in this class
    int get_skills() {return 0;}
    void set_skills(int x) {}
    char get_move() {return ' ';}
};

#endif

