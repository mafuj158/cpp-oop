#include <iostream>
#include <string>

// ============================================================================
// CONCEPT: Abstraction
// ============================================================================
// - Abstraction means showing only essential features to the outside world
//   while hiding the complex background implementation details.
// - Analogy: Driving a car. You press the gas pedal (simple interface),
//   without needing to manually manage fuel injection, air-fuel ratio, or spark timing.
// ============================================================================

class CoffeeMachine {
private:
    int waterLevelMl;
    int coffeeBeansGrams;

    // Private helper methods - Complex internal processes hidden from user
    bool checkSupplies() {
        if (waterLevelMl < 200) {
            std::cout << "[Internal Check] Not enough water!\n";
            return false;
        }
        if (coffeeBeansGrams < 15) {
            std::cout << "[Internal Check] Not enough coffee beans!\n";
            return false;
        }
        return true;
    }

    void boilWater() {
        std::cout << "[Internal Step] Heating water to 93C...\n";
    }

    void grindBeans() {
        std::cout << "[Internal Step] Grinding fresh coffee beans...\n";
        coffeeBeansGrams -= 15;
    }

    void brew() {
        std::cout << "[Internal Step] Extracting espresso under 9 bars of pressure...\n";
        waterLevelMl -= 200;
    }

public:
    CoffeeMachine(int water, int beans) 
        : waterLevelMl(water), coffeeBeansGrams(beans) {}

    // Public simple interface - The user only calls this!
    void makeEspresso() {
        std::cout << "\nPreparing your Espresso:\n";
        if (!checkSupplies()) {
            std::cout << "Cannot make coffee. Please refill supplies.\n";
            return;
        }
        boilWater();
        grindBeans();
        brew();
        std::cout << "Your rich Espresso is ready! Enjoy!\n";
    }
};


class Shape {

    virtual void draw() = 0;


};
class Circle : public Shape{
    public:
        void draw(){
            std::cout <<"Drawing circle"<<std::endl;
        }

};

class Rectangle : public Shape{
    public:
        void draw(){
            std::cout <<"Drawing Rectangle"<<std::endl;
        }

};




int main() {
    std::cout << "=== Abstraction Demo ===\n";

    CoffeeMachine machine(500, 50);

    // The user interacts with high-level abstraction:
    machine.makeEspresso();
    machine.makeEspresso();


    // pol
    Circle c1;
    c1.draw();

    return 0;
}
