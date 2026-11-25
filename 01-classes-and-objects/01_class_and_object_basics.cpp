#include <iostream>
#include <string>

// ============================================================================
// CONCEPT: Classes & Objects Basics in C++
// ============================================================================
// - A Class is a user-defined blueprint/data type.
// - An Object is an instance of a class that occupies memory.
// - Access specifiers:
//     - private: Accessible only within the class (default in C++ class).
//     - public:  Accessible from outside the class.
// ============================================================================

class Car {
private:
    // Member variables (Attributes) - Kept private for data protection
    std::string brand;
    std::string model;
    int year;
    int speed;

public:
    // Member function to initialize data
    void setDetails(std::string b, std::string m, int y) {
        brand = b;
        model = m;
        year = y;
        speed = 0;
    }

    // Member function (Method) to accelerate
    void accelerate(int amount) {
        speed += amount;
        std::cout << brand << " " << model << " accelerated to " << speed << " km/h.\n";
    }

    // Member function to display car info
    void displayInfo() const {
        std::cout << "------------------------\n";
        std::cout << "Car: " << year << " " << brand << " " << model << "\n";
        std::cout << "Current Speed: " << speed << " km/h\n";
        std::cout << "------------------------\n";
    }
};

class Player {
private:
    std::string name;
    int salary;

public:
    // Member function to set player details
    void setDetails(std::string n, int s) {
        name = n;
        salary = s;
    }

    // Member function to display player details
    void displayInfo() const {
        std::cout << "Player: " << name << " | Salary: $" << salary << "\n";
    }
};





int main() {
    std::cout << "=== OOP Basics: Classes & Objects ===\n\n";

    // 1. Creating an object on the Stack
    // Car car1;
    // car1.setDetails("Toyota", "Corolla", 2022);
    // car1.displayInfo();
    // car1.accelerate(45);
    // car1.accelerate(25);
    // car1.displayInfo();

    // 2. Creating an object dynamically on the Heap
    // Car* car2 = new Car();
    // car2->setDetails("Tesla", "Model 3", 2024);
    // car2->accelerate(80);
    // car2->displayInfo();

    Player player1;
    player1.setDetails("Ronaldo", 1000000);
    player1.displayInfo();
    

    // Always release heap memory
    // delete car2;
    // car2 = nullptr;

    return 0;
}
