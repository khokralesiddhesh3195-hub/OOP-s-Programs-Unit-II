#include <iostream>                  // Includes input/output stream library
using namespace std;                 // Allows use of cout without std::

class Shape {                        // Abstract base class
public:
    virtual double area() const = 0; // Pure virtual function makes Shape abstract
    virtual ~Shape() = default;      // Virtual destructor
};

class Rectangle : public Shape {      // Rectangle inherits from Shape
private:
    double length;                   // Stores rectangle length
    double width;                    // Stores rectangle width

public:
    // Constructor to initialize length and width
    Rectangle(double givenLength, double givenWidth)
        : length(givenLength), width(givenWidth) {}

    // Overrides the pure virtual area() function
    double area() const override {
        return length * width;       // Returns rectangle area
    }
};

//  MODIFICATION: New Triangle class added
class Triangle : public Shape {       // Triangle inherits from Shape
private:
    double base;                     // Stores triangle base
    double height;                   // Stores triangle height

public:
    //  MODIFICATION: Constructor for Triangle
    Triangle(double givenBase, double givenHeight)
        : base(givenBase), height(givenHeight) {}

    //  MODIFICATION: Implements the pure virtual area() function
    double area() const override {
        return 0.5 * base * height;  // Triangle area = 0.5 × base × height
    }
};

int main() {                          // Program execution starts here

    Rectangle rectangle(8.0, 4.0);   // Creates Rectangle object

    // Displays rectangle area
    cout << "Rectangle Area: " << rectangle.area() << '\n';

    //  MODIFICATION: Creates a Triangle object
    Triangle triangle(10.0, 6.0);

    //  MODIFICATION: Displays triangle area
    cout << "Triangle Area: " << triangle.area() << '\n';

    return 0;                         // Ends the program successfully
}
