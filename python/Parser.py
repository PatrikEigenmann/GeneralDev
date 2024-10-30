#!/bin/python
# ***************************************************************************************************************************
# parser.py - The TemplateParser class is a simple template parser written in Python. It’s designed to read a template from a
# file and replace placeholders in the template with specified values.
#
# When you create an instance of the TemplateParser class, you provide the name of a template file. The class reads the
# contents of this file and stores it as the template to be parsed.
#
# The class has a method called parse that takes a dictionary as input. Each key-value pair in the dictionary represents a
# placeholder in the template and the value that should replace it. The parse method goes through the template and replaces
# each placeholder with its corresponding value. The resulting string, which is the template with all placeholders replaced,
# is then returned.
#
#    Template File         Dictionary
# +----------------+   +----------------+
# | Hello, {{name}}|   |  "name": "John"|
# +----------------+   +----------------+
#          |                    |
#          v                    v
# +-----------------+  TemplateParser   +-----------------+
# | __init__ method | <---------------> |  parse method   |
# +-----------------+                   +-----------------+
#          |                                     ^
#          v                                     |
# +----------------+                             |
# | Hello, {{name}}|                             |
# +----------------+                             |
#          |                                     |
#          v                                     |
# +----------------------+ <---------------------+
# | Hello, John          |
# +----------------------+
#
# ---------------------------------------------------------------------------------------------------------------------------
# Author:       Patrik Eigenmann
# eMail:        p.eigenmann@gmx.net
# ---------------------------------------------------------------------------------------------------------------------------
# <day>		<date>          File created.							                                           Version: 00.01
# ***************************************************************************************************************************

class TemplateParser:
    """
The TemplateParser class is a simple template parser written in Python. It’s designed to read a template from a
file and replace placeholders in the template with specified values.

When you create an instance of the TemplateParser class, you provide the name of a template file. The class reads the
contents of this file and stores it as the template to be parsed.

The class has a method called parse that takes a dictionary as input. Each key-value pair in the dictionary represents a
placeholder in the template and the value that should replace it. The parse method goes through the template and replaces
each placeholder with its corresponding value. The resulting string, which is the template with all placeholders replaced,
is then returned.

   Template File         Dictionary
+----------------+   +----------------+
| Hello, {{name}}|   |  "name": "John"|
+----------------+   +----------------+
         |                    |
         v                    v
+-----------------+  TemplateParser   +-----------------+
| __init__ method | <---------------> |  parse method   |
+-----------------+                   +-----------------+
         |                                    ^
         v                                    |
+----------------+                            |
| Hello, {{name}}|                            |
+----------------+                            |
         |                                    |
         v                                    |
+----------------------+ <--------------------+
| Hello, John          |
+----------------------+

"""
    def __init__(self, template_file):
        with open(template_file, 'r') as file:
            self.template = file.read()

    def parse(self, data):
        result = self.template
        for key, value in data.items():
            result = result.replace("{{" + key + "}}", str(value))
        return result

data = {
    "param1": "Patrik",
    "param2": "Eigenmann",
    "param3": "Hayward, CA"
}
parser = TemplateParser("template.txt")
print(parser.parse(data))  # Outputs: Hello Patrik Eigenmann from Hayward, CA!


