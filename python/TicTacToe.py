#!/bin/python
# ****************************************************************************************************************
# TicTacToe.py - Class TicTacToe
# ----------------------------------------------------------------------------------------------------------------
# Author:       Patrik Eigenmann
# eMail:        p.eigenmann@gmx.net
# ----------------------------------------------------------------------------------------------------------------
# Tue 2024-02-27 File created.                                                                      Version: 00.01
# ----------------------------------------------------------------------------------------------------------------
# To Do's:
# ****************************************************************************************************************

class TicTacToe:
    
    # ------------------------------------------------------------------------------------------------------------
    # Creating the board, the board has 9 fields, on initialisation the field just will be filled with a space
    # string " ". I choose an array, because it will be way simpler to operate on the board.
    # ------------------------------------------------------------------------------------------------------------
    Board = [" "] * 9

    # ------------------------------------------------------------------------------------------------------------
    # isMoveValid - The method is checking if the move to a certain field on the board is valid.
    # @param index - number between 0 and 9
    # @return True/False
    # ------------------------------------------------------------------------------------------------------------
    def isMoveValid(self, index):
        check = True
        if not self.Board[index] == ' ' and index >=0 and index < 9:
            check = False
            
        return check
    
    # ------------------------------------------------------------------------------------------------------------
    # makeMove - The method is checking if the move to a certain field on the board is valid, and if it is, it
    # actually makes the move.
    # @param index - number between 0 and 9
    # @param player - either 'X' or 'O'
    # @return True/False
    # ------------------------------------------------------------------------------------------------------------
    def makeMove(self, index, player):
        check = True
        
        if index >= 0 and index < 9 and player == 'X' or player == 'O':
            self.Board[index] = player
        else:
            check = False
        
        return check
    
    # ------------------------------------------------------------------------------------------------------------
    # makeMove - The method is checking if the move to a certain field on the board is valid, and if it is, it
    # actually makes the move.
    # @param index - number between 0 and 9
    # @param player - either 'X' or 'O'
    # @return True/False
    # ------------------------------------------------------------------------------------------------------------
    def findTwoInRow(self, player):
        count = 0
        empty = 0
        
        return 0
        
    # ------------------------------------------------------------------------------------------------------------
    # printBoard - The method will print the board out on the screen according the already set moves.
    #
    #    a   b   c
    # 1  0 | 1 | 2
    #   ---+---+---
    # 2  3 | 4 | 5
    #   ---+---+---
    # 3  6 | 7 | 8
    #
    # ------------------------------------------------------------------------------------------------------------
    def printBoard(self):
        str_board = "   a   b   c\n"
        
        for index in range(9):
            if index == 0 or index == 3 or index == 6:
                str_board += str(int((index / 3) + 1)) + "  " + self.Board[index] + " |"
           
            if index == 1 or index == 4 or index == 7:
                str_board += " " + self.Board[index] + " |"
            
            if index == 2 or index == 5:
                str_board += " " + self.Board[index] + "\n  ---+---+---\n"
            
            if index == 8:
                str_board += " " + self.Board[index] + "\n"
                
        return str_board
        
t = TicTacToe()

t.makeMove(0, 'X')
t.makeMove(1, 'X')

print(t.printBoard())