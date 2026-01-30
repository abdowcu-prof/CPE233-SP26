#include <iostream>
#include <vector>
using namespace std;

int main() {
   vector<int> userVals;
   unsigned int i;

   userVals.push_back(3);
   userVals.push_back(6);
   userVals.push_back(7);

   for (i = 0; i < userVals.size(); ++i) {
      cout << userVals.at(i) << endl;
   }

   return 0;
}