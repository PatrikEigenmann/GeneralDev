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
 * ---------------------------------------------------------------------------------------------------------------
 * To Do's:
 * ***************************************************************************************************************/
#ifndef CVERSION_H
#define CVERSION_H

#include <stdio.h>

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

#endif