 /* Palindrome.cpp
 * This program: Takes a given user input string, creates a copy in lowercase with no punctuation, and
 * compares that string to a reversed copy of itself. If the string is the same forward and backward, 
 * it is a palindrome; if not, it is not a palindrome. The result is stored accordingly in
 * a respective vector, "palindromes" and "not_palindromes", and subsequently displayed when the user
 * inputs "quit".
 * Author: Jordan Revon
 * Last modified on: 10/16/2020
*/

// Declare libraries to use
// Note: this program requires <string> and <vector> to function properly!
#include <iostream>
#include <string>
#include <vector>

using namespace std;


// removePunctuation creates a copy of the string and removes punctuation from the copy leaving the original alone.
// @param sentence is the string to clean.
// @returns a cleaned string with no punctuation.
string removePunctuation(const string sentence);


// convertToLower returns a lowercase version of the inputString string.
// @param mixedcase is the string to convert.
// @returns a lowercase string.
string convertToLower(const string mixedcase);

// Returns a reverse version of the cleanInput string.
// @param input is the string to reverse.
// @returns a string with the contents that's the reverse of the input.
string reverse(string input);

// display displays the strings.
// @param vstrings is a vector of strings to display
void display(vector<string> vstrings);

// isPalindrome passes the input string and calls all of the other 
//  functions to prepare the string.
// Once the string is cleaned, it tests if it's a palindrome. 
// @param palindrome is the string to check.
// @returns true if it's a palindrome and false if not.
bool isPalindrome(string palindrome);

int main()
{
    // Bool variable to continue running a do-while loop
    bool tryAgain = true;
    // String variable for user input
    string inputString;
    // String vectors to store palindrome inputs and inputs that are not palindromes
    vector<string> palindromes, not_palindromes;
    // Do-while loop to gather input and add them to their respective lists
    do
    {
        cout << "Enter your palindrome or type quit: " << endl;
        // Read a whole line of user input
        getline(cin, inputString);
        // Quit the loop if the inputString is "quit"
        if(inputString == "quit")
        {
            break;
        }
        // Otherwise take the inputString and call isPalindrome() on it
        else
        {
            // If the inputString is a palindrome, store it in the "palindromes" vector
            if(isPalindrome(inputString))
                palindromes.push_back(inputString);
            // Otherwise store it in the "not_palindromes" vector
            else
                not_palindromes.push_back(inputString);
        }
    }
    while(tryAgain == true);
    // Display the contents of both lists by calling display()
    cout << "Palindromes:" << endl;
    display(palindromes);
    cout << "NOT Palindromes:" << endl;
    display(not_palindromes);
    return 0;
}


// removePunctuation - Removes punctuation from a given string
// Precondition: a string that may or may not have punctuation.
// Postcondition: returns a (possibly shorter) string with punctuaton removed.
string removePunctuation(const string sentence)
{
    // Variable to make a copy of the string to manipulate
    //  without changing the input
    string noPunct;
    // For-loop to remove punctuation from the given string
    //  and store it in the copy, noPunct
    for(int i = 0; i < sentence.length(); i++)
    {
        // If the element at index i in the given string is a
        //  character or number, concatenate it to noPunct
        if(isalpha(sentence[i]) || isdigit(sentence[i]))
        {
            noPunct += sentence[i];
        }
    }
  // Return the contents of the copy, noPunct 
  return noPunct;
}

// convertToLower - Converts a provided string to lowercase only
// Precondition: a string that may have mixed case in it.
// Postcondition: returns a lowercase string
string convertToLower(const string mixedcase)
{
    // Variable to make a copy of the string to manipulate
    //  without changing the input 
    string lowerInput;
    // For-loop to change any uppercase characters to lowercase
    for(int i = 0; i < mixedcase.length(); i++)
    {
        // Each element at index i is concatenated to 
        //  lowerInput in lowercase only
        lowerInput += tolower(mixedcase[i]);
    }
    // Return the contents of the copy, lowerInput
    return lowerInput;
}

// reverse - Reverses a provided string (i.e. first letter is the last letter,
// second letter is the second-to-last letter, etc)
// Precondition: a string to be reversed
// Postcondition: returns a string that is the reverse of the input string.
string reverse(string input)
{
    // Variable to make a copy of the string to manipulate
    //  without changing the input 
    string reverseString;
    // For-loop to reverse the given string starting at the last element
    //  and working toward the first element, concatenating each into
    //  reverseString
    for(int i = input.length()-1; i >= 0; i--)
    {
        reverseString += input[i];
    }
    // Return the contents of the copy, reverseString
    return reverseString;
}

// display - Displays the contents of a vector
// Precondition: a vector of strings to print. 
// Postcondition: Use a tab character for space. strings are printed one per line.
void display(vector<string> vstrings)
{
    // For-loop to iterate through each item in the given vector
    for(unsigned int i = 0; i < vstrings.size(); i++)
    {
        // Output the contents of the index i with a tab character in front
        cout << "\t" << vstrings[i] << endl;
    }
}

// isPalindrome - Checks to see if a cleaned string is the same forward
//  as it is backward
// Precondition: a string to be tested
// Postcondition: returns a bool that is true if the input is a palindrome
// returns false otherwise.
bool isPalindrome(string palindrome)
{
    // Variable to store a string that has been converted to lowercase
    //  and had its punctuation removed
    string cleanString = convertToLower(removePunctuation(palindrome));
    // Variable to store the cleaned string in reverse
    string reverseInput = reverse(cleanString);
    // Return the result of a reverseInput and cleanString comparison
    // If they're the same, return value will be "true"
    // If they're not the same, return value will be "false"
    return (reverseInput == cleanString);
}
