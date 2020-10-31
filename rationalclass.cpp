#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

class rational
{
public:
	/* Done: default constructor set the rational number to 0, (i.e., numerator is 0, denominator is 1) */
  rational();
  rational(int n);
  rational(int n, int d);

	/* Done: define input to set the invoking object's value from user input */
	void input();

	/* Done: define output to display invoking object's value in the standard output, in the form of numerator/denominator */
	void output() const;

	/* Done: declare the accessor to return the invoking object's numerator */
  int get_numerator() const { return numerator;}
	
	/* Done: declare the accessor to return the invoking object's denominator */
  int get_denominator() const { return denominator;}

	/* Done: declare Add to set the invoking object to be the sum of op1 and op2, use const & parameters */
  void Add(const rational& op1, const rational& op2);


	/* Done: declare Subtract to set the invoking object to the difference of op1 and op2, use const & parameters */
  void Subtract(const rational& op1, const rational& op2);


	/* Done: declare Multiply to set the invoking object to the product of op1 and op2, use const & parameters */
  void Multiply(const rational& op1, const rational& op2);


	/* Done: declare Divide to set the invoking object to the Quotient of op1 and op2, use const & parameters */
  void Divide(const rational& op1, const rational& op2);


private:
	/* Done: declare data members for rational object */
  int numerator;
  int denominator;

};


int main()
{
	char oper;
	// Done: declare rational objects for result and operand.
  rational result, op2;

	cout << "Enter op1 (in the format of p/q): ";
	// Done: Use your input function to read the first operand into result.
  result.input();
  

	//Test rational class member function 
	do {
		cout << "\nEnter operator [+, -, /, *, =, c(lear), a(ccessors), q(uit)]: ";
    // Done: Read the operator into oper
    cin >> oper;
    
	  // Done: Implement a switch or multiway if statement with one case for each option above where
		// '+','*','/','-' inputs a rational op1 and calculates result.oper(result,op1)
		// '=' outputs the current result,
		// 'c' to clear current result, use input function to read first operand into result,
		// 'a' to test accessors, 'q' to quit.

    // if c - read in a new value to start with i.e. re-enter op1's values
    if(oper == 'c')
    {
      cout << "\nEnter op1 (in the format of p/q): ";
      result.input();
    }
		
    // if a - output numerator and output denominator
    else if(oper == 'a')
    {
      cout << "\nresult's numerator is: " << result.get_numerator() << endl;
      cout << "result's denominator is: " << result.get_denominator();
    }

		// if + add a specified op2 to result
		else if(oper == '+')
    {
      cout << "\nEnter op2 (in the format of p/q): ";
      op2.input();
      result.Add(result, op2);
    }
    // if - subtract a specified op2 from result
    else if(oper == '-')
    {
      cout << "\nEnter op2 (in the format of p/q): ";
      op2.input();
      result.Subtract(result, op2);
    }
    // if * multiply a specified op2 and result
    else if(oper == '*')
    {
      cout << "\nEnter op2 (in the format of p/q): ";
      op2.input();
      result.Multiply(result, op2);

    }
    // if / divide a specified op2 and result
    else if(oper == '/')
    {
			cout << "\nEnter op2 (in the format of p/q): ";
      op2.input();
      result.Divide(result, op2);
    
		}
    else if(oper == '=')
    {
      cout << "result = "; 
      result.output();
    }


	} while (oper != 'q');
	return 0;
}


// Done: Definitions of all member functions declared above

// DONE: Default constructor sets numerator to 0 and denominator to 1
rational::rational()
{
  numerator = 0;
  denominator = 1;
}

rational::rational(int n)
{
  numerator = n;
  denominator = 1;
}

rational::rational(int n, int d)
{
  if(denominator <= 0)
  {
    cout << "Cannot set denominator to 0. Denominator set to 1" << endl;
    denominator = 1;
  }
  else
  {
    numerator = n;
    denominator = d;
  }
}

void rational::input()
{
  char slash;
  cin >> numerator >> slash >> denominator;
  if(denominator <= 0)
  {
    cout << "Cannot set denominator to 0. Denominator set to 1" << endl;
    denominator = 1;
  }

}

void rational::output() const
{
  cout << numerator << '/' << denominator;

}


void rational::Add(const rational& op1, const rational& op2)
{
  //numerator = n1*d2 + n2+d1;
  numerator = op1.numerator*op2.denominator + op2.numerator*op1.denominator;

  //denominator = d1*d2
  denominator = op1.denominator*op2.denominator;

}

void rational::Subtract(const rational& op1, const rational& op2)
{
  // numerator = n1*d2 - n2+d1;
  numerator = op1.numerator*op2.denominator - op2.numerator*op1.denominator;

  // denominator = d1*d2
  denominator = op1.denominator*op2.denominator;

}

void rational::Multiply(const rational& op1, const rational& op2)
{
  // numerator = n1*n2
  numerator = op1.numerator*op2.numerator;

  // denominator = d1*d2
  denominator = op1.denominator*op2.denominator;
  
}

void rational::Divide(const rational& op1, const rational& op2)
{
  // invert the second fraction
  // i.e. 3/4 divided by 2/3 is 
  // (3*3)/(4*2) = 9/8

  // numerator = n1*d2
  numerator = op1.numerator*op2.denominator;

  // denominator = d1*n2
  denominator = op1.denominator*op2.numerator;

}


