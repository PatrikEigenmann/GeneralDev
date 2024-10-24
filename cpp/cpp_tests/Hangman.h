/* ***************************************************************************************************************
 * Hangman.h - <description>
 * ---------------------------------------------------------------------------------------------------------------
 * Author:       Patrik Eigenmann
 * eMail:        p.eigenmann@gmx.net
 * ---------------------------------------------------------------------------------------------------------------
 * Fri 2024-02-09 File created.                                                                     Version: 00.01
 * Sat 2024-02-10 Words loaded from a comma seperated file called "Hangman.txt"                     Version: 00.02
 * Sun 2024-02-11 MAX_TRIAL and GetMaxTrials are integrated.                                        Version: 00.03
 * Sun 2024-02-11 Changed end message, if the trials are less then MAX_TRIAL. Win else loose.       Version: 00.04
 * Sun 2024-02-11 Versionized the class, so it can be exported into Hangman.h.                      Version: 01.00
 * ---------------------------------------------------------------------------------------------------------------
 * To Do's:
 * ***************************************************************************************************************/
#ifndef HANGMAN_H
#define HANGMAN_H

#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>

#include "Version.h"

// ---------------------------------------------------------------------------------------------------------------
// class Hangman - The Hangman class is the core of a suspenseful game of Hangman. It’s a testament to
// object-oriented design, encapsulating the game’s logic and state within its own structure.
//
// The class begins its journey by opening a file named Hangman.txt, which is a treasure trove of words, each one
// a potential protagonist for a round of Hangman. These words are read from the file and stored in a vector,
// creating a pool of candidates.
//
// Once the words are loaded, the class makes its first major decision. Using the rand function, it selects a
// random word from the vector. This word, unknown to the player, becomes the secret word they must guess.
//
// Throughout the game, the player’s guesses are stored in a vector. The class uses this record to determine the
// game’s state, checking if the player’s latest guess is in the secret word and whether the game is over.
//
// In essence, the Hangman class is a compact and self-contained representation of a Hangman game. It demonstrates
// principles of object-oriented design, encapsulation, and the use of standard library features in C++. It’s a
// game master, silently directing the flow of the game from behind the scenes. 😊
// ---------------------------------------------------------------------------------------------------------------
class Hangman {
private:
    std::string word;                               // The Word to guess.
    std::vector<char> guesses;                      // The past guesses.
    const int MAX_TRIALS = 20;                      // The maximum of trials

    /* Version Control on class level. */
    Version version_;                               // Version number.

public:
    // ------------------------------------------------------------------------------------------------------------
    // The constructor of the Hangman class is a crucial part of the game setup. It’s where the secret word is
    // selected that will be the focus of the upcoming game.
    //
    // The constructor takes a filename as an argument. This file is expected to contain a list of words, which are
    // potential candidates for the player to guess. The use of a file for word storage allows for easy updates to
    // the word list, as well as the ability to have a large, diverse set of words without cluttering the code itself.
    //
    // The std::ifstream object, part of the C++ Standard Library, is used to open and read from the file. This is a
    // common way to handle file input in C++. The filename passed into the constructor is used to locate and open
    // the file.
    //
    // Once the file is open, the constructor reads through it line by line using the std::getline function. Each
    // line is read into a temporary string variable, line, and then added to the words vector. The std::getline
    // function is a versatile tool in C++ for reading input from a variety of sources, including files and user
    // input.
    //
    // After all words have been read into the words vector, a random word is selected to be the secret word for
    // the game. This is done using the rand function, another part of the C++ Standard Library. The rand function
    // generates a pseudo-random number, which is then used to index into the words vector and select a word. The
    // srand(time(0)) function is called to seed the random number generator with the current time, ensuring a
    // different sequence of random numbers each time the program is run.
    //
    // In summary, the constructor of the Hangman class demonstrates a number of important C++ concepts, including
    // file I/O, string manipulation, vector usage, and random number generation. It sets up the initial state of
    // the game by selecting a secret word from a file, ready for the player to start guessing. 😊
    // 
    // @param filename - The name of the file with the comma seperated word list.
    // ------------------------------------------------------------------------------------------------------------
    Hangman(std::string filename) : version_ (1,0) {
        std::vector<std::string> words;
        std::ifstream file(filename);
        std::string line;
        while (std::getline(file, line, ',')) {
            words.push_back(line);
        }
        srand(time(0));
        word = words[rand() % words.size()];
    }

    // ------------------------------------------------------------------------------------------------------------
    // The getMaxTrials() function is a getter method that provides access to the private constant MAX_TRIALS. In
    // object-oriented programming, it’s a common practice to make class members private to encapsulate and protect
    // them from being modified directly by other parts of the program. This is known as data hiding or encapsulation.
    //
    // However, there are times when we still need to access these private members, and that’s where getter methods
    // come in. A getter method allows other parts of the program to read the value of a private member without
    // exposing the member itself.
    //
    // In the case of MAX_TRIALS, even though it’s a constant and its value can’t be changed once it’s set, it’s
    // still kept private to maintain consistency in the class design and to ensure that all class members are
    // accessed in a controlled manner.
    //
    // So, the getMaxTrials() method provides a safe and controlled way to access the value of MAX_TRIALS from
    // outside the Hangman class, while keeping the data member itself private and protected. 😊
    //
    // @return Maximum amount of trials.
    // ------------------------------------------------------------------------------------------------------------
    int getMaxTrials() const {
        return MAX_TRIALS;
    }

    // ------------------------------------------------------------------------------------------------------------
    // The guess(char letter) function is a key part of the Hangman class. It represents the action of a player
    // making a guess in the game.
    // When a player guesses a letter, this function is called with the guessed letter as an argument. The function
    // then adds the guessed letter to the guesses vector. This vector keeps track of all the letters that the
    // player has guessed during the game.
    //
    // By storing the guesses, the game can later check if a guessed letter is in the secret word and display the
    // current state of the game to the player. This function is a clear example of how a simple action in the
    // game (making a guess) corresponds to a method in the class.
    //
    // In essence, the guess(char letter) function encapsulates the action of making a guess in the Hangman game,
    // demonstrating the principle of encapsulation in object-oriented programming. 😊
    //
    // @param letter - The letter the player just guessed.
    // ------------------------------------------------------------------------------------------------------------
    void guess(char letter) {
        guesses.push_back(letter);
    }

    // ------------------------------------------------------------------------------------------------------------
    // Imagine you’re playing a game of Hangman. You have a secret word in mind and your friend is trying to guess
    // it letter by letter. Each time your friend guesses a letter, you need to check if that letter is in your
    // secret word.
    //
    // That’s exactly what the isCorrectGuess(char letter) function does. It’s like your brain in the game of Hangman.
    // When your friend (the player) makes a guess, this function checks if the guessed letter is in the secret word.
    // If it is, the function tells your friend that they’ve made a correct guess. If not, it tells them that they
    // need to try again.
    //
    // So, in simple terms, this function is the part of the game that checks if a guess is correct or not. 😊
    //
    // @param letter - The letter the players just guessed.
    //
    // @return True/False depending if the guess was correct or not.
    // ------------------------------------------------------------------------------------------------------------
    bool isCorrectGuess(char letter) {
        return word.find(letter) != std::string::npos;
    }

    // ------------------------------------------------------------------------------------------------------------
    // The isGameOver() function is your decision-making process in the game of Hangman. It goes through each letter
    // in the secret word and checks if your friend has guessed that letter. If there’s even a single letter in the
    // secret word that your friend hasn’t guessed yet, the game isn’t over, so the function says “No, the game
    // isn’t over yet.” But if your friend has guessed all the letters in the secret word, then the game is indeed
    // over, and the function says “Yes, the game is over.”
    //
    // @return True/False depending if the game is over or not.
    // ------------------------------------------------------------------------------------------------------------
    bool isGameOver() {
        for (char letter : word) {
            if (std::find(guesses.begin(), guesses.end(), letter) == guesses.end()) {
                return false;
            }
        }
        return true;
    }

    // ------------------------------------------------------------------------------------------------------------
    // The method displayGameState() function is your voice in the game of Hangman. It goes through each letter in
    // the secret word and checks if your friend has guessed that letter. If they have, it says the letter out loud.
    // If they haven’t, it says “_”, keeping the letter a secret.
    //
    // So, in simple terms, this function is the part of the game that shows the player their progress. It’s like a
    // friendly guide, always ready to show the player how they’re doing and what they need to do next. 😊
    // ------------------------------------------------------------------------------------------------------------
    void displayGameState() {
        for (char letter : word) {
            if (std::find(guesses.begin(), guesses.end(), letter) != guesses.end()) {
                std::cout << letter << ' ';
            } else {
                std::cout << "_ ";
            }
        }
        std::cout << '\n';
    }

    // ------------------------------------------------------------------------------------------------------------
    // The method getVersion() returns the correct formatted version number.
    //
    // @return Version number as MM.mm
    // ------------------------------------------------------------------------------------------------------------
    std::string getVersion() const {
        return version_.toString();
    }
};

 #endif
