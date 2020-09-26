 /* Working with arrays and functions
 * Author: Jordan Revon
 * Last modified on: 9/26/2020
 * Known bug: Entering in values for the array in a single line, rather than pressing enter after each value, will not terminate the fillArray function after 20 values; -1 still terminates correctly this way, and any values after the 20th will not be stored in the array
 */
 
#include <iostream>
using namespace std;

const int CAPACITY=20;

// displayArray - display the array on a single line separated by blanks.
// @param: int array[] is an unordered array of integers
// @param: int numberOfElements
void displayArray(int array[], int numElements);

// fillArray - fills an int array with values entered by the user until -1
// is entered or until CAPACITY is met
// @param: int array[] is an unordered array of integers when leaving this function
// @param: int& numberElements is the number of Elements in the array after function
// @returns void.
void fillArray(int array[], int &numberElements);

// removeElement - removes the element of the given index from the given array.
// @param: int array[] is an unordered array of integers
// @param: int &numberElements
// @param: int position of element to delete
// @returns: true if delete was successful, false otherwise
bool removeElement(int array[], int &numElements, int position);

// insertElement - inserts the element of the given index from the given array.
// @param: int array[] is an unordered array of integers
// @param: int numberElements
// @param: int position to insert into
// @param: int target to insert.
// @returns: true if insert was successful, false otherwise
bool insertElement(int array[], int &numberElements, int position, int target);
// this version of the insertElement function handles appending a value rather than inserting it in a position
bool insertElement(int array[], int &numberElements, int target);

// searchElement - searches for the element in the given array.
// @param int array[] is an unordered array of integers
// @param int numberOfElements
// @param int target
// @returns index of element or -1 if not found.
int searchElement(int array[], int numberOfElements, int target);

int main()
{
	// Declare an int array with a given CAPACITY
	int NumArray[CAPACITY];
	// Declare an int to keep track of the number of elements in the array
	// The array is initially empty, i.e., contains 0 elements
	int NumArrayElems = 0;
	// Declare variable to store user-entered value to search for in the array, and another variable for the position for later
	int target, position;

	// Call fillArray to enter values into NumArray
	fillArray(NumArray, NumArrayElems);
	// Call displayArray to print the number of elements, NumArrayElems in the array, NumArray
	displayArray(NumArray, NumArrayElems);

	// Read in a target value and position from the user
	cout << "Enter a value and a position to insert: ";
	cin >> target >> position;
	// Call insertElement function to insert target value at position
	insertElement(NumArray, NumArrayElems, position, target);
	// Call displayArray to print the number of elements, NumArrayElems in the array, NumArray
	displayArray(NumArray, NumArrayElems);

	// Prompt user to enter a target value to delete from the array
	cout << "Enter a value to delete from the array: ";
	cin >> target;
	// Call removeElement to remove the target if it is present in the array
	// Note: searchElement gets called first to determine the position parameter and will either be the index of the target if found, or -1 if not found
	// searchElement returning -1 will cause removeElement to not remove anything
	// If removeElement returns true, call displayArray to print the updated array
	if(removeElement(NumArray, NumArrayElems,searchElement(NumArray, NumArrayElems, target)) == true)
	{
		displayArray(NumArray, NumArrayElems);
	}

	// Read in a value to append
	cout << "Enter a value to append: ";
	cin >> target;
	// Call insertElement function to append target to the end of the array
	insertElement(NumArray, NumArrayElems, target);
	// Call displayArray to print the NumArrayElems in NumArray
	displayArray(NumArray, NumArrayElems);
	
	return 0;
}

// displayArray - displays the array
// precondition: int array[] is an unordered array of numElements integers.
// postcondition: array is displayed on the console on a single line separated by blanks.
void displayArray(int array[], int numElements)
{
	// For-loop to print each element at index i in the array
	for (int i = 0; i < numElements; i++)
		cout << array[i] << " ";
	cout << endl;
}

// fillArray - fills the array
// precondition: int array[] is an unordered array of numberElements integers
// postcondition: array contains user's entered elements and increases the numberElements accordingly
void fillArray(int array[], int &numberElements)
{
	// Declare a variable for user inputs
	int user_input;
	// Prompt the user to enter inputs
	cout << "Enter a list of up to 20 integers or -1 to end the list" << endl;
	// For-loop to fill the array with user inputs
	// Loop will exit if i reaches CAPACITY
	for(int i = 0; i < CAPACITY; i++)
	{
		// Read user's input
		cin >> user_input;
		// If the user entered -1, break out of the code
		if(user_input == -1)
		{
			break;
		}
		// Otherwise set the element at i index to the user's input
		//and increment numberElements accordingly
		else
		{
			array[i] = user_input;
			numberElements++;
		}
	}
}

// removeElement - removes an element from a given array
// precondition: the position must be greater than or equal to 0 AND 
// less than the total number of elements, numElements
// postcondition: returns "true" if removal is successful, or "false" if removal is not successful
bool removeElement(int *array, int &numElements, int position)
{
	if((position >= 0) && (position < numElements))
	{
		// For-loop to step through each element at i index in the array, from a given position, position, until the total number of elements, numElements
		for(int i = position; i < numElements; i++)
		{
			// Set the element at i index to the element at the next highest index
			array[i] = array[i+1];
		}
		// Decrement the total number of elements to account for the removal
		numElements--;
		// Then return true to indicate removal of an element
		return true;
	}
	// Otherwise if neither of the preconditions are met, return false to indicate no removal
	else
	return false;
}

// insertElement - inserts a given element into a position in an array
// precondition: numberElements must be less than CAPACITY, the given position must be less than numberElements, and the position must be greater than or equal to 0
// postcondition: returns "true" if insertion is successful, or "false" if not
bool insertElement(int array[], int &numberElements, int position, int target)
{
	// Declare bool variable to determine if an element was successfully inserted
	bool targetInserted = false;
	// If:
	// - numberElements is less than CAPACITY, AND
	// - the given position is less than numberElements, AND 
	// - the given position is greater than or equal to 0
	if((numberElements < CAPACITY) && (position < numberElements) && (position >= 0))
	{
		// Increment the total numberElements by one to account for the new value to be added
		numberElements++;
		// For-loop to step through each element at i index in the array, from the total number of elements, numberElements, until the given position, position
		for(int i = numberElements - 1; i > position; i--)
		{
			array[i] = array[i-1];
		}
		// Set the element at position index in the array to the target value
		array[position] = target;
		// Finally, set targetInserted to "true" to indicate a value was added
		targetInserted = true;
	}
	
	// If targetInserted was set to true
	if(targetInserted == true)
	{
		// Then return true
		return true;
	}
	// Otherwise the target was not inserted
	else
	{
		// So return false
		return false;
	}
}

// insertElement - appends a given element to the end of an array
// precondition: numberElements must be less than CAPACITY
// postcondition: returns "true" if appending was successful, or "false" if not
bool insertElement(int array[], int &numberElements, int target)
{
	// Declare bool variable to determine if an element was successfully appended
	bool targetAppended = false;
	// If the total number of elements, numberElements, is less than the total CAPACITY
	if(numberElements < CAPACITY)
	{
		// Increment numberElements to account for the new value
		numberElements++;
		// Set the new empty position in the array to the target value
		array[numberElements - 1] = target;
		// Finally, set targetAppended to "true" to indicate a value was appended
		targetAppended = true;
	}
	
	// If targetAppended was set to true
	if(targetAppended == true)
	{
		// Then return true
		return true;
	}
	// Otherwise the target was not appended
	else
	{
		// So return false
		return false;
	}
}

// searchElement - searches for a target element in a given array
// precondition: int target is a value being searched for in an int array[], an unordered array of numberElements integers
// postcondition: returns the index of the target if target is found or -1 if target is not found
int searchElement(int array[], int numberOfElements, int target)
{
	// Declare a bool to check later if we found the target value
	bool targetFound = false;
	// Declare an int to store the index the target was found at
	int indexFound;
	// For-loop to step through each element in the array[]
	for(int i = 0; i < numberOfElements; i++)
	{
		// If the value at i index equals the target value passed as argument
		if(array[i] == target)
		{
			// Then set targetFound to true
			targetFound = true;
			// And set indexFound to the index the target was found at
			indexFound = i;
		}
	}
	
	// If targetFound was set to true
	if(targetFound == true)
	{
		// Then return the index the target was found at 
		return indexFound;
	}
	// Otherwise the target was not found
	else
	{
		cout << "Value not found!" << endl;
		// So return -1
		return -1;
	}
}
