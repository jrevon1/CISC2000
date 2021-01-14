#include <iostream>
#include <string>
using namespace std;

// ToDo: write a function to determine if we have a winner! 
// @param: "aPoints" takes in the Team A score from a loop
// @param: "bPoints" takes in the Team B score from a loop
// @return: void, prints the outcome of the game (win/loss or draw)

bool weHaveAWinner(int aPoints, int bPoints);

/*
 * Determines the outcome of a volleyball game.
 */
int main() {
    int aPoints = 0;
    int bPoints = 0;
    string input;
    
    // Loop until input is "end" or we have a winner
    // the loop should read the input and add a point to aPoints if "A"
    // or add a point to bPoints if "B", don't do anything but leave the
    // loop if "end"
    do{
        if((aPoints > bPoints + 1 && aPoints >= 21) || (bPoints > aPoints + 1 && bPoints >= 21))
            break;
        else{
            cin >> input;
            if(input == "A")
                aPoints++;
            else if(input == "B")
                bPoints++;
        }
    }
    while(input != "end");
    weHaveAWinner(aPoints, bPoints);
    
    return 0;
}


bool weHaveAWinner(int aPoints, int bPoints)
{
    bool winner;
    // Tell the user if we have a winner or not
    if(aPoints > bPoints + 1 && aPoints >= 21)
    {
        cout << "Team A won! (" << aPoints << "-" << bPoints << ")" << endl;
        winner = true;

    }
    else if(bPoints > aPoints + 1 && bPoints >= 21)
    {
        cout << "Team B won! (" << aPoints << "-" << bPoints << ")" << endl;
        winner = true;
    }
    else
    {
        cout << "Game ended as a draw. (" << aPoints << "-" << bPoints << ")" << endl;
        winner = false;
    }

    return winner;
}
