#!/bin/php
<?php
/* ***************************************************************************************************
 * <php script> - <description>
 * ---------------------------------------------------------------------------------------------------
 * Author:       Patrik Eigenmann
 * eMail:        p.eigenmann@gmx.net
 * ---------------------------------------------------------------------------------------------------
 * <day>	<date>		File created.													Version: 00.01
 * ***************************************************************************************************/

 class MadLibs {
    private $story;
    private $words;

    public function __construct($story, $words) {
        $this->story = $story;
        $this->words = $words;
    }

    public function generateStory() {
        $result = $this->story;
        foreach ($this->words as $placeholder => $word) {
            $result = str_replace("{" . $placeholder . "}", $word, $result);
        }
        return $result;
    }
}

// Usage
$story = "Today, I went to the {place}. I saw a {animal} jumping around.";
$words = array("place" => "zoo", "animal" => "monkey");

$madLibs = new MadLibs($story, $words);
echo $madLibs->generateStory();  // Output: Today, I went to the zoo. I saw a monkey jumping around.

?>
