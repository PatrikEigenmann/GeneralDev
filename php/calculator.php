#!/bin/php
<?php
/* ***************************************************************************************************
 * <php script> - This class Calculator takes two numbers as input when an object is created. It has
 * four methods: add(), subtract(), multiply(), and divide(), each performing the respective operation.
 * The divide() method checks if the second number is zero to avoid a division by zero error. To use
 * this calculator, you can create an object of the Calculator class and call the methods on that
 * object. Please note that this is a very basic calculator and does not perform error checking beyond
 * what’s shown.
 * ---------------------------------------------------------------------------------------------------
 * Author:       Patrik Eigenmann
 * eMail:        p.eigenmann@gmx.net
 * ---------------------------------------------------------------------------------------------------
 * Sun	2023-12-24	File created.													    Version: 00.01
 * ***************************************************************************************************/

// Calculator - This class takes two numbers as input when an object is created. It has four methods:
// add(), subtract(), multiply(), and divide(), each performing the respective operation. The divide()
// method checks if the second number is zero to avoid a division by zero error. To use this calculator,
// you can create an object of the Calculator class and call the methods on that object. Please note
// that this is a very basic calculator and does not perform error checking beyond what’s shown. 
 class Calculator {
    private $num1;          // Number 1
    private $num2;          // Number 2

    // Construction of the class.
    // @param1 $num1 as integer or double
    // @param2 $num2 as integer or double
    public function __construct($num1, $num2) {
        $this->num1 = $num1;    // Overwrite $num1
        $this->num2 = $num2;    // Overwrite $num2
    }

    // add() - Addition
    // @return addition of $num1 and $num2
    public function add() {
        return $this->num1 + $this->num2;
    }

    // subtract() - Subtraction
    // @return subtraction of $num1 and $num2
    public function subtract() {
        return $this->num1 - $this->num2;
    }

    // multiply() - Multiplication
    // @return multiplication of $num1 and $num2
    public function multiply() {
        return $this->num1 * $this->num2;
    }

    // divide() - Divition (warning divition by zero is mathematically not possible)
    // @return divition of $num1 and $num2
    public function divide() {
        if ($this->num2 != 0) {
            return $this->num1 / $this->num2;
        } else {
            return "Error! Division by zero is not allowed.";
        }
    }
}

$calculator = new Calculator(10, 5);
echo "Addition: " . $calculator->add() . "\n";
echo "Subtraction: " . $calculator->subtract() . "\n";
echo "Multiplication: " . $calculator->multiply() . "\n";
echo "Division: " . $calculator->divide() . "\n";
?>
