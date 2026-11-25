#include <iostream>
#include <string>

// ============================================================================
// CONCEPT: Copy Constructor
// ============================================================================
// - A Copy Constructor initializes an object using another object of the same class.
// - Signature: ClassName(const ClassName& source);
// - When is it invoked?
//     1. Passing an object by value to a function.
//     2. Returning an object by value from a function.
//     3. Initializing an object with another (e.g., Book b2 = b1;).
// ============================================================================

class Book {
private:
    std::string title;
    std::string author;
    int pages;

public:
    // Parameterized constructor
    Book(std::string t, std::string a, int p)
        : title(t), author(a), pages(p) {
        std::cout << "Normal constructor called for: " << title << "\n";
    }

    // Custom Copy Constructor
    Book(const Book& other)
        : title(other.title + " (Copy)"), author(other.author), pages(other.pages) {
        std::cout << "Copy constructor called to duplicate: " << other.title << "\n";
    }

    void display() const {
        std::cout << "\"" << title << "\" by " << author << " (" << pages << " pages)\n";
    }
};

// Function receiving object by value (triggers copy constructor)
void printBookByValue(Book b) {
    std::cout << "Inside printBookByValue:\n  ";
    b.display();
}

int main() {
    std::cout << "=== Copy Constructor Demo ===\n\n";

    Book original("Clean Code", "Robert C. Martin", 464);
    original.display();

    std::cout << "\n1. Explicitly copying an object:\n";
    Book duplicate = original; // Copy constructor
    duplicate.display();

    std::cout << "\n2. Passing to a function by value:\n";
    printBookByValue(original); // Copy constructor called for parameter

    return 0;
}
