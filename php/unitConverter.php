#!/bin/php
<?php
/* ***************************************************************************************************
 * unitConverter.php - The UnitConverter class is a versatile and efficient tool designed to simplify
 * the process of converting between different units of measurement. It’s like a Swiss Army knife for
 * unit conversions!
 * This class is equipped with a variety of methods, each tailored to convert between specific units.
 * Whether you’re looking to convert distances from miles to kilometers or vice versa, weights from
 * pounds to kilograms or vice versa, or even smaller units like ounces to grams or vice versa, this
 * class has got you covered.
 * But that’s not all! The UnitConverter class is also capable of handling conversions between meters
 * and yards, as well as inches and centimeters. This makes it a comprehensive solution for a wide
 * range of unit conversion needs.
 * Each method in the class takes a single argument - the value you wish to convert. It then uses
 * predefined conversion ratios to calculate and return the converted value. The beauty of this
 * design is its simplicity and efficiency. You don’t need to worry about the conversion logic -
 * the class handles it all for you!
 * In essence, the UnitConverter class is a powerful, easy-to-use tool that takes the complexity out
 * of unit conversions. It’s a testament to the power of well-structured, object-oriented programming
 * in PHP. Whether you’re building a weather app, a physics simulator, or just need to convert your
 * height from centimeters to inches, the UnitConverter class is ready to help!
 * ---------------------------------------------------------------------------------------------------
 * Author:       Patrik Eigenmann
 * eMail:        p.eigenmann@gmx.net
 * ---------------------------------------------------------------------------------------------------
 * Tue	2023-12-26	File created.													    Version: 00.01
 * ***************************************************************************************************/

/**
 * Class UnitConverter
 *
 * This class provides methods for converting between different units of measurement.
 * Currently supported conversions are:
 * - Miles to kilometers and vice versa
 * - Pounds to kilograms and vice versa
 * - Ounces to grams and vice versa
 * - Meters to yards and vice versa
 * - Inches to centimeters and vice versa
 *
 * Each conversion method takes a single argument, the value to be converted,
 * and returns the converted value.
 */
class UnitConverter {
    // Conversion ratios
    private $miles_to_km_ratio = 1.60934;
    private $lbs_to_kg_ratio = 0.453592;
    private $oz_to_g_ratio = 28.3495;
    private $m_to_yd_ratio = 1.09361;
    private $in_to_cm_ratio = 2.54;

    // Method to convert miles to kilometers
    public function milesToKm($miles) {
        return $miles * $this->miles_to_km_ratio;
    }

    // Method to convert kilometers to miles
    public function kmToMiles($km) {
        return $km / $this->miles_to_km_ratio;
    }

    // Method to convert pounds to kilograms
    public function lbsToKg($lbs) {
        return $lbs * $this->lbs_to_kg_ratio;
    }

    // Method to convert kilograms to pounds
    public function kgToLbs($kg) {
        return $kg / $this->lbs_to_kg_ratio;
    }

    // Method to convert ounces to grams
    public function ozToG($oz) {
        return $oz * $this->oz_to_g_ratio;
    }

    // Method to convert grams to ounces
    public function gToOz($g) {
        return $g / $this->oz_to_g_ratio;
    }

    // Method to convert meters to yards
    public function mToYd($m) {
        return $m * $this->m_to_yd_ratio;
    }

    // Method to convert yards to meters
    public function ydToM($yd) {
        return $yd / $this->m_to_yd_ratio;
    }

    // Method to convert inches to centimeters
    public function inToCm($in) {
        return $in * $this->in_to_cm_ratio;
    }

    // Method to convert centimeters to inches
    public function cmToIn($cm) {
        return $cm / $this->in_to_cm_ratio;
    }
}

// Create a new instance of the class and test a few methods!
$convertor = new UnitConverter();

printf("10 Kilometers are %f Miles! \n", $convertor->kmToMiles(10));
printf("10 Miles are %f Kilometers! \n", $convertor->milesToKm(10));
printf("10 Meter are %f Yards! \n", $convertor->mToYd(10));
printf("10 Yards are %f Meters! \n", $convertor->ydToM(10));
printf("10 Centimeters are %f Inches! \n", $convertor->cmToIn(10));
printf("10 Inches are %f Centimeters! \n", $convertor->inToCm(10));
printf("10 kg are %f lbs! \n", $convertor->kgToLbs(10));
printf("10 lbs are %f kg! \n", $convertor->lbsToKg(10));
printf("10 g are %f oz! \n", $convertor->gToOz(10));
printf("10 oz are %f g! \n", $convertor->ozToG(10));
?>