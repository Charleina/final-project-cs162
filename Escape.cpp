/*********************************************************************
 *** Program Filename: application.cpp
 * ** Author: Charlene Wang
 * ** Date: 3/20/19
 * ** Description: contains main function
 * ** Input: command line needs text file
 * ** Output: the entire game
 * *********************************************************************/
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <time.h> //for time
#include <ctime>
#include <stdio.h>
#include <stdlib.h>


#include "instructor.hpp"
#include "intrepidstudent.hpp"
#include "maze.hpp"
#include "mazelevel.hpp"
#include "mazelocation.hpp"
#include "mazeperson.hpp"
#include "openspace.hpp"
#include "ta.hpp"
#include "wall.hpp"


using namespace std;

/*********************************************************************
 ** Function: Main
 ** Description: contains main function
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: will do the entire game of Wumpus
 *********************************************************************/
int main(int argc, char **argv){
    
    string maze_file(argv[1]);
    
    ifstream maze;
    maze.open(maze_file);
    
    if(!maze.is_open()){
        cerr << "File does not exist" << endl;
        return 1;
    }
    
    
    srand(time(NULL));
    
    //create maze object
    Maze m(maze);
    
    m.run();
    
    return 0;
    
}
