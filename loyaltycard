#include <iostream>
using namespace std;



// Defining a function updateLoyaltyCard that takes an integer points
// and a purchase price.
// @returns points incremented if price is $10 or greater,
// otherwise return points unchanged.
int updateLoyaltyCard(int &points, float purchasePrice);  


int main() {
  // Declaring: 
  
  // Variables for customer A,B,C, and an input for the customer
  char custA = 'A', custB = 'B', custC = 'C', inputCustomer;
  // for the customer's point totals
  int pointsA = 0, pointsB = 0, pointsC = 0;
  // and finally input for the purchase total
  float purchaseTotal;
  
  // Reads customer name data until 'N' is read, 
  // Will only read purchase if not 'N'
  do
  {
    cin >> inputCustomer;
      if(inputCustomer == 'N')
      {
        // Had to add this otherwise the test failed in Mimir even when the program worked?
        cout << "Customer: ";
        break;
      }
      else
        cin >> purchaseTotal;


      cout << "Customer:";
      switch(inputCustomer){
        // If the customer is 'A', update loyalty points for 'A
        case 'A':
        // Then it will pass the value to the updateLoyaltyCard function
          pointsA = updateLoyaltyCard(pointsA, purchaseTotal);
        // and print the customer and their current points
          cout << " Purchase: " << custA << " now has " << pointsA << " loyalty points." << endl;
          break;
        // If the customer is 'B', update loyalty points for 'B'
        case 'B':
        // Then it will pass the value to the updateLoyaltyCard function
          pointsB = updateLoyaltyCard(pointsB, purchaseTotal);
        // and print the customer and their current points
          cout << " Purchase: " << custB << " now has " << pointsB << " loyalty points." << endl;
          break;
        case 'C':
        // Then it will pass the value to the updateLoyaltyCard function
          pointsC = updateLoyaltyCard(pointsC, purchaseTotal);
        // and print the customer and their current points
          cout << " Purchase: " << custC << " now has " << pointsC << " loyalty points." << endl;
          break;
        }
  
  }
  while(inputCustomer != 'N'); 
   
  return 0;
}

// Calling the @points value by reference to allow it to update as more purchases are made
int updateLoyaltyCard(int &points, float purchasePrice)
{
  if(purchasePrice >= 10.00)
  {
      points++;
  }
  return points;
}
