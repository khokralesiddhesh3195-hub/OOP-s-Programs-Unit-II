#include <iostream>  // Includes the input/output library.

class Base {  // Defines the base class.
public:
    virtual void display() const {
        // Defines a virtual display function.

        std::cout << "Base object\n";
        // Displays the base message.
    }

    virtual ~Base() = default;
    // Defines a virtual destructor.
};

class Derived : public Base {
    // Defines the derived class.

public:
    void display() const override {
        // Overrides the virtual display function.

        std::cout << "Derived object\n";
        // Displays the derived message.
    }
};

void displayByValue(Base object) {
    // Receives the object by value, causing slicing.

    object.display();
    // Calls Base::display() on the sliced object.
}

void displayByReference(const Base& object) {
    // Receives the object by reference.

    object.display();
    // Calls the correct derived display() function.
}

int main() {
    // Program execution begins here.

    Derived derived;
    // Creates a Derived object.

    std::cout << "Passing by value: ";
    // Displays a message.

    displayByValue(derived);
    // Passes the Derived object by value and causes slicing.

    std::cout << "Passing by reference: ";
    // Displays a message.

    displayByReference(derived);
    // Passes the object by reference.

    return 0;
    // Indicates successful execution.
}

🎯 Expected Output

Passing by value: Base object
Passing by reference: Derived object
