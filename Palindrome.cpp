// TO DO: Add comments to the code

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string remove_punct(const string &inputString); // done
string convert_lower(const string &inputString); //done
string reverse(string cleanInput); // done
void display(vector<string> palindromes, vector<string> non_palindromes); //done
bool is_palindrome(string inputString); // done

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
            cleanInput = remove_punct(convert_lower(inputString));
            if(is_palindrome(cleanInput))
                palindromes.push_back(inputString);
            else
                non_palindromes.push_back(inputString);
        }
    }
    while(tryAgain == true);
    display(palindromes, non_palindromes);
    return 0;
}

// Removes punctuation from a string
string remove_punct(const string &inputString)
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
string convert_lower(const string &inputString)
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
void display(vector<string> palindromes, vector<string> non_palindromes)
{
    cout << "Palindromes:" << endl;
    for(unsigned int i = 0; i < palindromes.size(); i++)
    {
        cout << "\t" << palindromes[i] << endl;
    }
    cout << "NOT Palindromes:" << endl;
    for(unsigned int i = 0; i < non_palindromes.size(); i++)
    {
        cout << "\t" << non_palindromes[i] << endl;
    }
}

// Checks to see if a cleaned string is a palindrome
bool is_palindrome(string inputString)
{
    string cleanString = convert_lower(remove_punct(inputString));
    string reverseInput = reverse(cleanString);
    if(reverseInput == cleanString)
        return true;
    else
        return false;
}
