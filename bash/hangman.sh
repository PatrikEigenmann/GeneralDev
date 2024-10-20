#!/bin/bash

# *******************************************************************************************************************
# hangman.sh - In the dimly lit corners of a forgotten hard drive, a bash script lies dormant. Its purpose? To engage
# in a chilling game of wits with any who dare to invoke it.
#
# The script, a spectral entity known only as `hangman.sh`, awakens at the call of the user. It reaches out into the
# ether, pulling in a list of words from a text file, each word a potential key to its enigmatic puzzle.
#
# With a word selected at random, the game begins. The word is hidden, replaced by a string of underscores, each one
# a silent challenge to the user. The user must guess the letters of the word, their every input echoing in the void
# of the terminal.
#
# If the user's guess is correct, the script reveals the letter in its rightful place, a glimmer of hope in the
# darkness. But if the guess is incorrect, the script responds with a cold, stark message: "Incorrect guess."
#
# The game continues, a relentless cycle of guessing and revelation, until the word is finally unmasked. And then,
# the script delivers its final message, a chilling whisper in the silence of the terminal: "Congratulations, you've
# won!"
#
# And with that, the script returns to its slumber, waiting for the next brave soul to challenge its eerie game.
# -------------------------------------------------------------------------------------------------------------------
# Author: 	Patrik Eigenmann
# eMail: 	p.eigenmann@gmx.net
# -------------------------------------------------------------------------------------------------------------------
# Change Log:
# Sunday	2024-02-04 File created.																   Version: 00.01
# *******************************************************************************************************************

# Read the words from a file into an array
IFS=',' read -r -a words <<< "$(cat words.txt)"

# Select a random word from the array
word=${words[RANDOM % ${#words[@]}]}

word_length=${#word}
guessed_word=$(printf '_%.0s' $(seq 1 $word_length))

# Game loop
while [ "$word" != "$guessed_word" ]; do
	echo "Word: $guessed_word"
	read -p "Guess a letter: " guess

	# Check if the guessed letter is in the word
	if [[ $word == *$guess* ]]; then
		for (( i=0; i<$word_length; i++ )); do
			letter=${word:$i:1}
			if [ "$letter" == "$guess" ]; then
				guessed_word=${guessed_word:0:$i}$guess${guessed_word:$((i+1))}
			fi
		done
	else
		echo "Incorrect guess."
	fi
done

echo "Congratulations, you've won!"