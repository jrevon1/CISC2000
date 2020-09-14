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

/*
 * getCPIValues - gets user input for old and new consumer price index values
 * @param old_cpi: is the consumer price index that it was a year ago
 * @param new_cpi: is the consumer price index that it is currently 
 * @return is void
 */
void getCPIValues (float &old_cpi, float &new_cpi);

int main()
{   
    // Declaring variables for the two user CPI inputs, to hold the calculated inflation rate, and to hold the running average rate, respectively
    float old_cpi, new_cpi, inflation_rate, average_rate;
    // A counter to calculate the final average rate
    int counter = 0;
    // An input to trigger the do/while loop
    char user_input;
    // A constant to limit the maximum number of CPI inputs to 20
    const int MAX_RATES = 20;
    // An array to accumulate the computed inflation rates
    double rates[MAX_RATES];
    
    // A do/while loop asking the user to enter two CPI inputs unless they don't type "y" or "Y" after
    do{ 
        cout << "Enter the old and new consumer price indices: ";
    
        getCPIValues(old_cpi, new_cpi);


        // Function call for InflationRate with the two CPI inputs
        inflation_rate = InflationRate(old_cpi, new_cpi);
        // Printing the calculations
        cout << "Inflation rate is " << inflation_rate << endl;
        cout << "Try again? (y or Y): ";
        cin >> user_input;
        
        // If user entered "y" or "Y", AND the inflation rate was NOT 0, advance the counter, then add the inflation rate to the running total
        if (inflation_rate != 0){
          // Storing the calculated inflation rate in each subsequent array index
          rates[counter] = inflation_rate;
          counter++;
          average_rate += inflation_rate;
        }
    }
    while ((user_input == 'y') || (user_input == 'Y'));
    // If the user doesn't enter "y" or "Y", calculate the final average by dividing the running total by the number of times the loop executed
    average_rate /= counter;
    // Printing the result
    cout << "Average rate is " << average_rate << endl;
    
    // TEST to print out the array values and check them after execution
    for (int i = 0; i <= MAX_RATES; i++){
            cout << rates[i] << endl;
        }

    return 0;
}


double InflationRate(float old_cpi, float new_cpi)
{
    // InflationRate will calculate the percentage increase or decrease
    double InflationRate = (new_cpi - old_cpi) / old_cpi * 100;
    // precondition:   both prices must be greater than 0.0
    // postcondition:  the inflation rate is returned or 0 for invalid inputs
    if ((new_cpi <= 0) || (old_cpi <= 0))
        return InflationRate = 0;
    // otherwise return the calculated inflation rate
    else
        return InflationRate;
}

void getCPIValues (float &old_cpi, float &new_cpi)
{
    do{
        // Read in two float values for the cpi and store them in the variables
        cin >> old_cpi >> new_cpi;
        // If old_cpi and new_cpi are 0 or less than 0, message displays to enter valid values
        if ((old_cpi <= 0) && (new_cpi <= 0))
            cout << "Error: CPI values must be greater than 0" << endl;
    }
    // If old_cpi and new_cpi are 0 or less than 0, loop to get valid values
    while ((old_cpi <= 0) && (new_cpi <= 0));
}
