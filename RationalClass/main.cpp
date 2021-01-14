 /* 
 * Rationalclass2.cpp
 * Author: Jordan Revon
 * Last modified on: 12/3/2020
 */

#include <iostream>
#include <string>
#include <stdlib.h>
#include "rational.h"

using namespace std;


int main()
{
    // Declare character 'oper' to store user input later.
	char oper;
	// Declare rational objects for operand1 'result' and operand2 'op2'.
    rational result, op2;
    // Prompt user to enter first rational number, 'result'.
	cout << "Enter op1 (in the format of p/q): ";
	// Read in the numerator and denominator for 'result'.
    cin >> result;
    // Do-while loop to handle operations.
	do 
	{
        // Prompt user to enter an value for 'oper'.
        cout << "\nEnter operator [+, -, /, *, =, ?(==), <(less), >(greater), c(lear), a(ccessors), q(uit)]: ";
        // Read the operator value into 'oper'.
        cin >> oper;

        // Multiway if-statements to handle operations
        if(oper == '+' || oper == '-' || oper == '*' || oper == '/' || oper == '?' || oper == '<' || oper == '>')
        {
            // Prompt user to enter a value for the second operand.
            cout << "\nEnter op2 (in the format of p/q): ";
            // Read in the second operand.
            cin >> op2;

            // If 'oper' is '+',
		    if(oper == '+')
            {
                // Add 'result' and 'op2'.
                result = result + op2;
            }

            // If 'oper' is '-',
            else if(oper == '-')
            {
                // Subtract 'op2' from 'result'.
                result = result - op2;
            }

            // If 'oper' is '*',
            else if(oper == '*')
            {
                // Multiply 'result' and 'op2'.
                result = result * op2;
            }

            // If 'oper' is '/',
            else if(oper == '/')
            {
                // Divide 'result' by 'op2'.
                result = result / op2;
            }
      
            // If 'oper' is '?' (==),
            else if(oper == '?')
            {
                // Output an answer based on the result of the comparison
                cout << ((result == op2)? "Correct! Good job!" : "Oh no! Good try!") << endl;
            } 
            
            // If 'oper' is '<' (less than),
            else if(oper == '<')
            {
                // Output an answer based on the result of the comparison
                cout << ((result < op2) ? "True, great!" : "False, try again!") <<endl;
            }
            
            // If 'oper' is '>' (greater than),
            else if(oper == '>')
            {
                // Output an answer based on the result of the comparison
                cout << ((result > op2) ? "True, great!" : "False, try again!") << endl;
            }
        }

        // If 'oper' is '=',
        else if(oper == '=')
        {
            // Display the first rational, 'result'
            cout << "result = " << result;
        }
    
        // If 'oper' is 'c',
        else if(oper == 'c')
        {
            // Prompt user to enter a new value for the first operand and store it.
            cout << "\nEnter op1 (in the format of p/q): ";
            cin >> result;
        }
		
        // If 'oper' is 'a',
        else if(oper == 'a')
        {
            // Output the numerator and then output the denominator.
            cout << "\nresult's numerator is: " << result.get_numerator() << endl;
            cout << "result's denominator is: " << result.get_denominator();
        }

        if (cin.fail()) 
        {
            cout << "Invalid rational format!";
            cin.clear(); 
            cin.ignore();
        }   
    }
    // If the user enters 'q' for 'oper', leave the do-while loop.
    while (oper != 'q');
	
	return 0;
}
