/*********************************************************************
 *** Program Filename: intrepidstudent.cpp
 * ** Author: Charlene Wang
 * ** Date: 3/20/19
 * ** Description: implementation of the intrepidstudent class contains all the functions in intrepidstudent that needs more than one line of code
 * ** Input: none
 * ** Output: none
 * *********************************************************************/
#include "intrepidstudent.hpp"

using namespace std;

/*********************************************************************
 ** Function: intrepidstudent
 ** Description: constructor
 ** Parameters: none
 ** Pre-Conditions: needs to be called
 ** Post-Conditions: intializes certain variables
 *********************************************************************/
IntrepidStudent :: IntrepidStudent(){
    skills = 0;
    row = 0;
    col = 0;
}

/*********************************************************************
 ** Function: get_move
 ** Description: will move the character given a move
 ** Parameters: char move
 ** Pre-Conditions: row and col must exist
 ** Post-Conditions: will change locaation
 *********************************************************************/
char IntrepidStudent :: get_move(){
    bool error = true;
    int count = 0;
    do {
        error = true;
        cout << "Would you like to move, demonstrate, or go up ladder?  (‘w’ for up/’s’ for down/’a’ for left/’d’ for right/’p’ to demonstrate skill/’u’ to go up a ladder)" << endl;
        string answer;
        cin >> answer;
        
        if(answer == "w") // up
        {
            col -= 1;
            return 'w';
        }
        else if(answer == "s")// down
        {
            col += 1;
            return 's';
        }
        else if(answer == "a")// left
        {
            row -= 1;
            return 'a';
        }
        else if(answer == "d")// right
        {
            row += 1;
            return 'd';
        }
        else if(answer == "p")// demonstrate
        {
            return 'p';
        }
        else if(answer == "u")// go up ladder
        {
            return 'u';
        }
        else
        {
            error = false;
            cout << "Invalid Input, Try again." << endl;
        }
    } while(!error);
}

/*********************************************************************
 ** Function: set_location
 ** Description: will set location for student
 ** Parameters: int _row, int _col
 ** Pre-Conditions: row and col must exist
 ** Post-Conditions: change locaation
 *********************************************************************/
void IntrepidStudent :: set_location(int _row, int _col){
    this->row = _row;
    this->col = _col;
}






