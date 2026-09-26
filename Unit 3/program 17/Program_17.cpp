#include <iostream>  // Provides input and output operations.
#include <memory>    // Provides smart pointers such as unique_ptr.
#include <vector>    // Provides the vector container.

class Shape {  // Defines the abstract base class Shape.

public:

    virtual double area() const = 0;
    // Declares area() as a pure virtual function.

    virtual void draw() const = 0;
    // Declares draw() as another pure virtual function.

    virtual ~Shape() = default;
    // Defines a virtual destructor for safe polymorphic destruction.
};

class Circle : public Shape {
    // Circle inherits from the Shape class.

private:

    double radius;
    // Stores the radius of the circle.

public:

    explicit Circle(double r) : radius(r) {}
    // Constructor initializes the radius.

    double area() const override {
        // Overrides the area() function of Shape.

        return 3.14159265359 * radius * radius;
        // Calculates and returns the area of the circle.
    }

    void draw() const override {
        // Overrides the draw() function of Shape.

        std::cout << "Drawing circle with radius "
                  << radius << '\n';
        // Displays information about the circle.
    }
};

class Rectangle : public Shape {
    // Rectangle inherits from Shape.

private:

    double length;
    // Stores the length of the rectangle.

    double width;
    // Stores the width of the rectangle.

public:

    Rectangle(double l, double w) : length(l), width(w) {}
    // Constructor initializes length and width.

    double area() const override {
        // Overrides the area() function.

        return length * width;
        // Calculates and returns the rectangle area.
    }

    void draw() const override {
        // Overrides the draw() function.

        std::cout << "Drawing rectangle "
                  << length << " x " << width << '\n';
        // Displays rectangle information.
    }
};

class Triangle : public Shape {
    // Triangle inherits from Shape.

private:

    double base;
    // Stores the base of the triangle.

    double height;
    // Stores the height of the triangle.

public:

    Triangle(double b, double h) : base(b), height(h) {}
    // Constructor initializes base and height.

    double area() const override {
        // Overrides the area() function.

        return 0.5 * base * height;
        // Calculates and returns the triangle area.
    }

    void draw() const override {
        // Overrides the draw() function.

        std::cout << "Drawing triangle with base "
                  << base
                  << " and height "
                  << height << '\n';
        // Displays triangle information.
    }
};

int main() {
    // Program execution starts here.

    std::vector<std::unique_ptr<Shape>> shapes;
    // Creates a vector that stores pointers to Shape objects.

    shapes.push_back(std::make_unique<Circle>(5.0));
    // Adds a Circle object to the vector.

    shapes.push_back(std::make_unique<Rectangle>(4.0, 6.0));
    // Adds a Rectangle object to the vector.

    shapes.push_back(std::make_unique<Triangle>(3.0, 8.0));
    // Adds a Triangle object to the vector.

    std::cout << "=== CAD Shape System ===\n";
    // Displays the program heading.

    for (const auto& shape : shapes) {
        // Loops through every Shape object.

        shape->draw();
        // Calls the correct draw() function at run time.

        std::cout << "Area: "
                  << shape->area()
                  << " square units\n";
        // Calls the correct area() function at run time.
    }

    return 0;
    // Indicates successful program execution.
}

🎯 Expected Output

=== CAD Shape System ===
Drawing circle with radius 5
Area: 78.5398 square units
Drawing rectangle 4 x 6
Area: 24 square units
Drawing triangle with base 3 and height 8
Area: 12 square units
