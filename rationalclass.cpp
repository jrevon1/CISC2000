/*work in progress*/

#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

// don't forget to include variables for a TOTAL and RESULT
// op2.input()
// total.Add

//Please follow the order suggested below when working on this lab, always maintaining a compilable version of the code. Take an incremental approach. Write and test one function at a time!


//  Implement input function. which will read a rational number.
//  Implement Add, Subtract, Multiply, Divide functions like but remember that we have 
//    rational result as an accumulator for all operations. Call all functions like this 
//    result.Add(result, op1);
class rational
{
public:
	/* DONE: default constructor set the rational number to 0, (i.e., numerator is 0, denominator is 1) */
  rational();

	/* TODO: define input to set the invoking object's value from user input */
	void input();

	/* TODO: define output to display invoking object's value in the standard output, in the form of numerator/denominator */
	void output() const;

	/* DONE: declare the accessor to return the invoking object's numerator */
  int get_numerator() const { return numerator;}
	
	/* DONE: declare the accessor to return the invoking object's denominator */
  int get_denominator() const { return denominator;}

	/* TODO: declare Add to set the invoking object to be the sum of op1 and op2, use const & parameters */
  void Add(const rational& op1, const rational& op2);


	/* TODO: declare Subtract to set the invoking object to the difference of op1 and op2, use const & parameters */
  void Subtract(const rational& op1, const rational& op2);


	/* TODO: declare Multiply to set the invoking object to the product of op1 and op2, use const & parameters */
  void Multiply(const rational& op1, const rational& op2);


	/* TODO: declare Divide to set the invoking object to the Quotient of op1 and op2, use const & parameters */
  void Divide(const rational& op1, const rational& op2);


private:
	/* TODO: declare data members for rational object */
  int numerator;
  int denominator;

};


int main()
{
	char oper;
  rational result, op1;
	// TODO: declare rational objects for result and operand.

	cout << "Enter op1 (in the format of p/q): ";
	// TODO: Use your input function to read the first operand into result.
  op1.input();
  op1.output();
  

	// //Test rational class member function 
	// do {
	// 	cout << "\nEnter operator [+, -, /, *, =, c(lear), a(ccessors), q(uit)]: ";
	// 	// TODO: Read the operator into oper
  //   // c - read in a new value to start with i.e. re-enter op1's values
  //   // a - output numerator and output denominator

	// 	// TODO: Change the pseodocode below to test oper for binary operators
	// 	if (oper in "+,-,*,/") {
	// 		cout << "\nEnter op2 (in the format of p/q): ";
	// 		// TODO: Use your input function to read the operand into operand

	// 	}

	// 	// ToDo: Implement a switch or multiway if statement with one case for each option above where
	// 	// '+','*','/','-' inputs a rational op1 and calculates result.oper(result,op1)
	// 	// '=' outputs the current result,
	// 	// 'c' to clear current result, use input function to read first operand into result,
	// 	// 'a' to test accessors, 'q' to quit.

  //   if(oper == '+')
  //   {
  //     result.Add(result, op2);
  //   }


	// } while (oper != 'q');
	return 0;
}


// TODO: Definitions of all member functions declared above

// DONE: Default constructor sets numerator to 0 and denominator to 1
rational::rational()
{
  numerator = 0;
  denominator = 1;
}

void rational::input()
{
  char delim = '/';
  string inputString;
  getline(cin, inputString);
  // before delim = numerator;
  // after delim = denominator;



}

void rational::output() const
{
  cout << numerator << '/' << denominator;

}

//int rational::get_numerator() const
//{}

//int rational:: get_denominator() const
//{}



void rational::Add(const rational& op1, const rational& op2)
{
  // numerator = n1*d2 + n2+d1;
  // numerator = op1.numerator*op2.denominator + op2.numerator*op1.denominator;

  // denominator = d1*d2
  // denominator = op1.denominator*op2.denominator;

}

void rational::Subtract(const rational& op1, const rational& op2)
{
  // numerator = n1*d2 - n2+d1;
  // numerator = op1.numerator*op2.denominator - op2.numerator*op1.denominator;

  // denominator = d1*d2
  // denominator = op1.denominator*op2.denominator;

}

void rational::Multiply(const rational& op1, const rational& op2)
{
  // numerator = n1*n2
  // numerator = op1.numerator*op2.numerator;

  // denominator = d1*d2
  // denominator = op1.denominator*op2.denominator;
  
}

void rational::Divide(const rational& op1, const rational& op2)
{
  // invert the second fraction
  // i.e. 3/4 divided by 2/3 is 
  // (3*3)/(4*2) = 9/8

  // numerator = n1*d2
  // numerator = op1.numerator*op2.denominator;

  // denominator = d1*n2
  // denominator = op1.denominator*op2.numerator;

}


