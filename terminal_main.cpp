// Created on GG7FDFRFQ16M.
// Hello! this is my first proper c++ program. Cheers!

#include <iostream>
using namespace std;

int main() {


    //Initialyzing most of the variables
    string userName = "place_holder";


    // Asking for User's names for future reference
    cout << "Hello there! Please enter your first name: " << endl;
    cin >> userName;


    // Welcome to this program text.
    cout << "\n\n\n\nWelcome " << userName << "! This is my first C++ program."<< endl;
    cout << "This was begun Jan 18. 22' for my C++ Class at OSU." << endl;
    cout << "The course is primarily concerned with bringing students \nbrand new up to speed on programming essentials." << endl;
    cout << "This makes my time in class quite dull, since I have been \nplaying around with different languages for quite some time." << endl;
    cout << "To make the most of my time, I am writing this program. Its just me screwing around. \nEnjoy :)" << endl;
    cout << "\n\n" << endl;

    // Menu for the User to choose what they want to do:
    
    int userChoice = 0;
    cout << "Choose a menu option to explore: " << endl;
    cout << "[0] - Quit program" << endl;
    cout << "[1] - Nonogram Puzzle (work in proggress)" << endl;
    cin  >> userChoice;
    
    
    /*
    this is a series of IF statements that run based on the userChoice. (composing like this whole project lol)
    the 0 choice, and the default, is not to run any of these and end the program. 
    for this reason, dont use else statements on the base level or else the null option
    will trigger a section of the if statements not intended. use nested IFs to get 
    around this. 
    */

    
    // this is the nonogram game, its kinda a huge load of variables and is a pain to write in the terminal.
    // not cause the console is hard, but on my ipad this cannot clear the terminal window :((
    // so to compensate I am just entering a shitton of \n so that the terminal looks empty. 


    if (userChoice == 1){
        // insert a puzzle into and explanation then, after user says so, enter the game properly. 
        // print main puzzle diagram (this is going to be crazy long, sorry :( but this makes sense so the user's experience can be easier to design. Each line is the line the user will see.)


        // This is the main game loop, the game over bool is used to exit the loop. 
        bool game_over = false;
        int turn_counter = 0;
        
        
        // nonogram variables. you need a user visible array (w_grid - working_grid), solution to compare it to (s_grid - solution grid),
        // then a bunch of row and column variables for the totals used to solve the puzzle. 
        int dimensions_grid = 26;
        int s_grid[dimensions_grid];
        int w_grid[dimensions_grid];
        int selection = 0;
        
        // set all solution and working array positions to 0
        for (selection = 1; selection < 26; selection++){
            w_grid[selection] = 0;
            s_grid[selection] = 0;
        }      

        // general in variables
        int user_in_row = 0;
        int user_in_col = 0;
        // this variable records the translation from user input to an actually usable grid position. 
        int user_change = 0;



        // this is kinda tedious, but here are the totals of the arrays, the arrays are only 1*dimensions of grid,
        // so we compensate by assuming its a square and printing the array as if it had row breaks
        // but that makes this tedius bs required:
        int s_row_total[5];
        int s_column_total[5];
        int w_row_total[5];
        int w_column_total[5];

        // this is the solution to the puzzle.
        s_grid[1] = 1;
        s_grid[2] = 1;
        s_grid[3] = 0;
        s_grid[4] = 1;
        s_grid[5] = 0;
        s_grid[6] = 0;
        s_grid[7] = 0;
        s_grid[8] = 0;
        s_grid[9] = 1;
        s_grid[10] = 0;
        s_grid[11] = 1;
        s_grid[12] = 0;
        s_grid[13] = 1;
        s_grid[14] = 0;
        s_grid[15] = 1;
        s_grid[16] = 0;
        s_grid[17] = 0;
        s_grid[18] = 1;
        s_grid[19] = 0;
        s_grid[20] = 0;
        s_grid[21] = 0;
        s_grid[22] = 1;
        s_grid[23] = 0;
        s_grid[24] = 1;
        s_grid[25] = 0;
        

        s_row_total[1] = (s_grid[1] + s_grid[2] + s_grid[3] + s_grid[4] + s_grid[5]);
        s_row_total[2] = (s_grid[6] + s_grid[7] + s_grid[8] + s_grid[9] + s_grid[10]);
        s_row_total[3] = (s_grid[11] + s_grid[12] + s_grid[13] + s_grid[14] + s_grid[15]);
        s_row_total[4] = (s_grid[16] + s_grid[17] + s_grid[18] + s_grid[19] + s_grid[20]);
        s_row_total[5] = (s_grid[21] + s_grid[22] + s_grid[23] + s_grid[24] + s_grid[25]);

        // I am going to feel so so dumb if there is a way to denote rows and columns in an array or something like that :/
        s_column_total[1] = (s_grid[1] + s_grid[6] + s_grid[11] + s_grid[16] + s_grid[21]);
        s_column_total[2] = (s_grid[2] + s_grid[7] + s_grid[12] + s_grid[17] + s_grid[22]);
        s_column_total[3] = (s_grid[3] + s_grid[8] + s_grid[13] + s_grid[18] + s_grid[23]);
        s_column_total[4] = (s_grid[4] + s_grid[9] + s_grid[14] + s_grid[19] + s_grid[24]);
        s_column_total[5] = (s_grid[5] + s_grid[10] + s_grid[15] + s_grid[20] + s_grid[25]);

        // but such is life as a beginner 
        w_row_total[1] = (w_grid[1] + w_grid[2] + w_grid[3] + w_grid[4] + w_grid[5]);
        w_row_total[2] = (w_grid[6] + w_grid[7] + w_grid[8] + w_grid[9] + w_grid[10]);
        w_row_total[3] = (w_grid[11] + w_grid[12] + w_grid[13] + w_grid[14] + w_grid[15]);
        w_row_total[4] = (w_grid[16] + w_grid[17] + w_grid[18] + w_grid[19] + w_grid[20]);
        w_row_total[5] = (w_grid[21] + w_grid[22] + w_grid[23] + w_grid[24] + w_grid[25]);

        // I am going to feel so so dumb if there is a way to denote rows and columns in an array or something like that :/
        w_column_total[1] = (w_grid[1] + w_grid[6] + w_grid[11] + w_grid[16] + w_grid[21]);
        w_column_total[2] = (w_grid[2] + w_grid[7] + w_grid[12] + w_grid[17] + w_grid[22]);
        w_column_total[3] = (w_grid[3] + w_grid[8] + w_grid[13] + w_grid[18] + w_grid[23]);
        w_column_total[4] = (w_grid[4] + w_grid[9] + w_grid[14] + w_grid[19] + w_grid[24]);
        w_column_total[5] = (w_grid[5] + w_grid[10] + w_grid[15] + w_grid[20] + w_grid[25]);





        while (game_over == false){
            turn_counter += 1;
            if (turn_counter == 100){
                game_over = true;
                break;
            }


            cout << "\n\n\n\n\n\n\n" << endl;
            cout << "   |" << s_column_total[1] << "|" << s_column_total[2] << "|" << s_column_total[3] << "|" << s_column_total[4] << "|" << s_column_total[5] << "|" << "\n" << endl;
            cout << s_row_total[1] << "  " << "|" << w_grid[1] << "|" << w_grid[2] << "|" << w_grid[3] << "|" << w_grid[4] << "|" << w_grid[5] << "|" << endl;
            cout << s_row_total[2] << "  " << "|" << w_grid[6] << "|" << w_grid[7] << "|" << w_grid[8] << "|" << w_grid[9] << "|" << w_grid[10] << "|" << endl;
            cout << s_row_total[3] << "  " << "|" << w_grid[11] << "|" << w_grid[12] << "|" << w_grid[13] << "|" << w_grid[14] << "|" << w_grid[15] << "|" << endl;
            cout << s_row_total[4] << "  " << "|" << w_grid[16] << "|" << w_grid[17] << "|" << w_grid[18] << "|" << w_grid[19] << "|" << w_grid[20] << "|" << endl;
            cout << s_row_total[5] << "  " << "|" << w_grid[21] << "|" << w_grid[22] << "|" << w_grid[23] << "|" << w_grid[24] << "|" << w_grid[25] << "|" << endl;


            cout << "\nWhat change would would to make? (Row)" << endl;
            cin >> user_in_row;
            cout << "\nAnd which column?" << endl;
            cin >> user_in_col;

            if (user_in_col == 0){game_over = true;}
            user_change = ((user_in_row -1)*5) + user_in_col;

            if(w_grid[user_change] == 0){
                w_grid[user_change] = 1;
            } else{

                w_grid[user_change] = 0;
            }



            // welcome back to tedious bullshit :)
            w_row_total[1] = (w_grid[1] + w_grid[2] + w_grid[3] + w_grid[4] + w_grid[5]);
            w_row_total[2] = (w_grid[6] + w_grid[7] + w_grid[8] + w_grid[9] + w_grid[10]);
            w_row_total[3] = (w_grid[11] + w_grid[12] + w_grid[13] + w_grid[14] + w_grid[15]);
            w_row_total[4] = (w_grid[16] + w_grid[17] + w_grid[18] + w_grid[19] + w_grid[20]);
            w_row_total[5] = (w_grid[21] + w_grid[22] + w_grid[23] + w_grid[24] + w_grid[25]);

            // this must be done for an accurate check about correctness.  
            w_column_total[1] = (w_grid[1] + w_grid[6] + w_grid[11] + w_grid[16] + w_grid[21]);
            w_column_total[2] = (w_grid[2] + w_grid[7] + w_grid[12] + w_grid[17] + w_grid[22]);
            w_column_total[3] = (w_grid[3] + w_grid[8] + w_grid[13] + w_grid[18] + w_grid[23]);
            w_column_total[4] = (w_grid[4] + w_grid[9] + w_grid[14] + w_grid[19] + w_grid[24]);
            w_column_total[5] = (w_grid[5] + w_grid[10] + w_grid[15] + w_grid[20] + w_grid[25]);
            

            
            
            // check for win state:
            int score = 0;
            for(int i = 1; i<=5; i++){
                if (s_row_total[i] == w_row_total[i]){
                    score += 1;
                }
                if (s_column_total[i] == w_column_total[i]){
                    score += 1;
                }
                
            }
            if (score >= 10){
                game_over = true;
                cout << "\n\n\n\n\n\n\n#############\nYou Win!! gg \nThanks for Playing!\n#############"<< endl;
            }


        }
    }

    return 0;
}