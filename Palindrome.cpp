 /* Palindrome.cpp
 * This program: Takes a given user input string, converts it to lowercase and removes punctuation,
 * then checks to see if that string is the exact same when reversed. If the string is the same forward
 * and backward, it is a palindrome; if not, it is not a palindrome. The result is stored accordingly in
 * a respective vector, "palindromes" and "not_palindromes", and subsequently displayed when the user
 * inputs "quit".
 * Author: Jordan Revon
 * Last modified on: 10/13/2020
*/

// Declare libraries to use
// Note: this program requires <string> and <vector> to function properly!
#include <iostream>
#include <string>
#include <vector>

using namespace std;


// removePunctuation creates a copy of the string and removes punctuation from the copy leaving the original alone.
// @param inputString is the string to clean.
// @returns a cleaned string with no punctuation.
string removePunctuation(const string sentence);


// convertToLower returns a lowercase version of the inputString string.
// @param inputString is the string to convert.
// @returns a lowercase string.
string convertToLower(const string mixedcase);

// Returns a reverse version of the cleanInput string.
// @param cleanInput is the string to reverse.
// @returns a string with the contents that's the reverse of the input.
string reverse(string input);

// display displays the strings.
// @param vstrings is a vector of strings to display
void display(vector<string> vstrings);

// isPalindrome passes the input string and calls all of the other 
//  functions to prepare the string.
// Once the string is cleaned, it tests if it's a palindrome. 
// @param inputString is the string to check.
// @returns true if it's a palindrome and false if not.
bool isPalindrome(string palindrome);

int main()
{
    // Bool variable to run the following do-while loop
    bool tryAgain = true;
    // String variables for user input before, inputString, and after
    // converting to lowercase and removing punctuation, cleanInput
    string inputString, cleanInput;
    // String vectors to store palindrome inputs and inputs that are not palindromes
    vector<string> palindromes, not_palindromes;
    // Do-while loop to gather user input, convert to lowercase and remove punctuation,
    // and add the subsequent cleanInput to the palindrome vector or not_palindrome vector
    // until the inputString is "quit"
    do
    {
        cout << "Enter your palindrome or type quit: " << endl;
        getline(cin, inputString);
        // Quit the loop if the inputString is "quit"
        if(inputString == "quit")
        {
            break;
        }
        // Otherwise take the inputString and call convertToLower(), and 
        // removePunctuation() and store the result in cleanInput
        else
        {
            cleanInput = removePunctuation(convertToLower(inputString));
            // if the cleanInput is a palindrome, store it in the "palindromes" vector
            if(isPalindrome(cleanInput))
                palindromes.push_back(inputString);
            // Otherwise store cleanInput in the "not_palindromes" vector
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
// Postcondition: returns a (possibly shorter) string with punctuaton
// removed.
string removePunctuation(const string sentence)
{
    // Variable to make a copy of the string to manipulate
    //  without changing the input
    string cleanInput;
    // For-loop to remove punctuation from the given string
    //  and store it in the copy, cleanInput
    for(int i = 0; i < sentence.length(); i++)
    {
        // If the element at index i in the given string is a
        //  character or number, concatenate it to cleanInput
        if(isalpha(sentence[i]) || isdigit(sentence[i]))
        {
            cleanInput += sentence[i];
        }
    }
  // Return the contents of the copy, cleanInput 
  return cleanInput;
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
        // Each element at index i is converted to lowercase
        //  and concatenated to lowerInput
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
    // If the reversed string is the same as the cleaned string,
    // it's a palindrome, so return true
    if(reverseInput == cleanString)
        return true;
    // Otherwise it's not a palindrome so return false
    else
        return false;
}
