#include <cctype>   // Provides character-checking functions.
#include <iostream> // Provides input and output operations.
#include <string>   // Provides the string class.

class Validator {
    // Defines the Validator class.

public:

    bool validate(int marks) const {
        // Overloaded validate() for integer marks.

        return marks >= 0 && marks <= 100;
        // Returns true if marks are between 0 and 100.
    }

    bool validate(double amount) const {
        // Overloaded validate() for payment amount.

        return amount > 0.0 &&
               amount <= 1000000.0;
        // Returns true for a valid positive amount within the limit.
    }

    bool validate(const std::string& name) const {
        // Overloaded validate() for a name.

        if (name.empty()) {
            // Checks whether the name is empty.

            return false;
            // Returns false for an empty name.
        }

        for (char ch : name) {
            // Checks every character in the name.

            if (!std::isalpha(
                    static_cast<unsigned char>(ch)) &&
                ch != ' ') {
                // Checks whether the character is a letter or space.

                return false;
                // Returns false if an invalid character is found.
            }
        }

        return true;
        // Returns true when all characters are valid.
    }
};

int main() {
    // Program execution starts here.

    Validator validator;
    // Creates a Validator object.

    std::cout << std::boolalpha;
    // Displays boolean values as true or false.

    std::cout << "Marks 88 valid: "
              << validator.validate(88) << '\n';
    // Calls validate(int).

    std::cout << "Marks 120 valid: "
              << validator.validate(120) << '\n';
    // Calls validate(int) with an invalid mark.

    std::cout << "Amount 4500.50 valid: "
              << validator.validate(4500.50) << '\n';
    // Calls validate(double).

    std::cout << "Name Priya Sharma valid: "
              << validator.validate(
                     std::string("Priya Sharma"))
              << '\n';
    // Calls validate(string) for a valid name.

    std::cout << "Name Priya123 valid: "
              << validator.validate(
                     std::string("Priya123"))
              << '\n';
    // Calls validate(string) for an invalid name.

    return 0;
    // Indicates successful program execution.
}

🎯 Expected Output

Marks 88 valid: true
Marks 120 valid: false
Amount 4500.50 valid: true
Name Priya Sharma valid: true
Name Priya123 valid: false
