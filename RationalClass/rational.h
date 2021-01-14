 /* 
 * rational.h
 * Author: Jordan Revon
 * Last modified on: 12/3/2020
 */

#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

#ifndef _RATIONAL_H
#define _RATIONAL_H

// rational Class Definitions
class rational
{
    public:
        // Default constructor declaration
        // Sets the rational number to 0 (i.e., numerator is 0, denominator is 1).
        rational();
        
        // Constructor that initializes a whole number represented as a fraction.
        // Initializes with a chosen numerator value and a default denominator value of '1'.
        rational(int n);
      
        // Constructor that initializes the rational number to a chosen numerator and a chosen denominator value.
        rational(int n, int d);
    
        // Accessor function for numerator.
        // @returns a numerator value
        int get_numerator() const { return numerator;}
    	
        // Accessor function for denominator.
        // @returns a denominator value
        int get_denominator() const { return denominator;}
    
        // Mutator function to set numerator and denominator
        void set(int a_numerator, int a_denominator);
    
        // Add - Adds two rational numbers together.
        // @param const rational& op1 is an object of the rational class with a numerator and denominator 
        // @param const rational& op2 is an object of the rational class with a numerator and denominator
        // @returns a rational with the sum
        friend rational operator + (const rational& op1, const rational& op2);
    
    
        // Subtract -  Subtracts a rational number from another rational number.
        // @param const rational& op1 is an object of the rational class with a numerator and denominator 
        // @param const rational& op2 is an object of the rational class with a numerator and denominator
        // @returns a rational with the difference
        friend rational operator - (const rational& op1, const rational& op2);
    
        // Multply - Multiplies two rational numbers together.
        // @param const rational& op1 is an object of the rational class with a numerator and denominator 
        // @param const rational& op2 is an object of the rational class with a numerator and denominator
        // @return a rational with the product
        friend rational operator * (const rational& op1, const rational& op2);
    
    
        // Divide - Divides a rational number by a second rational number.
        // @param const rational& op1 is an object of the rational class with a numerator and denominator 
        // @param const rational& op2 is an object of the rational class with a numerator and denominator
        // @return a rational with the quotient
        friend rational operator / (const rational& op1, const rational& op2);
    
        // Comparison - Tests to see if a rational number is equal to another
        // @param const rational& op1 is an object of the rational class with a numerator and denominator 
        // @param const rational& op2 is an object of the rational class with a numerator and denominator
        // @returns true if equal (compare cross product of n1*d2 == n2*d1) or false if not.
        friend bool operator == (const rational& op1, const rational& op2);
    
        // Less than - Tests to see if a rational number is less than another
        // @param const rational& op1 is an object of the rational class with a numerator and denominator 
        // @param const rational& op2 is an object of the rational class with a numerator and denominator
        // @return true if op1 < op2 (compare cross product of n1*d2 < n2*d1) or false if not. 
        friend bool operator < (const rational& op1, const rational& op2);
    
        // Greater than - Tests to see if a rational number is greater than another
        // @param const rational& op1 is an object of the rational class with a numerator and denominator 
        // @param const rational& op2 is an object of the rational class with a numerator and denominator
        // @return true if op1 > op2 (compare cross product of n1*d2 > n2*d1) or false if not. 
        friend bool operator > (const rational& op1, const rational& op2);
    
        // Overloaded extraction operator
        friend ostream& operator << (ostream& os, const rational& op1);
        // Overloaded insertion operator
        friend istream& operator >> (istream& is, rational& op1);
    
    private:
    	// Private data member declarations
        int numerator;
        int denominator;
        // simplify sets the invoking object to be a simplified rational
        void simplify();
        // gcd returns the greatest common denominator, used in simplify() above.
        int gcd(int a, int b);

};

#endif
