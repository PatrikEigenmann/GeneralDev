#!/bin/python
# ***************************************************************************************************************************
# config.py - The Config class is like a magical chest, holding the secrets of your application’s settings. It’s crafted from
# the finest Python code, and it’s as flexible as a gymnast.
#
# When you create an instance of Config, it’s like unlocking this chest with a special key - the path to your XML file. As
# the lock turns, the class reads the XML file, delving into its structure, and absorbing the knowledge within. Each parameter
# in the XML file is like a unique artifact, and the Config class carefully stores each one in its memory.
#
# But the magic doesn’t stop there. The Config class has a special ability - the get method. This method is like a friendly
# librarian, always ready to fetch the information you need. When you ask for a parameter, the get method delves into its
# collection and retrieves the value for you. If the parameter doesn’t exist, it doesn’t get flustered. Instead, it calmly
# returns None, letting you know that it couldn’t find what you were looking for.
#
# In essence, the Config class is a diligent, reliable guardian of your application’s settings, always ready to provide the
# information you need when you need it. It’s a testament to the power and elegance of Python, and a valuable tool for any
# developer. 
# ---------------------------------------------------------------------------------------------------------------------------
# Author:       Patrik Eigenmann
# eMail:        p.eigenmann@gmx.net
# ---------------------------------------------------------------------------------------------------------------------------
# Thu	2023-12-28  File created.                                                                              Version: 00.01
# ***************************************************************************************************************************

import xml.etree.ElementTree as ET

class Config:
    """
    The Config class is like a magical chest, holding the secrets of your application’s settings. It’s crafted from the finest
    Python code, and it’s as flexible as a gymnast.

    When you create an instance of Config, it’s like unlocking this chest with a special key - the path to your XML file. As
    the lock turns, the class reads the XML file, delving into its structure, and absorbing the knowledge within. Each
    parameter in the XML file is like a unique artifact, and the Config class carefully stores each one in its memory.

    But the magic doesn’t stop there. The Config class has a special ability - the get method. This method is like a friendly
    librarian, always ready to fetch the information you need. When you ask for a parameter, the get method delves into its
    collection and retrieves the value for you. If the parameter doesn’t exist, it doesn’t get flustered. Instead, it calmly
    returns None, letting you know that it couldn’t find what you were looking for.

    In essence, the Config class is a diligent, reliable guardian of your application’s settings, always ready to provide the
    information you need when you need it. It’s a testament to the power and elegance of Python, and a valuable tool for any
    developer. 
    """

    def __init__(self, xml_file):
        """
        Initialize the Config class and load parameters from the given XML file.

        Args:
            xml_file (str): Path to the XML file.
        """
        tree = ET.parse(xml_file)
        root = tree.getroot()

        self.params = {}
        for child in root:
            self.params[child.tag] = child.text

    def get(self, param):
        """
        Get the value of the given parameter.

        Args:
            param (str): The name of the parameter.

        Returns:
            The value of the parameter, or None if the parameter is not found.
        """
        return self.params.get(param)

# Usage
config = Config("./config.xml")     # Load the local config.xml
param = config.get("param1")
print(f"Parameter 1 is {param}")   # Display param1
param = config.get("param2")
print(f"Parameter 2 is {param}")   # Display param2