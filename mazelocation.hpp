
/*********************************************************************
 *** Program Filename: MazeLocation.hpp
 * ** Author: Charlene Wang
 * ** Date: 3/20/19
 * ** Description: holds the code for the MazeLocation class and is abstract
 * ** Input: none
 * ** Output: none
 * *********************************************************************/
#ifndef MAZELOCATION_HPP
#define MAZELOCATION_HPP
#include <iostream>

using namespace std;

class MazeLocation {
protected:
    bool has_student, has_ta, has_instructor, has_ladder, has_skill, start, end;
    bool occupiable;
    char display;
    
public:
    virtual bool is_occupiable() = 0;
    virtual void set_occupiable(bool x)=0;
    
    virtual char get_display_character() = 0;
    virtual void set_display_character(char x)= 0;
    
    virtual bool get_has_student() = 0;
    virtual void set_has_student(bool x) = 0;
    
    virtual void set_is_start(bool x) = 0;
    virtual bool is_start() = 0;
    
    virtual void set_is_end(bool x) = 0;
    virtual bool is_end() = 0;
    
    virtual void set_has_ta(bool x) = 0;
    virtual bool get_has_ta() = 0;
    
    virtual void set_has_instructor(bool x)  = 0;
    virtual bool get_has_instructor()  = 0;
    
    virtual void set_has_ladder(bool x) = 0;
    virtual bool get_has_ladder() = 0;
    
    virtual void set_has_skill(bool x) = 0;
    virtual bool get_has_skill() = 0;
    
};

#endif

