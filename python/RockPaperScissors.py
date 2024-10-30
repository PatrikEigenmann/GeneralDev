
#!/bin/python
# ***************************************************************************************************************************
# RockPaperScissors.py - The program is a simple implementation of the classic game Rock, Paper, Scissors in Python. It
# consists of three main functions and a game loop.
#
# 1. **get_computer_choice function**: This function is responsible for determining the choice of the computer player. It does
# this by randomly selecting one of the three possible choices: rock, paper, or scissors.
#
# 2. **get_winner function**: This function takes the choices of both the player and the computer as input and determines the
# winner of the game based on the rules of Rock, Paper, Scissors. If the player and computer make the same choice, the game is
# a tie. Otherwise, the function checks the combinations of choices to determine the winner.
#
# 3. **play_game function**: This is the main game loop. It first prompts the player to enter their choice. Then, it calls the
# `get_computer_choice` function to determine the computer's choice and prints it. Finally, it calls the `get_winner` function
# to determine and print the winner of the game.
#
# The game is played in the console, with the player entering their choice as text. The computer's choice is randomly generated,
# and the winner is determined based on the rules of the game. The result of the game is then printed to the console.
#
# Please note that this code does not include any error checking. If you enter something other than "rock", "paper", or "scissors",
# it will not work correctly. You might want to add some error checking to make sure the player's input is valid. 
#
# Also, this code is designed to be run in a console or terminal. If you're planning to use it in a different context (like
# a web page or a GUI application), you'll need to modify it to get input and display output in a way that's appropriate for
# your context. 
# ---------------------------------------------------------------------------------------------------------------------------
# Author:       Patrik Eigenmann
# eMail:        p.eigenmann@gmx.net
# ---------------------------------------------------------------------------------------------------------------------------
# Thu 2023-12-28    File created.		        					                                           Version: 00.01
# ***************************************************************************************************************************

import random

def get_computer_choice():
    choices = ["rock", "paper", "scissors"]
    return random.choice(choices)

def get_winner(player_choice, computer_choice):
    if player_choice == computer_choice:
        return "It's a tie!"
    if (player_choice == "rock" and computer_choice == "scissors") or \
       (player_choice == "scissors" and computer_choice == "paper") or \
       (player_choice == "paper" and computer_choice == "rock"):
        return "Player wins!"
    else:
        return "Computer wins!"

def play_game():
    player_choice = input("Enter your choice (rock, paper, scissors): ")
    computer_choice = get_computer_choice()
    print(f"Computer chose {computer_choice}")
    print(get_winner(player_choice, computer_choice))

play_game()
