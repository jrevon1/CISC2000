// This is the header file CommissionEmployee.h.
// This is the interface for the class CommissionEmployee
#ifndef _COMMISSION_H
#define _COMMISSION_H

#include <iostream>
#include <string>
#include "Employee.h"

using namespace std;


class CommissionEmployee : public Employee
{
  public:
    // Default constructor for CommissionEmployee
    CommissionEmployee( );

    // Constructor for CommissionEmployee that takes a name, SSN, sales, commission percent
    CommissionEmployee(string the_name, string the_ssn, double sales, double commission);

    // Accessor functions
    double get_sales( ) const;
    double get_commission( ) const;

    // Mutator functions
    void set_sales(double new_sales);
    void set_commission(double new_commission);

    // Virtual function overrides
    double get_net_pay() const override;
    void print_check( ) const override;
    istream& promptInput(istream& in, ostream& out) override;

  private:
    // Unique variables for CommissionEmployee
    // Double variable for CommissionEmployee's sales amount
    double sales;
    // Double variable for CommissionEmployee's commission rate
    // NOTE: Expressed as a percent
    double commission;
};
#endif // _COMMISSION_H
