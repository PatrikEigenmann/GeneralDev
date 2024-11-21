/* ***************************************************************************************************************
 * cVersion.h - Let’s think of the cVersion.h file as a blueprint for a machine that makes labels for different
 * versions of a product.
 * 
 * Imagine you’re a manufacturer who produces different versions of a product. Each version of the product has
 * two parts to its version number: a major number and a minor number. The major number changes when you make
 * significant updates or improvements to the product, like adding a new feature. The minor number changes when you
 * make smaller updates or fixes, like correcting a small bug.
 * 
 * Now, you need a machine that can create labels for each version of your smartphone. That’s where the cVersion.h
 * file comes in. It’s like a blueprint for building that machine.
 * 
 * The blueprint specifies that the machine (or in technical terms, the Version struct) needs to keep track of two
 * numbers: the major and minor version numbers. It also specifies how to build the machine (the create_version
 * function), how to check what the major and minor numbers are (the get_major and get_minor functions), and how
 * to print out a label with the version number (the to_string function).
 * 
 * So, in simple terms, the cVersion.h file is a plan for creating a machine that helps keep track of and label
 * different versions of a product. It ensures that each version has a unique label and that the labels are always
 * formatted in the same way, making it easy to tell which version of the product you have.
 * ---------------------------------------------------------------------------------------------------------------
 * Author:       Patrik Eigenmann
 * eMail:        p.eigenmann@gmx.net
 * ---------------------------------------------------------------------------------------------------------------
 * Sun 2024-02-11 File created.                                                                     Version: 00.01
 * Sat 2024-10-26 #include <stdlib.h> removed.                                                      Version: 00.02
 * Thu 2024-11-21 int get_major & int get_minor removed due to not using these methods at all.      Version: 00.03
 * ***************************************************************************************************************/
#ifndef CVERSION_H
#define CVERSION_H

// ---------------------------------------------------------------------------------------------------------------
// This structure as a small box labeled “Version”. Inside this box, there are two compartments. One compartment
// is labeled “major”, and the other is labeled “minor”.
//
// These compartments can hold numbers. The number in the “major” compartment represents big changes or updates,
// like a new design or a significant feature. The number in the “minor” compartment represents small changes or
// updates, like a bug fix or a minor improvement.
//
// So, this “Version” box helps us keep track of both big and small updates in an organized way.
// ---------------------------------------------------------------------------------------------------------------
typedef struct {
    int major;                              // Major built
    int minor;                              // Minor built
} Version;

// ---------------------------------------------------------------------------------------------------------------
// The create_version function is a set of instructions that takes two numbers as input. These numbers represent
// the major and minor parts of a version number, respectively. The function then constructs a Version object
// using these two numbers. The major and minor numbers are stored within this Version object. Once this Version
// object is created, it is then returned by the function. This Version object can be used to represent and keep
// track of the version number of a software or a product. The major part of the version usually indicates
// significant changes or updates, while the minor part indicates smaller updates or bug fixes.
//
// @param int major - Major build number.
// @param int minor - Minor build number.
// ---------------------------------------------------------------------------------------------------------------
Version create_version(int major, int minor);

// ---------------------------------------------------------------------------------------------------------------
// The to_string function is like a translator for the Version object.
//
// When you call to_string(v, buffer) where v is a Version object and buffer is a space in memory to store a string,
// you’re essentially asking, “Can you translate your version number into a string format?”
//
// In response to this request, the Version object takes its major and minor version numbers, formats them into a
// string that looks like “MM.mm” (where MM is the major version number and mm is the minor version number), and then
// stores this string in the provided buffer.
//
// So, in simple terms, to_string is a way to convert the version number of a Version object into a string format.
// ---------------------------------------------------------------------------------------------------------------
void to_string(Version v, char* buffer);

#endif