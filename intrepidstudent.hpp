
/*********************************************************************
 *** Program Filename: intrepidstudent.hpp
 * ** Author: Charlene Wang
 * ** Date: 3/20/19
 * ** Description: holds the code for the intrepidstudent class inherits from mazeperson
 * ** Input: none
 * ** Output: none
 * *********************************************************************/
#ifndef intrepidSTUDENT_HPP
#define intrepidSTUDENT_HPP
#include <iostream>

#include "mazeperson.hpp"

using namespace std;

class IntrepidStudent: public MazePerson {
private:
    int skills;
public:
    IntrepidStudent();
    char get_move();
    
    void set_location(int _row, int _col);
    int get_row() {return this->row;}
    int get_col() {return this->col;}
    int get_skills() {return this->skills;}
    void set_skills(int x) {this->skills = x;}
    int return_type() {return 2;}
};

#endif

