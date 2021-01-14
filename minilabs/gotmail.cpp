#include <iostream>
using namespace std;

// 2 functions with the same name to allow overloading
// @param: "name" is a string of the winner's name
// @param: "win" is a boolean; true if they won, false if not
// @param: "prize" is a string of the winner's prize

void personal_email(string name, bool win, string prize);
void personal_email(string name, bool win);

int main() {
    // Defining our variables for name, win condition, and prize
    string name;
    bool win;
    string prize;
    
    // Calling the functions with the recipients' details:
    personal_email(name = "Shauna", win = true, prize = "a stuffed giraffe toy");
    personal_email(name = "Jorge", win = true, prize = "a nintendo switch");
    personal_email(name = "Juanita", win = false);
    
    return 0;
}

// This function will display a message to the winner's name
// and tell them the prize they've won
void personal_email(string name, bool win, string prize)
{
    cout << "Dear " << name << "," << endl;
    cout << "You are the winner of our raffle for charity." << endl;
    cout << "The prize was: " << prize << endl;
    cout << "Thank you for giving to charity!" << endl;
    cout << "Sincerely," << endl;
    cout << "The Boolean Foundation" << endl;
    cout << endl;
}

// This function will display a message if the recipient
// is not a winner
void personal_email(string name, bool win)
{
    cout << "Dear " << name << "," << endl;
    cout << "We're sorry that you did not win our raffle for charity." << endl;
    cout << "Thank you for giving to charity!" << endl;
    cout << "Sincerely," << endl;
    cout << "The Boolean Foundation" << endl;
    cout << endl;
}
