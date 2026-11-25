#include <iostream>
#include <vector>
#include <cmath>

// ============================================================================
// CONCEPT: Pure Virtual Functions & Abstract Classes (Interfaces)
// ============================================================================
// - Pure Virtual Function: A function with `= 0` in its declaration.
//     virtual void draw() = 0;
// - Abstract Class: A class containing at least ONE pure virtual function.
//     Cannot be instantiated directly! (e.g. Shape s; is illegal).
// - Subclasses MUST override all pure virtual functions to become concrete classes.
// ============================================================================

// Abstract Base Class / Interface
class Shape {
public:
    virtual ~Shape() = default;

    // Pure virtual functions:
    virtual double calculateArea() const = 0;
    virtual double calculatePerimeter() const = 0;
    virtual void printDetails() const = 0;
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double calculateArea() const override {
        return M_PI * radius * radius;
    }

    double calculatePerimeter() const override {
        return 2.0 * M_PI * radius;
    }

    void printDetails() const override {
        std::cout << "Circle (radius: " << radius << ") -> Area: " 
                  << calculateArea() << " | Perimeter: " << calculatePerimeter() << "\n";
    }
};

class Rectangle : public Shape {
private:
    double width;
    double height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}

    double calculateArea() const override {
        return width * height;
    }

    double calculatePerimeter() const override {
        return 2.0 * (width + height);
    }

    void printDetails() const override {
        std::cout << "Rectangle (" << width << "x" << height << ") -> Area: " 
                  << calculateArea() << " | Perimeter: " << calculatePerimeter() << "\n";
    }
};

int main() {
    std::cout << "=== Abstract Classes & Pure Virtual Functions ===\n\n";

    // Shape s; // COMPILE ERROR! Cannot instantiate abstract class

    std::vector<Shape*> shapes;
    shapes.push_back(new Circle(5.0));
    shapes.push_back(new Rectangle(4.0, 6.0));
    shapes.push_back(new Circle(2.5));

    for (const auto* s : shapes) {
        s->printDetails();
    }

    for (auto* s : shapes) {
        delete s;
    }

    return 0;
}
