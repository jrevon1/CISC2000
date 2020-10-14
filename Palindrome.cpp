// TO DO: Add comments to the code
 /* Palindrome.cpp
 * This program:

 * Author: Jordan Revon
 * Last modified on: 10/13/2020
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;


// removePunctuation creates a copy of the string and removes punctuation from the copy leaving the original alone.
// @param inputString is the string to clean.
// @returns a cleaned string with no punctuation.
string removePunctuation(const string &inputString);


// convertToLower returns a lowercase version of the inputString string.
// @param inputString is the string to convert.
// @returns a lowercase string.
string convertToLower(const string &inputString);

// Returns a reverse version of the cleanInput string.
// @param cleanInput is the string to reverse.
// @returns a string with the contents that's the reverse of the input.
string reverse(string cleanInput);

// display displays the strings.
// @param vstrings is a vector of strings to display
void display(vector<string> vstrings);

// isPalindrome passes the input string and calls all of the other 
//  functions to prepare the string.
// Once the string is cleaned, it tests if it's a palindrome. 
// @param inputString is the string to check.
// @returns true if it's a palindrome and false if not.
bool isPalindrome(string inputString);

int main()
{
    bool tryAgain = true;
    string inputString, cleanInput;
    vector<string> palindromes, non_palindromes;
    do
    {
        cout << "Enter your palindrome or type quit: " << endl;
        getline(cin, inputString);
        if(inputString == "quit")
        {
            break;
        }
        else
        {
            cleanInput = removePunctuation(convertToLower(inputString));
            if(isPalindrome(cleanInput))
                palindromes.push_back(inputString);
            else
                non_palindromes.push_back(inputString);
        }
    }
    while(tryAgain == true);
    cout << "Palindromes:" << endl;
    display(palindromes);
    cout << "NOT Palindromes:" << endl;
    display(non_palindromes);
    return 0;
}

// Removes punctuation from a string
string removePunctuation(const string &inputString)
{
    string cleanInput;
    for(int i = 0; i < inputString.length(); i++)
    {
        if(isalpha(inputString[i]) || isdigit(inputString[i]))
        {
            cleanInput += inputString[i];
        }
    }
  return cleanInput;
}

// Converts a string to lowercase only
string convertToLower(const string &inputString)
{
    string lowerInput;
    for(int i = 0; i < inputString.length(); i++)
    {
        lowerInput += tolower(inputString[i]);
    }
    return lowerInput;
}

// Reverses a provided string 
string reverse(string inputCopy)
{
    string reverseString;
    for(int i = inputCopy.length()-1; i >= 0; i--)
    {
        reverseString += inputCopy[i];
    }
    return reverseString;
}

// Displays the contents of the vectors
void display(vector<string> vstrings)
{
    for(unsigned int i = 0; i < vstrings.size(); i++)
    {
        cout << "\t" << vstrings[i] << endl;
    }
}

// Checks to see if a cleaned string is a palindrome
bool isPalindrome(string inputString)
{
    string cleanString = convertToLower(removePunctuation(inputString));
    string reverseInput = reverse(cleanString);
    if(reverseInput == cleanString)
        return true;
    else
        return false;
}
