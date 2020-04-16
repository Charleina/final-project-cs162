
/*********************************************************************
 *** Program Filename: openspace.hpp
 * ** Author: Charlene Wang
 * ** Date: 3/20/19
 * ** Description: holds the code for the Openspace class inherits from mazelocation
 * ** Input: none
 * ** Output: none
 * *********************************************************************/
#ifndef OPENSPACE_HPP
#define OPENSPACE_HPP
#include <iostream>

#include "mazelocation.hpp"

using namespace std;

class Openspace : public MazeLocation {
public:
    Openspace();
    
    bool get_has_student() {return this->has_student;}
    void set_has_student(bool x) {this->has_student = x;}
    
    void set_is_start(bool x) {this->start = x;}
    bool is_start() {return this->start;}
    
    void set_is_end(bool x) {this->end = x;}
    bool is_end() {return this->end;}
    
    void set_has_ta(bool x) { this->has_ta = x;}
    bool get_has_ta() {return this->has_ta;}
    
    void set_has_instructor(bool x) { this->has_instructor = x;}
    bool get_has_instructor() {return this->has_instructor;}
    
    void set_has_ladder(bool x){ this->has_ladder = x;}
    bool get_has_ladder() {return this->has_ladder;}
    
    void set_has_skill(bool x){ this->has_skill = x;}
    bool get_has_skill() {return this->has_skill;}
    
    bool is_occupiable() {return this->occupiable;}
    void set_occupiable(bool x) {this->occupiable = x;}
    
    char get_display_character() {return this->display;}
    void set_display_character(char x) {this->display = x;}
    
};

#endif

