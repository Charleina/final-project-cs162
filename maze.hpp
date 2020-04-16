
/*********************************************************************
 *** Program Filename: maze.hpp
 * ** Author: Charlene Wang
 * ** Date: 3/20/19
 * ** Description: holds the code for the Maze class
 * ** Input: needs an ifstream object
 * ** Output: prints out entire game
 * *********************************************************************/
#ifndef MAZE_HPP
#define MAZE_HPP
#include <iostream>
#include <fstream>
#include <vector>

#include "instructor.hpp"
#include "intrepidstudent.hpp"
#include "mazelevel.hpp"
#include "mazelocation.hpp"
#include "mazeperson.hpp"
#include "openspace.hpp"
#include "ta.hpp"
#include "wall.hpp"

using namespace std;

class Maze {
private:
    vector< MazeLevel > map;
    int num_level, level_height, level_width;
    
public:
    Maze(ifstream& m);
    //~Maze();
    void run();
    void welcome();
    
    
    
};

#endif

