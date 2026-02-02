#include <iostream>
#include <string>
using namespace std;

// Base class
class Employee {
    
    // private , protected , public
protected:
    string name;
    int id;

public:
    // The constructor method - is responsible for initializing your internal built in data members
    Employee(){};
    
    Employee(string n, int i) : name(n), id(i) {}
    
    Employee(int i) : id(i) {}


    void showInfo() const {
        cout << "Name: " << name << ", ID: " << id << endl;
    }
    
    
    
    
};

// Derived class 1 - child 1
// default inheritance type which gives you the default access level to anything that is either public or protected
class FullTimeEmployee : public Employee {
    double monthlySalary;

public:
    FullTimeEmployee(string n, int i, double salary)
        : Employee(n, i), monthlySalary(salary) {}

    double getPay() const {
        return monthlySalary;
    }
};

// Derived class 2 - child type 2
class PartTimeEmployee : public Employee {
    double hourlyRate;
    int hoursWorked;

public:
    PartTimeEmployee(string n, int i, double rate, int hours)
        : Employee(n, i), hourlyRate(rate), hoursWorked(hours) {}

    double getPay() const {
        return hourlyRate * hoursWorked;
    }
};

int main() {
    
    FullTimeEmployee e1("Ali", 101, 5000);
    PartTimeEmployee e2("Mona", 202, 15, 40);

    e1.showInfo();
    cout << "Pay: " << e1.getPay() << endl;

    e2.showInfo();
    cout << "Pay: " << e2.getPay() << endl;

    return 0;
}
