/* ******************************************************************************************************************
 * cHangman.c - cHangman is a classic word guessing game that's both fun and educational. Here’s how it works:
 * The game picks a word from a list, but doesn’t reveal it. Instead, it shows a series of blank spaces, each
 * representing a letter in the word. Your goal is to guess the word by suggesting letters, one at a time.
 *
 * If you guess a letter that's in the word, the game fills in all the blanks where that letter appears. If you guess
 * a letter that's not in the word, you lose an attempt. You only have a limited number of incorrect guesses, so each
 * wrong guess brings you closer to losing the game.
 *
 * The game continues until you've either guessed the word correctly or used up all your attempts. If you manage to
 * guess the word before your attempts run out, you win! But if you run out of guesses, the game ends, and the hidden
 * word is revealed.
 *
 * It's a fun challenge that tests your vocabulary and spelling skills, all while keeping you on your toes with each
 * guess.
 * -------------------------------------------------------------------------------------------------------------------
 * Author:       Patrik Eigenmann
 * eMail:        p.eigenmann@gmx.net
 * -------------------------------------------------------------------------------------------------------------------
 * Sat 2024-11-23 File created.                                                                         Version: 00.01
 * Mon 2024-11-25 Integrated mylibs.                                                                    Version: 00.02
 * -------------------------------------------------------------------------------------------------------------------
 * To Do's:
 * ********************************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#ifdef _WIN32
    /* --= Windows Section =-- */
    #include "..\mylibs\cVersion.h"
    #include "..\mylibs\cManPage.h"

#else
    /* --= MacOS/Linux Section =-- */
    #include "../mylibs/cVersion.h"
    #include "../mylibs/cManPage.h"

#endif

/* ---------------------------------------------------------------------------------------------------------------
 * The print_help function is our top-notch guidance feature, crafted to provide users with clear, intuitive
 * instructions for leveraging our command-line utility within the Windows Command Prompt environment. Think of it
 * as your personal guide, always ready to offer step-by-step explanations for each option available in the tool.
 *
 * When users invoke this function, they receive a clear and concise breakdown of the command and all available
 * options. This helps them understand the functionality and usage of the program, ensuring they can use it
 * effectively. The help messages are intuitive and user-friendly, providing familiarity for users accustomed
 * to similar command-line tools on various platforms.
 *
 * In essence, show_help embodies our commitment to user empowerment, making sure every feature is accessible and
 * easily understood. This minimizes learning curves and maximizes productivity. This function is the cornerstone
 * of our user-centric approach, providing instant, reliable support whenever needed. Welcome to a new era of
 * intuitive, efficient command-line interaction.
 * --------------------------------------------------------------------------------------------------------------- */
void print_help() {

    // Version control implemented
    Version v = create_version(0, 2);
    
    // The buffer is needed to write
    // the correct formated version number.
    char buffer[6];
    
    // Format the buffer with the
    // correct version number.
    to_string(v, buffer);

    char *manpage = NULL;

    // Write the ManPage style help file.
    append_format(&manpage, "NAME\n");
    append_format(&manpage, "       cHangman Version: %s\n", buffer);
    append_format(&manpage, "       cHangman is a classic word guessing game that's both fun and educational.\n");
    append_format(&manpage, "       Here’s how it works: The game picks a word from a list, but doesn’t reveal\n");
    append_format(&manpage, "       it. Instead, it shows a series of blank spaces, each representing a letter\n");
    append_format(&manpage, "       in the word. Your goal is to guess the word by suggesting letters, one at\n");
    append_format(&manpage, "       a time.\n");
    append_format(&manpage, "\n");
    append_format(&manpage, "       If you guess a letter that's in the word, the game fills in all the blanks\n");
    append_format(&manpage, "       where that letter appears. If you guess a letter that's not in the word,\n");
    append_format(&manpage, "       you lose an attempt. You only have a limited number of incorrect guesses,\n");
    append_format(&manpage, "       so each wrong guess brings you closer to losing the game.\n");
    append_format(&manpage, "\n");
    append_format(&manpage, "       The game continues until you've either guessed the word correctly or used\n");
    append_format(&manpage, "       up all your attempts. If you manage to guess the word before your attempts\n");
    append_format(&manpage, "       run out, you win! But if you run out of guesses, the game ends, and the\n");
    append_format(&manpage, "       hidden word is revealed.\n");
    append_format(&manpage, "\n");
    append_format(&manpage, "       It's a fun challenge that tests your vocabulary and spelling skills, all\n");
    append_format(&manpage, "       while keeping you on your toes with each guess.\n");
    append_format(&manpage, "\n");
    append_format(&manpage, "SYNOPSIS\n");
    append_format(&manpage, "       cHangman (without any parameters to play the game)\n");
    append_format(&manpage, "\n");
    append_format(&manpage, "DESCRIPTION\n");
    append_format(&manpage, "       -h, -help -H -Help\n");
    append_format(&manpage, "              Display this help and exit.\n");
    append_format(&manpage, "\n");
    append_format(&manpage, "AUTHOR\n");
    append_format(&manpage, "       Patrik Eigenmann (p.eigenmann@gmx.net)\n");
    append_format(&manpage, "\n");
    append_format(&manpage, "COPYRIGHT\n");
    append_format(&manpage, "      Copyright 2024 Free Software Foundation, Inc. License GPLv3+:\n");
    append_format(&manpage, "      GNU GPL version 3 or later <https://gnu.org/licenses/gpl.html>.\n");
    append_format(&manpage, "      This is free software: you are free to change and redistribute it.\n");
    append_format(&manpage, "      There is NO WARRANTY, to the extent permitted by law.\n");

    // Create the manpage in the file /temp/cp.man
    create_manpage("cp", manpage, v.major, v.minor);

    // Free up the memory.
    free(manpage);
}

/* *****************************************************************************************************************
 * The loadWords function reads words from a file and stores them in an array. It opens the specified file, reads
 * each word separated by a comma, and stores them in the provided array until either the end of the file is reached
 * or the maximum number of words is read. If the file cannot be opened, an error message is printed.
 *
 * @param filename: The name of the file containing the comma-separated list of words.
 * @param words: An array to store the words read from the file.
 * @param maxWords: The maximum number of words to read from the file.
 * @return: The number of words successfully read from the file.
 * ***************************************************************************************************************** */
int loadWords(const char *filename, char words[][50], int maxWords) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 0;
    }

    int wordCount = 0;
    while (fscanf(file, "%49[^,],", words[wordCount]) == 1) {
        wordCount++;
        if (wordCount >= maxWords) {
            break;
        }
    }

    fclose(file);
    return wordCount;
}

/* *****************************************************************************************************************
 * The guessCharacter function checks if the guessed character is present in the word. If the character is found
 * and has not been guessed before, it updates the guessed word with the character in the correct position. The
 * function returns the number of times the guessed character is found in the word.
 *
 * @param word: The word that needs to be guessed.
 * @param guessedWord:  The current state of the guessed word, with correctly guessed letters and underscores for
 *                      letters yet to be guessed.
 * @param guess: The character guessed by the player.
 * @return: The number of occurrences of the guessed character found in the word.
 * ***************************************************************************************************************** */
int guessCharacter(const char *word, char *guessedWord, char guess) {
    int found = 0;
    for (int i = 0; i < strlen(word); ++i) {
        if (word[i] == guess && guessedWord[i] == '_') {
            guessedWord[i] = guess;
            found++;
        }
    }
    return found;
}

/* ---------------------------------------------------------------------------------------------------------------
 * main - In the vast, uncharted realms of cyberspace, there exists a function. Not just any function, but the main
 * function. It is the gatekeeper, the sentinel that stands at the threshold of every C and C++ program. It is the
 * beginning and the end, the alpha and the omega.
 *
 * @param int argc     - Command argument count
 * @param char **argv  - Command argument strings
 * @return             - 0 if the program executes successfully. If the program encounters an error that warrants
 *                       termination, you can return a different integer value (commonly 1 or another non-zero value)
 *                       to indicate the type of error.
 * --------------------------------------------------------------------------------------------------------------- */
int main (int argc, char **argv) {
    
    char *argument = "\0";

    if(argv[1] != NULL) {
        argument = argv[1];
    } 

    // Check if the help is triggered. I have to trick the function,
    // because if the programm is called without parameters, the game
    // should start.
    if(isHelpTriggered((argc + 1), argument)) {
        print_help();
        return 1;
    }

    const char *filename = "words.txt";
    char words[100][50];
    int wordCount = loadWords(filename, words, 100);

    if (wordCount == 0) {
        printf("No words found in file.\n");
        return 1;
    }

    srand(time(NULL));
    int randomIndex = rand() % wordCount;
    const char *word = words[randomIndex];

    char guessedWord[50] = {0};
    for (int i = 0; i < strlen(word); ++i) {
        guessedWord[i] = '_';
    }

    int maxAttempts = 6;
    int attempts = 0;
    int correctGuesses = 0;
    int wordLength = strlen(word);

    while (attempts < maxAttempts && correctGuesses < wordLength) {
        char guess;
        printf("Word: %s\n", guessedWord);
        printf("Enter a letter: ");
        scanf(" %c", &guess);

        int found = guessCharacter(word, guessedWord, guess);

        if (found) {
            correctGuesses += found;
        } else {
            ++attempts;
            printf("Incorrect guess! Attempts left: %d\n", maxAttempts - attempts);
        }
    }

    if (correctGuesses == wordLength) {
        printf("Congratulations! You guessed the word: %s\n", word);
    } else {
        printf("Game over! The word was: %s\n", word);
    }

    return 0;
}