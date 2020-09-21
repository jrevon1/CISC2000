//This program calculates the inflation rate given two Consumer Price Index values, stores the value in an array, sorts the array from smallest to largest values, and finds the median value

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
 * @param &old_cpi: is the consumer price index that it was a year ago
 * @param &new_cpi: is the consumer price index that it is currently
 * @return is void; &old_cpi and &new_cpi are updated by reference
 */
void getCPIValues (float &old_cpi, float &new_cpi);

/*
 * swap_values - takes two inputs, x and y, and creates a temporary variable to swap them
 * @param &x : the first value being swapped
 * @param &y: the second value being swapped
 * @return is void; &x and &y are updated by reference
*/
void swap_values(double &x, double &y);

/*
 * sort_array - takes in an array and a size, then uses a for-loop to compare the element at the current index [i] to the element at the next index [i+1]
 * @param *array: is a pointer to an array of doubles' first position
 * @param size: is the total number of elements in the aforementioned array
 * @return is void; sort_array uses the swap_values function to update the order by reference
*/
void sort_array(double *array, int size);

/*
 * findMedianRate - takes in an array and a number of elements, then calculates the median number in the array
 * @param *array: is a pointer to an array of doubles' first position
 * @param numElements: is an integer of the number of elements in the array
 * @returns a double which will be the median rate
*/
double findMedianRate(double *array, int numElements);

int main()
{
    // Declare variables for the two user CPI inputs, to hold the calculated inflation rate, and to hold the running average rate, respectively
    float old_cpi, new_cpi, inflation_rate, average_rate;
    // A counter to calculate the final average rate
    int counter = 0;
    // An input to trigger the do/while loop
    char user_input;
    // A constant to limit the maximum number of CPI inputs to 20
    const int MAX_RATES = 20;
    // An array to accumulate the computed inflation rates
    double rates[MAX_RATES];
    // A boolean value to check if the array is full
    bool isArrayFull = false;

    // A do/while loop asking the user to enter two CPI inputs unless they don't type "y" or "Y" after
    do
    {
        // If the array is NOT full, it will ask the user for input
        if (isArrayFull == false)
        {
          cout << "Enter the old and new consumer price indices: ";

          // Call the getCPIValues function to get user input
          getCPIValues(old_cpi, new_cpi);

          // Call InflationRate function with the two CPI inputs as parameters
          inflation_rate = InflationRate(old_cpi, new_cpi);

          // Print the calculations
          cout << "Inflation rate is " << inflation_rate << endl;

          // If the calculated inflation rate is NOT 0, then:
          if (inflation_rate != 0)
          {
            // Store the calculated inflation rate in the current index in the array
            rates[counter] = inflation_rate;
            // Advance the counter, for both the array indexing, and calculating the average later
            counter++;
            // If the counter is equal to the maximum number of items in the array, set the isArrayFull boolean value to "true"
            if (counter == MAX_RATES)
            {
              isArrayFull = true;
            }
            // Then add the inflation rate to the running total
            average_rate += inflation_rate;
          }
          // If the array is full, this message won't display
          if (isArrayFull == false)
          {
            cout << "Try again? (y or Y): ";
            cin >> user_input;
          }
        }
        // When isArrayFull is set to true, break out of the block
        else
          break;
      }
    while ((user_input == 'y') || (user_input == 'Y'));
    // If the user doesn't enter "y" or "Y", calculate the final average by dividing the running total by the number of times the loop executed
    average_rate /= counter;
    // Print the result
    cout << "Average rate is " << average_rate << endl;
    // Sort the list then print the result by calling the findMedianRate function
    cout << "Median rate is " << findMedianRate(rates, counter) << endl;

    return 0;
}

/*
 * InflationRate - calculates the inflation rate
 * precondition: both prices must be greater than or equal to 0
 * postcondition: the inflationRate calculation is returned or 0 is returned for invalid inputs
*/
double InflationRate(float old_cpi, float new_cpi)
{
    // Declare variable to store the calculated inflation rate
    double inflationRate;
    if ((new_cpi <= 0) || (old_cpi <= 0))
        return inflationRate = 0;
    // Otherwise return the calculated inflation rate
    else
        return inflationRate = (new_cpi - old_cpi) / old_cpi * 100;
}

/*
 * getCPIValues - gets user input for two consumer price index values
 * precondition: none
 * postcondition: both user inputs must be greater than or equal to 0
*/
void getCPIValues (float &old_cpi, float &new_cpi)
{
    do
    {
        // Read in two float values for the cpi and store them in the variables
        cin >> old_cpi >> new_cpi;
        // If old_cpi and new_cpi are 0 or less than 0, message displays to enter valid values and prompts re-entry
        if ((old_cpi <= 0) || (new_cpi <= 0))
        {
            cout << "Error: CPI values must be greater than 0" << endl;
            cout << "Enter the old and new consumer price indices: ";
        }
    }
    // If old_cpi and new_cpi are less than or equal to 0, loop to get valid values
    while ((old_cpi <= 0) || (new_cpi <= 0));
}

/*
 * swap_values - swaps two values passed as arguments
 * precondition: at least one set of values should be assigned using getCPIValues
 * postcondition: x's starting value is now y and y's starting value is now x
*/
void swap_values(double &x, double &y)
{
  // Create a temporary variable and set it to the first argument
  // This MUST be a double otherwise you'll lose values in the array!
  double temp = x;
  // Set the first argument to the second argument
  x = y;
  // Set the temporary variable to the second argument
  y = temp;
}

/*
 * sort_array - performs a bubble sort given an array and size
 * precondition: double array[] is an unordered array of size
 * postcondition: array is ordered from smallest value to highest value
*/
void sort_array(double array[], int size)
{
  while(1)
  {
    // Declare a boolean variable for later to check if the list was sorted or not
    bool wasListSorted = false;

    // For-loop to cycle through each element in the array, minus 1
    // otherwise it won't be able to compare the very last value to anything
    for(int i = 0; i < size - 1; i++)
    {
      // If the element at [i] is bigger than the
      // element at the next index in the array, [i+1]
      if(array[i] > array[i+1])
      {
        // Then call swap_values to swap that element [i] and
        // the element at the next index in the array [i+1]
        swap_values(array[i], array[i+1]);
        // And finally set wasListSorted to "true" because we did sort it this time
        wasListSorted = true;
      }

    }
    // If the element at [i] was not bigger than the element
    // at the next index [i+1], then we didn't need to swap
    // This means the list is in order so sorted stays false
    // and finally break out of the block
    if(wasListSorted == false)
    {
      break;
    }
  }
}

/*
 * findMedianRate - finds the middle value given an array and number of elements
 * precondition: double *array is a pointer to an unordered array of numElements
 * postcondition: returns the value at the middle index if numElements is odd or
   returns the value of the two middle indicies divided by two if numElements is even
*/
double findMedianRate(double *array, int numElements)
{
  // Sort the list by calling the sort_array function
  sort_array(array, numElements);
  // If the number of elements in the array is even
  if(numElements % 2 == 0)
    // Return the value at the index of the middle two elements, added together and divided by two
    return (array[(numElements - 1) / 2] + array[numElements / 2]) / 2.0;
  // Else the number of elements in the array is odd
  else
  // So return the value at the index of the number of elements divided by 2
    return array[numElements/2];
}
