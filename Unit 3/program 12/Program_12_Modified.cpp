#include <iostream>                 // Provides input/output functions
#include <memory>                   // Provides std::unique_ptr and std::make_unique
#include <vector>                   // Provides std::vector

using namespace std;                // Allows us to use standard library names directly

// Abstract base class
class Shape {
public:
    virtual double area() const = 0;        // Pure virtual function to calculate area
    virtual void displayName() const = 0;   // Pure virtual function to display shape name
    virtual ~Shape() = default;             // Virtual destructor for proper cleanup
};

// Rectangle class derived from Shape
class Rectangle : public Shape {
private:
    double length;                  // Stores the length of rectangle
    double width;                   // Stores the width of rectangle

public:
    // Constructor to initialize length and width
    Rectangle(double givenLength, double givenWidth)
        : length(givenLength), width(givenWidth) {}

    // Calculates the area of rectangle
    double area() const override {
        return length * width;      // Area = length × width
    }

    // Displays the name of the shape
    void displayName() const override {
        cout << "Rectangle";        // Prints Rectangle
    }
};

// Circle class derived from Shape
class Circle : public Shape {
private:
    double radius;                  // Stores the radius of circle

public:
    // Constructor to initialize radius
    explicit Circle(double givenRadius)
        : radius(givenRadius) {}

    // Calculates the area of circle
    double area() const override {
        constexpr double PI = 3.141592653589793; // Constant value of PI
        return PI * radius * radius;             // Area = πr²
    }

    // Displays the name of the shape
    void displayName() const override {
        cout << "Circle";           // Prints Circle
    }
};

//  MODIFICATION: Triangle class added
class Triangle : public Shape {
private:
    double base;                    //
