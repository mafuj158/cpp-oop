#include <iostream>
#include <string>

// ============================================================================
// CONCEPT: Encapsulation
// ============================================================================
// - Encapsulation is the bundling of data and the methods that operate on that
//   data into a single unit (class), while restricting direct access to internal details.
// - How it is achieved:
//     1. Keep data members `private`.
//     2. Provide `public` getters (read) and setters (write) with validation.
// - Why? Prevents invalid states and protects data integrity.
// ============================================================================

class BankAccount {
private:
    std::string accountNumber;
    std::string accountHolder;
    double balance; // Protected from unauthorized direct modification

public:
    BankAccount(std::string accNum, std::string holder, double initialDeposit)
        : accountNumber(accNum), accountHolder(holder), balance(0.0) {
        if (initialDeposit > 0) {
            balance = initialDeposit;
        }
    }

    // Getter (Accessor) - Read-only access
    double getBalance() const {
        return balance;
    }

    std::string getAccountHolder() const {
        return accountHolder;
    }

    // Setter (Mutator) with validation
    void setAccountHolder(const std::string& newName) {
        if (!newName.empty()) {
            accountHolder = newName;
            std::cout << "Account holder name updated to: " << accountHolder << "\n";
        } else {
            std::cout << "Error: Name cannot be empty!\n";
        }
    }

    // Controlled operations on sensitive data
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            std::cout << "Deposited $" << amount << ". New Balance: $" << balance << "\n";
        } else {
            std::cout << "Error: Deposit amount must be positive.\n";
        }
    }

    bool withdraw(double amount) {
        if (amount <= 0) {
            std::cout << "Error: Withdrawal amount must be positive.\n";
            return false;
        }
        if (amount > balance) {
            std::cout << "Error: Insufficient funds! Current balance: $" << balance << "\n";
            return false;
        }
        balance -= amount;
        std::cout << "Withdrew $" << amount << ". Remaining Balance: $" << balance << "\n";
        return true;
    }
};

int main() {
    std::cout << "=== Encapsulation Demo ===\n\n";

    BankAccount acc("ACC-10024", "Alice Smith", 500.0);

    // Direct access to balance is prohibited:
    // acc.balance = 100000; // COMPILE ERROR! private member

    std::cout << "Holder: " << acc.getAccountHolder() << "\n";
    std::cout << "Initial Balance: $" << acc.getBalance() << "\n\n";

    // Operations through validated public interfaces
    acc.deposit(250.0);
    acc.withdraw(100.0);
    acc.withdraw(900.0); // Will be rejected by validation logic
    acc.setAccountHolder(""); // Rejected by validation

    return 0;
}
