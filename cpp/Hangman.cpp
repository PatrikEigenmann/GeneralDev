/* ***************************************************************************************************************
 * Hangman.cpp - In the shadowy depths of your computer’s memory, a game of life and death unfolds. A program
 * known only as Hangman.cpp, is the puppet master in this chilling drama.
 *
 * The protagonist, a simple character, is chosen at random from a cryptic list of words, concealed within a file
 * named Hangman.txt. This innocent string of letters is unaware of the fate that awaits it, as it is thrust into
 * the spotlight of the terminal screen.
 *
 * The player, a relentless guesser, is the only hope for this word. With each guess, the tension mounts. The
 * word’s life hangs in the balance, teetering on the edge of oblivion. Each correct guess brings a sigh of relief,
 * each incorrect guess, a step closer to the end.
 *
 * The game is a merciless judge. It grants the player only 20 chances to guess the word correctly. With each
 * passing trial, the terminal screen flickers, echoing the player’s growing desperation.
 *
 * As the game reaches its climax, the final state of the word is revealed. If the player has guessed the word
 * correctly, the terminal screen lights up with the words of victory: “Congratulations, you figured out the word in
 * X trials!” But if the player has failed, the screen darkens, delivering the somber message: “Sorry, you didn’t
 * figure out the word. Better luck next time!”
 *
 * Hangman.cpp is not just a game. It’s a thrilling test of wits, a battle against time, a journey into the heart
 * of suspense. It’s a reminder that in the world of programming, even a simple word can become the hero of a
 * thrilling narrative. 😊
 * ---------------------------------------------------------------------------------------------------------------
 * Author:       Patrik Eigenmann
 * eMail:        p.eigenmann@gmx.net
 * ---------------------------------------------------------------------------------------------------------------
 * Fri 2024-02-09 File created.                                                                     Version: 00.01
 * Sat 2024-02-10 When word is figured out, message change and prior displaying the word.           Version: 00.02
 * Sat 2024-02-10 How many trials the player uses are integrated.                                   Version: 00.04
 * ---------------------------------------------------------------------------------------------------------------
 * To Do's:
 *
 * ***************************************************************************************************************/
#include <iostream>
#include <string>

#include "Version.h"
#include "Hangman.h"

// Version control for the main application.
Version mainVersion(0, 4);

// ------------------------------------------------------------------------------------------------------------------
// main - In the vast, uncharted realms of cyberspace, there exists a function. Not just any function, but the main
// function. It is the gatekeeper, the sentinel that stands at the threshold of every C and C++ program. It is the
// beginning and the end, the alpha and the omega.
//
// @param int argc     - Command argument count
// @param char **argv  - Command argument strings
//
// @return 1/0
// ------------------------------------------------------------------------------------------------------------------
int main (int argc, char **argv) {
    Hangman game("Hangman.txt");

    if (argc > 1) {  // If any command-line argument is provided
        std::cout << "Hangman Game Version " << mainVersion.toString() << ":\n";
        std::cout << "  - Hangman class version " << game.getVersion() << "\n";
        return 1;
    } else {
        char guess;
        int trials = 0;
        while (!game.isGameOver() && trials < game.getMaxTrials()) {
            game.displayGameState();
            std::cout << "Enter your guess: ";
            std::cin >> guess;
            game.guess(guess);
            trials++;
            if (!game.isCorrectGuess(guess)) {
                std::cout << "Incorrect guess!\n";
            }
        }
        game.displayGameState();
        if (game.isGameOver()) {
            std::cout << "Congratulations, you figured out the word in " << trials << " trials!\n";
        } else {
            std::cout << "Sorry, you didn't figure out the word. Better luck next time!\n";
        }
        return 0;
    }
    
}
