#include <iostream>  // Includes the input/output library.

class Complex {  // Defines the Complex class.
private:
    int real;       // Stores the real part.
    int imaginary;  // Stores the imaginary part.

public:
    Complex(int realPart = 0, int imaginaryPart = 0)
        : real(realPart), imaginary(imaginaryPart) {}
    // Constructor initializes real and imaginary parts.

    Complex operator+(const Complex& other) const {
        // Overloads the binary + operator.

        return Complex(real + other.real,
                       imaginary + other.imaginary);
        // Returns a new Complex object containing the sum.
    }

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
        // Prints the absolute imaginary value followed by i.
    }
};

int main() {
    // Program execution begins here.

    Complex first(2, 3);
    // Creates the first complex number.

    Complex second(4, 5);
    // Creates the second complex number.

    Complex sum = first + second;
    // Calls the overloaded + operator.

    std::cout << "First complex number: ";
    // Displays a message.

    first.display();
    // Displays the first complex number.

    std::cout << "Second complex number: ";
    // Displays a message.

    second.display();
    // Displays the second complex number.

    std::cout << "Sum: ";
    // Displays a message.

    sum.display();
    // Displays the result.

    return 0;
    // Indicates successful execution.
}

🎯 Expected Output

First complex number: 2 + 3i
Second complex number: 4 + 5i
Sum: 6 + 8i
