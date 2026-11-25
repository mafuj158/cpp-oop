# Module 06: Capstone Practice Project

## 1. System Overview: University Member Directory

The **University Member Directory** is a capstone application designed to demonstrate how all four pillars of Object-Oriented Programming (Encapsulation, Abstraction, Inheritance, and Polymorphism) collaborate in a cohesive, real-world C++ system.

---

## 2. Architecture & Class Diagram

```mermaid
classDiagram
    class Person {
        <<Abstract>>
        #int id
        #string name
        #string email
        +Person(id, name, email)
        +virtual ~Person()
        +getId() int
        +getName() string
        +getEmail() string
        +virtual printDetails()* void
        +virtual getRole()* string
    }

    class Student {
        -string major
        -double gpa
        +Student(id, name, email, major, gpa)
        +setGpa(double) void
        +getGpa() double
        +getMajor() string
        +printDetails() void
        +getRole() string
    }

    class Professor {
        -string department
        -double salary
        +Professor(id, name, email, dept, salary)
        +getDepartment() string
        +getSalary() double
        +printDetails() void
        +getRole() string
    }

    class UniversityDirectory {
        -vector~unique_ptr~Person~~ members
        +addMember(unique_ptr~Person~) void
        +listAllMembers() void
        +findById(int) void
    }

    Person <|-- Student : Inherits (IS-A)
    Person <|-- Professor : Inherits (IS-A)
    UniversityDirectory o-- Person : Owns & Manages (Aggregation)
```

---

## 3. The 4 Pillars in Action

### 1. Encapsulation
- Sensitive fields like `gpa`, `salary`, `id`, and `email` are encapsulated (`private`/`protected`).
- `Student::setGpa` verifies that the value falls within the valid range `[0.0, 4.0]`. Direct state corruption is impossible.

### 2. Abstraction
- The `Person` class exposes high-level pure virtual functions (`printDetails()`, `getRole()`), hiding specific formatting mechanics from `UniversityDirectory`.
- Callers of `UniversityDirectory` simply invoke `listAllMembers()` or `findById()`.

### 3. Inheritance
- `Student` and `Professor` inherit shared characteristics (`id`, `name`, `email`) from `Person`, eliminating duplicated code and establishing a logical hierarchy.

### 4. Polymorphism
- `UniversityDirectory` stores generic `std::unique_ptr<Person>` pointers.
- When iterating through the collection:
  ```cpp
  member->printDetails();
  ```
  The C++ runtime automatically dispatches the call to `Student::printDetails()` or `Professor::printDetails()` based on the actual object type in memory.

---

## 4. Sequence Diagram: Polymorphic Listing

```mermaid
sequenceDiagram
    autonumber
    participant Main
    participant Directory as UniversityDirectory
    participant StudentObj as Student (ID: 101)
    participant ProfObj as Professor (ID: 201)

    Main->>Directory: listAllMembers()
    Directory->>StudentObj: printDetails() [Dynamic Dispatch]
    StudentObj-->>Directory: Outputs formatted Student profile
    Directory->>ProfObj: printDetails() [Dynamic Dispatch]
    ProfObj-->>Directory: Outputs formatted Professor profile
    Directory-->>Main: Listing complete
```

---

## 5. Code File

- [`student_management_system.cpp`](file:///F:/MY%20CLASS/ALL%20OF%20MY%20PROJECTS/cpp-oop/06-practice-projects/student_management_system.cpp)

### Compiling & Running:
```powershell
cd "F:\MY CLASS\ALL OF MY PROJECTS\cpp-oop\06-practice-projects"
g++ -std=c++17 student_management_system.cpp -o student_system.exe
.\student_system.exe
```

---

## 6. Project Expansion Challenges

Ready to practice? Try extending this project:
1. **Add a `Staff` Class:** Derive `Staff` from `Person` with a `jobTitle` attribute and appropriate overrides.
2. **Interactive CLI Menu:** Replace the static `main()` calls with a `while(true)` terminal menu allowing user input to add students or professors interactively.
3. **File Persistence:** Add an `exportToFile()` and `importFromFile()` method to save and load directory records using `std::fstream`.
4. **Course Enrollment:** Create a `Course` class (`courseCode`, `courseName`, `credits`) and allow students to enroll in courses.
