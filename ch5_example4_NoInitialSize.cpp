#include <iostream>
#include <vector>
using namespace std;

int main() {
   vector<int> oldestPeople;  
   
      vector<int> oldestPeopleCopy;  

   
   int nthPerson;               // User input, Nth oldest person

   oldestPeople.push_back(122); // Died 1997 in France
   oldestPeople.push_back(119); // Died 1999 in U.S.
   oldestPeople.push_back(117); // Died 1993 in U.S. 
   oldestPeople.push_back(117); // Died 1998 in Canada
   oldestPeople.push_back(116); // Died 2006 in Ecuador

    cout << "Size after push_back: " << oldestPeople.size() << "\n";

   cout << "Enter N (1..5): ";
   cin  >> nthPerson;

   if ((nthPerson >= 1) && (nthPerson <= 5)) {
      cout << "The #" << nthPerson << " oldest person lived ";
      cout << oldestPeople.at(nthPerson - 1) << " years." << endl;
   }



   return 0;
}
