// Implementation for the Derived Class Administrator
// This is the file: Administrator.cpp
// This is the implementation for the class Administrator.
// The interface for the class Administrator is in
//  the header file Administrator.h.
#include <iostream>
#include "Administrator.h"

using namespace std;

// Default constructor
Administrator::Administrator():SalariedEmployee(), title("NA"), bonus(0)
{
  // deliberately empty
}

// Constructor that calls SalariedEmployee() base class constructor
Administrator::Administrator(string name, string SSN, double salary, string title, double bonus):SalariedEmployee()
{
	// deliberately empty
	// cout << "Adminstrator(" << name << "," << SSN << "," << salary << "," << title << "," << bonus << ")\n";
}

// Accessor functions
  // get_title() - returns the employee's title
  string Administrator::get_title( ) const
  {
      return title;
  }
  // get_bonus() - returns the employee's total bonus amount
  double Administrator::get_bonus( ) const
  {
      return bonus;
  }

// Mutator functions
  // set_title() - sets the employee's title
  void Administrator::set_title(string new_title)
  {
      title = new_title;
  }

  // set_bonus() - sets the employee's bonus amount
  void Administrator::set_bonus(double new_bonus)
  {
      bonus = new_bonus;
  }

// Virtual function override implementations
  // get_net_pay() - return the net_pay calculation
  double Administrator::get_net_pay( ) const
  {
      // Administrators are paid salary plus a bonus
      //  so call the get_salary() function in the SalariedEmployee()
      //  base class and add the bonus amount to it
      return SalariedEmployee::get_salary() + bonus;
  }

  // print_check() - print the Administrator check
  void Administrator::print_check( ) const
  {
      // Call the print_check() function in the SalariedEmployee()
      //  base class first
      SalariedEmployee::print_check();
      // Then add the Administrator check's unique text
      cout << "Administrator Title: " << title << endl;
      cout << "Bonus: " << bonus << " Pay: " << get_net_pay( ) << endl;
      cout << "_________________________________________________\n";
  }

  // promptInput() - prompts the user to enter information unique to the Administator class
  istream & Administrator::promptInput(istream & in, ostream & out)
  {
  	 // Call the promptInput() function SalariedEmployee() base class first
      SalariedEmployee::promptInput(in, out);
      // Then add the Administrator's unique text
      out << "Enter bonus and title: ";
      // Read in the Administrator's bonus amount
      in >> bonus;
      // Ignore the space between the bonus and the title
      ignorespace(in);
  	  // Read in the rest of the line as the Administrator's title
      getline(in, title);
      // Return the bonus and the title
      return in;
  }
