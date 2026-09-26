#include <iostream>  // Includes the input/output library.

class Complex {  // Defines the Complex class.
private:
    int real;       // Stores the real part.
    int imaginary;  // Stores the imaginary part.

public:
    Complex(int realPart = 0, int imaginaryPart = 0)
        : real(realPart), imaginary(imaginaryPart) {}
    // Constructor initializes the complex number.

    friend Complex operator+(int value, const Complex& number);
    // Declares a friend function for integer + Complex.

    void display() const {
        // Displays the complex number.

        std::cout << real;
        // Prints the real part.

        if (imaginary >= 0) {
            std::cout << " + ";
            // Prints + for a positive imaginary part.
        } else {
            std::cout << " - ";
            // Prints - for a negative imaginary part.
        }

        std::cout << (imaginary >= 0 ? imaginary : -imaginary) << "i\n";
        // Prints the imaginary part.
    }
};

Complex operator+(int value, const Complex& number) {
    // Defines the friend operator function.

    return Complex(value + number.real, number.imaginary);
    // Adds the integer to the real part.
}

int main() {
    // Program execution begins here.

    Complex number(2, 3);
    // Creates a complex number.

    Complex result = 10 + number;
    // Calls the friend operator function.

    std::cout << "Result: ";
    // Displays a message.

    result.display();
    // Displays the result.

    return 0;
    // Indicates successful execution.
}

🎯 Expected Output

Result: 12 + 3i
