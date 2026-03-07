#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Review {
   public:
      void SetRatingAndComment(int revRating, string revComment) {
         rating = revRating;
         comment = revComment;
      }
      int GetRating() const { return rating; }
      string GetComment() const { return comment; }

   private:
      int rating = -1;
      string comment = "NoComment";
};
// END Review class


class Reviews {
   public:
      void InputReviews();
      void PrintCommentsForRating(int currRating) const;
      int GetAverageRating() const;

   private:
      vector<Review> reviewList;
};

// Get rating comment pairs, add each to list. -1 rating ends.
void Reviews::InputReviews() {
   Review currReview;
   int currRating;
   string currComment;

   cin >> currRating;
   while (currRating >= 0) {
      getline(cin, currComment); // Gets rest of line
      currReview.SetRatingAndComment(currRating, currComment);
      reviewList.push_back(currReview);
      cin >> currRating;
   }
}

// Print all comments for reviews having the given rating
void Reviews::PrintCommentsForRating(int currRating) const {
   Review currReview;
   unsigned int i;

   for (i = 0; i < reviewList.size(); ++i) {
      currReview = reviewList.at(i);
      if (currRating == currReview.GetRating()) {
         cout << currReview.GetComment() << endl;
      }
   }
}

int Reviews::GetAverageRating() const {
   int ratingsSum;
   unsigned int i;

   ratingsSum = 0;
   for (i = 0; i < reviewList.size(); ++i) {
      ratingsSum += reviewList.at(i).GetRating();
   }
   return (ratingsSum / reviewList.size());
}
// END Reviews class

class Restaurant {
   public:
      void SetName(string restaurantName) {
         name = restaurantName;
      }
      void ReadAllReviews();
      void PrintCommentsByRating() const;

   private:
      string name;
      Reviews reviews;
};

void Restaurant::ReadAllReviews() {
   cout << "Type ratings + comments. To end: -1" << endl;
   reviews.InputReviews();
}

void Restaurant::PrintCommentsByRating() const {
   int i;

   cout << "Comments for each rating level: " << endl;
   for (i = 1; i <= 5; ++i) {
     cout << i << ":" << endl;
     reviews.PrintCommentsForRating(i);
   }
}

int main() {
   Restaurant ourPlace;
   string currName;

   cout << "Type restaurant name: " << endl;
   getline(cin, currName);
   ourPlace.SetName(currName);
   cout << endl;

   ourPlace.ReadAllReviews();
   cout << endl;

   ourPlace.PrintCommentsByRating();

   return 0;
}


