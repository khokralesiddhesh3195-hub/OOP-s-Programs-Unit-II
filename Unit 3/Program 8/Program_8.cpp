#include <iostream>  // Includes the input/output library.

class Base {  // Defines the base class.
public:
    void display() const {
        // Defines a non-virtual display function.

        std::cout << "Base display function\n";
        // Displays the base-class message.
    }
};

class Derived : public Base {  // Defines a class derived from Base.
public:
    void display() const {
        // Defines another display function in Derived.

        std::cout << "Derived display function\n";
        // Displays the derived-class message.
    }
};

int main() {
    // Program execution begins here.

    Derived derivedObject;
    // Creates a Derived object.

    Base* basePointer = &derivedObject;
    // Stores the address of the Derived object in a Base pointer.

    basePointer->display();
    // Calls Base::display() because display() is not virtual.

    return 0;
    // Indicates successful execution.
}

🎯 Expected Output

Base display function
