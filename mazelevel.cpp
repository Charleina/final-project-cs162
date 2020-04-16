/*********************************************************************
 *** Program Filename: mazelevel.cpp
 * ** Author: Charlene Wang
 * ** Date: 3/20/19
 * ** Description: implementation of the Mazelevelclass contains all logic for the entire assignment
 * ** Input: none
 * ** Output: none
 * *********************************************************************/
#include "mazelevel.hpp"

using namespace std;

/*********************************************************************
 ** Function: Mazelevel
 ** Description: constructor
 ** Parameters: none
 ** Pre-Conditions: needs to be called
 ** Post-Conditions: intializes certain variables
 *********************************************************************/
MazeLevel :: MazeLevel(){
    this->_height = 0;
    this->_width = 0;
    this->instructor = false;
    this->fail = false;
    this->appeased = false;
    this->count_for_ta = 0;
    this->howmanypeople = 0;
    this->people = vector< MazePerson* >(4);
    this->appeased= false;
}

/*********************************************************************
 ** Function: Mazelevel
 ** Description: copy constructor
 ** Parameters: const MazeLevel& m
 ** Pre-Conditions: needs to be called
 ** Post-Conditions: intializes certain variables
 *********************************************************************/
MazeLevel :: MazeLevel(const MazeLevel& m){
    this->_height = m._height;
    this->_width = m._width;
    this->instructor = m.instructor;
    this->fail = m.fail;
    this->appeased = m.appeased;
    this->count_for_ta = m.count_for_ta;
    this->people = vector< MazePerson* >(howmanypeople);
    this->howmanypeople = m.howmanypeople;
    //copying info over
    for(int i =0; i < howmanypeople; i++)
        this->people[i] = m.people[i];
    this->appeased= m.appeased;
}

/*********************************************************************
 ** Function: operator=
 ** Description: operator overload
 ** Parameters: const MazeLevel& m1
 ** Pre-Conditions: needs to be called
 ** Post-Conditions: intializes certain variables
 *********************************************************************/
void MazeLevel :: operator=(const MazeLevel& m1){
    this->_height = m1._height;
    this->_width = m1._width;
    this->instructor = m1.instructor;
    this->fail = m1.fail;
    this->appeased = m1.appeased;
    this->count_for_ta = m1.count_for_ta;
    this->people = vector< MazePerson* >(howmanypeople);
    this->howmanypeople = m1.howmanypeople;
    //copying info over
    for(int i =0; i < howmanypeople; i++)
        this->people[i] = m1.people[i];
    this->appeased= m1.appeased;
}

/*********************************************************************
 ** Function: initialize
 ** Description: will initialize everything with the ifstream object
 ** Parameters:fstream& m, int height, int width
 ** Pre-Conditions: variables and functions need to exist
 ** Post-Conditions: intializes certain vectors and other information from other classes
 *********************************************************************/
void MazeLevel :: initialize(ifstream& m, int height, int width){
    this->_height = height;
    this->_width = width;
    this->locations = vector< vector<MazeLocation*> >(_height, vector<MazeLocation*>(_width));
    this->line = vector< string >(_height);
    
    int count = 0;
    while(count < this->_height && m.good()){
        getline(m, this->line[count]);
        //cout << line[count] << endl;
        count++;
    }
    
    bool instructor_exists = false;
    
    for(int i = 0; i < this->_height; i++){
        for(int j = 0; j < this->_width; j++){
            //this is just an openspace
            if(this->line[i][j] == ' ')
                this->locations.at(i).at(j) = new Openspace();
            //this is starting position
            else if(this->line[i][j] == '@'){
                this->locations.at(i).at(j) = new Openspace();
                this->locations.at(i).at(j)->set_has_student(true);
                this->locations.at(i).at(j)->set_display_character('@');
                this->locations.at(i).at(j)->set_is_start(true);
                this->people[howmanypeople] = new IntrepidStudent();
                this->people[howmanypeople++]->set_location(i,j);
            }
            //the ladder
            else if(this->line[i][j] == '^'){
                this->locations.at(i).at(j) = new Openspace();
                this->locations.at(i).at(j)->set_display_character('^');
                this->locations.at(i).at(j)->set_has_ladder(true);
                this->locations.at(i).at(j)->set_is_end(true);
            }
            //the instructor
            else if(this->line[i][j] == '%'){
                this->locations.at(i).at(j) = new Openspace();
                this->locations.at(i).at(j)->set_has_instructor(true);
                this->locations.at(i).at(j)->set_display_character('%');
                this->people[howmanypeople] = new Instructor();
                this->people[howmanypeople++]->set_location(i,j);
                instructor_exists = true;
            }
            //a wall
            else if(this->line[i][j] == '#')
                this->locations.at(i).at(j) = new Wall();
        }
    }
    
    //if instructor doesnt exist then people is only 3 spaces not 4
    if(!instructor_exists){
        //reset the count for howmanypeople
        howmanypeople = 0;
        MazePerson* person = people[howmanypeople];
        //re size vector for people
        this->people = vector< MazePerson* >(3);
        //recreate the student in first position
        this->people[howmanypeople++] = person;
    }
    
    //so it can randomly occur 5 times total for 3 skill and 2 tas
    vector<int> v = {0, 1, 2, 3, 4};
    random_shuffle(v.begin(), v.end());
    
    //used for the do while loops
    int count_for_placement = 0, placement = 0, j = 0, i = 0;
    
    do{
        i = rand() % _height;
        j = rand() % _width;
        //checks if space is not a wall
        if(locations.at(i).at(j)->is_occupiable()){
            //then increments and calls this number in the v vector
            placement = v[count_for_placement++];
            //for tas
            if(placement == 0 || placement == 2){
                //this is for when the spot can't have a ta
                if((i >= people[0]->get_row()-1 && i <= people[0]->get_row()+1 && j >= people[0]->get_col() && j <= people[0]->get_col()+1) || validate_can_move(i, j) == false){
                    --count_for_placement;
                }
                else {
                    this->locations.at(i).at(j)->set_display_character('T');
                    this->locations.at(i).at(j)->set_has_ta(true);
                    this->people[howmanypeople] = new Ta();
                    this->people[howmanypeople++]->set_location(i,j);
                }
            }
            //for skills
            else if( placement == 1 || placement == 3 || placement == 4){
                //this is for when the spot can't have a skill
                if((i >= people[0]->get_row()-1 && i <= people[0]->get_row()+1 && j >= people[0]->get_col() && j <= people[0]->get_col()+1) ||validate_can_move(i, j) == false){
                    --count_for_placement;
                }
                else {
                    this->locations.at(i).at(j)->set_display_character('$');
                    this->locations.at(i).at(j)->set_has_skill(true);
                }
            }
        }
    } while(count_for_placement < 5);
    
}

/*********************************************************************
 ** Function: ~Mazelevel
 ** Description: deconstructor
 ** Parameters: none
 ** Pre-Conditions: object and variables need to exist
 ** Post-Conditions: will free memory
 *********************************************************************/
MazeLevel :: ~MazeLevel(){
    for(int i = 0; i < this->_height; i++){
        for(int j = 0; j < this->_width; j++){
            delete this->locations.at(i).at(j);
        }
    }
    for(int i = 0; i < howmanypeople; i++)
        delete this->people.at(i);
}

/*********************************************************************
 ** Function: get_location
 ** Description:
 ** Parameters: none
 ** Pre-Conditions: needs to be called
 ** Post-Conditions: intializes certain variables
 *********************************************************************/
MazeLocation* MazeLevel :: get_location(int row, int col){
    return this->locations.at(row).at(col);
}

/*********************************************************************
 ** Function: display_maze
 ** Description: will take map and print it out
 ** Parameters: none
 ** Pre-Conditions: maze needs to exist
 ** Post-Conditions: will print out maze
 *********************************************************************/
void MazeLevel :: display_maze(){
    int count_line = 1;
    for(int i = 0; i < this->_height; i++){
        for(int j = 0; j < this->_width; j++){
            //will print out the
            cout << this->locations.at(i).at(j)->get_display_character();
            if(count_line % this->_width == 0){
                cout << endl;
            }
            count_line++;
        }
    }
}

/*********************************************************************
 ** Function: randomly_move_ta
 ** Description: will randomly move each ta to a valid spot
 ** Parameters: none
 ** Pre-Conditions: variables and functions need to exist
 ** Post-Conditions: ta's will have moved in locations and in their own class
 *********************************************************************/
void MazeLevel :: randomly_move_ta(){
    char c = ' ';
    bool error = false;
    
    for(int i = 0; i < _height; i++){
        for(int j = 0; j < _width; j++){
            if(locations.at(i).at(j)->get_has_ta()){
                int which = 0;
                //finding the exact ta.
                while( which < howmanypeople ){
                    if(people[which]->return_type() == 1 && people[which]->get_row() == i && people[which]->get_col() == j){
                        break;
                    }
                    
                    else{
                        ++which;
                    }
                }
                do{
                    
                    error = false;
                    
                    c = this->people[which]->get_move();
                    
                    if(c == 'w'){//go up
                        if(validate_can_move(i-1, j) == false)
                            error = true;
                    }
                    else if(c == 's'){//go down
                        if(validate_can_move(i+1, j) == false)
                            error = true;
                    }
                    else if(c == 'a'){//go left
                        if(validate_can_move(i, j-1) == false)
                            error = true;
                    }
                    else if(c == 'd'){//go right
                        if(validate_can_move(i, j+1) == false)
                            error = true;
                    }
                    
                }while(error);
                
                //cout << which << c << endl;
                
                if(c == 'w')//up
                {
                    this->locations.at(i).at(j)->set_display_character(' ');
                    this->locations.at(i).at(j)->set_has_ta(false);
                    this->people[which]->set_location(i-1,j);
                    //move_ta(i-1, j, which);
                    check();
                }
                else if( c == 'd')//right
                {
                    this->locations.at(i).at(j)->set_display_character(' ');
                    this->locations.at(i).at(j)->set_has_ta(false);
                    this->people[which]->set_location(i,j+1);
                    //move_ta(i, j+1, which);
                    check();
                }
                else if(c == 'a')//left
                {
                    this->locations.at(i).at(j)->set_display_character(' ');
                    this->locations.at(i).at(j)->set_has_ta(false);
                    this->people[which]->set_location(i,j-1);
                    //move_ta(i, j-1, which);
                    check();
                }
                else //down
                {
                    this->locations.at(i).at(j)->set_display_character(' ');
                    this->locations.at(i).at(j)->set_has_ta(false);
                    this->people[which]->set_location(i+1,j);
                    //move_ta(i+1, j, which);
                    check();
                }
            }
            //display_maze();
        }
    }
    
    //finding the each ta.
    for( int which = 0; which < howmanypeople; which++)
        if(people[which]->return_type() == 1){
            //this is outside of the prvious for loops because sometimes the ta is placed somewhere after the initial spot and the locations vector causes it to get moved again.
            move_ta(people[which]->get_row(), people[which]->get_col());
        }
}

/*********************************************************************
 ** Function: prompt
 ** Description: will prompt user and thn move them or demonstrate skill or go up a levl if valid
 ** Parameters: none
 ** Pre-Conditions: variables and functions need to exist
 ** Post-Conditions: user will have moved/demonstrated/went up a level and skills or appeased will be changed
 *********************************************************************/
bool MazeLevel :: prompt(){
    //will be used to return whether or not the student chose and can move up the ladder
    bool ladder = false;
    
    //for the move so i can use it for if statements
    char answer = ' ';
    
    //for the people vector since student will always be first it is 0
    int count = 0;
    
    //for if the student has already been moved
    bool found_student = false;
    
    //checking if game is already won
    if(!instructor){
        for(int i = 0; i < _height && found_student == false; i++){
            for(int j = 0; j < _width && found_student == false; j++){
                //checking for which spot has student
                if(locations.at(i).at(j)->get_has_student()){
                    found_student = true;
                    //for checking if use input is valid for demonstrating and going up ladders
                    bool error = false;
                    //for if the user choooses demonstrate or ladder and if they dont have any skills or are not standing in a space with a ladder, i have to re-ask the user
                    do{
                        //for checking if user input is valid for moving
                        bool error2 = false;
                        //reseting the error for checking demonstrating and going up ladders
                        error = false;
                        //checking if the space they move to is occupiable and if they choose something else then nothing happens here.
                        do{
                            //reseting the error for checking moves
                            error2 = false;
                            //getting the answer, the intrepid student class has a part where it prompts the user for their choice.
                            answer = this->people[count]->get_move();
                            
                            if(answer == 'w'){//go up
                                if(this->locations.at(i-1).at(j)->is_occupiable() == false){
                                    error2 = true;
                                    cout << "Invalid input, try again" << endl;
                                }
                            }
                            else if(answer == 's'){//go down
                                if(this->locations.at(i+1).at(j)->is_occupiable() == false){
                                    error2 = true;
                                    cout << "Invalid input, try again" << endl;
                                }
                            }
                            else if(answer == 'a'){//go left
                                if(this->locations.at(i).at(j-1)->is_occupiable() == false){
                                    error2 = true;
                                    cout << "Invalid input, try again" << endl;
                                }
                            }
                            else if(answer == 'd'){//go right
                                if(this->locations.at(i).at(j+1)->is_occupiable() == false){
                                    error2 = true;
                                    cout << "Invalid input, try again" << endl;
                                }
                            }
                        }while(error2);
                        
                        if(answer == 'w'){//go up
                            this->locations.at(i).at(j)->set_display_character(' ');
                            this->locations.at(i).at(j)->set_has_student(false);
                            move_student(i-1, j);
                            check();
                        }
                        else if(answer == 's'){//go down
                            this->locations.at(i).at(j)->set_display_character(' ');
                            this->locations.at(i).at(j)->set_has_student(false);
                            move_student(i+1, j);
                            check();
                        }
                        else if(answer == 'a'){//go left
                            this->locations.at(i).at(j)->set_display_character(' ');
                            this->locations.at(i).at(j)->set_has_student(false);
                            move_student(i,j-1);
                            check();
                        }
                        else if(answer == 'd'){ //go right
                            this->locations.at(i).at(j)->set_display_character(' ');
                            this->locations.at(i).at(j)->set_has_student(false);
                            move_student(i,j+1);
                            check();
                        }
                        else if(answer == 'p'){//demonstrate
                            this->people[count]->set_skills(this->skill);
                            //checking if user has skills
                            if(people[count]->get_skills() > 0){
                                cout << "You demonstrated a skill! All Ta's on this level will be appeased for a total of 10 turns." << endl;
                                //drop a skill first
                                people[count]->set_skills(people[count]->get_skills()-1);
                                this->skill--;
                                this->appeased = true;
                                //setting to 0 in case this happens again and its set to 10 not 0
                                this->count_for_ta = 0;
                            }
                            //for when the user does not have skills
                            else{
                                cout << "You do not have any programming skills! Enter another answer!" << endl;
                                error = true;
                            }
                        }
                        else if(answer == 'u'){
                            //checking if there is a ladder there
                            if(locations.at(i).at(j)->get_has_ladder() == false){
                                cout << "You are not standing in a space with the ladder! Enter another answer!" << endl;
                                error = true;
                            }
                            //for when there is a ladder
                            else
                                ladder = true;
                        }
                    }while(error);
                }
            }
        }
    }
    
    
    //checking if it has been 10 turns
    if(count_for_ta == 10)
        this->appeased = false;
    
    //if the ta's are appeased it will increase count_for_ta
    else if(appeased)
        this->count_for_ta++;
    
    //this will tell the Maze class whether or not the user changed levels
    return ladder;
}

/*********************************************************************
 ** Function: move_ta
 ** Description: moves ta
 ** Parameters: int row, int col, int count
 ** Pre-Conditions: variables and functions need to exist
 ** Post-Conditions: this will move tas in location vector
 *********************************************************************/
void MazeLevel :: move_ta(int row, int col){
    this->locations.at(row).at(col)->set_display_character('T');
    this->locations.at(row).at(col)->set_has_ta(true);
}

/*********************************************************************
 ** Function: move_student
 ** Description: moves student
 ** Parameters: int row, int col, int count
 ** Pre-Conditions: variables and functions need to exist
 ** Post-Conditions:this will move student in location vector
 *********************************************************************/
void MazeLevel :: move_student(int row, int col){
    this->locations.at(row).at(col)->set_display_character('*');
    this->locations.at(row).at(col)->set_has_student(true);
}

/*********************************************************************
 ** Function: check
 ** Description: for after student moves, chcks if space has programming skill or ta/instructor adjacent or in same space.
 ** Parameters: none
 ** Pre-Conditions: variables and functions need to exist
 ** Post-Conditions: will change vectors locations or people to fit the sitution
 *********************************************************************/
void MazeLevel :: check(){
    //for the people vector
    int count = 0;
    
    //tto check if the game is already won then it will exit the for loop
    bool won_game = false;
    
    for(int i = 0; i < _height; i++){
        for(int j = 0; j < _width; j++){
            //making sure the start position is always marked
            if(locations.at(i).at(j)->is_start())
                locations.at(i).at(j)->set_display_character('@');
            
            //making sure the ladder position is always marked
            if(locations.at(i).at(j)->get_has_ladder())
                locations.at(i).at(j)->set_display_character('^');
            
            //checking if student is near ta
            if(locations.at(i).at(j)->get_has_ta() && !appeased)
                for(int row = i-1; row <= i+1; row++){
                    for(int col = j-1; col <= j+1; col++){
                        if(locations.at(row).at(col)->get_has_student()){
                            ta_caught();
                        }
                    }
                }
            
            //checking if instructor exists and then if student is adjacent to instructor
            if(locations.at(i).at(j)->get_has_instructor())
                for(int row = i-1; row <= i+1 && won_game == false; row++){
                    for(int col = j-1; col <= j+1 && won_game == false; col++){
                        if(locations.at(row).at(col)->get_has_student()){
                            won_game = instructor_caught();
                        }
                    }
                }
            
            //checking if the space the student in has a skill.
            if(locations.at(i).at(j)->get_has_skill())
                if(locations.at(i).at(j)->get_has_student()){
                    this->locations.at(i).at(j)->set_has_skill(false);
                    if(this->people[0]->return_type() == 2){
                        this->people[0]->set_skills(people[0]->get_skills() + 1);
                        this->skill++;
                        cout << "Picked up a skill!" << endl;
                    }
                }
            //making sure it just exits when the game is won
            if(won_game)
                break;
        }
        //making sure it just exits when the game is won
        if(won_game)
            break;
    }
}

/*********************************************************************
 ** Function: ta_caught
 ** Description: when the student comes within space of ta or same and loses skills and goes back to beginning of level
 ** Parameters: none
 ** Pre-Conditions: variables and functions need to exist
 ** Post-Conditions: will remove all skills and tas then randomly place them in again
 *********************************************************************/
void MazeLevel :: ta_caught(){
    //for the people vector
    int count = 0;
    
    cout << "You were caught by a TA! The stress of being caught caused you to lose all your programming skills... and now you have to start this level over again." << endl;
    //circling through to find ta
    while( count < howmanypeople){
        //looking for student in people vector
        if(this->people[count]->return_type() == 2){
            //setting the skills to 0 becuase they lose them when they meet or come near ta
            this->people[count]->set_skills(0);
            this->skill = 0;
            
            for(int i = 0; i < _height; i++){
                for(int j = 0; j < _width; j++){
                    //finding the position of the student
                    if(locations.at(i).at(j)->get_has_student()){
                        //clear the spot of student's presence
                        this->locations.at(i).at(j)->set_display_character(' ');
                        this->locations.at(i).at(j)->set_has_student(false);
                    }
                    //finding where start is
                    if(locations.at(i).at(j)->is_start()){
                        //set students new location
                        this->people[count]->set_location(i, j);
                        move_student(i, j);
                    }
                }
            }
        }
        count++;
    }
    
    //deletes all current skills
    for(int row = 0; row < _height; row++)
        for(int col = 0; col < _width; col++)
            if(locations.at(row).at(col)->get_has_skill()){
                this->locations.at(row).at(col)->set_has_skill(false);
                this->locations.at(row).at(col)->set_display_character(' ');
            }
    
    
    //so it can randomly occur 5 times total for 3 skill and 2 tas
    vector<int> v = {0, 1, 2, 3, 4};
    random_shuffle(v.begin(), v.end());
    
    //used for the do while loops
    int count_for_placement = 0, placement = 0, j = 0, i = 0;
    
    do{
        i = rand() % _height;
        j = rand() % _width;
        //checks if space is not a wall
        if(locations.at(i).at(j)->is_occupiable()){
            //then increments and calls this number in the v vector
            placement = v[count_for_placement++];
            //for tas
            if(placement == 0 || placement == 2){
                //this is for when the spot can't have a ta
                if((i >= people[0]->get_row()-1 && i <= people[0]->get_row()+1 && j >= people[0]->get_col() && j <= people[0]->get_col()+1) || validate_can_move(i, j) == false){
                    count_for_placement--;
                }
                else {
                    //to check if ta is found
                    bool found_ta = false;
                    //circles through the locations array
                    for(int r = 0; r < _height && found_ta == false; r++){
                        for(int c = 0; c < _width && found_ta == false; c++){
                            //finding ta
                            if(locations.at(r).at(c)->get_has_ta()){
                                
                                //deleting ta from locataions
                                this->locations.at(r).at(c)->set_display_character(' ');
                                this->locations.at(r).at(c)->set_has_ta(false);
                                
                                //looking for ta but only once.
                                for( int which = 0; which < howmanypeople; which++)
                                    if(this->people[which]->return_type() == 1 && this->people[which]->get_row() == r && this->people[which]->get_col() == c){
                                        this->people[which]->set_location(i,j);
                                        found_ta = true;
                                        break;
                                    }
                            }
                        }
                    }
                }
            }
            //for skills
            else if( placement == 1 || placement == 3 || placement == 4){
                //this is for when the spot can't have a skill
                if((i >= people[0]->get_row()-1 && i <= people[0]->get_row()+1 && j >= people[0]->get_col() && j <= people[0]->get_col()+1) || validate_can_move(i, j) == false){
                    count_for_placement--;
                }
                else {
                    this->locations.at(i).at(j)->set_display_character('$');
                    this->locations.at(i).at(j)->set_has_skill(true);
                }
            }
        }
    } while(count_for_placement < 5);
    
    //finding the each ta.
    for( int which = 0; which < howmanypeople; which++)
        if(people[which]->return_type() == 1){
            //this is outside of the prvious for loops because sometimes the ta is placed somewhere after the initial spot and the locations vector causes it to get moved again.
            move_ta(people[which]->get_row(), people[which]->get_col());
        }
}


/*********************************************************************
 ** Function: instructor_caught
 ** Description:when the student comes within space of instructor and loses skills and goes back to beginning of maze
 ** Parameters: none
 ** Pre-Conditions: variables and functions need to exist
 ** Post-Conditions: will either reset the game or win the game
 *********************************************************************/
bool MazeLevel :: instructor_caught(){
    int count = 0;
    cout << "You are met by the Instructor, he will now test your skills." << endl;
    while(count < howmanypeople){
        if(this->people[count]->return_type() == 2){
            if(this->people[count]->get_skills() >= 3){
                cout << "You demonstrated three skills to the Instructor and succeeded! Congratulations you have passed CS 162!" << endl;
                this->instructor = true;
                return true;
            }
            else{
                cout << "You did not have enough programming skills for the Instructor, they have given you a failing grade and you must now restart the entire maze!" << endl;
                this->fail = true;
                return false;
            }
        }
        ++count;
    }
}

/*********************************************************************
 ** Function: validate_can_move
 ** Description: return true if it can move and false if it cannot move
 ** Parameters: int i, int j
 ** Pre-Conditions: variables have to exist
 ** Post-Conditions: will return a boolean
 *********************************************************************/
bool MazeLevel:: validate_can_move(int i, int j){
    return this->locations.at(i).at(j)->is_occupiable() && !(this->locations.at(i).at(j)->get_has_ta() || this->locations.at(i).at(j)->get_has_skill() || this->locations.at(i).at(j)->get_has_instructor() || this->locations.at(i).at(j)->get_has_ladder());
}

/*********************************************************************
 ** Function: restart_initialization
 ** Description: is called when instructor fails student
 ** Parameters: none
 ** Pre-Conditions: variables have to exist
 ** Post-Conditions: will re-initialize everything
 *********************************************************************/
void MazeLevel:: restart_initialization(){
    //free all the memory
    for(int i = 0; i < this->_height; i++){
        for(int j = 0; j < this->_width; j++){
            delete this->locations.at(i).at(j);
        }
    }
    for(int i = 0; i < howmanypeople; i++)
        delete this->people.at(i);
    
    //reset variables
    this->instructor = false;
    this->fail = false;
    this->appeased = false;
    this->count_for_ta = 0;
    this->howmanypeople = 0;
    this->appeased= false;
    
    //re-making the vectors
    this->locations = vector< vector<MazeLocation*> >(_height, vector<MazeLocation*>(_width));
    //set to 4 for now
    this->people = vector< MazePerson* >(4);
    
    bool instructor_exists = false;
    
    for(int i = 0; i < this->_height; i++){
        for(int j = 0; j < this->_width; j++){
            //this is just an openspace
            if(this->line[i][j] == ' ')
                this->locations.at(i).at(j) = new Openspace();
            //this is starting position
            else if(this->line[i][j] == '@'){
                this->locations.at(i).at(j) = new Openspace();
                this->locations.at(i).at(j)->set_has_student(true);
                this->locations.at(i).at(j)->set_display_character('@');
                this->locations.at(i).at(j)->set_is_start(true);
                this->people[howmanypeople] = new IntrepidStudent();
                this->people[howmanypeople++]->set_location(i,j);
            }
            //the ladder
            else if(this->line[i][j] == '^'){
                this->locations.at(i).at(j) = new Openspace();
                this->locations.at(i).at(j)->set_display_character('^');
                this->locations.at(i).at(j)->set_has_ladder(true);
                this->locations.at(i).at(j)->set_is_end(true);
            }
            //the instructor
            else if(this->line[i][j] == '%'){
                this->locations.at(i).at(j) = new Openspace();
                this->locations.at(i).at(j)->set_has_instructor(true);
                this->locations.at(i).at(j)->set_display_character('%');
                this->people[howmanypeople] = new Instructor();
                this->people[howmanypeople++]->set_location(i,j);
                instructor_exists = true;
            }
            //a wall
            else if(this->line[i][j] == '#')
                this->locations.at(i).at(j) = new Wall();
        }
    }
    
    //if instructor doesnt exist then people is only 3 spaces not 4
    if(!instructor_exists){
        //reset the count for howmanypeople
        howmanypeople = 0;
        MazePerson* person = people[howmanypeople];
        //re size vector for people
        this->people = vector< MazePerson* >(3);
        //recreate the student in first position
        this->people[howmanypeople++] = person;
    }
    
    //so it can randomly occur 5 times total for 3 skill and 2 tas
    vector<int> v = {0, 1, 2, 3, 4};
    random_shuffle(v.begin(), v.end());
    
    //used for the do while loops
    int count_for_placement = 0, placement = 0, j = 0, i = 0;
    
    do{
        i = rand() % _height;
        j = rand() % _width;
        //checks if space is not a wall
        if(locations.at(i).at(j)->is_occupiable()){
            //then increments and calls this number in the v vector
            placement = v[count_for_placement++];
            //for tas
            if(placement == 0 || placement == 2){
                //this is for when the spot can't have a ta
                if((i >= people[0]->get_row()-1 && i <= people[0]->get_row()+1 && j >= people[0]->get_col() && j <= people[0]->get_col()+1) || validate_can_move(i, j) == false){
                    --count_for_placement;
                }
                else {
                    this->locations.at(i).at(j)->set_display_character('T');
                    this->locations.at(i).at(j)->set_has_ta(true);
                    this->people[howmanypeople] = new Ta();
                    this->people[howmanypeople++]->set_location(i,j);
                }
            }
            //this is for when the spot can't have a skill
            else if( placement == 1 || placement == 3 || placement == 4){
                if(validate_can_move(i, j) == false){
                    --count_for_placement;
                }
                else {
                    this->locations.at(i).at(j)->set_display_character('$');
                    this->locations.at(i).at(j)->set_has_skill(true);
                }
            }
        }
    } while(count_for_placement < 5);
}

