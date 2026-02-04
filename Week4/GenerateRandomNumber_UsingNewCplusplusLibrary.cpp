#include <iostream>
#include <vector>
//#include <cstdlib>
//#include <ctime>    // Enables use of time() function
#include <random>

using namespace std;

int main() {
   const int NUM_ELEMENTS = 8;      // Number of elements to add
   vector<int> userVals;            // Empty vector for user values
   unsigned int i;                  // Loop index
   int val;                         // Element value
   int sumVal;                      // Sum of elements
   
   
    // Random device provides non-deterministic
    //seed to the rng mt19937 algorithm
    random_device rd;
    mt19937 rng(rd());

    // Random generation with fixed seed for
    // reproducible scenarios
    // you can use any value you want for this
    // repeatable scenario
   // uint32_t seed = 27346;
  //  mt19937 rng(seed);

    // Random ranges
    uniform_int_distribution<int> myDistribution(1000, 9999);



   cout << "Enter " << NUM_ELEMENTS << " integer values..." << endl;
   for (i = 0; i < NUM_ELEMENTS; ++i) {
      
      
      val = myDistribution(rng);
      cout << val << endl;
      userVals.push_back(val);
   }

   sumVal = 0;
   for (i = 0; i < userVals.size(); ++i) {
      sumVal = sumVal + userVals.at(i);
   }
   cout << "Sum of elements: " << sumVal << endl;
   
   
   int maxVal = userVals.at(0);
   for (i = 0; i < userVals.size(); ++i) {
      if (userVals.at(i) > maxVal) {
         maxVal = userVals.at(i);
      }
    }
   cout << "Max of elements: " << maxVal << endl;
   
   

   return 0;
}