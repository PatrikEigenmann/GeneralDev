#!/bin/python
# ***************************************************************************************************************************
# calculator.py - This program first prompts the user to select an operation. Then it asks for two numbers and performs the
# selected operation on those two numbers. If the user selects division, the program checks if the second number is zero to
# avoid a division by zero error. If the user enters anything other than 1, 2, 3, or 4, the program will output "Invalid
# input." To use this calculator again, you can call the calculator() function. Please note that this is a very basic
# calculator and does not perform error checking beyond what's shown.
# ---------------------------------------------------------------------------------------------------------------------------
# Author:       Patrik Eigenmann
# eMail:        p.eigenmann@gmx.net
# ---------------------------------------------------------------------------------------------------------------------------
# Sun	2023-12-23  File created.							                                                   Version: 00.01
# ***************************************************************************************************************************
def calculator():
    """
    This program first prompts the user to select an operation. Then it asks for two numbers and performs the
    selected operation on those two numbers. If the user selects division, the program checks if the second number is zero to
    avoid a division by zero error. If the user enters anything other than 1, 2, 3, or 4, the program will output �Invalid
    input." To use this calculator again, you can call the calculator() function. Please note that this is a very basic
    calculator and does not perform error checking beyond what�s shown.
    """
    # Promp the selection of operation
    print("Select operation:")
    print("1. Addition")
    print("2. Subtraction")
    print("3. Multiplication")
    print("4. Division")

    # Make your choice
    choice = input("Enter choice (1/2/3/4): ")

    # Then input the numbers
    num1 = float(input("Enter first number: "))
    num2 = float(input("Enter second number: "))

    # Addition
    if choice == '1':
        print(num1, "+", num2, "=", num1 + num2)

    # Subtraction
    elif choice == '2':
        print(num1, "-", num2, "=", num1 - num2)

    # Multiplication
    elif choice == '3':
        print(num1, "*", num2, "=", num1 * num2)

    # Divition
    elif choice == '4':
        if num2 != 0:
            print(num1, "/", num2, "=", num1 / num2)
        else:
            print("Error! Division by zero is not allowed.")

    else:
        print("Invalid input")

# Class using
calculator()
