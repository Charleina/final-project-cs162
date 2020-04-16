
/*********************************************************************
 *** Program Filename: mazeperson.hpp
 * ** Author: Charlene Wang
 * ** Date: 3/20/19
 * ** Description: holds the code for the Mazeperson class and is abstract
 * ** Input: none
 * ** Output: none
 * *********************************************************************/
#ifndef MAZEPERSON_HPP
#define MAZEPERSON_HPP
#include <iostream>

using namespace std;

class MazePerson {
protected:
    int row, col;
public:
    virtual char get_move() = 0;
    virtual void set_location(int _row, int _col) = 0;
    virtual int get_row() = 0;
    virtual int get_col() = 0;
    virtual int return_type() =0;
    
    //for student
    virtual int get_skills() =0;
    virtual void set_skills(int x) =0;
};

#endif

