#include <iostream>
#include <string>

// ============================================================================
// CONCEPT: Single & Multilevel Inheritance
// ============================================================================
// - Inheritance allows a class (Derived/Child) to inherit attributes and methods
//   from another class (Base/Parent), promoting code reusability.
// - Single Inheritance: A -> B
// - Multilevel Inheritance: A -> B -> C
// - Construction Order: Base constructor runs FIRST, then Derived constructor.
// - Destruction Order: Derived destructor runs FIRST, then Base destructor.
// ============================================================================

// Base Class
class Person {
protected:
    std::string name;
    int age;

public:
    Person(std::string n, int a) : name(n), age(a) {
        std::cout << "  [Person Constructor] Initializing " << name << "\n";
    }

    void introduce() const {
        std::cout << "Hi, I am " << name << ", " << age << " years old.\n";
    }

    ~Person() {
        std::cout << "  [Person Destructor] Cleaning up " << name << "\n";
    }
};

// Single Inheritance: Employee inherits from Person
class Employee : public Person {
protected:
    int employeeId;
    double salary;

public:
    // Pass arguments to Base class constructor
    Employee(std::string n, int a, int id, double sal)
        : Person(n, a), employeeId(id), salary(sal) {
        std::cout << "  [Employee Constructor] Initializing ID " << employeeId << "\n";
    }

    void showEmployeeDetails() const {
        introduce(); // Call inherited method
        std::cout << "Employee ID: " << employeeId << " | Salary: $" << salary << "\n";
    }

    ~Employee() {
        std::cout << "  [Employee Destructor] Cleaning up Employee ID " << employeeId << "\n";
    }
};

// Multilevel Inheritance: Manager inherits from Employee
class Manager : public Employee {
private:
    int teamSize;

public:
    Manager(std::string n, int a, int id, double sal, int team)
        : Employee(n, a, id, sal), teamSize(team) {
        std::cout << "  [Manager Constructor] Managing team of " << teamSize << "\n";
    }

    void conductMeeting() const {
        std::cout << name << " is hosting a standup meeting with " << teamSize << " engineers.\n";
    }

    ~Manager() {
        std::cout << "  [Manager Destructor] Cleaning up Manager\n";
    }
};

int main() {
    std::cout << "=== Single & Multilevel Inheritance Demo ===\n\n";

    {
        std::cout << "Creating a Manager (Watch constructor order):\n";
        Manager mgr("Sarah Connor", 38, 5001, 125000, 8);
        std::cout << "\nDisplaying info:\n";
        mgr.showEmployeeDetails();
        mgr.conductMeeting();
        std::cout << "\nLeaving scope (Watch destructor order):\n";
    }

    return 0;
}
