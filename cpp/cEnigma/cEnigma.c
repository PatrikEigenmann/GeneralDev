/* ***********************************************************************************************
 * cEnigma.c - This c console application is a very simplified emulation of the Enigma decypher
 * device used by the Nazis in World War II. The Enigma decypher machine was developed and used in
 * the early to mid-20th century to protect commercial, diplomatic, and military communication. It
 * was employed extensively by Nazi Germany during World War II, across all branches of the German
 * military. The machine was considered so secure that it was used to encipher the most top-secret
 * messages.
 *
 * The Enigma machine has an electromechanical rotor mechanism that scrambles the 26 letters of the
 * alphabet. In typical use, one person enters text on the Enigma’s keyboard and another person
 * writes down which of the 26 lights above the keyboard illuminated at each key press. If plain
 * text is entered, the illuminated letters are the ciphertext. Entering ciphertext transforms it
 * back into readable plaintext. The rotor mechanism changes the electrical connections between the
 * keys and the lights with each keypress.
 *
 * The security of the system depends on machine settings that were generally changed daily, based
 * on secret key lists distributed in advance, and on other settings that were changed for each
 * message. The receiving station would have to know and use the exact settings employed by the
 * transmitting station to successfully decrypt a message.
 *
 * While the Enigma machine was complex and provided a high level of security, it was not
 * unbreakable. The code was first broken by the Poles, under the leadership of mathematician
 * Marian Rejewski, in the early 1930s2. Later, during the war, the British set up a secret
 * code-breaking group known as Ultra, under mathematician Alan M. Turing. The intelligence gained
 * from decrypting Enigma-enciphered messages contributed significantly to the Allied victories in
 * WWII.
 *
 * In this version of the program, the first command line argument is used to determine whether
 * to encode or decode the input file. The second argument is the base name of the input and
 * output files. If the operation is encoding, the program reads from a .txt file and writes to
 * a .enc file. If the operation is decoding, the program reads from a .enc file and writes to
 * a .txt file.
 *
 * Compile instructions:
 * For Windows  -> gcc cEnigma.c ..\mylibs\cVersion.o ..\mylibs\cManPage.o -o cEnigma.exe
 * For MacOS    -> clang cEnigma.c ..\mylibs\cVersion.o ..\mylibs\cManPage.o -o cEnigma.bin
 * ***********************************************************************************************
 * Author:      Patrik Eigenmann
 * eMail:       p.eigenmann@gmx.net
 * -----------------------------------------------------------------------------------------------
 * Version Control:
 * Wed 2023-06-07 File created.                                                     Version: 00.01
 * Thu 2023-06-08 Outsourced encryption.                                            Version: 00.02
 * Wed 2024-02-07 Complete overhaul, with implementation of external files.         Version: 00.03
 * Wed 2024-02-07 Help file man pages style implemented.                            Version: 00.04
 * Wed 2024-02-07 Cleaned up the code and comments.                                 Version: 00.05
 * Mon 2024-02-12 Version control implemented.                                      Version: 00.06
 * Mon 2024-02-12 Man page help made scrollable.                                    Version: 00.07
 * Mon 2024-11-05 cManPage.h implemented. Updates and Bugfixes.                     Version: 00.08
 * Thu 2024-11-21 Updated create_manpage("cEnigma", mp.manpage, v.major, v.minor);  Version: 00.09
 * -----------------------------------------------------------------------------------------------
 * To Do's:
 * ***********************************************************************************************/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#include "..\mylibs\cVersion.h"
#include "..\mylibs\cManPage.h"

// Size of the alphabet
#define ALPHABET_SIZE 26

/* -----------------------------------------------------------------------------------------------
 * rotate - Rotate the rotors by one position. The rotors, also known as cipher wheels, are a
 * crucial part of the Enigma machine, a cipher device used extensively during World War II1.
 *
 * Each Enigma machine came with a set of rotors that could be interchanged. The rotors had 26
 * contacts on one side and 26 pins on the other. When placed into the machine on a shaft, the
 * pins of one rotor connected to the contacts of the next.
 *
 * The rotors were responsible for scrambling the 26 letters of the alphabet. Each rotor was wired
 * differently, meaning each rotor contained a different cipher3. The wartime Enigma machines
 * could choose from a stock of five rotors, and any three could be used in any order.
 *
 * The position of each rotor, the ring setting, and its internal wiring all played a role in how
 * the machine encrypted messages. As the rotors rotated, the electrical connections between the
 * keys and the lights changed with each keypress. This rotation and the resulting changes in
 * connections created a vast number of possible scramblings, making the Enigma machine a powerful
 * tool for encryption.
 *
 * @param char* rotor
 * -----------------------------------------------------------------------------------------------*/
void rotate(char* rotor) {
    char first = rotor[0];
    for (int i = 0; i < ALPHABET_SIZE - 1; i++) {
        rotor[i] = rotor[i + 1];
    }
    rotor[ALPHABET_SIZE - 1] = first;
}

/* ------------------------------------------------------------------------------------------------
 * encode - The encode function is a key element in simulating the Enigma machine’s encryption
 * process. It takes an input character and a rotor configuration, and encodes the character based
 * on the rotor’s settings. This function simplifies the complex mechanism of the Enigma machine
 * into a digestible piece of code. If the character is an alphabetic letter, it’s transformed
 * using the rotor configuration. Non-alphabetic characters are returned as is. This function is a
 * testament to the power of programming in simulating real-world processes, providing a glimpse
 * into the workings of one of history’s most famous encryption devices.
 *
 * @param char ch
 * @param char* rotor
 *
 * @return char ch
 * ------------------------------------------------------------------------------------------------*/
char encode(char ch, char* rotor) {
    if(isalpha(ch)) {
        ch = toupper(ch); // Convert to uppercase
        return rotor[ch - 'A'];
    } else {
        return ch; // Return non-alphabet characters as is
    }
}

/* -------------------------------------------------------------------------------------------------
 * decode - The decode function is the counterpart to the encode function, reversing the encoding
 * process. It takes an input character and a rotor configuration, and if the character is an
 * alphabetic letter, it finds the original character before it was encoded by the rotor. This is
 * done by searching through the rotor until it finds the encoded character, then returns the
 * character that corresponds to that position in the alphabet. If the character is not an alphabetic
 * letter, it is returned as is. This function is another key piece in simulating the Enigma
 * machine’s process, turning encoded messages back into their original form.
 * 
 * @param char ch
 * @param char* rotor
 *
 * @return char ch
 * -------------------------------------------------------------------------------------------------*/
char decode(char ch, char* rotor) {
    if(isalpha(ch)) {
        ch = toupper(ch); // Convert to uppercase
        for(int i = 0; i < ALPHABET_SIZE; i++) {
            if(rotor[i] == ch) {
                return 'A' + i;
            }
        }
    }
    return ch; // Return non-alphabet characters as is
}

/* ------------------------------------------------------------------------------------------------
 * print_help - This function is a helper function that prints out the help message for the cEnigma
 * program in man pages style. This message includes but is not limited to:
 *
 * NAME: A brief description of the program.
 *
 * SYNOPSIS: How to use the program, including the command-line arguments it accepts.
 *
 * DESCRIPTION: Detailed information about what the program does and how to use it. It explains the
 *              -e and -d options for encoding and decoding a text file, respectively.
 *
 *              /?, -?, -h, -H, -help: These options display the help message.
 *
 * AUTHOR: Information about the author of the program.
 *
 * COPYRIGHT: The copyright notice, license information, and a disclaimer.
 *
 * This function does not take any arguments and does not return any values. It simply prints the
 * help message to the standard output. It’s typically called when the user passes a help flag
 * (-h, -H, -help, -?, or /?) or when the program is used incorrectly. It helps users understand
 * how to use the program correctly.
 * ------------------------------------------------------------------------------------------------*/
void print_help() {
    
    // Version control implemented
    Version v = create_version(0, 9);
    
    // The buffer is needed to write
    // the correct formated version number.
    char buffer[6];
    
    // Format the buffer with the
    // correct version number.
    to_string(v, buffer);

    char *manpage = NULL;

    // Write the ManPage style help file.
    append_format(&manpage, "NAME\n");
    append_format(&manpage, "      cEnigma Version: %s\n", buffer);
    append_format(&manpage, "      The Enigma machine was an electromechanical cypher in the World War II used by Nazi Germany.\n");
    append_format(&manpage, "      The rotor mechanism of the Enigma machine scrambled the all the 26 letters of the alphabet.\n");
    append_format(&manpage, "      In typical use, one person enters text on the Enigma’s keyboard and another person writes down\n");
    append_format(&manpage, "      which of the 26 lights above the keyboard illuminated at each key press. If plain text is entered,\n");
    append_format(&manpage, "      the illuminated letters are the ciphertext. Entering ciphertext transforms it back into readable \n");
    append_format(&manpage, "      plaintext. The rotor mechanism changes the electrical connections between the keys and the lights\n");
    append_format(&manpage, "      with each keypress.\n");
    append_format(&manpage, "\n");
    append_format(&manpage, "SYNOPSIS\n");
    append_format(&manpage, "      cEnigma -e/-d <textfile without ending>\n");
    append_format(&manpage, "\n");
    append_format(&manpage, "DESCRIPTION\n");
    append_format(&manpage, "      This program encodes (-e) or decodes (-d) a text\n");
    append_format(&manpage, "      file using a simplified Enigma machine emulation.\n");
    append_format(&manpage, "\n");
    append_format(&manpage, "      -e <textfile without ending>\n");
    append_format(&manpage, "            The -e option plus <file without ending> like input\n");
    append_format(&manpage, "            will search for a file input.txt in the active folder,\n");
    append_format(&manpage, "            and encode the plaintext in it. and save the text into\n");
    append_format(&manpage, "            the an encoding file with the same name. As example input.enc.\n");
    append_format(&manpage, "\n");
    append_format(&manpage, "      -d <encoding file without ending>\n");
    append_format(&manpage, "            The -d option plus <file without ending> like input\n");
    append_format(&manpage, "            will search for a file input.enc in the active folder,\n");
    append_format(&manpage, "            and decode the cyphered text in it, and save the plain text\n");
    append_format(&manpage, "            into the a text file with the same name. As example input.txt.\n");
    append_format(&manpage, "\n");
    append_format(&manpage, "      /?, -?, -h, -H, -help\n");
    append_format(&manpage, "            Display this help message.\n");
    append_format(&manpage, "\n");
    append_format(&manpage, "AUTHOR\n");
    append_format(&manpage, "      Patrik Eigenmann (p.eigenmann@gmx.net).\n");
    append_format(&manpage, "\n");
    append_format(&manpage, "COPYRIGHT\n");
    append_format(&manpage, "      Copyright 2024 Free Software Foundation, Inc. License GPLv3+:\n");
    append_format(&manpage, "      GNU GPL version 3 or later <https://gnu.org/licenses/gpl.html>.\n");
    append_format(&manpage, "      This is free software: you are free to change and redistribute it.\n");
    append_format(&manpage, "      There is NO WARRANTY, to the extent permitted by law.\n");

    // Create the manpage in the file /temp/cEnigma.man
    create_manpage("cEnigma", manpage, v.major, v.minor);

    // Free up the memory.
    free(manpage);
}

/* ---------------------------------------------------------------------------------------------------------
 * main - The main function is like the front door of the cEnigma program—it’s where everything starts.
 * When you run the program, it first checks if you’ve given it the right instructions. If not, it shows you
 * a help message to guide you on how to use it properly.
 *
 * If you’ve given the correct instructions, it then decides whether you want to encode (convert plain text
 * into secret code) or decode (convert secret code back into plain text) based on your input.
 *
 * So, in a nutshell, the main function is the conductor of the cEnigma program, orchestrating the whole
 * process from start to finish.
 *
 * @param int argc
 * @param char *argv[]
 *
 * @return 0 or 1
 * --------------------------------------------------------------------------------------------------------*/
int main(int argc, char *argv[]) {

    // Check if the correct number of arguments are provided
    if(argc != 3 || strcmp(argv[1], "/?") == 0
        || strcmp(argv[1], "-?") == 0 || strcmp(argv[1], "-h") == 0
        || strcmp(argv[1], "-H") == 0 || strcmp(argv[1], "-help") == 0) {
        print_help();
        return 1;
    }

    // Check if the operation is encode or decode
    int encode_flag = strcmp(argv[1], "-e") == 0;

    // Open the input file
    char inputFile[100];
    strcpy(inputFile, argv[2]);
    if(encode_flag) {
        strcat(inputFile, ".txt");
    } else {
        strcat(inputFile, ".enc");
    }
    
    FILE *input = fopen(inputFile, "r");
    if(input == NULL) {
        printf("Could not open input file %s\n", inputFile);
        return 1;
    }

    // Open the output file
    char outputFile[100];
    strcpy(outputFile, argv[2]);
    if(encode_flag) {
        strcat(outputFile, ".enc");
    } else {
        strcat(outputFile, ".txt");
    }
    
    FILE *output = fopen(outputFile, "w");
    if(output == NULL) {
        printf("Could not open output file %s\n", outputFile);
        return 1;
    }

    // Define the rotor (initially in alphabetical order)
    char rotor[ALPHABET_SIZE] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    // Read the input file character by character
    char ch;
    while((ch = fgetc(input)) != EOF) {
        // Encode or decode the character
        char processed = encode_flag ? encode(ch, rotor) : decode(ch, rotor);
        // Write the processed character to the output file
        fputc(processed, output);
        // Rotate the rotor
        rotate(rotor);
    }

    // Close the files
    fclose(input);
    fclose(output);

    printf("%s complete. Check the output file for the %s message.\n", encode_flag ? "Encoding" : "Decoding", encode_flag ? "encoded" : "decoded");

    return 0;
}