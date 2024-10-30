#!/bin/python
# **************************************************************************************************
# Numbers.py - In this game, the program first generates a random number between 1 and 100. Then
# it enters a loop where it asks the user to enter their guess. If the user's guess is too high or
# too low, it tells them so and asks for another guess. If the user's guess is correct, it
# congratulates the user and ends the game. The game also counts the number of tries it took for the
# user to guess the number correctly. If the user enters something that's not a number, the program
# will ask for a valid number.
# --------------------------------------------------------------------------------------------------
# Author:       Patrik Eigenmann
# eMail:        p.eigenmann@gmx.net
# --------------------------------------------------------------------------------------------------
# Fri 2023-12-23    File created.			                             Version: 00.01
# **************************************************************************************************

# Importing the library to create random numbers
import random

number_to_guess = random.randint(1, 100)    # Creating the random number
number_of_tries = 0                         # Increases everytime after a guess
is_correct = False                          # Boolean as the checker if the guess was right

# Screen a short message
print("Welcome to the Numbers Game! Guess a number between 1 and 100.")

# Playing while loop
while not is_correct:
    # get a guessed number from the player
    user_guess = input("Enter your guess: ")

    # check if the input is numeric
    if not user_guess.isdigit():
        print("Invalid input. Please enter a number.")
        continue

    user_guess = int(user_guess)                # Convert the input into an integer    
    number_of_tries += 1                        # Increase the number of tries

    # Compare the user input with the randomly generated number
    if user_guess > number_to_guess:
        print("Too high! Try again.")
    elif user_guess < number_to_guess:
        print("Too low! Try again.")
    else:
        print(f"Congratulations! You've guessed the number correctly after {number_of_tries} attempts.")
        is_correct = True

