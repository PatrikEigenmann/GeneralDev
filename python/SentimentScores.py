#!/bin/python
# ***************************************************************************************************************************
# sentiment_scores.py - In this example, we’re using the VADER sentiment analysis tool from NLTK, which is specifically
# designed for social media and works well on texts with limited context. It gives a sentiment score between -1 (negative
# sentiment) and 1 (positive sentiment). Running this code on the sentence “I absolutely love this movie. It’s fantastic!”
# will give you a sentiment score indicating a very positive sentiment.
#
# Please note that you’ll need to have the NLTK library installed and the ‘vader_lexicon’ downloaded to run this code. You
# can install NLTK with pip (pip install nltk) and download ‘vader_lexicon’ using the nltk.download() function in the script.
#
# This is a very basic example of what you can do with NLP. More advanced techniques include things like language translation,
# named entity recognition, topic modeling, and much more. NLP is a vast field with a wide range of applications in areas
# like chatbots, translation services, sentiment analysis, and information extraction, to name a few.
# ---------------------------------------------------------------------------------------------------------------------------
# Author:       Patrik Eigenmann
# eMail:        p.eigenmann@gmx.net
# ---------------------------------------------------------------------------------------------------------------------------
# Sun 2023-12-31 File created.                                                                                 Version: 00.01
# ***************************************************************************************************************************

from nltk.sentiment.vader import SentimentIntensityAnalyzer
import nltk
nltk.download('vader_lexicon')

# Initialize the sentiment intensity analyzer
sia = SentimentIntensityAnalyzer()

# Let's try it on a sentence
sentence = "I absolutely love this movie. It's fantastic!"

# Get the sentiment scores
sentiment_scores = sia.polarity_scores(sentence)

print(sentiment_scores)
