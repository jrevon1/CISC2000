//This program calculates the inflation rate given two Consumer Price Index values and prints it to the monitor.

#include <iostream>
using namespace std;

/*
 * InflationRate - calculates the inflation rate given the old and new consumer price index
 * @param old_cpi: is the consumer price index that it was a year ago
 * @param new_cpi: is the consumer price index that it is currently 
 * @returns the computed inflation rate or 0 if inputs are invalid.
 */
double InflationRate(float old_cpi, float new_cpi);

int main()   //C++ programs start by executing the function main
{
   // TODO #1: declare two float variables for the old consumer price index (cpi) and the new cpi
   float old_cpi, new_cpi;
   
   cout << "Enter the old and new consumer price indices: " << endl;
    

   // TODO #2: Read in two float values for the cpi and store them in the variables
   cin >> old_cpi >> new_cpi;

   // TODO #3: call the function InflationRate with the two cpis
   // TODO #4: print the results
   cout << "Inflation rate is " << InflationRate(old_cpi, new_cpi) << endl;


   // BONUS #1: Put the logic in TODO #2-4 in a loop that asks the user to enter 'y' if there's more data


   // BONUS #2: Keep a running total of the valid inflation rates and the number of computed rates to calculate the average rate.
   // Print the results after the loop

   return 0;
}


// double InflationRate(float old_cpi, float new_cpi)
// precondition:   both prices must be greater than 0.0
// postcondition:  the inflation rate is returned or 0 for invalid inputs
double InflationRate(float old_cpi, float new_cpi)
{
   // TODO: Implement InflationRate to calculate the percentage increase or decrease
   // Use (new_cpi - old_cpi) / old_cpi * 100
   double InflationRate = (new_cpi - old_cpi) / old_cpi * 100;
    if ((new_cpi <= 0) || (old_cpi <= 0))
        return InflationRate = 0;
    else
        return InflationRate;
}
