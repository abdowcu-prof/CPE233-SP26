#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>    // Enables use of time() function
using namespace std;

int main() {
   const int NUM_ELEMENTS = 8;      // Number of elements to add
   vector<int> userVals;            // Empty vector for user values
   unsigned int i;                  // Loop index
   int val;                         // Element value
   int sumVal;                      // Sum of elements
   
   
    srand(time(0));  // Unique seed

   cout << "Enter " << NUM_ELEMENTS << " integer values..." << endl;
   for (i = 0; i < NUM_ELEMENTS; ++i) {
      
      
      val = rand();
      cout << val << endl;
      userVals.push_back(val);
   }

   sumVal = 0;
   for (i = 0; i < userVals.size(); ++i) {
      sumVal = sumVal + userVals.at(i);
   }
   cout << "Sum of elements: " << sumVal << endl;

   return 0;
}