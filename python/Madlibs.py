#!/bin/python
# ***************************************************************************************************************************
# Madlibs.py - In the realm of programming, where logic reigns supreme and creativity often takes a backseat, there emerges a
# hero - the MadLibs class. This isn't your typical Python class, oh no. It's a class that brings joy, laughter, and a dash
# of absurdity into the world of code.
#
# The MadLibs class is a storyteller, a jester, and a friend all rolled into one. It weaves tales of adventure, each unique
# and shaped by the words you choose. It prompts you, teases you, and in the end, surprises you with a story that is as
# much yours as it is its own.
#
# The heart of MadLibs is its play method. It's here that the magic happens. With each call to play, you're invited to embark
# on a new journey. A journey filled with adjectives, nouns, verbs, and adverbs. A journey where you're the author, and the
# story is yours to shape.
#
# But the MadLibs class is more than just a game. It's a testament to the power of Python - a language that's as versatile as
# it is powerful. It's proof that programming can be fun, creative, and accessible to all.
#
# So, dear reader, a you delve into the world of MadLibs, remember this: every word you choose, every story you create, is a
# reflection of your imagination. And in the world of MadLibs, your imagination is the only limit.
# ---------------------------------------------------------------------------------------------------------------------------
# Author:       Patrik Eigenmann
# eMail:        p.eigenmann@gmx.net
# ---------------------------------------------------------------------------------------------------------------------------
# Fri 2023-12-29    File created.                                                                               Version: 00.01
# Sat 2024-01-19    Modified that now stories can be read from the stories.xml file.                            Version: 00.02
# Sat 2024-01-19    Modified the code, so I can use multiple times the same placeholder                         Version: 00.03
# ***************************************************************************************************************************

from lxml import etree
import random
import re
import os

class MadLibs:
    def __init__(self, xml_file):
        tree = etree.parse(xml_file)
        root = tree.getroot()

        self.stories = [story.text for story in root.findall('story')]

    def play(self):
        story = random.choice(self.stories)
        placeholders = re.findall(r'{(.*?)}', story)
        answers = {}

        for placeholder in placeholders:
            if placeholder not in answers:
                answers[placeholder] = []
            answer = input("Enter a(n) {}: ".format(placeholder))
            answers[placeholder].append(answer)

        for placeholder, answer_list in answers.items():
            for answer in answer_list:
                story = story.replace("{" + placeholder + "}", answer, 1)

        print(story)

# Clear the screen
os.system('cls' if os.name == 'nt' else 'clear')

game = MadLibs('stories.xml')
game.play()
