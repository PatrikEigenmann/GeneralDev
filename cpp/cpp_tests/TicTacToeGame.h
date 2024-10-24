/* ***************************************************************************************************************
 * TicTacToeGame.h - The TicTacToeGame class embodies the computer’s strategy in a game of Tic Tac Toe. It’s where
 * the magic happens that allows the computer to be a challenging opponent. This class is not just about making
 * random moves, but about making smart decisions based on the current state of the game. It’s what makes the game
 * fun and engaging.
 * ---------------------------------------------------------------------------------------------------------------
 * Refactoring notes:
 * ---------------------------------------------------------------------------------------------------------------
 * Author:       Patrik Eigenmann
 * eMail:        p.eigenmann@gmx.net
 * ---------------------------------------------------------------------------------------------------------------
 * Wed 2024-02-14 File created.                                                                     Version: 00.01
 * Wed 2024-02-14 Construction implemented.                                                         Version: 00.02
 * Wed 2024-02-14 Method playGame implemented.                                                      Version: 00.03
 * Wed 2024-02-14 Method makeHumanMove implemented.                                                 Version: 00.04
 * Wed 2024-02-14 Method makeComputerMove implemented.                                              Version: 00.05
 * Wed 2024-02-14 Method count implemented.                                                         Version: 00.06
 * Wed 2024-02-14 Method twoInARow implemented.                                                     Version: 00.07
 * Thu 2024-02-15 Method strategize implemented.                                                    Version: 00.08
 * Thu 2024-02-15 Method makeDecision implemented.                                                  Version: 00.09
 * Thu 2024-02-15 Method twoInARowInColumn implemented.                                             Version: 00.10
 * Thu 2024-02-15 Method twoInARowInRow implemented.                                                Version: 00.11
 * Thu 2024-02-15 Method twoInARowInDiagonal implemented.                                           Version: 00.12
 * Thu 2024-02-15 Method findEmptyInRow implemented.                                                Version: 00.13
 * Thu 2024-02-15 Method findEmptyInColumn implemented.                                             Version: 00.14
 * Thu 2024-02-15 Method findEmptyInDiagonal implemented.                                           Version: 00.15
 * Thu 2024-02-15 Exclude method count -> it is not a playing stragety. It belongs in TicTacToe.    Version: 00.16
 * Thu 2024-02-15 Variable debug implemented.                                                       Version: 00.17
 * Thu 2024-02-15 Method twoInARowInColumn excluded -> method is not stragety -> TicTacToe.         Version: 00.18
 * Thu 2024-02-15 Method twoInARowInRow excluded -> method is not stragety -> TicTacToe.            Version: 00.19
 * Thu 2024-02-15 Method twoInARowInDiagonal excluded -> TicTacToe.                                 Version: 00.20
 * Thu 2024-02-15 Method findEmptyInRow excluded -> TicTacToe.                                      Version: 00.21
 * Thu 2024-02-15 Method findEmptyInColumn excluded -> TicTacToe.                                   Version: 00.22
 * Thu 2024-02-15 Method findEmptyInDiagonal excluded -> TicTacToe.                                 Version: 00.23
 * Fri 2024-02-16 Version control implemented.                                                      Version: 00.24
 * Sat 2024-02-16 Changed debug information to a more suitable developer flexible usage.            Version: 00.25
 * ---------------------------------------------------------------------------------------------------------------
 * To Do's:
 * - Clean up the code, some methodes are more suitable in the class TicTacToe.
 * - Prepare Class for refactoring, meaning implement all refactored methods from TicTacToe and use them properly.
 * - Then Versionize this class ang get the class ready to refactor.
 * ***************************************************************************************************************/

#ifndef TICTACTOEGAME_H
#define TICTACTOEGAME_H

#include <cstdlib>
#include <ctime>

#include "Version.h"
#include "TicTacToe.h"

// ---------------------------------------------------------------------------------------------------------------
// The TicTacToeGame class embodies the computer’s strategy in a game of Tic Tac Toe. It’s where the magic happens
// that allows the computer to be a challenging opponent. This class is not just about making random moves, but
// about making smart decisions based on the current state of the game. It’s what makes the game fun and engaging.
// ---------------------------------------------------------------------------------------------------------------
class TicTacToeGame {

    private:

        TicTacToe game;                             // The TicTacToe game.
        char currentPlayer;                         // Who is currently playing 'X'/'O'
        bool debug;

        Version version_;
    
    public:

    // -----------------------------------------------------------------------------------------------------------
    // Construction - let's see if that is even nessecary.
    // -----------------------------------------------------------------------------------------------------------
    TicTacToeGame(bool debugIn = false) : game(), currentPlayer('X'), version_(0, 25) {
        debug = debugIn;    
    }

    // ------------------------------------------------------------------------------------------------------------
    // The method getVersion() returns the correct formatted version number.
    //
    // @return Version number as MM.mm
    // ------------------------------------------------------------------------------------------------------------
    std::string getVersion() const {
        return version_.toString();
    }

    // ------------------------------------------------------------------------------------------------------------
    // The method getVersion() returns the correct formatted version number.
    //
    // @return Version number as MM.mm
    // ------------------------------------------------------------------------------------------------------------
    std::string getTicTacToeVersion() const {
        return game.getVersion();
    }

    // -----------------------------------------------------------------------------------------------------------
    // The method playGame() is the main loop. If the game is over either by maxing out moves or winning, it will
    // print the board one more time, and then announce the winner.
    // -----------------------------------------------------------------------------------------------------------
    void playGame() {
        
        while (!game.isGameOver()) {

            // print the board on the screen
            game.printBoard();

            if (currentPlayer == 'X') {
                makeHumanMove();
            } else {
                makeComputerMove();
            }

        }
        game.printBoard();
        std::cout << game.getWinMessage();
    }

    // -----------------------------------------------------------------------------------------------------------
    // 
    // -----------------------------------------------------------------------------------------------------------
    void makeHumanMove() {
        char col;
        int row;
        do {
            std::cout << "Enter column (a-c) and row (1-3) for your move: ";
            std::cin >> col >> row;


            int index = game.mapRowColumnToIndex(col, row);
            game.makeMove(index, currentPlayer);
            
            row--; // adjust for 0-indexed array
            col = tolower(col) - 'a'; // convert char to int, adjust for 0-indexed array
        } while (!game.makeMove(row, col, currentPlayer));

        currentPlayer = 'O';
    }

    // -----------------------------------------------------------------------------------------------------------
    // 
    // -----------------------------------------------------------------------------------------------------------
    void makeComputerMove() {
        
        int strategy = strategize();
        if (strategy == -1) {
            int row;
            int col;
            
            // Occupy the center or one of the corners
            if(game.isValidMove(1,1)) {
                row = 1;
                col = 1;
            } else if (game.isValidMove(0,0)) {
                row = 0;
                col = 0;
            }
            else if (game.isValidMove(0,2)) {
                row = 0;
                col = 2;
            }
            else if (game.isValidMove(2,0)) {
                row = 2;
                col = 0;
            }
            else if (game.isValidMove(2,2)) {
                row = 2;
                col = 2;
            }

            if (debug) std::cout << "DEBUG - Strategy -1 => row " << row << " col " << col << "\n";
            
            char column = 'a';
            if (col == 0) column = 'a'; 
            if (col == 1) column = 'b';
            if (col == 2) column = 'c';

            std::cout << "Okay, I see what you are doing! Well lets see how you deal with my move: " << column << (row + 1) << "\n";
            game.makeMove(row, col, 'O');

            currentPlayer = 'X';
            return;

        } else if (strategy == 1) {
            
            // Block the opponent's win
            int decision = makeDecision('X');
            int row;
            int col;
            if (debug) std::cout << "DEBUG - Decision " << decision << "\n"; 
            if(decision >= 1 && decision <= 3) {
                
                row = game.findEmptyInColumn(decision - 1);
                col = decision - 1;

            } else if(decision == 4 || decision == 8) {
                int temp = game.findEmptyInDiagonal();
                if (temp == 1) {
                    row = 0;
                    col = 0;
                } else if(temp == 2) {
                    row = 0;
                    col = 2;
                } else if(temp == 3) {
                    row = 1;
                    col = 1;
                } else if(temp == 4) {
                    row = 2;
                    col = 0;
                } else if(temp == 5) {
                    row = 2;
                    col = 2;
                }
            } else if(decision >= 5 && decision <= 7) {
                row = decision - 5;
                col = game.findEmptyInRow(decision - 5);
            }

            if (debug) std::cout << "DEBUG - Strategy 1 => row " << row << " col " << col << "\n";

            char column = 'a';
            if (col == 0) column = 'a'; 
            if (col == 1) column = 'b';
            if (col == 2) column = 'c';

            std::cout << "Okay, I see what you are doing! Well lets see how you deal with my move: " << column << (row + 1) << "\n";

            game.makeMove(row, col, 'O');

            currentPlayer = 'X';
            return;

        } else {
            // Try to complete a row or take the next available spot
            int decision = makeDecision('O');
            int row;
            int col;
            
            if (debug) std::cout << "DEBUG - Decision " << decision << " Column " << col << "\n";
            
            if(decision >= 1 && decision <= 2) {
                row = game.findEmptyInColumn(decision);
                col = decision;
            } else if(decision == 4 || decision == 8) {
                int temp = game.findEmptyInDiagonal();
                if (temp == 1) {
                    row = 0;
                    col = 0;
                } else if(temp == 2) {
                    row = 0;
                    col = 2;
                } else if(temp == 3) {
                    row = 1;
                    col = 1;
                } else if(temp == 4) {
                    row = 2;
                    col = 0;
                } else if(temp == 5) {
                    row = 2;
                    col = 2;
                }
            } else if(decision >= 5 && decision <= 7) {
                row = decision - 5;
                col = game.findEmptyInRow(decision - 5);
            } else {
                bool checker = false;
                for(int i = 0; i < 3; i++) {
                    for(int y = 0; y < 3; y++) {
                        if(game.isValidMove(i , y) && !checker) {
                            row = i;
                            col = y;
                            checker = true;
                        }
                    }
                }
            }

            if (debug) std::cout << "DEBUG - Strategy 0 => row " << row << " col " << col << "\n";
            
            char column = 'a';
            if (col == 0) column = 'a'; 
            if (col == 1) column = 'b';
            if (col == 2) column = 'c';

            std::cout << "Okay, I see what you are doing! Well lets see how you deal with my move: " << column << (row + 1) << "\n";
            
            game.makeMove(row, col, 'O');

            currentPlayer = 'X';
            return;
        }
    }

    // -----------------------------------------------------------------------------------------------------------
    // 
    // -----------------------------------------------------------------------------------------------------------
    int strategize() {
        // If the opponent has set their first 'X'

        if (game.count('X') == 1) {
            return -1;  // Occupy the center or one of the corners
        }

        // If the opponent has 2 or more fields occupied
        if (game.count('X') >= 2) {
            
            // Check if two 'O's build a row
            if (twoInARow('O')) {
                return 0; // Try to win
            }
            
            // Check if two 'X's build a row
            if (twoInARow('X')) {
                return 1;  // Block
            }
        }

        // If none of the above happens
        return 0;  // Either fill to make a row or use any empty field
    }

    // -----------------------------------------------------------------------------------------------------------
    // 
    // -----------------------------------------------------------------------------------------------------------
    bool twoInARow(char player) const {
        auto board = game.getBoard();
        // Check rows and columns
        for (int i = 0; i < 3; ++i) {
            if ((board[i][0] == player && board[i][1] == player && board[i][2] == ' ') ||
                (board[i][0] == player && board[i][2] == player && board[i][1] == ' ') ||
                (board[i][1] == player && board[i][2] == player && board[i][0] == ' ') ||
                (board[0][i] == player && board[1][i] == player && board[2][i] == ' ') ||
                (board[0][i] == player && board[2][i] == player && board[1][i] == ' ') ||
                (board[1][i] == player && board[2][i] == player && board[0][i] == ' ')) {
                return true;
            }
        }

        // Check diagonals
        if ((board[0][0] == player && board[1][1] == player && board[2][2] == ' ') ||
            (board[0][0] == player && board[2][2] == player && board[1][1] == ' ') ||
            (board[1][1] == player && board[2][2] == player && board[0][0] == ' ') ||
            (board[0][2] == player && board[1][1] == player && board[2][0] == ' ') ||
            (board[0][2] == player && board[2][0] == player && board[1][1] == ' ') ||
            (board[1][1] == player && board[2][0] == player && board[0][2] == ' ')) {
            return true;
        }

        // Check for two in a row with a space in between
        if ((board[0][0] == player && board[0][2] == player && board[0][1] == ' ') ||
            (board[2][0] == player && board[2][2] == player && board[2][1] == ' ') ||
            (board[0][0] == player && board[2][2] == player && board[1][1] == ' ') ||
            (board[0][2] == player && board[2][0] == player && board[1][1] == ' ')) {
            return true;
        }

        return false;
    }

    // -----------------------------------------------------------------------------------------------------------
    // 
    // -----------------------------------------------------------------------------------------------------------
    int makeDecision(char player) {
        
        // Check columns
        for (int col = 0; col < 3; ++col) {
            if (game.twoInARowInColumn(player, col)) {
                return col + 1;  // Return column number (1-indexed)
            }
        }

        // Check diagonals
        if (game.twoInARowInDiagonal(player, true)) {
            return 4;  // Diagonal from row 2, col 0 to row 0, col 2
        }
        if (game.twoInARowInDiagonal(player, false)) {
            return 8;  // Diagonal from row 2, col 2 to row 0, col 0
        }

        // Check rows
        for (int row = 0; row < 3; ++row) {
            if (game.twoInARowInRow(player, row)) {
                return row + 5;  // Return row number (5-indexed)
            }
        }

        return -1;  // No suitable position found
    }
};

#endif