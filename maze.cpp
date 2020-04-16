/*********************************************************************
 *** Program Filename: maze.cpp
 * ** Author: Charlene Wang
 * ** Date: 3/20/19
 * ** Description: implementation of the Mazelevelclass with its functions implemented
 * ** Input: none
 * ** Output: none
 * *********************************************************************/
#include "maze.hpp"

using namespace std;

/*********************************************************************
 ** Function: Maze
 ** Description: constructor
 ** Parameters: none
 ** Pre-Conditions: needs to be called
 ** Post-Conditions: intializes certain variables
 *********************************************************************/
Maze :: Maze(ifstream& m){
    this->num_level = 0;
    this->level_height= 0;
    this->level_width = 0;
    m >> num_level >> level_height >> level_width;
    
    if (m.fail()) {
        std::cerr << "Failed to read an integer value"
        << std::endl;
    }
    
    this->map = vector< MazeLevel > (num_level);
    
    string s = "";
    m.seekg(0, m.beg);
    getline(m,s);
    //cout << s << endl;
    
    for(int i = 0; i < num_level; i++)
        this->map[i].initialize(m, level_height, level_width);
}

/*********************************************************************
 ** Function: run
 ** Description: will run the entire game with a do while loop
 ** Parameters: none
 ** Pre-Conditions: everything in mazelevel needs to exist and be initialized
 ** Post-Conditions: will run the game
 *********************************************************************/
void Maze :: run(){
    int count = 0;
    int skill = 0;
    bool ladder = false;
    bool win = false;
    bool fail = false;
    
    welcome();
    
    do{
        //this->map[count].display_maze();
        this->map[count].randomly_move_ta();
        this->map[count].display_maze();
        ladder = this->map[count].prompt();
        cout << "You have " << this->map[count].get_skill() << " skill(s)" << endl;
        win = this->map[count].get_win();
        fail = this->map[count].get_fail();
        //will move to next level
        if(ladder){
            //making sure students keeps their skills as they go up
            skill = this->map[count].get_skill();
            ++count;
            this->map[count].set_skill(skill);
        }
        //restarts game if fail
        if(fail){
            for(int i = 0; i < this->num_level; i++)
                map[i].restart_initialization();
            run();
        }
    } while( !win );
    
    cout << "Thanks for playing!" << endl;
}

/*********************************************************************
 ** Function: welcome
 ** Description: will print all info out
 ** Parameters: none
 ** Pre-Conditions: num_level needs to exist
 ** Post-Conditions: will print out welcome statement
 *********************************************************************/
void Maze :: welcome(){
    cout << endl;
    cout << "***************************************************************" << endl;
    cout << "                                                               " << endl;
    cout << "                                                               " << endl;
    cout << "                  Welcome to Escape CS 162!                    " << endl;
    cout << "                                                               " << endl;
    cout << "                                                               " << endl;
    cout << "***************************************************************" << endl;
    
    cout << "There are " << num_level << " level(s) in this game!" << endl << endl;
    
    cout << "In this game you will be an Intrepid Student traversing the CS" << endl;
    cout << "162 maze! Your symbol will be * and on each level you start within" << endl;
    cout << "the @ sign and as soon as you move * will pop up. the @ sign is" << endl;
    cout << "the starting position and you will be sent back there each time" << endl;
    cout << "you are caught by a TA or given a failing grade." << endl << endl;
    
    cout << "***************************************************************" << endl << endl;
    
    cout << "Each level also has a ladder, represented by ^, you must go to" << endl;
    cout << "the ladder to go up a level. Once you are in a new level, you" << endl;
    cout << "cannot go back." << endl << endl;
    
    cout << "***************************************************************" << endl << endl;
    
    cout << "Each level will have Two TAs, represented by T, who will" << endl;
    cout << "wander randomly around the CS 162 maze, trying to catch students" << endl;
    cout << "to make sure they know how to program. Each turn of the game," << endl;
    cout << "each TA moves randomly into an open space in the maze adjacent" << endl;
    cout << "to their current location." << endl << endl;
    
    cout << "***************************************************************" << endl << endl;
    
    cout << "If a TA occupies the same space as the Intrepid Student or a" << endl;
    cout << "space adjacent to the space occupied by the Intrepid Student," << endl;
    cout << "the Intrepid Student is caught, and the stress of being caught" << endl;
    cout << "causes them to lose all of their Programming Skills." << endl << endl;
    
    cout << "***************************************************************" << endl << endl;
    
    cout << "However, if you demonstrate a Programming Skill before a TA" << endl;
    cout << "enters the same space or an adjacent one, then all of the TAs" << endl;
    cout << "on the current level of the maze are appeased for 10 turns." << endl;
    cout << "While the TAs are appeased, they will still move, but they" << endl;
    cout << "will ignore the Intrepid Student and not catch them." << endl << endl;
    
    cout << "***************************************************************" << endl << endl;
    
    cout << "Each level will also have Three Programming skills, represented" << endl;
    cout << "by $, which are placed in a random open space and do not move." << endl;
    cout << "These are important to have!" << endl << endl;
    
    cout << "***************************************************************" << endl << endl;
    
    cout << "The last level will contain One Instructor, represented by %," << endl;
    cout << "who does not move. You have to have at least three Programming" << endl;
    cout << "Skills to satisfy the Instructor." << endl << endl;
    
    cout << "***************************************************************" << endl << endl;
    
    cout << "If you satisfy the Instructor you are given a passing grade and" << endl;
    cout << "allowed to exit the CS 162 maze. If you do not satisfy the" << endl;
    cout << "Instructor then you are given a failing grade and must complete" << endl;
    cout << "the CS 162 maze again, starting from the beginning of the first" << endl;
    cout << "level." << endl << endl;
    
    cout << "***************************************************************" << endl << endl;
    
    cout << "Good luck, hope you pass!" << endl << endl;
}

/*Maze :: ~Maze(){
    cout << "calling destructor" << endl;
}*/
