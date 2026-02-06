#include <iostream>
#include <vector>
using namespace std;

int main() {
   vector<int> myVector(3);
   int myVectorSize;
   int numExtra;
   int i;
   
   myVector.at(0) = 5;
	myVector.at(1) = 6;
	myVector.at(2) = 7;
   
   cin >> numExtra;
   
   cout << "Start ";
	for (i = 0; i < myVector.size(); ++i) {
      cout << myVector.at(i) << " ";
   }
	cout << "End" << endl;


    myVectorSize = myVector.size();
    myVector.resize(myVectorSize + numExtra);

    // There is a more efficient wayt to initialize all new variables
    // without explicit user defined loop
   for (i = 3; i < numExtra + myVectorSize; ++i) {
		myVector.at(i) = 1;
	}

	
	cout << "Start ";
	for (i = 0; i < myVector.size(); ++i) {
      cout << myVector.at(i) << " ";
   }
	cout << "End" << endl;

   return 0;
}