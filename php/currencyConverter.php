#!/bin/php
<?php
/* ***************************************************************************************************
 * currencyConverter - Meet the CurrencyConverter, your new best friend in the world of finance and
 * currency exchange! This class is a powerful tool, designed to effortlessly handle the complexities
 * of currency conversion, making it an essential asset for any finance-related PHP project.
 * 
 * The CurrencyConverter class is like a master key to the world’s currencies. It’s equipped with the
 * ability to fetch real-time exchange rates from an API, ensuring that your conversions are always
 * up-to-date with the global financial market.
 * 
 * But the magic doesn’t stop there! The CurrencyConverter class is also capable of performing the
 * actual currency conversions. Whether you’re converting from USD to EUR, GBP to JPY, or any other
 * currency pair, this class has got you covered. All you need to do is provide the amount and the
 * currencies, and the CurrencyConverter class will take care of the rest.
 * 
 * Under the hood, the CurrencyConverter class is a testament to the power of object-oriented
 * programming in PHP. It encapsulates the conversion logic within easy-to-use methods, keeping your
 * code clean, organized, and efficient.
 * 
 * In essence, the CurrencyConverter class is more than just a piece of code; it’s a robust, reliable,
 * and resourceful companion that’s ready to tackle the challenges of currency conversion. So why
 * wait? Start leveraging the power of the CurrencyConverter class and take your PHP project to new
 * heights! 
 * ---------------------------------------------------------------------------------------------------
 * Author:       Patrik Eigenmann
 * eMail:        p.eigenmann@gmx.net
 * ---------------------------------------------------------------------------------------------------
 * Tue	2023-12-26	File created.													    Version: 00.01
 * ***************************************************************************************************/

 /**
 * Class CurrencyConverter
 *
 * This class provides methods for converting between different currencies.
 * It fetches the latest exchange rates from an API and uses these rates to perform the conversions.
 *
 * The class includes two public methods:
 * - getExchangeRate($fromCurrency, $toCurrency): Fetches the exchange rate between two currencies from the API.
 * - convert($amount, $fromCurrency, $toCurrency): Converts an amount from one currency to another using the exchange rate.
 */
class CurrencyConverter {
    // The URL of the API that provides the exchange rates
    private $api_url = 'http://api.exchangeratesapi.io/v1/latest?access_key=YOUR_ACCESS_KEY';  // Replace with actual API URL

    /**
     * Fetch the exchange rate between two currencies from the API
     *
     * @param string $fromCurrency The currency to convert from
     * @param string $toCurrency The currency to convert to
     * @return float The exchange rate from $fromCurrency to $toCurrency
     */
    public function getExchangeRate($fromCurrency, $toCurrency) {
        // Fetch data from API
        $json = file_get_contents($this->api_url);
        $data = json_decode($json, true);

        // Calculate exchange rate
        $baseRate = $data['rates'][$fromCurrency];
        $exchangeRate = $data['rates'][$toCurrency];

        return $exchangeRate / $baseRate;
    }

    /**
     * Convert an amount from one currency to another
     *
     * @param float $amount The amount to convert
     * @param string $fromCurrency The currency to convert from
     * @param string $toCurrency The currency to convert to
     * @return float The converted amount in $toCurrency
     */
    public function convert($amount, $fromCurrency, $toCurrency) {
        $rate = $this->getExchangeRate($fromCurrency, $toCurrency);
        return $amount * $rate;
    }
}
?>