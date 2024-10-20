/* ***************************************************************************************************************
 * TicTacToe.cpp - The main program for the TicTacToe C++ class essentially starts a game of TicTacToe between the
 * computer and a player. When the executable is run, it initiates this interactive game where the player and the
 * computer take turns to make their moves on the TicTacToe board. The game continues until a player wins or the
 * game is a draw. The result is then displayed.
 * ---------------------------------------------------------------------------------------------------------------
 * Author:       Patrik Eigenmann
 * eMail:        p.eigenmann@gmx.net
 * ---------------------------------------------------------------------------------------------------------------
 * Wed 2024-02-14 File created.                                                                     Version: 00.01
 * Fri 2024-02-16 Version control integrated.                                                       Version: 00.02
 * ---------------------------------------------------------------------------------------------------------------
 * To Do's:
 * ***************************************************************************************************************/
#include "TicTacToeGame.h"
#include "TicTacToe.h"
#include "Version.h"

#include<iostream>
using namespace std;


Version mainVersion(0, 2);

// ------------------------------------------------------------------------------------------------------------------
// main - In the vast, uncharted realms of cyberspace, there exists a function. Not just any function, but the main
// function. It is the gatekeeper, the sentinel that stands at the threshold of every C and C++ program. It is the
// beginning and the end, the alpha and the omega.
// int argc     - Command argument count
// char **argv  - Command argument strings
// ------------------------------------------------------------------------------------------------------------------
int main (int argc, char **argv)
{
    TicTacToeGame game(true);

    if(argc > 1) {
        cout << "TicTacToe.cpp       Version: " << mainVersion.toString() << "\n";
        cout << "  - TicTacToe.h     Version: " << game.getTicTacToeVersion() << "\n";
        cout << "  - TicTacToeGame.h Version: " << game.getVersion() << "\n";
    }
    else {       
        game.playGame();
        return 0;
    }
}