#include <iostream>
using namespace std;

class Sample {
public:
    int *x;

    Sample(int val) {
        x = new int;
        *x = val;
    }
};

int main() {
    Sample obj1(10);     // Original object
    Sample obj2 = obj1; // Shallow copy

    *obj2.x = 50;       // Modify copied object

    cout << "obj1.x = " << *obj1.x << endl;
    cout << "obj2.x = " << *obj2.x << endl;

    return 0;
}