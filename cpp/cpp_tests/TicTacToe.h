/* ***************************************************************************************************************
 * TicTacToe.h - The TicTacToe class represents the game board in a game of Tic Tac Toe. It provides an
 * abstraction of the board, keeping track of which fields are occupied and which are empty.
 * 
 * This class is responsible for managing the state of the game. It knows where the 'X’s and 'O’s are on the board,
 * and it can tell you how many fields are occupied and how many are still available.
 * 
 * When a move is made, this class updates the state of the board. It also has methods to check the status of the
 * game - whether there’s a win, a draw, or the game should continue.
 * 
 * In addition to managing the state of the game, the TicTacToe class also has the responsibility of visually
 * representing the game on the screen. It takes the current state of the board and translates it into a visual
 * format that players can easily understand. This makes it not just the game’s memory, but also its storyteller,
 * turning the abstract concept of the game state into a concrete visual reality.
 * ---------------------------------------------------------------------------------------------------------------
 * Refactoring notes:
 * Create a shit load of metadata. For now I need moveCount, I need humanMoveCount and I need computerMoveCount.
 * Let's start there, but I'm sure I will need more. I will just describe what I need as I go along. As I am
 * cleaning code snippets out, I mark everything not needed anymore as depricated. I'll do at the end of the
 * file a commented out region for depricated functions and variables.
 * One thing I want to keep in mind. It is a Object Oriented Programming, let's keep MVC seperate. Meaning: Model,
 * View, Controller. Now, most software project's I was involved in, the had a form of M(VC). That means, Model was
 * completely seperated and View and Controller fused together. It is just the nature of OOP languages in times of
 * GUI. Web development however practiced MVC strictly. Database(Model) Backend (Server-side) and Frontend (Webside).
 * Here I'll keep TicTacToe.h as the Model and TicTacToeGame.h as the View & Control together. So, in this class
 * TicTacToe.h I'll keep it as far from controlling the game as possible. I store the state of the game, how many
 * moves are made and by who. What indexes are empty and used by which player. These are informations that need to
 * be calculated and then given to the controller. And the controller should decide what to do with that info.
 * 
 * One thing I try to do with this refactoring project is to simplify things. And make the code more understandable
 * and optimize the program. Also reduceing errors by eliminating for loops and miscalculations. One way is replacing
 * the vector as board with an indexed array, which replaces most iterative operations with direct access to the indexed
 * field.
 * Let me explain: cBoard[9]           Instead of: board[3][3]
 * 
 *    a   b   c
 * 1  0 | 1 | 2                          0-0 | 0-1 | 0-2
 *   ---+---+---                        -----+-----+-----
 * 2  3 | 4 | 5                          1-0 | 1-1 | 1-2
 *   ---+---+---                        -----+-----+-----
 * 3  6 | 7 | 8                          2-0 | 2-1 | 2-2
 * 
 * 
 * 
 * ---------------------------------------------------------------------------------------------------------------
 * Author:       Patrik Eigenmann
 * eMail:        p.eigenmann@gmx.net
 * ---------------------------------------------------------------------------------------------------------------
 * Wed 2024-02-14 File created & Construction implemented -> initialize board.                      Version: 00.01
 * Wed 2024-02-14 Methode makeMove implemented.                                                     Version: 00.02
 * Wed 2024-02-14 Methode checkWin implemented.                                                     Version: 00.03
 * Wed 2024-02-14 Methode isGameOver implemented.                                                   Version: 00.04
 * Wed 2024-02-14 Methode printBoard implemented.                                                   Version: 00.05
 * Wed 2024-02-14 Methode getBoard implemented.                                                     Version: 00.06
 * Wed 2024-02-14 Methode isValidMove implemented.                                                  Version: 00.07
 * Thu 2024-02-15 Methode count imported from TicTacToeGame.                                        Version: 00.08
 * Thu 2024-02-15 Variable debug implemented.                                                       Version: 00.09
 * Thu 2024-02-15 Methode twoInARowInColumn imported from TicTacToeGame.                            Version: 00.10
 * Thu 2024-02-15 Methode twoInARowInRow imported from TicTacToeGame.                               Version: 00.11
 * Thu 2024-02-15 Methode twoInARowInDiagonal imported from TicTacToeGame.                          Version: 00.12
 * Thu 2024-02-15 Methode findEmptyInRow imported from TicTacToeGame.                               Version: 00.13
 * Thu 2024-02-15 Methode findEmptyInColumn imported from TicTacToeGame.                            Version: 00.14
 * Thu 2024-02-15 Methode findEmptyInDiagonal imported from TicTacToeGame.                          Version: 00.15
 * Thu 2024-02-15 Variable moveCount implemented.                                                   Version: 00.16
 * Thu 2024-02-15 Methode isGameOver corrected.                                                     Version: 00.17
 * Fri 2024-02-16 Variable winMessage plus getter implemented.                                      Version: 00.18
 * Fri 2024-02-16 Version control implemented.                                                      Version: 00.19
 * Sat 2024-02-17 Versioning the class before refactoring the code to simplify some things.         Version: 01.00
 * Sat 2024-02-17 Variables humanMoveCount and computerMoveCount plus getter/update methodes added. Version: 01.01
 * Sat 2024-02-17 Removed method count and replaced it with a optimized version.                    Version: 01.02
 * Sat 2024-02-17 Implement a new board as a char array.                                            Version: 01.03
 * Sat 2024-02-17 Integrate a mapping methode mapRowColumnToIndex() and mapIndexToRowcolumn()       Version: 01.04
 * ---------------------------------------------------------------------------------------------------------------
 * To Do's:
 * - Clean up the code and import methods from TicTacToeGame class.
 * - Refactoring the class into a more simplified and more easier readable code.
 * ***************************************************************************************************************/

#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <vector>
#include <iostream>
#include <string>

#include "Version.h"

// ---------------------------------------------------------------------------------------------------------------
// The TicTacToe class represents the game board in a game of Tic Tac Toe. It provides an abstraction of the board,
// keeping track of which fields are occupied and which are empty.
//
// This class is responsible for managing the state of the game. It knows where the 'X’s and 'O’s are on the board,
// and it can tell you how many fields are occupied and how many are still available.
// 
// When a move is made, this class updates the state of the board. It also has methods to check the status of the
// game - whether there’s a win, a draw, or the game should continue.
// 
// In addition to managing the state of the game, the TicTacToe class also has the responsibility of visually
// representing the game on the screen. It takes the current state of the board and translates it into a visual
// format that players can easily understand. This makes it not just the game’s memory, but also its storyteller,
// turning the abstract concept of the game state into a concrete visual reality.
// ---------------------------------------------------------------------------------------------------------------
class TicTacToe {

    private:
    /* Version control & debug information */
    Version version_;
    bool debug;

    /* Counters are to optimize certain routines. As example, instead of counting all 'X's in a for loop, just
     * increase moveCount and humanMoveCount at the end of the humanMove procedure! Saves a lot of iterating. */
    int moveCount;
    int humanMoveCount;
    int computerMoveCount;

    /* Constants and unchangebles */
    const int POSSIBLE_MOVES = 9;

    /* --------------------------------------------------------------------------------------------------------------
     * This array represents the board. All fields are indexed. Let me explain how the indexing of the board works:
     *
     *      a   b   c
     *   1  0 | 1 | 2
     *     ---+---+---
     *   2  3 | 4 | 5
     *     ---+---+---
     *   3  6 | 7 | 8
     * 
     * Okay, let's create a few examples. Field row 1 column a has the index 0: cBoard[0].
     * Or row 2 column c has the index 5: the value you're looking for is stored in cBoard[5].
     * ---------------------------------------------------------------------------------------------------------------- */
    char cBoard[9];

    std::string winMessage;
    std::vector<std::vector<char>> board;
    
    public:
    // -----------------------------------------------------------------------------------------------------------
    // The TicTacToe class represents the game board in a game of Tic Tac Toe. It provides an abstraction of the
    // board, keeping track of which fields are occupied and which are empty.
    //
    // This class is responsible for managing the state of the game. It knows where the 'X’s and 'O’s are on the
    // board, and it can tell you how many fields are occupied and how many are still available.
    //
    // When a move is made, this class updates the state of the board. It also has methods to check the status of
    // the game - whether there’s a win, a draw, or the game should continue.
    //
    // In addition to managing the state of the game, the TicTacToe class also has the responsibility of visually
    // representing the game on the screen. It takes the current state of the board and translates it into a visual
    // format that players can easily understand. This makes it not just the game’s memory, but also its storyteller,
    // turning the abstract concept of the game state into a concrete visual reality.
    // -----------------------------------------------------------------------------------------------------------
    TicTacToe(bool debugIn = false):version_(1, 3) {
        
        this->debug = debugIn;                      // Turn the debug information on/off.
        this->winMessage = "";                      // Initialize the message with the winner.
        this->moveCount = 0;                        // Reset the move counter.
        this->humanMoveCount = 0;                   // Reset the move counter for human moves.
        this->computerMoveCount = 0;                // Reset the move counter for computer moves.

        /* Initialize the board with empty ' ' values. */
        for(int i=0; i < this->POSSIBLE_MOVES; i++) this->cBoard[i] = ' ';

        /* Deprecated, but I leave it until it is save to move it into depricated. */
        this->board = std::vector<std::vector<char>>(3, std::vector<char>(3, ' '));
    }

    // ------------------------------------------------------------------------------------------------------------
    // The method getMoveCount() returns overall moves made 'X' and 'O' already.
    // @return moveCount - overall move count made in the game at the moment.
    // ------------------------------------------------------------------------------------------------------------
    int getMoveCount() const {
        if (this->debug) std::cout << "DEBUG - return moveCount: " << this->moveCount << std::endl;
        return this->moveCount;
    }

    // ------------------------------------------------------------------------------------------------------------
    // The method updateMoveCount() increases the variable moveCount by one. It should be called after every move
    // either player has done.
    // ------------------------------------------------------------------------------------------------------------
    void updateMoveCount() {
        if (this->debug) std::cout << "DEBUG - increase moveCount: " << this->moveCount << " by one." << std::endl;
        this->moveCount++;
    }

    // ------------------------------------------------------------------------------------------------------------
    // The method getHumanMoveCount() returns overall moves made by 'X' or the human.
    // @return humanMoveCount - move count made by the human at the moment.
    // ------------------------------------------------------------------------------------------------------------
    int getHumanMoveCount() const {
        if (this->debug) std::cout << "DEBUG - return humanMoveCount: " << this->humanMoveCount << std::endl;
        return this->humanMoveCount;
    }

    // ------------------------------------------------------------------------------------------------------------
    // The method updateHumanMoveCount() increases the variable humanMoveCount by one. It should be called after
    // every move player 'X' has done.
    // ------------------------------------------------------------------------------------------------------------
    void updateHumanMoveCount() {
        if (this->debug) std::cout << "DEBUG - increase humanMoveCount: " << this->humanMoveCount << " by one." << std::endl;
        this->humanMoveCount++;
    }

    // ------------------------------------------------------------------------------------------------------------
    // The method getComputerMoveCount() returns overall moves made by 'O' or the computer.
    // @return computerMoveCount - move count made by the computer 'O' at the moment.
    // ------------------------------------------------------------------------------------------------------------
    int getComputerMoveCount() const {
        if (this->debug) std::cout << "DEBUG - return computerMoveCount: " << this->computerMoveCount << std::endl;
        return this->computerMoveCount;
    }

    // ------------------------------------------------------------------------------------------------------------
    // The method updateComputerMoveCount() increases the variable computerMoveCount by one. It should be called
    // after every move player 'O' has done.
    // ------------------------------------------------------------------------------------------------------------
    void updateComputerMoveCount() {
        if (this->debug) std::cout << "DEBUG - increase computerMoveCount: " << this->moveCount << " by one." << std::endl;
        this->computerMoveCount++;
    }

    // ------------------------------------------------------------------------------------------------------------
    // The method count(char player) - Counting all occupied fields by one player 'X' or 'O' or if the parameter
    // is ' ' then all the moves are counted.
    //
    // @param player 'X' or 'O' or ' '
    // @return Count of all occupied field by the specified player.
    // ------------------------------------------------------------------------------------------------------------
    int count(char player) {
        int count = 0;

        if(player == 'X') count = this->getHumanMoveCount();            // The human players moves are counted.
        if(player == 'O') count = this->getComputerMoveCount();         // The computer player moves are counted.
        if(player == ' ') count = this->getMoveCount();                 // All the moves are counted.
        
        if(debug) std::cout << "DEBUG - Player: " << ((player == ' ')? 'A': player) << " Count:" << count << "\n";
        return count;
    }

    // ------------------------------------------------------------------------------------------------------------
    // The method getVersion() returns the correct formatted version number.
    // @return Version number as MM.mm
    // ------------------------------------------------------------------------------------------------------------
    std::string getVersion() const {
        /* I don't need to debug this!
        if (this->debug) std::cout << "DEBUG - Version #: " << this->version_.toString() << "." << std::endl;
        */
        return this->version_.toString();
    }

    // -----------------------------------------------------------------------------------------------------------
    // The method getWinMessage() return the internal message string of the winMessage.
    // @return winMessage - internal win message.
    // -----------------------------------------------------------------------------------------------------------
    std::string getWinMessage() const {
        return this->winMessage;
    }

    // -----------------------------------------------------------------------------------------------------------
    // The method mapRowColumnToIndex(char col, char row) works by mapping a cell’s row and column in a 2D grid to
    // a corresponding index in a 1D array. It takes two characters as input: col and row, which represent a cell’s
    // column and row in the grid.
    //
    // The function first converts the column character (‘a’, ‘b’, or ‘c’) to a 0-based index by subtracting the
    // ASCII value of ‘a’ from it. This gives us colIndex.
    //
    // Next, it converts the row character (‘1’, ‘2’, or ‘3’) to a 0-based index by subtracting the ASCII value
    // of ‘0’ from it and then subtracting 1. This gives us rowIndex.
    //
    // Finally, it calculates the overall index by multiplying the rowIndex by 3 and adding the colIndex. This is
    // because the grid is organized column by column. The calculated index is then returned by the function. For
    // example, for the cell at column ‘a’ and row ‘2’, the function would return the index 3.
    //
    //      a   b   c
    //   1  0 | 1 | 2
    //     ---+---+---
    //   2  3 | 4 | 5
    //     ---+---+---
    //   3  6 | 7 | 8
    // @param row (a, b, or c) 
    // @param column (1, 2, or 3)
    // @return the corresponding index.
    // -----------------------------------------------------------------------------------------------------------
    int mapRowColumnToIndex(char col, char row) {
        int colIndex = col - 'a'; // Convert column character to 0-based index (a -> 0, b -> 1, c -> 2)
        int rowIndex = row - '1'; // Convert row character to 0-based index (1 -> 0, 2 -> 1, 3 -> 2)
        if(debug) std::cout << "DEBUG - Colum: " << colIndex << " Row: " << rowIndex << " Index: " << (rowIndex * 3 + colIndex) << std::endl;
        return rowIndex * 3 + colIndex; // Calculate the overall index
    }

    // -----------------------------------------------------------------------------------------------------------
    // The method mapIndexToRowColumn(int index) works by dividing the index by 3 to get the row number and taking
    // the modulus of the index by 3 to get the column number. It then converts these numbers to characters by
    // adding the ASCII value of ‘1’ to the row number and ‘a’ to the column number. Finally, it combines the
    // column and row characters into a string and returns it.
    //      a   b   c
    //   1  0 | 1 | 2
    //     ---+---+---
    //   2  3 | 4 | 5
    //     ---+---+---
    //   3  6 | 7 | 8
    // @param index
    // @return the corresponding column and row (e.g., "a2" for index 4).
    // -----------------------------------------------------------------------------------------------------------
    std::string mapIndexToRowColumn(int index) {
        char col = 'a' + (index % 3); // Calculate the column character
        char row = '1' + (index / 3); // Calculate the row character
        if(debug) std::cout << "DEBUG - Index: " << index << " column row: " << col << std::string(1, row) << std::endl;
        return std::string(1, col) + std::string(1, row); // Combine row and column into a string
    }

    // -----------------------------------------------------------------------------------------------------------
    // The method isMoveValid(int index) checks if the field is empty, therefor a valid move.
    // @return is a valid move, true or false.
    // -----------------------------------------------------------------------------------------------------------
    bool isMoveValid(int index) const {
        return cBoard[index] == ' ';
    }

    // -----------------------------------------------------------------------------------------------------------
    // This method makeMove(int row, int col, char player) places the specified players move on the board. As an
    // return value it indicates if the move is successful or not.
    // @param int row - row number of the board.
    // @param int col - column number of the board.
    // @param char player - which player makes the move.
    // @return success or fail.
    // -----------------------------------------------------------------------------------------------------------
    bool makeMove(int index, char player) {
        
        if(index >= 0 && index <= 9 && cBoard[index] == ' ') {
            
            cBoard[index] = player;                                     // Overwrite the board with the player.

            if (player == 'X') this->updateHumanMoveCount();            // Increase the human move count.
            if (player == 'O') this->updateComputerMoveCount();         // Increase the computer move count.

            this->updateMoveCount();                                    // Increase the overall move count.

            if(debug) std::cout << "DEBUG - Move count: " << moveCount << "\n";

            return true;
        }

        return false;
    }

    // -----------------------------------------------------------------------------------------------------------
    // bool checkWin(char player) - Checks if the player won.
    // -----------------------------------------------------------------------------------------------------------
    bool checkWin(char player) {
        
        bool checkWin = false;

        for (int i = 0; i < 3; ++i) {
            if (board[i][0] == player && board[i][1] == player && board[i][2] == player) checkWin = true;
            if (board[0][i] == player && board[1][i] == player && board[2][i] == player) checkWin = true;
        }
        if (board[0][0] == player && board[1][1] == player && board[2][2] == player) checkWin = true;
        if (board[0][2] == player && board[1][1] == player && board[2][0] == player) checkWin = true;
        
        if(checkWin) winMessage = "Player " + std::string(1, player) + " wins!\n";
        if(!checkWin && moveCount == 9) winMessage = "No player wins!\n";

        return checkWin;
    }

    // -----------------------------------------------------------------------------------------------------------
    // The method isGameOver() simple checks if either player won or if there are no more moves. If the move count
    // reached 9 moves, the game is a stalemate and over. No one wins.
    // -----------------------------------------------------------------------------------------------------------
    bool isGameOver() {
        
        bool isGameOver = false;

        isGameOver |= this->checkWin('X');                              // First check if 'X' won.
        isGameOver |= this->checkWin('O');                              // Then check if 'O' won.
        isGameOver |= (this->getMoveCount() == this->POSSIBLE_MOVES);   // Then check if game is out of moves.

        if (debug) std::cout << "DEBUG - isGameOver: " << ((isGameOver)? "true" : "false") << "\n";
        
        return isGameOver;
    }

    // -----------------------------------------------------------------------------------------------------------
    // The method twoInARowInColumn(char player, int col) searches if two fields are occupied by the same player.
    // @param
    // @param
    // @return
    // -----------------------------------------------------------------------------------------------------------
    bool twoInARowInColumn(char player, int col) {
        int count = 0;
        int empty = 0;

        for (int row = 0; row < 3; ++row) {
            
            if (board[row][col] == ' ') {
                ++empty;
            }
            
            if (board[row][col] == player) {
                ++count;
            }
        }
        if(debug) std::cout << "DEBUG - Player: " << player << " Column:" << col << " Count: " << count << "\n";
        return count == 2 && empty == 1;
    }

    // -----------------------------------------------------------------------------------------------------------
    // The method twoInARowInRow(char player, int row) searches if two fields are occupied by the same player.
    // @param
    // @param
    // @return
    // -----------------------------------------------------------------------------------------------------------
    bool twoInARowInRow(char player, int row) {
        int count = 0;
        int empty = 0;

        for (int col = 0; col < 3; ++col) {
            
            if (board[row][col] == ' ') {
                ++empty;
            }
            
            if (board[row][col] == player) {
                ++count;
            }
        }
        if(debug) std::cout << "DEBUG - Player: " << player << " Row:" << row << " Count: " << count << "\n";
        return count == 2 && empty == 1;
    }

    // -----------------------------------------------------------------------------------------------------------
    // The method twoInARowInDiagonal(char player, bool isMainDiagonal) searches if two fields are occupied by
    // the same player.
    // @param
    // @param
    // @return
    // -----------------------------------------------------------------------------------------------------------
    bool twoInARowInDiagonal(char player, bool isMainDiagonal) {
        int count = 0;
        int empty = 0;

        for (int i = 0; i < 3; ++i) {
            int row = isMainDiagonal ? 2 - i : i;
            int col = i;

            if (board[row][col] == ' ') {
                ++empty;
            }

            if (board[row][col] == player) {
                ++count;
            }
        }

        if(debug) std::cout << "DEBUG - Player: " << player << " Diagonal:" << isMainDiagonal << " Count: " << count << "\n";
        return count == 2 && empty == 1;
    }

    // -----------------------------------------------------------------------------------------------------------
    // The method findEmptyInRow(int row) finds the empty field in a certain row.
    // @param int row - The row in which the empty field is to look for.
    // @return the col number of the empty field.
    // -----------------------------------------------------------------------------------------------------------
    int findEmptyInRow(int row) {

        int column = -1;

        for (int col = 0; col < 3; ++col) {
            if (board[row][col] == ' ') {                
                column = col;
            }
        }

        if(debug) std::cout << "DEBUG - Search in row: " << row;
        if(debug && column > -1) std::cout << ", empty field in column: " << column << " found." << std::endl;
        else if(debug) std::cout << " no empty field found!" << std::endl;
        
        return column;
    }

    // -----------------------------------------------------------------------------------------------------------
    // The method findEmptyInRow(int row) finds the empty field in a certain row.
    // @param int row - The row in which the empty field is to look for.
    // @return the col number of the empty field.
    // -----------------------------------------------------------------------------------------------------------
    int findEmptyInColumn(int col) {

        int internal_row = -1;

        for (int row = 0; row < 3; ++row) {
            if (board[row][col] == ' ') {                
                internal_row = row;
            }
        }

        if(debug) std::cout << "DEBUG - Search in column: " << col;
        if(debug && internal_row > -1) std::cout << ", empty field in row: " << internal_row << " found." << std::endl;
        else if(debug) std::cout << " no empty field found!" << std::endl;
        
        return internal_row;
    }

    // -----------------------------------------------------------------------------------------------------------
    // int findEmptyInDiagonal() - Find the empty field in the two diagonal settings.
    // -----------------------------------------------------------------------------------------------------------
    int findEmptyInDiagonal() {
        
        int field = 0;
        
        // Check main diagonal
        if (board[0][0] == ' ' && field == 0) field = 1;
        if (board[0][2] == ' ' && field == 0) field = 2;
        if (board[1][1] == ' ' && field == 0) field = 3;
        if (board[2][0] == ' ' && field == 0) field = 4;
        if (board[2][2] == ' ' && field == 0) field = 5;
        if (field == 0) field = -1;

        if (debug) std::cout << "DEBUG - Diagonal search field: " << field << " is empty.\n";
        return field;
    }



    // ----- @deprecated ------------- @deprecated ------------- @deprecated ------------ @deprecated ------------
    // All rendering and printing should be in the class TicTacToeGame. The only thing what should be printed here
    // in this class are debug informations. Nothing else!
    // ----- @deprecated ------------- @deprecated ------------- @deprecated ------------ @deprecated ------------
    void printBoard() {
        std::cout << "   a   b   c\n";
        for (int i = 0; i < 3; ++i) {
            std::cout << (i+1) << ' ';
            for (int j = 0; j < 3; ++j) {
                std::cout << ' ' << board[i][j] << ' ';
                if (j < 2) std::cout << '|';
            }
            std::cout << "\n";
            if (i < 2) std::cout << "  ---+---+---\n";
        }
    }

    // ----- @deprecated ------------- @deprecated ------------- @deprecated ------------ @deprecated ------------
    // The method isValidMove(int row, int col) checks if the field is empty, therefor a valid move.
    // @return is a valid move, true or false.
    // ----- @deprecated ------------- @deprecated ------------- @deprecated ------------ @deprecated ------------
    bool isValidMove(int row, int col) const {
        return row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ';
    }

    // ----- @deprecated ------------- @deprecated ------------- @deprecated ------------ @deprecated ------------
    // The method getBoard() returns the internal instance of board as a vector.
    // @return board - internal instance of board.
    //
    // POSSIBLY DEPRECATED!
    // ----- @deprecated ------------- @deprecated ------------- @deprecated ------------ @deprecated ------------
    std::vector<std::vector<char>> getBoard() const {
        return this->board;
    }

    // ----- @deprecated ------------- @deprecated ------------- @deprecated ------------ @deprecated ------------
    // This method makeMove(int row, int col, char player) places the specified players move on the board. As an
    // return value it indicates if the move is successful or not.
    // @param int row - row number of the board.
    // @param int col - column number of the board.
    // @param char player - which player makes the move.
    // @return success or fail.
    // ----- @deprecated ------------- @deprecated ------------- @deprecated ------------ @deprecated ------------
    bool makeMove(int row, int col, char player) {
        
        if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
            board[row][col] = player;                                   // Overwrite the board with the player.

            if (player == 'X') this->updateHumanMoveCount();            // Increase the human move count.
            if (player == 'O') this->updateComputerMoveCount();         // Increase the computer move count.

            this->updateMoveCount();                                    // Increase the overall move count.

            if(debug) std::cout << "DEBUG - Move count: " << moveCount << "\n";

            return true;
        }
        return false;
    }

    /* ----- @deprecated ------------- @deprecated ------------- @deprecated ------------ @deprecated ------------
     
    // ----- @deprecated ------------- @deprecated ------------- @deprecated ------------ @deprecated ------------
    // int count(char player) - Counting all occupied fields by one player 'X' or 'O'.
    //
    // @param player 'X' or 'O'
    // @return Count of all occupied field by the specified player.
    //
    // POSSIBLY DEPRECATED!
    // ----- @deprecated ------------- @deprecated ------------- @deprecated ------------ @deprecated ------------
    int count(char player) const {
        int count = 0;
        for (int row = 0; row < 3; ++row) {
            for (int col = 0; col < 3; ++col) {
                if (board[row][col] == player) {
                    count++;
                }
            }
        }
        if(debug) std::cout << "DEBUG - Player: " << player << " Count:" << count << "\n";
        return count;
    }

     * ----- @deprecated ------------- @deprecated ------------- @deprecated ------------ @deprecated ------------*/

};


#endif