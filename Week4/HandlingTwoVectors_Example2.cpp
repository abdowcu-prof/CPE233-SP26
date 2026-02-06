#include <iostream>
#include <vector>
using namespace std;

int main() {
   int numElements;
   unsigned int i;
   char charVal;
   double doubleVal;
   
   vector<char> labelList;
   vector<double> weightList;

   

   

   cin >> numElements;

   /* Your code goes here */
   for (i = 0; i < numElements; ++i)
   {
       
       cin >> charVal;
       cin >> doubleVal;
       labelList.push_back(charVal);
       weightList.push_back(doubleVal);
       
   }
   

    cout << endl;
   for (i = 0; i < labelList.size(); ++i) {
      cout << "Label: " << labelList.at(i) << ", ";
      cout << "Weight: " << weightList.at(i) << endl;
   }

   return 0;
}