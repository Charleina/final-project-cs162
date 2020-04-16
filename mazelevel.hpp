
/*********************************************************************
 *** Program Filename: mazelevel.hpp
 * ** Author: Charlene Wang
 * ** Date: 3/20/19
 * ** Description: holds the code for the Mazelevel class
 * ** Input: needs an ifstream object and it's information
 * ** Output: prints oout each level and actions
 * *********************************************************************/
#ifndef MAZELEVEL_HPP
#define MAZELEVEL_HPP
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <stdlib.h>

#include "instructor.hpp"
#include "intrepidstudent.hpp"
#include "mazelocation.hpp"
#include "mazeperson.hpp"
#include "openspace.hpp"
#include "ta.hpp"
#include "wall.hpp"

using namespace std;

class MazeLevel {
private:
    int _height, _width, count_for_ta;
    vector< vector<MazeLocation*> > locations;
    vector< MazePerson* > people;
    vector< string > line;
    bool instructor, fail, appeased;
    int skill;
    //this will keep count of the indexes within people vector counts from 0-4
    int howmanypeople;
    
public:
    MazeLevel();
    MazeLevel(const MazeLevel& m);
    void operator=(const MazeLevel& m1);
    ~MazeLevel();
    
    void initialize(ifstream& m, int height, int width);
    void display_maze();
    bool prompt();
    void randomly_move_ta();
    void move_ta(int row, int col);
    void move_student(int row, int col);
    void check();
    void ta_caught();
    bool instructor_caught();
    bool validate_can_move(int i, int j);
    void restart_initialization();
    
    void set_skill(int s) {this->skill = s;}
    
    //getters
    bool get_win(){return this->instructor;}
    bool get_fail(){return this->fail;}
    MazeLocation* get_location(int row, int col);
    int get_skill(){return this->skill;}
};

#endif
