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
 /*  cin  >> nthPerson;

   if ((nthPerson >= 1) && (nthPerson <= 5)) {
      cout << "The #" << nthPerson << " oldest person lived ";
      cout << oldestPeople.at(nthPerson - 1) << " years." << endl;
   }
*/

   oldestPeople.push_back(90); // Died 1997 in France
   oldestPeople.push_back(2000); // Died 1999 in U.S.
   
   
    cout << "Printing the size and the capacity  " << endl;


    cout << "Size after push_back: " << oldestPeople.size() << "\n";
        
    cout << "Size after push_back: " << oldestPeople.capacity() << "\n";
    
    
    
    cout << " Copy Vector 1 into Vector 2  " << endl;

    oldestPeopleCopy = oldestPeople;
    
    cout << "Printing the size and the capacity of vector 2 " << endl;

    
    cout << "Size after push_back: " << oldestPeopleCopy.size() << "\n";
        
    cout << "Size after push_back: " << oldestPeopleCopy.capacity() << "\n";
    
    
    // Iterating using Regular Loop Counter variable i

    cout << "Regular Loop Counter  " << endl;

   for (int i = 0; i < oldestPeopleCopy.size(); ++i) {
      cout << oldestPeopleCopy.at(i) << endl;
   }

// Fancy way to iterate 

     cout << "using Vector iterators " << endl;
     for (vector<int>::iterator it = oldestPeopleCopy.begin(); it != oldestPeopleCopy.end(); ++it) {
            // Dereference the iterator (*it) to access the element's value
            cout << *it << endl;
        }




   return 0;
}
