#include <iostream>
#include <string>
using namespace std;

/* Output every possible permutation of a word.
   Each recursive call moves a letter from
   remainLetters to scramLetters.
*/
// this code generates permutations of (n) letters, only when 
// each letter is allowed to be used once. 
// With a the possibility total count = factorial(n) = n!


void ScrambleLetters(string remainLetters,  // Remaining letters
                     string scramLetters) { // Scrambled letters
   string tmpString; // Temp word permutation
   unsigned int i;   // Loop index
   
   if (remainLetters.size() == 0) { // Base case: All letters used
      cout << scramLetters << endl;
   }
   else {                             // Recursive case: move a letter from
                                      // remaining to scrambled letters
      for (i = 0; i < remainLetters.size(); ++i) {
         // Move letter to scrambled letters
         tmpString = remainLetters.substr(i, 1);
         remainLetters.erase(i, 1);
         scramLetters = scramLetters + tmpString;
         
         ScrambleLetters(remainLetters, scramLetters);
         
         // Put letter back in remaining letters
         remainLetters.insert(i, tmpString);
         scramLetters.erase(scramLetters.size() - 1, 1);
      }
   }
}

int main() {
   string wordScramble; // User defined word to scramble
   
   // Prompt user for input
   cout << "Enter a word to be scrambled: ";
   cin >> wordScramble;
   
   // Call recursive function
   ScrambleLetters(wordScramble, "");
   
   return 0;
}