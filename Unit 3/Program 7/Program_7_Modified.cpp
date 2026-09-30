#include <iostream>                         // Includes the input/output stream library
using namespace std;                        // Allows us to use cout without std::

class Complex {                             // Defines the Complex class
private:
    int real;                               // Stores the real part
    int imaginary;                          // Stores the imaginary part

public:
    // Constructor to initialize real and imaginary parts
    Complex(int realPart = 0, int imaginaryPart = 0)
        : real(realPart), imaginary(imaginaryPart) {}

    // MODIFICATION: Friend non-member operator-()
    // It allows the expression: 10 - ComplexNumber
    friend Complex operator-(int value, const Complex& number);

    // Function to display the complex number
    void display() const {
        cout << real;                       // Displays the real part

        if (imaginary >= 0) {               // Checks whether imaginary part is positive
            cout << " + ";                  // Displays plus sign
        }
        else {
            cout << " - ";                  // Displays minus sign
        }

        // Displays the absolute value of imaginary part
        cout << (imaginary >= 0 ? imaginary : -imaginary) << "i" << endl;
    }
};

// MODIFICATION: Definition of friend operator-
// Performs: integer - complex number
Complex operator-(int value, const Complex& number) {

    // Real part = integer value - complex real part
    // Imaginary part = 0 - complex imaginary part
    return Complex(value - number.real, -number.imaginary);
}

int main() {                                // Main function starts

    Complex number(2, 3);                    // Creates complex number: 2 + 3i

    // MODIFICATION: Performs 10 - (2 + 3i)
    Complex result = 10 - number;

    cout << "Result: ";                      // Displays result label
    result.display();                       // Displays the calculated complex number

    return 0;                               // Indicates successful program execution
}
