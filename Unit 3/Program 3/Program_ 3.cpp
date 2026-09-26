#include <iostream>  // Includes the input/output library.

class Number {  // Defines a Number class.
private:
    int value;  // Stores the integer value.

public:
    explicit Number(int givenValue) : value(givenValue) {}
    // Constructor initializes the value.

    Number operator-() const {
        // Overloads the unary minus operator.

        return Number(-value);
        // Creates and returns a new Number with the negative value.
    }

    void display() const {
        // Function to display the stored value.

        std::cout << value << '\n';
        // Prints the value.
    }
};

int main() {
    // Program execution begins here.

    Number first(25);
    // Creates a Number object with value 25.

    Number second = -first;
    // Calls the overloaded unary minus operator.

    std::cout << "Original value: ";
    // Displays a message.

    first.display();
    // Displays the original value.

    std::cout << "Negated value: ";
    // Displays a message.

    second.display();
    // Displays the negative value.

    return 0;
    // Indicates successful execution.
}

🎯 Expected Output

Original value: 25
Negated value: -25
