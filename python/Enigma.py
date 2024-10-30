#!/bin/python
# ***************************************************************************************************************************
# enigma.py - The Enigma class is a simplified representation of the Enigma machine, a cipher device used by the Germans
# during World War II. Please note that this is a very simplified version of the Enigma machine and doesn't include many of
# its features, such as the plugboard, multiple rotor sets, or double stepping of rotors. Also, this code doesn't provide any
# real security, it's just for illustrative purposes. For real encryption, consider using established libraries and algorithms.
# 
# Remember to handle edge cases and errors in your actual code. For example, this code assumes that the input is always
# uppercase and doesn't contain any characters other than A-Z. If your input may be different, you'll need to add code to
# handle that. You might also want to add error checking to make sure the rotors and reflector arguments to the constructor
# are valid.
# ---------------------------------------------------------------------------------------------------------------------------
# Author:       Patrik Eigenmann
# eMail:        p.eigenmann@gmx.net
# ---------------------------------------------------------------------------------------------------------------------------
# Sun	2023-12-24  File created.							                                                   Version: 00.01
# ***************************************************************************************************************************

class Enigma:
    """
    The Enigma class is a simplified representation of the Enigma machine, a cipher device used by the Germans during World War II.

    Properties:
    rotors: An array representing the rotors in the Enigma machine. Each rotor is an integer that determines how much to shift a character.
    reflector: An integer representing the reflector in the Enigma machine. The reflector determines how much to shift a character after it has passed through all the rotors.

    Methods:
    __init__(self, rotors, reflector): The constructor method. It initializes the rotors and reflector properties with the given arguments.
    rotate(self): A private method that rotates the rotors by one position. This method is called after each character is ciphered or deciphered.
    cypher(self, input): This method takes a string as input and returns the ciphered text. It passes each character of the input through the rotors and the reflector, shifting it by the corresponding amounts. After each character, the rotors are rotated by one position.
    decypher(self, input): This method takes a string as input and returns the deciphered text. It reverses the operations of the cypher method, passing each character through the rotors and the reflector in the opposite order and direction.

    Please note that this is a very simplified version of the Enigma machine and doesn't include many of its features, such as the plugboard, multiple rotor sets, or double stepping of rotors. Also, this code doesn't provide any real security, it's just for illustrative purposes. For real encryption, consider using established libraries and algorithms.

    Remember to handle edge cases and errors in your actual code. For example, this code assumes that the input is always uppercase and doesn't contain any characters other than A-Z. If your input may be different, you'll need to add code to handle that. You might also want to add error checking to make sure the rotors and reflector arguments to the constructor are valid.
    """
    def __init__(self, rotors, reflector):
        self.rotors = rotors
        self.reflector = reflector

    def rotate(self):
        for i in range(len(self.rotors)):
            self.rotors[i] = (self.rotors[i] + 1) % 26

    def cypher(self, input):
        output = ''
        for char in input:
            char = ord(char) - ord('A')
            for rotor in self.rotors:
                char = (char + rotor) % 26
            char = (char + self.reflector) % 26
            for rotor in reversed(self.rotors):
                char = (char - rotor + 26) % 26
            output += chr(char + ord('A'))
            self.rotate()
        return output

    def decypher(self, input):
        output = ''
        for char in input:
            char = ord(char) - ord('A')
            for rotor in self.rotors:
                char = (char - rotor + 26) % 26
            char = (char - self.reflector + 26) % 26
            for rotor in reversed(self.rotors):
                char = (char + rotor) % 26
            output += chr(char + ord('A'))
            self.rotate()
        return output

enigma = Enigma([3, 5, 7], 2)
cyphered = enigma.cypher('HELLO')
print(cyphered)
print(enigma.decypher(cyphered))

