#include <iostream>  // Includes the input/output library.

class Shape {  // Defines the base Shape class.
public:
    virtual double area() const {
        // Declares area() as a virtual function.

        return 0.0;
        // Returns a default area.
    }

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
        // Overrides the virtual area() function.

        return length * width;
        // Returns the rectangle area.
    }
};

class Circle : public Shape {
    // Defines Circle derived from Shape.

private:
    double radius;  // Stores circle radius.

public:
    explicit Circle(double givenRadius) : radius(givenRadius) {}
    // Constructor initializes the radius.

    double area() const override {
        // Overrides the virtual area() function.

        constexpr double PI = 3.141592653589793;
        // Defines the value of PI.

        return PI * radius * radius;
        // Returns the circle area.
    }
};

void printArea(const Shape& shape) {
    // Accepts any Shape-derived object by reference.

    std::cout << "Area: " << shape.area() << '\n';
    // Calls the correct area() function at run time.
}

int main() {
    // Program execution begins here.

    Rectangle rectangle(5.0, 3.0);
    // Creates a rectangle.

    Circle circle(2.0);
    // Creates a circle.

    printArea(rectangle);
    // Calls printArea() for the rectangle.

    printArea(circle);
    // Calls printArea() for the circle.

    return 0;
    // Indicates successful execution.
}

🎯 Expected Output

Area: 15
Area: 12.5664
