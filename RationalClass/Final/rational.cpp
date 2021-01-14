 /* 
 * rational.cpp
 * Author: Jordan Revon
 * Last modified on: 12/3/2020
 */

#include <iostream>
#include <string>
#include <stdlib.h>
#include "rational.h"
using namespace std;


// Default constructor implementation.
// Initializes numerator to 0 and denominator to 1.
rational::rational()
{
    numerator = 0;
    denominator = 1;
}

// Constructor that initializes a whole number represented as a fraction.
// Denominator is set to 1 by default, representing a whole number.
rational::rational(int n)
{
    numerator = n;
    denominator = 1;
}

// Constructor that initializes the rational number to a chosen numerator and a chosen denominator value.
// Performs a check to see if the given denominator is 0; if so, it sets the denominator to 1 and
//  informs the user. Otherwise, the denominator is set to the given value.
rational::rational(int n, int d)
{
  
    numerator = n;
    if(denominator <= 0)
    {
        cout << "Cannot set denominator to 0. Denominator set to 1" << endl;
        denominator = 1;
    }
    else
    {
        denominator = d;
    }
}

// "set" member function implementation.
// Member function that sets the invoking object's numerator and denominator
// precondition: an initialized object of the rational class.
// postcondition: an object of the rational class with potentially a new numerator and denominator.
void rational::set(int a_numerator, int a_denominator)
{
    numerator = a_numerator;
    denominator = a_denominator;
}

// "Add" member function implementation.
// Member function that adds two rational class objects together.
// precondition: two initialized objects of the rational class.
// postcondition: invoking object's numerator and denominator are changed by reference.
rational operator + (const rational& op1, const rational& op2)
{
    // Declare temporary rational object
    rational temp;
    // Invoking temporary object's numerator is set to numerator1*denominator2, plus numerator2+denominator1.
    temp.numerator = op1.numerator*op2.denominator + op2.numerator*op1.denominator;

      // Invoking temporary object's denominator is set to denominator1*denominator2.
    temp.denominator = op1.denominator*op2.denominator;
    // Call simplify() function
    temp.simplify();
    return temp;
}

// "Subtract" member function implementation.
// Member function that subtracts one rational class object from another.
// precondition: two initialized objects of the rational class.
// postcondition: invoking object's numerator and denominator are changed by reference.
rational operator - (const rational& op1, const rational& op2)
{
    // Declare temporary rational object
    rational temp;
    // Temporary invoking object's numerator is set to numerator1*denominator2, minus numerator2+denominator1.
    temp.numerator = op1.numerator*op2.denominator - op2.numerator*op1.denominator;
    // Temporary invoking object's denominator is set to denominator1*denominator2.
    temp.denominator = op1.denominator*op2.denominator;
    // Call simplify() function
    temp.simplify();
    return temp;
}

// "Multiply" member function implementation.
// Member function that multiplies two rational class objects together.
// precondition: two initialized objects of the rational class.
// postcondition: invoking object's numerator and denominator are changed by reference.
rational operator * (const rational& op1, const rational& op2)
{
    // Declare temporary rational object
    rational temp;
    // Temporary invoking object's numerator is set to numerator1*numerator2.
    temp.numerator = op1.numerator*op2.numerator;
    // Temporary invoking object's denominator is set to denominator1*denominator2.
    temp.denominator = op1.denominator*op2.denominator;  
    // Call simplify() function
    temp.simplify();
    return temp;
}

// "Divide" member function implementation.
// Member function that divides one rational class object by another.
// precondition: two initialized objects of the rational class.
// postcondition: invoking object's numerator and denominator are changed by reference.
rational operator / (const rational& op1, const rational& op2)
{
    rational temp;
    // Invoking object's numerator is set to numerator1*denominator2.
    temp.numerator = op1.numerator*op2.denominator;
    // Invoking object's denominator is set to denominator1*numerator2.
    temp.denominator = op1.denominator*op2.numerator;
    // Call simplify() function
    temp.simplify();
    return temp;
}

// "Comparison" member function implementation
// Member function that tests whether two rational objects are the same or not
// precontidion: two initialized objects of the rational class.
// postcondition: a value of "true" or a value of "false"
bool operator == (const rational& op1, const rational& op2)
{
    return (op1.numerator*op2.denominator) == op2.numerator*op1.denominator;
}

// "Less than" member function implementation
// Member function that tests whether one rational object is less than the other
// precontidion: two initialized objects of the rational class.
// postcondition: a value of "true" or a value of "false"
bool operator < (const rational& op1, const rational& op2)
{
    return (op1.numerator*op2.denominator) < op2.numerator*op1.denominator;
}

// "Greater than" member function implementation
// Member function that tests whether one rational object is greater than the other
// precontidion: two initialized objects of the rational class.
// postcondition: a value of "true" or a value of "false"
bool operator > (const rational& op1, const rational& op2)
{
    return (op1.numerator*op2.denominator) > op2.numerator*op1.denominator ;
}

// Overloaded extraction operator
// precondition: an initialized object of the rational class
// postconditon: displays the invoking object's numerator, a slash character, then the invoking object's denominator
ostream& operator << (ostream& outs, const rational& op1)
{
    outs << op1.numerator << "/" << op1.denominator;
    return outs;
}

// Overloaded insertion operator
// precondition: an initialized object of the rational class
// postconditon: an object of the rational class with a numerator and a denominator
istream& operator >> (istream& ins, rational& op1)
{
    // Declare variable to store the slash input
    char slash;
    // Read in the numerator, the slash, and the denominator
    ins >> op1.numerator >> slash >> op1.denominator;
    // If the denominator is set to '0', which is not a legal rational
    if(op1.denominator == 0)
    {
        // Display a mesasage that the denominator cannot be set to '0'.
        cout << "Cannot set denominator to 0. Denominator set to 1" << endl;
        // And set the denominator to '1'.
        op1.denominator = 1;
    }
    return ins;
}

// "Simplify" member function implementation
// Member function that reduces a fraction to its greatest common divisor
// precondition: an initialized object of the rational class
// postcondition: an object of the rational class with a potentially smaller numerator and/or denominator
void rational::simplify()
{
    // Declare variables to store the greatest common divisor
    int gcd = rational::gcd(numerator, denominator);
    // Divide the numerator by the gcd and store it
    numerator /= gcd;
    // Divide the denominator by the gcd and store it
    denominator /= gcd;
}

// "Greatest Common Divisor" member function implementation
// Member function that determines if a numerator and denominator have a common divisor
// precondition: two integers
// postcondition: a common number to divide the two integers by, or either one of the integers which is already the the common divisor
int rational::gcd (int a, int b)
{
    while (a!=0 && b!=0)
    {
        a = a % b;
        if (a!=0)
        b = b % a;
    }
    if (a==0)
        return b;
    if (b==0)
        return a;
    return 1;
}
