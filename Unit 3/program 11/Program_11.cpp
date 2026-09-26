#include <iostream>  // Includes the input/output library.

class Shape {  // Defines the abstract base class.
public:
    virtual double area() const = 0;
    // Declares area() as a pure virtual function.

    virtual ~Shape() = default;
    // Defines a virtual destructor.
};

class Rectangle : public Shape {
    // Defines Rectangle derived from Shape.

private:
    double length;  // Stores rectangle length.
    double width;   // Stores rectangle width.

public:
    Rectangle(double givenLength, double givenWidth)
        : length(givenLength), width(givenWidth) {}
    // Constructor initializes length and width.

    double area() const override {
        // Implements the pure virtual function.

        return length * width;
        // Returns the rectangle area.
    }
};

int main() {
    // Program execution begins here.

    Rectangle rectangle(8.0, 4.0);
    // Creates a Rectangle object.

    std::cout << "Rectangle Area: " << rectangle.area() << '\n';
    // Calculates and displays the area.

    return 0;
    // Indicates successful execution.
}

🎯 Expected Output

Rectangle Area: 32
