// This is the header file Administrator.h.
// This is the interface for the class Administrator.
#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include "SalariedEmployee.h"

class Administrator : public SalariedEmployee
{
  public:
    // Default constructor for Administrator
    Administrator( );

    // Constructor for Administrator that takes a name, SSN, salary, title, bonus
    Administrator(string name, string SSN, double salary, string title, double bonus);

    // Accessor functions
    string get_title( ) const;
    double get_bonus( ) const;

    // Mutator functions
    void set_title(string new_title);
    void set_bonus(double new_bonus);

    // Virtual function overrides
    double get_net_pay() const override;
    void print_check( ) const override;
    istream& promptInput(istream& in, ostream& out) override;

  private:
  	// Unique variables for Administrator
  	// String variable for Administrator's title (i.e. "Vice President")
    string title;
    // Double variable for Administrator's bonus amount
    double bonus;
};
#endif
