#include <iostream>
#include <chrono>
#include <vector>
#include <numeric>
using namespace std;

int main() {
   const int NUM_ROWS = 1000;
   const int NUM_COLS = 500;
   int milesTracker[NUM_ROWS][NUM_COLS];
   int i;
   int j;
   int maxMiles = 0;
   int minMiles = 0;
   int value;
   
   
    // additional syntax to calculate how long it takes
    // to travese an array in linear search algorithm

       // 1. Record start time
    auto start = std::chrono::high_resolution_clock::now();


   // Read input values into the 2D array
   for (i = 0; i < NUM_ROWS; i++) {
      for (j = 0; j < NUM_COLS; j++) {
         
         milesTracker[i][j] = 10;
      }
   }


    // 2. Record end time
    auto finish = std::chrono::high_resolution_clock::now();

    // 3. Calculate duration
    std::chrono::duration<double, std::milli> elapsed = finish - start;
    
    std::cout << "Elapsed time: " << elapsed.count() << " ms\n";

    
    // Initialize max and min to the first element
   maxMiles = milesTracker[0][0];
   minMiles = milesTracker[0][0];

   // Find minimum and maximum values
   for (i = 0; i < NUM_ROWS; i++) {
      for (j = 0; j < NUM_COLS; j++) {

         if (milesTracker[i][j] > maxMiles) {
            maxMiles = milesTracker[i][j];
         }

         if (milesTracker[i][j] < minMiles) {
            minMiles = milesTracker[i][j];
         }

      }
   }

   cout << "Min miles: " << minMiles << endl;
   cout << "Max miles: " << maxMiles << endl;

   
   return 0;
}
