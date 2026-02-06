#include <iostream>
using namespace std;

int main() {
   const int NUM_ELEMENTS = 8; // Number of elements
   int userVals[NUM_ELEMENTS]; // User numbers
   int i;                      // Loop index
   int tempVal;                // Temp variable for swapping
   
   // Prompt user to input values
   cout << "Enter " << NUM_ELEMENTS << " integer values..." << endl;
   for (i = 0; i < NUM_ELEMENTS; ++i) {
      cout << "Value: ";
      cin >> userVals[i];
   }
   
   // Reverse array's elements
   for (i = 0; i < (NUM_ELEMENTS / 2); ++i) {
      tempVal = userVals[i];                        // Temp for swap
      userVals[i] = userVals[NUM_ELEMENTS - 1 - i]; // First part of swap
      userVals[NUM_ELEMENTS - 1 - i] = tempVal;     // Second complete
   }
   
   // Print numbers
   cout << endl << "New values: ";
   for (i = 0; i < NUM_ELEMENTS; ++i) {
      cout << userVals[i] << " ";
   }
   
   return 0;
}