//  main.cpp
//  ticTacToe Final Project
//  Created by Gregory Ulrich on 3/20/18.
//  Copyright © 2018 Gregory Ulrich.
//  Desscription: Using loops, functions and arrays, input validation
//  and the magic of C++, we get to play an amusing game of Tic Tac Toe.


#include <iostream>
#include <string>
using namespace std;

//declare and define column constant to create the board
const int COLS = 3;

        // Declare prototype functions
// Checks to see if there is a free space to make a move
bool goNoGo(char [][COLS], int);
// Checks to see if the space a user wants is free or not
bool isItFree(int, int, char [][COLS], int);
// X moves
void goX(char [][COLS], int);
// O moves
void goO(char [][COLS], int);
// Displays the board
void displayBoard(char [][COLS], int);
// Checks for winning patterns
int winner(char [][COLS], int);
// Displays the demonstration board
void displayDemo(string [][COLS], int);

int main()
{
    //declare and define row constant to create the board
    const int ROWS = 3;
    
    //board initialized with '*' characters
    char board [ROWS][COLS] =
        {{'*', '*', '*'},
        {'*', '*', '*'},
        {'*', '*', '*'}};
    
    //This array is pre-filled to save time for some testing.
    // {{'O', 'X', 'O'},
    // {'O', 'X', 'X'},
    // {'*', '*', '*'}};
    
    //demo board with coordinates
    string demoBoard [ROWS][COLS] =
        {{"0 0", "0 1", "0 2"},
        {"1 0", "1 1", "1 2"},
        {"2 0", "2 1", "2 2"}};
    
    
    //Introduction
    cout << "\t\tTIC TAC TOE!" << endl;
    cout << "Enter the coordinates of the grid separated by a space." << endl;
    cout << "Rows are numbered 0-2, columns are numbered 0-2." << endl;
    cout << "Like this:" << endl;
    displayDemo(demoBoard, ROWS);
    cout << "*******************************************************" << endl;
    cout << endl;
    
    // While loop runs as long as there is no winner (function winner returns a 0 interpreted as false)
    // and function goNoGo returns true indicating that there is at least one space in which to move
    while (!winner(board, ROWS) && goNoGo(board, ROWS))
    {
        // X goes
        if(goNoGo(board, ROWS) && !winner(board, ROWS))
            goX(board, ROWS);
        
        // O goes
        if(goNoGo(board, ROWS) && !winner(board, ROWS))
            goO(board, ROWS);
        
        // if there is a winner, a winner is chosen using the function winner return values 1 or 2
        if (winner(board, ROWS))
        {
            if (winner(board, ROWS) == 1)
                cout << "X Wins!" << endl;
            
            else
                cout << "O wins!" << endl;
        }

        //if there is no space yet to move and there is no winner, a tie is declared
        if (!goNoGo(board, ROWS) && !winner(board, ROWS))
        {
            cout << "It's a tie." << endl;
        }
    }
    // while loop ends and returns to main function

    cout << "Thanks for playing.\nGoodbye!" << endl;
    
    return 0;
}

//**********************************************************
// Function goNoGo checks to see if there is a             *
// free space available on the board by looping            *
// through to see if any space is still initialized.       *
// with a '*' character. It returns true if a space is     *
// available and false if one is not.                      *
// *********************************************************
bool goNoGo(char arr[][COLS], int rows)
{
    bool status = false;
    
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (arr[i][j] == '*')
                status = true;
        }
    }
    return status;
}

//**********************************************************
// Function goX prompts player "X" to enter.               *
// his/her move, validates whether the                     *
// coordinates are valid, checks to see if the             *
// space is free using function isItFree, assigns          *
// the space to "X" if it is free, then displays           *
// the board.                                              *
// *********************************************************
void goX(char arr[][COLS], int rows)
{
    int x, y;

    cout << "Hi X, your move: ";
    cin >> x >> y;
    
    while (x <0 || x > 2 || y < 0 || y > 2)
    {
        cout << "The number has to be between 0 and 2" << endl;
        cin >> x >> y;
    }
    
    while (!isItFree(x, y, arr, rows))
    {
        cout << "That's occupied. Try again. ";
        cin >> x >> y;
        
        while (x <0 || x > 2 || y < 0 || y > 2)
        {
            cout << "The number has to be between 0 and 2" << endl;
            cin >> x >> y;
        }
    }
    
    arr[x][y] = 'X';
    displayBoard(arr, rows);
    cout << endl;
}

//**********************************************************
// Function goO prompts player "O" to enter.               *
// his/her move, validates whether the                     *
// coordinates are valid, checks to see if the.            *
// space is free using function isItFree, assigns          *
// the space to "O" if it is free, then displays.          *
// the board.                                              *
// *********************************************************
void goO(char arr[][COLS], int rows)
{
    int x, y;

    cout << "Hi O, your move: ";
    cin >> x >> y;
    
    while (x <0 || x > 2 || y < 0 || y > 2)
    {
        cout << "The number has to be between 0 and 2" << endl;
        cin >> x >> y;
    }
    
    while (!isItFree(x, y, arr, rows))
    {
        cout << "That's occupied. Try again. ";
        cin >> x >> y;
        
        while (x <0 || x > 2 || y < 0 || y > 2)
        {
            cout << "The number has to be between 0 and 2" << endl;
            cin >> x >> y;
        }
    }
    
    arr[x][y] = 'O';
    
    displayBoard(arr, rows);
    
    cout << endl;
}

//**********************************************************
// Function displayBoard loops through the                 *
// array and displays the contents to the.                 *
// console.                                                *
// *********************************************************
void displayBoard(char arr[][COLS], int rows)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < COLS; j++)
            cout << '|' << arr[i][j];
            cout << '|' << endl;
    }
}


//**********************************************************
// Function displayDemo loops through the                  *
// demo array and displays the contents to the             *
// console.                                                *
// *********************************************************
void displayDemo(string arr[][COLS], int rows)
 {
     for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < COLS; j++)
                cout << '|' << arr[i][j];
                cout << '|' << endl;
        }
 }

//**********************************************************
// Function isItFree checks a specific space to see if the *
// coordinates chosen by the user are free (initialzed '*')*
// or assigned 'X' or 'O' by a previous move.              *
// *********************************************************
bool isItFree(int row, int col, char arr[][COLS], int rows)
{
    bool status;
    
    if ( arr[row][col] == '*')
        status = true;
    
    else
        status = false;
    
    return status;
}


//**********************************************************
// Function winner checks for a winner. It returns a 1 if  *
// X wins, a 2 if O wins and a 0 if there is no winner.    *
// 1 and 2 are true booleans, 0 is a false boolean.        *
//**********************************************************

int winner(char arr[][COLS], int rows)
{
    int x = 0;
    
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (
                ( arr[0][0] == 'X' && arr[0][1] == 'X' && arr[0][2] == 'X' ) ||
                ( arr[1][0] == 'X' && arr[1][1] == 'X' && arr[1][2] == 'X' ) ||
                ( arr[2][0] == 'X' && arr[2][1] == 'X' && arr[2][2] == 'X' ) ||
                ( arr[0][0] == 'X' && arr[1][0] == 'X' && arr[2][0] == 'X' ) ||
                ( arr[0][1] == 'X' && arr[1][1] == 'X' && arr[2][1] == 'X' ) ||
                ( arr[0][2] == 'X' && arr[1][2] == 'X' && arr[2][2] == 'X' ) ||
                ( arr[0][0] == 'X' && arr[1][1] == 'X' && arr[2][2] == 'X' ) ||
                ( arr[0][2] == 'X' && arr[1][1] == 'X' && arr[2][0] == 'X' )
                )
                 x = 1;
            
           else if (
                     ( arr[0][0] == 'O' && arr[0][1] == 'O' && arr[0][2] == 'O' ) ||
                     ( arr[1][0] == 'O' && arr[1][1] == 'O' && arr[1][2] == 'O' ) ||
                     ( arr[2][0] == 'O' && arr[2][1] == 'O' && arr[2][2] == 'O' ) ||
                     ( arr[0][0] == 'O' && arr[1][0] == 'O' && arr[2][0] == 'O' ) ||
                     ( arr[0][1] == 'O' && arr[1][1] == 'O' && arr[2][1] == 'O' ) ||
                     ( arr[0][2] == 'O' && arr[1][2] == 'O' && arr[2][2] == 'O' ) ||
                     ( arr[0][0] == 'O' && arr[1][1] == 'O' && arr[2][2] == 'O' ) ||
                     ( arr[0][2] == 'O' && arr[1][1] == 'O' && arr[2][0] == 'O' )
                     )
                 x = 2;
            
            else
                 x = 0;
        }
    }
    return x;
}
