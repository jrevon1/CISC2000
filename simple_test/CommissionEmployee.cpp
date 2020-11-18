// Implementation for the Derived Class CommissionEmployee
// This is the file: CommissionEmployee.cpp
// This is the implementation for the class CommissionEmployee.
// The interface for the class CommissionEmployee is in
//  the header file CommissionEmployee.h.
#include <iostream>
#include "CommissionEmployee.h"

using namespace std;

// Default constructor
CommissionEmployee::CommissionEmployee( ) : Employee( ), sales(0), commission(0)
{
  // deliberately empty
}

// Constructor that calls Employee() base class constructor
CommissionEmployee::CommissionEmployee(string name, string SSN, double sales, double commission):Employee()
{
	// deliberately empty
	// cout << "CommissionEmployee(" << name << "," << SSN << "," << sales << "," << commission << ")\n";
}

// Accessor functions
  // get_sales() - returns the employee's total sales amount
  double CommissionEmployee::get_sales( ) const
  {
    return sales;
  }

  // get_commission() - returns the employee's total commission amount
  double CommissionEmployee::get_commission( ) const
  {
    return commission;
  }

// Mutator functions
  // set_sales() - sets the employee's sales amount
  void CommissionEmployee::set_sales(double new_sales)
  {
    sales = new_sales;
  }

  // set_commission() - sets the employee's commission rate
  void CommissionEmployee::set_commission(double new_commission)
  {
    commission = new_commission;
  }

// Virtual function override implementations
  // get_net_pay() - return the net_pay calculation
  double CommissionEmployee::get_net_pay() const
  {
    // Commission employees are paid a percentage commission on their total sales amount
    //  so divide the commission rate by 100 and multiply that by the sales amount
    return commission/100 * sales;
  }

  // print_check() - print the CommissionEmployee's check
  void CommissionEmployee::print_check( ) const
  {
      // Call the print_check() function in the Employee() base class first
      Employee::print_check();
      // Then add the CommissionEmployee check's unique text
      cout << "Commission Employee." << endl;
      cout << "Gross sales: " << sales << " Commission: " << commission << " Pay: " << get_net_pay() << endl;
      cout << "_________________________________________________\n";
  }

  // promptInput() - prompts the user to enter information unique to the CommissionEmployee class
  istream& CommissionEmployee::promptInput(istream& in, ostream& out)
  {
      // Call the promptInput() function Employee()
      Employee::promptInput(in, out);
      // Then add the CommissionEmployee's unique text
      out << "Enter sales and commission: ";
  	  // Read the sales and commission.
      in >> sales >> commission;
      // Return the sales and commission
      return in;
  }
