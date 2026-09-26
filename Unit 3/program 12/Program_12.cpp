#include <iostream>  // Includes the input/output library.
#include <memory>    // Provides smart pointers.
#include <vector>    // Provides the vector container.

class Shape {  // Defines the abstract Shape class.
public:
    virtual double area() const = 0;
    // Declares a pure virtual area() function.

    virtual void displayName() const = 0;
    // Declares a pure virtual displayName() function.

    virtual ~Shape() = default;
    // Defines a virtual destructor.
};

class Rectangle : public Shape {
    // Defines Rectangle derived from Shape.

private:
    double length;  // Stores length.
    double width;   // Stores width.

public:
    Rectangle(double givenLength, double givenWidth)
        : length(givenLength), width(givenWidth) {}
    // Constructor initializes rectangle dimensions.

    double area() const override {
        // Implements the area function.

        return length * width;
        // Returns rectangle area.
    }

    void displayName() const override {
        // Implements displayName().

        std::cout << "Rectangle";
        // Displays the shape name.
    }
};

class Circle : public Shape {
    // Defines Circle derived from Shape.

private:
    double radius;  // Stores radius.

public:
    explicit Circle(double givenRadius) : radius(givenRadius) {}
    // Constructor initializes radius.

    double area() const override {
        // Implements the area function.

        constexpr double PI = 3.141592653589793;
        // Defines PI.

        return PI * radius * radius;
        // Returns circle area.
    }

    void displayName() const override {
        // Implements displayName().

        std::cout << "Circle";
        // Displays the shape name.
    }
};

int main() {
    // Program execution begins here.

    std::vector<std::unique_ptr<Shape>> shapes;
    // Creates a vector of smart pointers to Shape objects.

    shapes.push_back(std::make_unique<Rectangle>(5.0, 3.0));
    // Adds a Rectangle object to the vector.

    shapes.push_back(std::make_unique<Circle>(2.0));
    // Adds a Circle object to the vector.

    for (const auto& shape : shapes) {
        // Iterates through all shape objects.

        shape->displayName();
        // Calls the appropriate displayName() function.

        std::cout << " Area: " << shape->area() << '\n';
        // Calls the appropriate area() function.
    }

    return 0;
    // Indicates successful execution.
}

🎯 Expected Output

Rectangle Area: 15
Circle Area: 12.5664
