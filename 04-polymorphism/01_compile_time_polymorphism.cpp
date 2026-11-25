#include <iostream>
#include <string>

// ============================================================================
// CONCEPT: Compile-Time Polymorphism (Static Binding)
// ============================================================================
// 1. Function Overloading: Multiple functions in the same scope with the same
//    name but different parameter types or counts.
// 2. Operator Overloading: Giving custom meaning to standard C++ operators
//    (+, -, *, ==, <<) for user-defined classes.
// ============================================================================

// Part 1: Operator Overloading with 2D Vector
class Vector2D {
private:
    double x;
    double y;

public:
    Vector2D(double xVal = 0.0, double yVal = 0.0) : x(xVal), y(yVal) {}

    // Overloading '+' operator: Vector2D + Vector2D
    Vector2D operator+(const Vector2D& other) const {
        return Vector2D(this->x + other.x, this->y + other.y);
    }

    // Overloading '-' operator: Vector2D - Vector2D
    Vector2D operator-(const Vector2D& other) const {
        return Vector2D(this->x - other.x, this->y - other.y);
    }

    // Overloading '==' equality operator
    bool operator==(const Vector2D& other) const {
        return (this->x == other.x && this->y == other.y);
    }

    // Overloading '<<' stream insertion operator for std::cout << v
    friend std::ostream& operator<<(std::ostream& os, const Vector2D& vec) {
        os << "(" << vec.x << ", " << vec.y << ")";
        return os;
    }
};

// Part 2: Function Overloading
class Calculator {
public:
    int add(int a, int b) {
        return a + b;
    }

    double add(double a, double b) {
        return a + b;
    }

    std::string add(const std::string& a, const std::string& b) {
        return a + " " + b;
    }
};

int main() {
    std::cout << "=== Compile-Time Polymorphism ===\n\n";

    // 1. Function Overloading
    Calculator calc;
    std::cout << "Sum (int): " << calc.add(10, 20) << "\n";
    std::cout << "Sum (double): " << calc.add(3.14, 2.71) << "\n";
    std::cout << "Sum (string): " << calc.add("Hello", "World") << "\n\n";

    // 2. Operator Overloading
    Vector2D v1(3.0, 4.0);
    Vector2D v2(1.5, 2.5);

    Vector2D v3 = v1 + v2; // uses operator+
    Vector2D v4 = v1 - v2; // uses operator-

    std::cout << "v1 = " << v1 << "\n";
    std::cout << "v2 = " << v2 << "\n";
    std::cout << "v1 + v2 = " << v3 << "\n";
    std::cout << "v1 - v2 = " << v4 << "\n";
    std::cout << "v1 == v2? " << (v1 == v2 ? "Yes" : "No") << "\n";

    return 0;
}
