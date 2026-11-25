#include <iostream>
#include <cstring>

// ============================================================================
// CONCEPT: Deep Copy vs Shallow Copy & Rule of Three
// ============================================================================
// - Shallow Copy: Copies pointer addresses directly. Both objects point to the
//   SAME memory block. When one destructor frees it, the other is left with a
//   dangling pointer -> double-free crash!
// - Deep Copy: Allocates new memory and copies the actual values into it.
// - Rule of Three: If a class needs a custom Destructor, Copy Constructor,
//   or Copy Assignment Operator (operator=), it almost certainly needs ALL THREE.
// ============================================================================

class DynamicString {
private:
    char* data;
    size_t length;

public:
    // Constructor
    DynamicString(const char* str = "") {
        length = std::strlen(str);
        data = new char[length + 1];
        std::strcpy(data, str);
        std::cout << "[Constructed] Allocated: \"" << data << "\"\n";
    }

    // 1. Destructor
    ~DynamicString() {
        std::cout << "[Destructor] Deallocating: \"" << (data ? data : "null") << "\"\n";
        delete[] data;
    }

    // 2. Deep Copy Constructor
    DynamicString(const DynamicString& other) {
        length = other.length;
        data = new char[length + 1]; // Separate memory allocation!
        std::strcpy(data, other.data);
        std::cout << "[Deep Copy Constructor] Cloned: \"" << data << "\"\n";
    }

    // 3. Deep Copy Assignment Operator
    DynamicString& operator=(const DynamicString& other) {
        if (this == &other) {
            return *this; // Self-assignment check
        }
        delete[] data; // Free current resources
        length = other.length;
        data = new char[length + 1];
        std::strcpy(data, other.data);
        std::cout << "[Deep Copy Assignment] Assigned: \"" << data << "\"\n";
        return *this;
    }

    void modify(const char* newStr) {
        delete[] data;
        length = std::strlen(newStr);
        data = new char[length + 1];
        std::strcpy(data, newStr);
    }

    void print() const {
        std::cout << "String content: \"" << data << "\" (Address: " << (void*)data << ")\n";
    }
};

int main() {
    std::cout << "=== Deep Copy vs Shallow Copy Demo ===\n\n";

    DynamicString s1("Original Data");
    DynamicString s2 = s1; // Deep copy constructor

    std::cout << "\nBefore modification:\n";
    std::cout << "s1: "; s1.print();
    std::cout << "s2: "; s2.print();

    // Modifying s1 will NOT affect s2 because memory addresses are different!
    std::cout << "\nModifying s1...\n";
    s1.modify("Modified Data");

    std::cout << "s1: "; s1.print();
    std::cout << "s2: "; s2.print(); // s2 remains unharmed!

    return 0;
}
