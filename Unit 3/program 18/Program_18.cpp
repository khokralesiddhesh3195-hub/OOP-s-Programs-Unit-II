#include <iostream>  // Provides input and output operations.

class Complex {
    // Defines the Complex number class.

private:

    double real;
    // Stores the real part.

    double imag;
    // Stores the imaginary part.

public:

    Complex(double r = 0.0, double i = 0.0)
        : real(r), imag(i) {}
    // Constructor initializes the real and imaginary parts.

    Complex operator+(const Complex& other) const {
        // Overloads the + operator.

        return Complex(real + other.real,
                       imag + other.imag);
        // Returns the sum of two complex numbers.
    }

    Complex operator-(const Complex& other) const {
        // Overloads the - operator.

        return Complex(real - other.real,
                       imag - other.imag);
        // Returns the difference of two complex numbers.
    }

    Complex operator*(const Complex& other) const {
        // Overloads the * operator.

        return Complex(
            real * other.real - imag * other.imag,
            real * other.imag + imag * other.real
        );
        // Calculates and returns the product of two complex numbers.
    }

    bool operator==(const Complex& other) const {
        // Overloads the == operator.

        return real == other.real &&
               imag == other.imag;
        // Returns true when both parts are equal.
    }

    void display() const {
        // Displays the complex number.

        std::cout << real << " + "
                  << imag << "i\n";
        // Prints the complex number.
    }
};

int main() {
    // Program execution starts here.

    Complex c1(3.0, 4.0);
    // Creates the first complex number.

    Complex c2(1.0, 2.0);
    // Creates the second complex number.

    std::cout << "C1: ";
    // Displays a label.

    c1.display();
    // Displays the first complex number.

    std::cout << "C2: ";
    // Displays a label.

    c2.display();
    // Displays the second complex number.

    std::cout << "Sum: ";
    // Displays a label.

    (c1 + c2).display();
    // Calls the overloaded + operator.

    std::cout << "Difference: ";
    // Displays a label.

    (c1 - c2).display();
    // Calls the overloaded - operator.

    std::cout << "Product: ";
    // Displays a label.

    (c1 * c2).display();
    // Calls the overloaded * operator.

    return 0;
    // Indicates successful program execution.
}

🎯 Expected Output

C1: 3 + 4i
C2: 1 + 2i
Sum: 4 + 6i
Difference: 2 + 2i
Product: -5 + 10i
