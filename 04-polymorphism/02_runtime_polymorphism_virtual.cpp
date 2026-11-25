#include <iostream>
#include <vector>
#include <memory>

// ============================================================================
// CONCEPT: Run-Time Polymorphism (Dynamic Binding)
// ============================================================================
// - Virtual Functions: Member functions expected to be overridden in derived classes.
// - Dynamic Binding: Function call resolved at runtime using vtable (Virtual Table).
// - Without 'virtual', C++ uses static binding (calls base class method based on pointer type).
// - Crucial Rule: Always declare the base class destructor as 'virtual'!
//   Otherwise, deleting a derived object via a base pointer causes undefined behavior
//   and leaks derived memory.
// ============================================================================

class Animal {
public:
    // Virtual destructor is ESSENTIAL for polymorphic base classes!
    virtual ~Animal() {
        std::cout << "Animal destructor\n";
    }

    // Virtual function for runtime dispatch
    virtual void makeSound() const {
        std::cout << "Generic animal sound\n";
    }

    virtual std::string getSpecies() const {
        return "Unknown Animal";
    }
};

class Dog : public Animal {
public:
    ~Dog() override {
        std::cout << "Dog destructor\n";
    }

    void makeSound() const override {
        std::cout << "Woof! Woof!\n";
    }

    std::string getSpecies() const override {
        return "Dog (Canis lupus familiaris)";
    }
};

class Cat : public Animal {
public:
    ~Cat() override {
        std::cout << "Cat destructor\n";
    }

    void makeSound() const override {
        std::cout << "Meow! Purr...\n";
    }

    std::string getSpecies() const override {
        return "Cat (Felis catus)";
    }
};

int main() {
    std::cout << "=== Run-Time Polymorphism Demo ===\n\n";

    // Polymorphic collection: Storing base pointers to various derived objects
    std::vector<Animal*> zoo;
    zoo.push_back(new Dog());
    zoo.push_back(new Cat());
    zoo.push_back(new Animal());

    std::cout << "\nIterating polymorphically:\n";
    for (const auto* animal : zoo) {
        std::cout << animal->getSpecies() << " says: ";
        animal->makeSound(); // Dispatched at RUNTIME based on true object type!
    }

    std::cout << "\nCleaning up zoo (calls derived destructors first due to virtual ~Animal):\n";
    for (auto* animal : zoo) {
        delete animal;
    }
    zoo.clear();

    return 0;
}
