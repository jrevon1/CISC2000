#include <iostream>
using namespace std;

/* A function that reads a sequence of integers from input to fill a
dynamically allocated array. For example, if the length is 3, and the
numbers are 123 345 99 then the array returned will be of size 3, and 
stores values 123, 345 and 99.
@param size: upon return, stores the size of the array
@return the pointer pointing to the array
*/
int * ReadNumberSequence(int & size);

int main()
{
    // Delcare size integer
    int size;
    // Call the ReadNumberSequence function to read a sequence of numbers 
    int * array = ReadNumberSequence(size);
    // For loop to display the elements in the array returned
    for(int i = 0; i < size; i++)
    {
        cout << array[i] << endl;
    }
    // Free the array returned by ReadNumberSequence.
    delete[] array;

	return 0;
}

// ReadNumberSequence - takes a size input, creates a dynamic array 
// of that size, and takes input to store in the array
// precondition: none
// postcondition: a dynamic array of size, populated with integers
int * ReadNumberSequence(int & size)
{
    // Initialize the pointer to NULL
    int * array = NULL;
    // Do-while loop to take in an array size input
    do
    {
        cout <<"Enter the length of the number sequence:";
        cin >> size;
    // Size of 0 or a negative number will re-prompt size entry
    } while (size <= 0);
    // Allocate memory for the array
    array = new int[size];
    // Note: we know the value of size only at run time, so we need to DYNAMICALLY allocate the size of the array
    // For loop to read size # of int from input, and store in the array
    cout << "Enter " << size << " number of elements to store in the array: ";
    for(int i = 0; i < size; i++)
    {
        cin >> array[i];
    }
    
    return array;
}
