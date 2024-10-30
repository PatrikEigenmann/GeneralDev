#!/bin/python
# ***************************************************************************************************************************
# fibonacci.py - The Fibonacci class is designed to generate and print numbers from the Fibonacci sequence. It has two main
# components:
#
# - Initialization (__init__ method): When an instance of the Fibonacci class is created, it initializes a list, fib_sequence,
#   with the first two numbers of the Fibonacci sequence: 0 and 1.
#
# - Number Generation (generate method): This method takes two parameters, start and quantity. The start parameter determines
#   the first Fibonacci number to be printed that is greater than or equal to this parameter. The quantity parameter specifies
#   how many Fibonacci numbers to print.
#
# The generate method begins by setting a and b to the first two numbers in the Fibonacci sequence (0 and 1). It then enters a
# loop that generates Fibonacci numbers until it reaches a number that is greater than or equal to start. This is done by
# repeatedly replacing a and b with b and a + b, which are the next two numbers in the Fibonacci sequence.
#
# Once the desired starting point in the sequence is reached, the method enters another loop to print the next quantity
# Fibonacci numbers. It continues to replace a and b with b and a + b to generate the next number in the sequence, and prints
# a in each iteration of the loop.

# In use, an instance of the Fibonacci class is first created. Then, the generate method is called on this instance, with the
# desired start and quantity passed as parameters. The method will then print the specified quantity of Fibonacci numbers,
# starting from the first number that is greater than or equal to start.
# ---------------------------------------------------------------------------------------------------------------------------
# Author:       Patrik Eigenmann
# eMail:        p.eigenmann@gmx.net
# ---------------------------------------------------------------------------------------------------------------------------
# Fri 2024-01-12 File created.                                                                                 Version: 00.01
# ***************************************************************************************************************************
class Fibonacci:
    def __init__(self):
        self.fib_sequence = [0, 1]

    def generate(self, start, quantity):
        a, b = 0, 1
        while a < start:
            a, b = b, a + b

        for _ in range(quantity):
            print(a)
            a, b = b, a + b

# Usage
fib = Fibonacci()
fib.generate(start=100, quantity=20)
