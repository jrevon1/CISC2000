 /* 
 * Rationalclass.cpp
 * Author: Jordan Revon
 * Last modified on: 11/2/2020
 */

#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

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

	// input - Member function that sets the invoking object's values according to user input.
	void input();

	// output - Member function that displays invoking object's values.
  // in the standard output, styled as 'numerator/denominator'.
	void output() const;

	// Accessor function for numerator.
  // @returns a numerator value
  int get_numerator() const { return numerator;}
	
	// Accessor function for denominator.
  // @returns a denominator value
  int get_denominator() const { return denominator;}

	// Add - Adds two rational numbers together.
  // @param const rational& op1 is an object of the rational class with a numerator and denominator 
  // @param const rational& op2 is an object of the rational class with a numerator and denominator
  // @returns void
  void Add(rational& op1, const rational op2);


	// Subtract -  Subtracts a rational number from another rational number.
  // @param const rational& op1 is an object of the rational class with a numerator and denominator 
  // @param const rational& op2 is an object of the rational class with a numerator and denominator
  // @returns void
  void Subtract(rational& op1, const rational op2);


	// Multply - Multiplies two rational numbers together.
  // @param const rational& op1 is an object of the rational class with a numerator and denominator 
  // @param const rational& op2 is an object of the rational class with a numerator and denominator
  // @returns void
  void Multiply(rational& op1, const rational op2);


	// Divide - Divides a rational number by a second rational number.
  // @param const rational& op1 is an object of the rational class with a numerator and denominator 
  // @param const rational& op2 is an object of the rational class with a numerator and denominator
  // @returns void
  void Divide(rational& op1, const rational op2);


private:
	// Private data member declarations
  int numerator;
  int denominator;
};


int main()
{
  // Declare character 'oper' to store user input later.
	char oper;
	// Declare rational objects for operand1 'result' and operand2 'op2'.
  rational result, op2;
  // Prompt user to enter first rational number.
	cout << "Enter op1 (in the format of p/q): ";
	// Invoke the input function to read the first operand into 'result'.
  result.input();
  // Do-while loop to handle operations.
	do {
    // Prompt user to enter an value for 'oper'.
		cout << "\nEnter operator [+, -, /, *, =, c(lear), a(ccessors), q(uit)]: ";
    // Read the operator value into 'oper'.
    cin >> oper;

    // Multiway if-statements to handle operations
    // If 'oper' is 'c',
    if(oper == 'c')
    {
      // Prompt user to enter a new value for the first operand and store it.
      cout << "\nEnter op1 (in the format of p/q): ";
      result.input();
    }
		
    // If 'oper' is 'c',
    else if(oper == 'a')
    {
      // Output the numerator and then output the denominator.
      cout << "\nresult's numerator is: " << result.get_numerator() << endl;
      cout << "result's denominator is: " << result.get_denominator();
    }

		// If 'oper' is '+',
		else if(oper == '+')
    {
      // Prompt user to enter a value for the second operand.
      cout << "\nEnter op2 (in the format of p/q): ";
      // Call the input() function to store the second operand.
      op2.input();
      // Add 'result' and 'op2'.
      result.Add(result, op2);
    }

    // If 'oper' is '-',
    else if(oper == '-')
    {
      // Prompt user to enter a value for the second operand.
      cout << "\nEnter op2 (in the format of p/q): ";
      // Call the input() function to store the second operand.
      op2.input();
      // Subtract 'op2' from 'result'.
      result.Subtract(result, op2);
    }

    // If 'oper' is '*',
    else if(oper == '*')
    {
      // Prompt user to enter a value for the second operand.
      cout << "\nEnter op2 (in the format of p/q): ";
      // Call the input() function to store the second operand.
      op2.input();
      // Multiply 'result' and 'op2'.
      result.Multiply(result, op2);
    }

    // If 'oper' is '/',
    else if(oper == '/')
    {
      // Prompt user to enter a value for the second operand.
			cout << "\nEnter op2 (in the format of p/q): ";
      // Call the input() function to store the second operand.
      op2.input();
      // Divide 'result' by 'op2'.
      result.Divide(result, op2);
		}

    // If 'oper' is '=',
    else if(oper == '=')
    {
      cout << "result = "; 
      // Call the output() function to display the current 'result' as numerator/denominator.
      result.output();
    }
	}
  // If the user enters 'q' for 'oper', leave the do-while loop.
  while (oper != 'q');
	return 0;
}


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

// "input" member function implementation.
// Member function that sets the invoking object's values according to user input.
// precondition: an initialized object of the rational class.
// postcondition: an object of the rational class with potentially a new numerator and/or denominator.
void rational::input()
{
  // Declare character to separate user inputs.
  char slash;
  // Read in a value to store as a numerator, then a slash character, then read in a value to store as a denominator.
  cin >> numerator >> slash >> denominator;
  // If the user enters a value of '0' or less for the denominator,
  if(denominator <= 0)
  {
    // Display a mesasage that the denominator cannot be set to '0'.
    cout << "Cannot set denominator to 0. Denominator set to 1" << endl;
    // And set the denominator to '1'.
    denominator = 1;
  }
}

// "output" member function implementation.
// Member function that displays invoking object's values, styled as 'numerator/denominator'.
// precondition: an initialized object of the rational class.
// postcondition: outputs the invoking object's numerator value, a slash character, then the invoking object's denominator value
void rational::output() const
{
  cout << numerator << '/' << denominator;
}

// "Add" member function implementation.
// Member function that adds two rational class objects together.
// precondition: two initialized objects of the rational class.
// postcondition: invoking object's numerator and denominator are changed by reference.
void rational::Add(rational& op1, const rational op2)
{
  // Invoking object's numerator is set to numerator1*denominator2, plus numerator2+denominator1.
  numerator = op1.numerator*op2.denominator + op2.numerator*op1.denominator;

  // Invoking object's denominator is set to denominator1*denominator2.
  denominator = op1.denominator*op2.denominator;
}

// "Subtract" member function implementation.
// Member function that subtracts one rational class object from another.
// precondition: two initialized objects of the rational class.
// postcondition: invoking object's numerator and denominator are changed by reference.
void rational::Subtract(rational& op1, const rational op2)
{
  // Invoking object's numerator is set to numerator1*denominator2, minus numerator2+denominator1.
  numerator = op1.numerator*op2.denominator - op2.numerator*op1.denominator;

  // Invoking object's denominator is set to denominator1*denominator2.
  denominator = op1.denominator*op2.denominator;
}

// "Multiply" member function implementation.
// Member function that multiplies two rational class objects together.
// precondition: two initialized objects of the rational class.
// postcondition: invoking object's numerator and denominator are changed by reference.
void rational::Multiply(rational& op1, const rational op2)
{
  // Invoking object's numerator is set to numerator1*numerator2.
  numerator = op1.numerator*op2.numerator;

  // Invoking object's denominator is set to denominator1*denominator2.
  denominator = op1.denominator*op2.denominator; 
}

// "Divide" member function implementation.
// Member function that divides one rational class object by another.
// precondition: two initialized objects of the rational class.
// postcondition: invoking object's numerator and denominator are changed by reference.
void rational::Divide(rational& op1, const rational op2)
{
  // Invoking object's numerator is set to numerator1*denominator2.
  numerator = op1.numerator*op2.denominator;

  // Invoking object's denominator is set to denominator1*numerator2.
  denominator = op1.denominator*op2.numerator;
}
