#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <iomanip>

// ============================================================================
// PRACTICE PROJECT: University Member Management System
// ============================================================================
// This project synthesizes the core pillars of Object-Oriented Programming:
// 1. Classes & Objects: Clear modeling of entities (Person, Student, Professor).
// 2. Encapsulation: Sensitive data (ID, GPA, Salary) protected with accessors.
// 3. Inheritance: Reusable base class Person extended by Student & Professor.
// 4. Polymorphism: Virtual functions for role-specific behavior dispatch.
// ============================================================================

// Base Class
class Person {
protected:
    int id;
    std::string name;
    std::string email;

public:
    Person(int personId, const std::string& personName, const std::string& personEmail)
        : id(personId), name(personName), email(personEmail) {}

    virtual ~Person() = default; // Essential virtual destructor

    // Getters
    int getId() const { return id; }
    std::string getName() const { return name; }
    std::string getEmail() const { return email; }

    // Pure virtual method (Abstraction & Polymorphism)
    virtual void printDetails() const = 0;
    virtual std::string getRole() const = 0;
};

// Derived Class 1: Student
class Student : public Person {
private:
    std::string major;
    double gpa;

public:
    Student(int sId, const std::string& sName, const std::string& sEmail, 
            const std::string& sMajor, double sGpa)
        : Person(sId, sName, sEmail), major(sMajor), gpa(sGpa) {}

    void setGpa(double newGpa) {
        if (newGpa >= 0.0 && newGpa <= 4.0) {
            gpa = newGpa;
        } else {
            std::cout << "Invalid GPA value. Must be between 0.0 and 4.0\n";
        }
    }

    double getGpa() const { return gpa; }
    std::string getMajor() const { return major; }

    std::string getRole() const override {
        return "Student";
    }

    void printDetails() const override {
        std::cout << "[STUDENT] ID: " << std::setw(4) << id
                  << " | Name: " << std::setw(15) << std::left << name
                  << " | Major: " << std::setw(12) << major
                  << " | GPA: " << std::fixed << std::setprecision(2) << gpa
                  << " | Email: " << email << "\n";
    }
};

// Derived Class 2: Professor
class Professor : public Person {
private:
    std::string department;
    double salary;

public:
    Professor(int pId, const std::string& pName, const std::string& pEmail,
              const std::string& dept, double sal)
        : Person(pId, pName, pEmail), department(dept), salary(sal) {}

    std::string getRole() const override {
        return "Professor";
    }

    void printDetails() const override {
        std::cout << "[PROFESSOR] ID: " << std::setw(2) << id
                  << " | Name: " << std::setw(15) << std::left << name
                  << " | Dept: " << std::setw(13) << department
                  << " | Salary: $" << std::fixed << std::setprecision(2) << salary
                  << " | Email: " << email << "\n";
    }
};

// University Directory Manager (Demonstrates composition & container of polymorphic objects)
class UniversityDirectory {
private:
    std::vector<std::unique_ptr<Person>> members;

public:
    void addMember(std::unique_ptr<Person> person) {
        members.push_back(std::move(person));
    }

    void listAllMembers() const {
        std::cout << "\n================= UNIVERSITY DIRECTORY =================" << std::endl;
        if (members.empty()) {
            std::cout << "No members in the directory.\n";
            return;
        }
        for (const auto& member : members) {
            member->printDetails(); // Polymorphic dispatch!
        }
        std::cout << "========================================================\n\n";
    }

    void findById(int searchId) const {
        std::cout << "\nSearching for ID: " << searchId << "...\n";
        for (const auto& member : members) {
            if (member->getId() == searchId) {
                std::cout << "Match found!\n";
                member->printDetails();
                return;
            }
        }
        std::cout << "No member found with ID: " << searchId << "\n";
    }
};

int main() {
    std::cout << "========================================================\n";
    std::cout << "   WELCOME TO THE OOP UNIVERSITY DIRECTORY SYSTEM        \n";
    std::cout << "========================================================\n";

    UniversityDirectory directory;

    // Adding polymorphic objects using modern smart pointers (unique_ptr)
    directory.addMember(std::make_unique<Student>(101, "Alice Walker", "alice@univ.edu", "Computer Sci", 3.85));
    directory.addMember(std::make_unique<Student>(102, "Bob Martin", "bob@univ.edu", "Electrical Eng", 3.42));
    directory.addMember(std::make_unique<Professor>(201, "Dr. Ada Lovelace", "ada@univ.edu", "Computer Sci", 98000.0));
    directory.addMember(std::make_unique<Professor>(202, "Dr. Alan Turing", "alan@univ.edu", "Mathematics", 105000.0));

    // Display all members polymorphically
    directory.listAllMembers();

    // Query records
    directory.findById(102);
    directory.findById(999);

    return 0;
}
