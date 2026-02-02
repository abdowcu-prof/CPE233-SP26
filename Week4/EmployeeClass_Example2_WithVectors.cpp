#include <iostream>
#include <string>
#include <vector>
#include <random>

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
    


    void showInfo() const {
        cout << "Name: " << name << ", ID: " << id << endl;
    }
    
    
    
    
};

// Derived class 1 - child 1
// default inheritance type which gives you the default access level to anything that is either public or protected
class FullTimeEmployee : public Employee {
    double monthlySalary;

public:
    FullTimeEmployee(){}

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
    
    PartTimeEmployee(){}

    PartTimeEmployee(string n, int i, double rate, int hours)
        : Employee(n, i), hourlyRate(rate), hoursWorked(hours) {}

    double getPay() const {
        return hourlyRate * hoursWorked;
    }
};

string makeRandomName(mt19937 &rng) {
    uniform_int_distribution<int> dist(0, 999);
    int x = dist(rng);

    // Build "Emp" + 3 digits
    string s = "Emp";
    s += char('0' + (x / 100) % 10);
    s += char('0' + (x / 10) % 10);
    s += char('0' + (x / 1) % 10);
    return s;
}


int main() {
    
    // Random engine
    random_device rd;
    mt19937 rng(rd());

        // Random ranges
    uniform_int_distribution<int> idDist(1000, 9999);
    uniform_real_distribution<double> salaryDist(3000.0, 15000.0);   // monthly
    uniform_real_distribution<double> rateDist(5.0, 50.0);           // per hour
    uniform_int_distribution<int> hoursDist(5, 60);                  // hours worked

    vector<FullTimeEmployee> fullTimers;
    vector<PartTimeEmployee> partTimers;
    
    fullTimers.reserve(50);
    partTimers.reserve(50);


    // Create 50 FullTimeEmployee (traditional coding)
    for (int i = 0; i < 50; i++) {
        string name = makeRandomName(rng);
        int id = idDist(rng);
        double salary = salaryDist(rng);
        //automatically create new object and push it at the back 
        // starting at the last empty spot
        
        fullTimers.emplace_back(name, id, salary);
    }


    cout << fullTimers.size() << endl;
    cout <<fullTimers.capacity()<< endl;
    


    // Add another  50 Employees after resizing
    // utilizing more nice C++ features
    int startIndex = fullTimers.size(); 
    for (int i = startIndex; i < 100; i++) {
        
        // create random values that I need 
        // create a new instancc of the class
        string name = makeRandomName(rng);
        int id = idDist(rng);
        double salary = salaryDist(rng);
        // create new object using the generated values
        FullTimeEmployee myNewEntry(name, id, salary);
        // Push this new object into the vector at the back
        
        fullTimers.push_back(myNewEntry);
    }
 
 
    cout << fullTimers.size() << endl;
    cout <<fullTimers.capacity()<< endl;
    

    // Print all fulltime employees records using C++ built iterators
   cout << "Full-time employees " << endl;
     for (vector<FullTimeEmployee>::iterator it = fullTimers.begin(); it != fullTimers.end(); ++it) {

        // since we are using classes, now we use the '->' pointer operator to 
        // point to the function 
        it->showInfo();
        cout << "Monthly Pay: " << it->getPay() << "\n\n";

    }





  
   
  
    return 0;
}
