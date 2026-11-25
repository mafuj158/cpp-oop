#include <iostream>
#include <string>

// ============================================================================
// CONCEPT: Constructors & Destructors
// ============================================================================
// - Constructor: Special method invoked automatically when an object is created.
//   It has the same name as the class and NO return type.
// - Types of Constructors:
//     1. Default Constructor: Takes no arguments.
//     2. Parameterized Constructor: Takes arguments to initialize attributes.
//     3. Constructor Overloading: Multiple constructors with different parameters.
// - Member Initializer List: The preferred, efficient way to initialize members.
// - Destructor: Automatically called when object goes out of scope or is deleted.
//   Prefixed with a tilde (~). Used for resource cleanup (memory, files, sockets).
// ============================================================================

class Smartphone {
private:
    std::string brand;
    std::string model;
    double price;

public:
    // 1. Default Constructor
    Smartphone() : brand("Generic"), model("Phone"), price(0.0) {
        std::cout << "[Default Constructor] Unknown phone created.\n";
    }

    // 2. Parameterized Constructor with Member Initializer List
    Smartphone(std::string b, std::string m, double p) 
        : brand(b), model(m), price(p) {
        std::cout << "[Parameterized Constructor] " << brand << " " << model << " created.\n";
    }

    void display() const {
        std::cout << "Phone: " << brand << " " << model << " | Price: $" << price << "\n";
    }

    // Destructor
    ~Smartphone() {
        std::cout << "[Destructor] Cleaning up resources for " << brand << " " << model << ".\n";
    }
};

int main() {
    std::cout << "=== Constructors & Destructors Demo ===\n\n";

    {
        std::cout << "--- Entering Inner Scope ---\n";
        Smartphone p1; // calls default constructor
        Smartphone p2("Apple", "iPhone 16 Pro", 1199.99); // calls parameterized constructor

        p1.display();
        p2.display();
        std::cout << "--- Exiting Inner Scope (Notice destructor calls) ---\n";
    }

    std::cout << "\nBack in main scope. Program exiting soon.\n";
    return 0;
}
