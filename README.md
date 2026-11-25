# C++ Object-Oriented Programming (OOP) Practice Lab

Welcome to your structured C++ Object-Oriented Programming repository! This workspace is designed step-by-step from foundational concepts to advanced design patterns and practical applications.

---

## 📂 Project Structure

```
cpp-oop/
├── 01-classes-and-objects/
│   ├── 01_class_and_object_basics.cpp      # Classes, Objects, Attributes, Methods, Access Specifiers
│   ├── 02_constructors_and_destructor.cpp  # Default & Parameterized Constructors, Initializer Lists, Destructors
│   └── 03_copy_constructor.cpp            # Copy Constructor syntax, by-value copying
├── 02-encapsulation-abstraction/
│   ├── 01_encapsulation.cpp                # Data Hiding, Getters/Setters, State validation
│   └── 02_abstraction.cpp                  # Public interfaces, hiding implementation details
├── 03-inheritance/
│   ├── 01_single_and_multilevel.cpp        # Base & Derived classes, Constructor/Destructor execution order
│   └── 02_multiple_and_hierarchical.cpp    # Multiple inheritance, Diamond Problem & Virtual Base classes
├── 04-polymorphism/
│   ├── 01_compile_time_polymorphism.cpp    # Function overloading & Operator overloading (+, -, <<, ==)
│   ├── 02_runtime_polymorphism_virtual.cpp # Virtual functions, `override`, VTable concept, Virtual Destructors
│   └── 03_abstract_classes_interfaces.cpp  # Pure virtual functions (`= 0`), Abstract classes as Interfaces
├── 05-advanced-oop/
│   ├── 01_static_members.cpp               # Static variables, Static member functions
│   ├── 02_friend_function_and_class.cpp    # `friend` functions & classes
│   └── 03_deep_vs_shallow_copy.cpp         # Pointer members, Deep vs Shallow copy, Rule of Three
├── 06-practice-projects/
│   └── student_management_system.cpp       # Full console project integrating all OOP pillars
└── README.md
```

---

## 🏛️ The 4 Core Pillars of OOP

| Pillar | Concept | In C++ |
| :--- | :--- | :--- |
| **Encapsulation** | Bundling data & operations, hiding sensitive state | `private` / `protected` members, public getters & setters with validation |
| **Abstraction** | Exposing essential behavior while concealing internal complexity | Clean public methods, Abstract Classes (`virtual void func() = 0;`) |
| **Inheritance** | Deriving new classes from existing ones for reusability | `class Derived : public Base` |
| **Polymorphism** | "Many forms": One interface, multiple behaviors | Compile-time (Overloading) & Run-time (`virtual` methods & dynamic binding) |

---

## ⚙️ How to Compile & Run

Open a terminal (PowerShell, Command Prompt, or VS Code terminal) in any module directory and run `g++`:

### 1. Compile with C++17 standard:
```powershell
g++ -std=c++17 01_class_and_object_basics.cpp -o app.exe
```

### 2. Run the executable:
```powershell
.\app.exe
```

---

## 🎯 Practice Challenges for You

1. **Classes & Objects**:
   - Create a `BankAccount` class with `deposit()`, `withdraw()`, and `display()`.
   - Add a constructor with default arguments.

2. **Encapsulation**:
   - Implement an `Employee` class where `setSalary()` does not allow negative numbers or values exceeding a maximum limit.

3. **Inheritance**:
   - Create a hierarchy: `Vehicle` -> `ElectricCar`. Add properties like `batteryCapacity` and a method `charge()`.

4. **Polymorphism**:
   - Overload the `*` operator in a `Matrix2x2` or `Complex` class.
   - Build a payment system where `PaymentMethod` (base) is inherited by `CreditCard`, `PayPal`, and `Crypto` with a `virtual void processPayment(double amount)` method.

5. **Advanced**:
   - Write a dynamic `IntArray` class with dynamic memory allocation implementing the **Rule of Three** (Destructor, Copy Constructor, Copy Assignment Operator).


# cpp-oop
