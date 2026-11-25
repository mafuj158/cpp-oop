#include <iostream>
#include <string>

// ============================================================================
// CONCEPT: Static Members and Static Methods
// ============================================================================
// - Static Member Variable: Shared by ALL instances of a class. Stored once
//   in the data segment, not duplicated inside each object.
//   Must be defined outside the class declaration!
// - Static Member Function: Can be called without creating an instance (ClassName::Method()).
//   Can ONLY access static members (it has no 'this' pointer).
// ============================================================================

class UserAccount {
private:
    std::string username;
    int id;

    // Static variable to track total accounts created
    static int totalUsers;

public:
    UserAccount(std::string name) : username(name) {
        totalUsers++;
        id = totalUsers;
        std::cout << "User registered: " << username << " [User ID: " << id << "]\n";
    }

    ~UserAccount() {
        totalUsers--;
        std::cout << "User removed: " << username << "\n";
    }

    // Static method
    static int getActiveUserCount() {
        // id = 10; // ERROR! Cannot access non-static member 'id'
        return totalUsers;
    }
};

// Static variable definition outside the class
int UserAccount::totalUsers = 0;

int main() {
    std::cout << "=== Static Members Demo ===\n\n";
    std::cout << "Initial user count: " << UserAccount::getActiveUserCount() << "\n\n";

    UserAccount* u1 = new UserAccount("Alice");
    UserAccount* u2 = new UserAccount("Bob");
    UserAccount* u3 = new UserAccount("Charlie");

    std::cout << "\nCurrent active users: " << UserAccount::getActiveUserCount() << "\n\n";

    delete u2; // Bob logs out

    std::cout << "\nAfter deleting Bob: " << UserAccount::getActiveUserCount() << "\n";

    delete u1;
    delete u3;

    return 0;
}
