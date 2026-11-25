#include <iostream>

// ============================================================================
// CONCEPT: Friend Functions and Friend Classes
// ============================================================================
// - 'friend' keyword grants an external function or class full access to
//   private and protected members of this class.
// - Use judiciously: Overusing friends can weaken encapsulation.
// ============================================================================

class Box {
private:
    double width;
    double height;
    double depth;

public:
    Box(double w, double h, double d) : width(w), height(h), depth(d) {}

    // Declare friend function
    friend void printBoxDimensions(const Box& b);

    // Declare friend class
    friend class BoxInspector;
};

// Non-member friend function
void printBoxDimensions(const Box& b) {
    // Can access private width, height, depth directly!
    std::cout << "[Friend Function] Box: " << b.width << " x " << b.height << " x " << b.depth << "\n";
}

// Friend class
class BoxInspector {
public:
    double calculateVolume(const Box& b) {
        return b.width * b.height * b.depth;
    }

    bool isCube(const Box& b) {
        return (b.width == b.height && b.height == b.depth);
    }
};

int main() {
    std::cout << "=== Friend Function & Friend Class Demo ===\n\n";

    Box parcel(10.0, 10.0, 10.0);

    printBoxDimensions(parcel);

    BoxInspector inspector;
    std::cout << "Volume: " << inspector.calculateVolume(parcel) << " cm^3\n";
    std::cout << "Is Cube: " << (inspector.isCube(parcel) ? "Yes" : "No") << "\n";

    return 0;
}
