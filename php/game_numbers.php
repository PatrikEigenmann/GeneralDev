#!/bin/php
<?php
/* ***************************************************************************************************
 * numbers.php - In this game, the program first generates a random number between 1 and 100. Then it
 * enters a loop where it asks the user to enter their guess. If the user’s guess is too high or too
 * low, it tells them so and asks for another guess. If the user’s guess is correct, it congratulates
 * the user and ends the game. The game also counts the number of tries it took for the user to guess
 * the number correctly. If the user enters something that’s not a number, the program will ask for
 * a valid number.
 * ---------------------------------------------------------------------------------------------------
 * Author:       Patrik Eigenmann
 * eMail:        p.eigenmann@gmx.net
 * ---------------------------------------------------------------------------------------------------
 * Sat	2023-12-23		File created.													Version: 00.01
 * ***************************************************************************************************/

$numberToGuess = rand(1, 100);      # Create the random number
$numberOfTries = 0;                 # Number of tries
$isCorrect = false;                 # Boolean to check if the trie is correct

# Show the welcome message on the screen
echo "Welcome to the Numbers Game! Guess a number between 1 and 100.\n";

# Enter the while loop
while (!$isCorrect) {
    echo "Enter your guess: ";              # Show message on the screen
    $userGuess = trim(fgets(STDIN));        # Waiting for user input

    # First check if the user input is numeric
    if (!is_numeric($userGuess)) {
        echo "Invalid input. Please enter a number.\n";
        continue;
    }

    # Increase the number of tries
    $numberOfTries++;

    # Compering the user input and the random number
    if ($userGuess > $numberToGuess) {
        echo "Too high! Try again.\n";
    } elseif ($userGuess < $numberToGuess) {
        echo "Too low! Try again.\n";
    } else {
        echo "Congratulations! You've guessed the number correctly after $numberOfTries attempts.\n";
        $isCorrect = true;
    }
}
?>