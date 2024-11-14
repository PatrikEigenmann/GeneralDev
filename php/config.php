#!/bin/php
<?php
/* ***************************************************************************************************
 * config.php - The Config class is your personal guide to navigating the world of XML configuration
 * files. It’s like a translator, adeptly converting XML data into a language your PHP code can
 * understand and utilize.
 * 
 * This class is designed with simplicity and efficiency in mind. Upon instantiation, it immediately
 * gets to work, reading an XML file and transforming it into an associative array. This array then
 * serves as a treasure map, leading you directly to the configuration attributes you seek.
 * 
 * But the Config class isn’t just about reading data; it’s also about accessibility. With its get()
 * method, retrieving the value of a configuration attribute is as easy as calling a friend. Simply
 * provide the name of the attribute, and get() will return its value.
 * 
 * In essence, the Config class is a bridge, connecting your PHP code with the valuable data stored
 * in XML configuration files. It’s a testament to the power of object-oriented programming,
 * encapsulating complex processes within easy-to-use methods. So why wait? Let the Config class guide
 * you through your XML configuration files today!
 * ---------------------------------------------------------------------------------------------------
 * Author:       Patrik Eigenmann
 * eMail:        p.eigenmann@gmx.net
 * ---------------------------------------------------------------------------------------------------
 * Tue	2023-12-26	File created.													    Version: 00.01
 * ***************************************************************************************************/

/**
 * Class Config
 *
 * This class provides methods for reading configuration attributes from an XML file.
 *
 * The class includes one public method:
 * - get($attribute): Returns the value of a configuration attribute.
 */
class Config {
    private $config;

    /**
     * Config constructor.
     *
     * Reads the XML file and converts it to an associative array.
     */
    public function __construct() {
        $xml = simplexml_load_file('config.xml');  // Replace with actual XML file path
        $json = json_encode($xml);
        $this->config = json_decode($json, true);
    }

    /**
     * Get the value of a configuration attribute
     *
     * @param string $attribute The attribute to get
     * @return mixed The attribute value
     */
    public function get($attribute) {
        return $this->config[$attribute];
    }
}

$config = new Config();
echo "Firstname: " . $config->get('param1') . "\n";
echo "Lastname : " . $config->get('param2') . "\n";