#include <iostream>
#include <string>

// ============================================================================
// CONCEPT: Multiple Inheritance & The Diamond Problem
// ============================================================================
// - Multiple Inheritance: A class can inherit from more than one base class.
//   Class C : public ClassA, public ClassB
// - Diamond Problem:
//         PoweredDevice
//          /         \
//       Scanner     Printer
//          \         /
//           Copier
//   Without 'virtual' inheritance, Copier would receive TWO copies of PoweredDevice,
//   causing ambiguity and waste of memory.
// - Solution: Virtual Base Classes (`virtual public PoweredDevice`).
// ============================================================================

class PoweredDevice {
public:
    int powerWatts;
    PoweredDevice(int watts = 0) : powerWatts(watts) {
        std::cout << "PoweredDevice constructed with " << powerWatts << "W\n";
    }
};

// Virtual inheritance avoids duplicate subobjects in derived classes
class Scanner : virtual public PoweredDevice {
public:
    Scanner(int watts) : PoweredDevice(watts) {
        std::cout << "Scanner initialized\n";
    }
    void scanDocument() {
        std::cout << "Scanning document to PDF...\n";
    }
};

class Printer : virtual public PoweredDevice {
public:
    Printer(int watts) : PoweredDevice(watts) {
        std::cout << "Printer initialized\n";
    }
    void printDocument() {
        std::cout << "Printing high-res document...\n";
    }
};

// Copier inherits from both Scanner and Printer
class Copier : public Scanner, public Printer {
public:
    // With virtual base, the most-derived class initializes PoweredDevice directly
    Copier(int watts) : PoweredDevice(watts), Scanner(watts), Printer(watts) {
        std::cout << "Copier combo initialized\n";
    }
};

int main() {
    std::cout << "=== Multiple Inheritance & Diamond Problem Demo ===\n\n";

    Copier allInOne(350);
    allInOne.scanDocument();
    allInOne.printDocument();

    // No ambiguity about powerWatts because of virtual inheritance!
    std::cout << "Total Device Power: " << allInOne.powerWatts << "W\n";

    return 0;
}
