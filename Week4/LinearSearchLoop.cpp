#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
   // Source: The World Bank, 2022
   vector<string> ctryNames;   // Country names
   vector<int> ctryGDPs;       // Country annual GDPs (trillions)
   string userCountry;         // User-entered country
   bool foundCountry = false;  // Country-match flag
   unsigned int i;             // Loop index

   ctryNames.push_back("UK");
   ctryGDPs.push_back(3);

   ctryNames.push_back("India");
   ctryGDPs.push_back(3);

   ctryNames.push_back("Canada");
   ctryGDPs.push_back(2);

   ctryNames.push_back("Italy");
   ctryGDPs.push_back(2);

   ctryNames.push_back("Japan");
   ctryGDPs.push_back(4);

   cout << "Enter case-sensitive country to search for: ";
   cin >> userCountry;


    // Is this kind of loop over entire vector search good enough?!
    // Obviously we need another logic/another algorithm that save time 
    //when searching for an item within a list of items
    // the one below is linear searching
    // worst case ? , if the list has (n) elements
    // Big O Notation >> O(n) means it is a function of (n)
    // linear function
   foundCountry = false;
   for (i = 0; i < ctryNames.size() && !foundCountry; ++i) {
      if (ctryNames.at(i) == userCountry) {
         foundCountry = true;
         cout << userCountry << " has an annual GDP of ";
         cout << "$" << ctryGDPs.at(i) << "T." << endl;
      }
      
   }

   if (!foundCountry) {
      cout << "Country not found; try again." << endl;
   }

   return 0;
}
