 /* Galtonboard.cpp
 * This program:
 *  - creates a Galton board, represented as a 2-dimensional array, using
 *    dynamic memory allocation, and
 *  - simulates a ball falling a chosen number of times through a chosen 
 *    number of rows using a chosen pseudo-random seed, and
 *  - finally displays the results before freeing the dynamic memory allocation.
 * Author: Jordan Revon
 * Last modified on: 10/13/2020 - minor changes to styling
*/

#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

// createNewBoard creates a new Galton board.
// @param: rows is the board size.
int** createNewBoard(int rows);

// freeBoard frees up the space allocated to the dynamic array
// in the "createNewBoard" function to prevent memory leaks.
// @param: board is a two-dimensional diagonal array.
// @param: rows is the board size.
void freeBoard(int *board[], int rows);

// runSimulation does the logic to run the Galton board
// to see how the balls drop through the pegs.
// @param: board is a two-dimensional diagonal array.
// @param: rows is the board size.
// @param: nTests is the number of tests to run.
void runSimulations(int *board[], int rows, int nTests);

// display prints the generated and completed Galton board
// @param: board is a two-dimensional diagonal array
// @param: rows is the board size
void display(int *board[], int rows);

int main()
{
	// Declare variables for board size, number 
	//  of tests, and pseudo-random seed, respectively
	int boardSize, numTests, seed;
	// Get user inputs for board size, number
	//  of tests, and pseudo-random seed
	cout << "Enter the size of the board: ";
	cin >> boardSize ;
	cout << "Enter the number of tests: ";
	cin >> numTests;
	cout << "Enter the random seed: ";
	cin >> seed;
	srand(seed);

	// Create the Galton Board, run simulation, display results
	//  and free the board
	int **board = createNewBoard(boardSize);
	runSimulations(board, boardSize, numTests);
	display(board, boardSize);
	freeBoard(board, boardSize);

	return 0;
}

// createNewBoard - creates a new Galton board
// precondition: none
// postcondition: a dynamically allocated array 
//  of size "rows", where the first row
//  contains i elements, the second contains i+1
//  elements, and so on while i is less than "rows".
// Note: all elements in the array are set to 0 initially
int** createNewBoard(int rows)
{
    // Declare an integer pointer to a pointer "board" and
    //  set that to a pointer to the memory location 
    //  of a new dynamic integer array with a size of "rows"
    int** board = new int*[rows];
    // For-loop to create the rows
    // Each row has space for one more element than the one before it
    for(int i = 0; i < rows; i++)
    {
        board[i] = new int[i + 1];
        // Inner for-loop to set each element in the entire array to 0
        for(int j = 0; j <= i; j++)
        {
            board[i][j] = 0;
        }
    }
    return board;
}

// freeBoard - frees up the dynamic memory allocation created
// by the "createNewBoard" function.
// precondition: a dynamically allocated array created using 
//  the "createNewBoard" function.
// postcondition: the aforementioned array is deleted and that 
//  memory space is properly freed up for later use.
void freeBoard(int *board[], int rows)
{
    // For-loop to delete each first element of a row in the dynamic array
    for(int i = 0; i < rows; i++)
    {
        delete[] board[i];
    }
}

// runSimulations - does the logic to run the Galton board.
// precondition: a dynamically allocated two-dimensional array 
//  created using the "createNewBoard" function, and a number of 
//  tests to perform.
// postcondition: a dynamically allocated two-dimensional array
//  filled with values based on the number of tests and rows.
void runSimulations(int *board[], int rows, int nTests)
{
    int i, j;
    // Loop to run the number of tests
    for (int trials = 0; trials < nTests; trials++)
    {
	    // Dropping a ball in always hits the first peg.
	    i = j = 0;
		board[i][j]++;

		// Simulate the ball dropping. 
		// It either falls straight down or bounces to the right.
		// But gravity always takes it down to the bottom
		for (i = 1; i < rows; i++)
		{
			int right = rand()%2;
			if (right == 1) j++;
			board[i][j]++;
		}
	}
}

// display - displays the generated and completed Galton board
// precondition: a dynamically allocated two-dimensional array 
//  created using the "createNewBoard" function.
// postcondition: neatly prints the contents of the Galton
//  board in a diagonal array with spacing.
void display(int *board[], int rows)
{
    // For-loop to run the inner loop for each row
    for(int i = 0; i < rows; i++)
    {
        // For-loop to print the contents of each element in the row, [j]
        for(int j = 0; j <= i; j++)
        {
            // Print each element in the array
            cout << setw(4) << board[i][j];
        }
        // Print a new line after each row
        cout << endl;
  }
}
