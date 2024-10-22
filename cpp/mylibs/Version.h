/* ***************************************************************************************************************
 * Version.h - The Version class is a utility class designed to encapsulate versioning information for software
 * components. It provides a standardized way to represent and manipulate version numbers.
 * 
 * The class has two private member variables, major_ and minor_, which represent the major and minor components
 * of the version number respectively. The major version number typically changes with significant updates or
 * overhauls, while the minor version number changes with smaller updates or bug fixes.
 * 
 * The Version class provides a constructor that takes two integers representing the major and minor version
 * numbers. This constructor initializes the major_ and minor_ member variables with these values.
 * 
 * The class also provides getter methods getMajor() and getMinor() to access the major and minor version numbers.
 * 
 * The toString() method returns a string representation of the version number in the format MM.mm, where MM is
 * the major version number and mm is the minor version number. Both are represented as two-digit numbers, with
 * leading zeros if necessary.
 * 
 * By using the Version class, developers can easily manage versioning information for their software components,
 * and ensure that this information is represented in a consistent and standardized format. This can be
 * particularly useful in larger software projects with many components, each potentially having its own
 * version number.
 * ---------------------------------------------------------------------------------------------------------------
 * Author:       Patrik Eigenmann
 * eMail:        p.eigenmann@gmx.net
 * ---------------------------------------------------------------------------------------------------------------
 * Sun 2024-02-11 File created.                                                                     Version: 00.01
 * ***************************************************************************************************************/

#ifndef VERSION_H
#define VERSION_H

#include <string>
#include <sstream>
#include <iomanip>

// ---------------------------------------------------------------------------------------------------------------
// The Version class serves as a blueprint for creating objects that represent software versioning information.
// It encapsulates the concept of a software version, which is typically composed of major and minor components.
// ---------------------------------------------------------------------------------------------------------------
class Version {
public:
    
    // Construction of the class with major and minor build numbers as parameters.
    Version(int major, int minor)
        : major_(major), minor_(minor) {}

    // Getters for the private members of the class.
    int getMajor() const { return major_; }    
    int getMinor() const { return minor_; }

    // The toString methode which returns a string formatted like MM.mm as version number.
    std::string toString() const {
        std::ostringstream oss;
        oss << std::setfill('0') << std::setw(2) << major_ << '.' << std::setw(2) << minor_;
        return oss.str();
    }

private:
    int major_;                                 // Major build
    int minor_;                                 // Minor build
};

#endif