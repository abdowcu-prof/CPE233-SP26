#include <iostream>
#include <vector>
using namespace std;

int main() {
   const int SIZE_LIST = 4;
   vector<int> keysList;
   vector<int> itemsList;
   unsigned int i;
   int input;

   for (i = 0; i < SIZE_LIST; ++i) {
      cin >> input;
      keysList.push_back(input);
   }

   for (i = 0; i < SIZE_LIST; ++i) {
      cin >> input;
      itemsList.push_back(input);
   }

   /* Your solution goes here  */
   for (int i = 0; i < keysList.size(); ++i)
   {
       
       if (keysList.at(i) > 100 )
       {
           
           cout << itemsList.at(i) << endl;
       }
   }

   cout << endl;

   return 0;
}