#!/bin/php
<?php
/* ***************************************************************************************************
 * rockPaperScissors.php - In this code, the game function is the same as before. The $choices array
 * contains the possible choices. The $computerChoice is determined randomly from the $choices array.
 * The readline function is used to get your choice from the console. The result of the game is then
 * printed to the console.
 * ---------------------------------------------------------------------------------------------------
 * Author:       Patrik Eigenmann
 * eMail:        p.eigenmann@gmx.net
 * ---------------------------------------------------------------------------------------------------
 * Mon	2023-12-25		File created.													Version: 00.01
 * ***************************************************************************************************/

 // --------------------------------------------------------------------------------------------------
 // function game - playes the actual game.
 // @param1 - choice of the player
 // @param2 - choice of the computer
 // @return - Tie or who ever wins.
 // --------------------------------------------------------------------------------------------------
 function game($player1, $player2) {
    
    // Now we can reveal the computer's choice.
    echo "You chose: $player1 \nComputer chose: $player2\n";
    
    // If the player's1 choice is the same like player2,
    // it's a tie.
    if ($player1 === $player2) {
        return "It's a tie!";
    }

    // If it is not a tie, someone has to win.
    switch ($player1) {
        case "rock":
            return ($player2 === "scissors") ? "You win!" : "Computer wins!";
        case "paper":
            return ($player2 === "rock") ? "You win!" : "Computer wins!";
        case "scissors":
            return ($player2 === "paper") ? "You win!" : "Computer wins!";
    }
}

$choices = array("rock", "paper", "scissors");
$computerChoice = $choices[array_rand($choices)];

echo "Computer made it's choice\n";

$yourChoice = readline("Enter your choice (rock, paper, scissors): ");
echo game($yourChoice, $computerChoice);
?>
