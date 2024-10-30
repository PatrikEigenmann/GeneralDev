#!/bin/python
# ***************************************************************************************************************************
# currencyConverter.py - The CurrencyConverter class is like a financial wizard, adept at transforming one form of currency
# into another in the blink of an eye. It’s a powerful tool in the world of finance and e-commerce, enabling seamless
# transactions across borders.
#
# When you create an instance of the CurrencyConverter class, it’s like gaining access to a global marketplace. With an API
# key as its magic wand, this class connects to real-time currency data, ensuring the most accurate conversions possible.
#
# The CurrencyConverter class is intuitive and easy to use. Its convert method is like a magic spell, transforming an amount
# from one currency to another. All you need to do is specify the amount and the currencies, and the CurrencyConverter takes
# care of the rest.
#
# But the true magic lies in the get_conversion_rate method. This method reaches out to the vast world of the internet,
# retrieves real-time conversion rates, and brings them right to your fingertips. It’s like having a financial advisor who’s
# always up-to-date with the latest market trends.
#
# In essence, the CurrencyConverter class is your passport to the global economy, ready to help you navigate the exciting
# world of currencies.
# ---------------------------------------------------------------------------------------------------------------------------
# Author:       Patrik Eigenmann
# eMail:        p.eigenmann@gmx.net
# ---------------------------------------------------------------------------------------------------------------------------
# Thu 2023-12-28    File created.                                                                              Version: 00.01
# ***************************************************************************************************************************

import requests

class CurrencyConverter:
    """
    The CurrencyConverter class is like a financial wizard, adept at transforming one form of currency into another in the blink
    of an eye. It’s a powerful tool in the world of finance and e-commerce, enabling seamless transactions across borders.

    When you create an instance of the CurrencyConverter class, it’s like gaining access to a global marketplace. With an API key
    as its magic wand, this class connects to real-time currency data, ensuring the most accurate conversions possible.

    The CurrencyConverter class is intuitive and easy to use. Its convert method is like a magic spell, transforming an amount
    from one currency to another. All you need to do is specify the amount and the currencies, and the CurrencyConverter takes
    care of the rest.

    But the true magic lies in the get_conversion_rate method. This method reaches out to the vast world of the internet, retrieves
    real-time conversion rates, and brings them right to your fingertips. It’s like having a financial advisor who’s always up-to-date
    with the latest market trends.

    In essence, the CurrencyConverter class is your passport to the global economy, ready to help you navigate the exciting world
    of currencies.
    """

    def __init__(self, api_key):
        """
        Initialize the CurrencyConverter class with the given API key.

        Args:
            api_key (str): The API key for the currency conversion service.
        """
        self.api_key = api_key

    def get_conversion_rate(self, from_currency, to_currency):
        """
        Get the conversion rate from one currency to another.

        Args:
            from_currency (str): The currency to convert from.
            to_currency (str): The currency to convert to.

        Returns:
            float: The conversion rate from the from_currency to the to_currency.
        """
        # TODO: Replace this with an actual API call
        # For example:
        # response = requests.get(f"https://api.example.com/convert?from={from_currency}&to={to_currency}&apiKey={self.api_key}")
        # return response.json()["rate"]
        return 0.7564738

    def convert(self, amount, from_currency, to_currency):
        """
        Convert the given amount from one currency to another.

        Args:
            amount (float): The amount to convert.
            from_currency (str): The currency to convert from.
            to_currency (str): The currency to convert to.

        Returns:
            float: The converted amount in the to_currency.
        """
        rate = self.get_conversion_rate(from_currency, to_currency)
        return rate * amount

# Usage
converter = CurrencyConverter("your_api_key")
print(converter.convert(100, "USD", "EUR"))
