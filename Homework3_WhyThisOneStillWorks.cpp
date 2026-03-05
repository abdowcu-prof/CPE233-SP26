#include <iostream>
#include <string>
#include <stdexcept>
#include <exception>

#include <stacktrace>
#include <vector>

using namespace std;

class Restaurant {                          // Info about a restaurant
   public:
     Restaurant (){};
      Restaurant (string namexx, int rate);
      void SetName(string restaurantName);  // Sets the restaurant's name
      void SetRating(int userRating);       // Sets the rating (1-5, with 5 best)
      void Print();                         // Prints name and rating on one line
    
   private:
      string name;
      int rating;
};


 Restaurant::Restaurant(string namexx, int rate) {
   name = namexx;
   rating = rate;
}



// Sets the restaurant's name
void Restaurant::SetName(string restaurantName) {
   name = restaurantName;
}

// Sets the rating (1-5, with 5 best)
void Restaurant::SetRating(int userRating) {
   rating = userRating;
}

// Prints name and rating on one line
void Restaurant::Print() {
   cout << name << " -- " << rating << endl;
}

int main() {
    
        vector<Restaurant> sylvaAllBusiness(100);
        vector<int> myVector(3);

   Restaurant favLunchPlace ("Tai friends", 5);
   Restaurant favDinnerPlace ("HEllo sylava", 3);
   
      
    for (int i = 0; i < 100; i++) {
        
        // create random values that I need 
        // create a new instancc of the class
        string name = "Hakona";
        int rate =9; 
        
        Restaurant myTemp(name, rate);
        
        
        
            sylvaAllBusiness.at(i) = myTemp;
        
        
    }
 
      
   
   cout << "My favorite restaurants: " << endl;

   cout << sylvaAllBusiness.size();
   
   cout << "\n";
   
   
    for (int i = 0; i < 100; i++) {
        
        // create random values that I need 
        // create a new instancc of the class
       

        sylvaAllBusiness.at(i).Print();
    }
   
   return 0;
}