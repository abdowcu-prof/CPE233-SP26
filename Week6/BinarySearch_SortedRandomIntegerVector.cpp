#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

const int SIZE = 20;

// why passing by reference?
// why passed as const ? 

int binarySearchRecursive(const vector<int>& arr, int left, int right, int target) {


    cout << left << , right << endl;

    if (left > right)
    {
        return -1;
    }
    
   int mid = left + (right - left) / 2;

    if (arr[mid] == target)
        return mid;

    if (target < arr[mid])
        return binarySearchRecursive(arr, left, mid - 1, target);
    else
        return binarySearchRecursive(arr, mid + 1, right, target);
}

int main() {

    vector<int> arr;

    // Modern C++ random generator
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(0, 1000);

    // Fill vector with random numbers
    for (int i = 0; i < SIZE; i++) {
        arr.push_back(dist(gen));
    }

    // Sort the vector (required for binary search)
    sort(arr.begin(), arr.end());

    cout << "Sorted vector:\n";
    for (int value : arr) {
        cout << value << " ";
    }
    cout << endl;

    int target;
    cout << "\nEnter value to search: ";
    cin >> target;

    int result = binarySearchRecursive(arr, 0, arr.size() - 1, target);

    if (result != -1)
        cout << "Value found at index: " << result << endl;
    else
        cout << "Value not found." << endl;

    return 0;
}
