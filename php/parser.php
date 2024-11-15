#!/bin/php
<?php
/* ***************************************************************************************************
 * parser.php - Imagine having a personal assistant who could read a letter for you, understand the
 * placeholders in it, and fill them in with the exact details you provide. That’s exactly what the
 * TemplateParser class does!
 * 
 * This class is like a master key to your templates. It opens the door to any template file, reads it,
 * and understands the placeholders in it. But it doesn’t stop there. It goes one step further and
 * replaces those placeholders with the values you provide.
 * 
 * The TemplateParser class is designed with simplicity and efficiency in mind. It has a parse()
 * method that does all the heavy lifting. You just need to provide the path to your template file
 * and an array of placeholder-value pairs, and the parse() method takes care of the rest.

In essence, the TemplateParser class is a powerful, easy-to-use tool that takes the complexity out of template parsing. It’s a testament to the power of well-structured, object-oriented programming in PHP. Whether you’re building a web application, a content management system, or just need to personalize your emails, the TemplateParser class is ready to help!
 * ---------------------------------------------------------------------------------------------------
 * Author:       Patrik Eigenmann
 * eMail:        p.eigenmann@gmx.net
 * ---------------------------------------------------------------------------------------------------
 * <day>	<date>		File created.													Version: 00.01
 * ***************************************************************************************************/

/**
 * Class TemplateParser
 *
 * This class provides a method for parsing templates.
 * It reads a template from a file and replaces placeholders in the template with provided values.
 *
 * The class includes one public method:
 * - parse($templateFile, $values): Returns the parsed template string.
 */
class TemplateParser {
    /**
     * Parse a template file
     *
     * @param string $templateFile The path to the template file
     * @param array $values An associative array of placeholder-value pairs
     * @return string The parsed template string
     */
    public function parse($templateFile, $values) {
        $template = file_get_contents($templateFile);
        foreach ($values as $key => $value) {
            $template = str_replace('{' . $key . '}', $value, $template);
        }
        return $template;
    }
}

$parser = new TemplateParser();
$templateFile = 'template.txt';  // Replace with the path to your actual template file
$values = ['name' => 'John', 'day' => 'Monday'];
echo $parser->parse($templateFile, $values);  // Outputs: Parsed template string
?>