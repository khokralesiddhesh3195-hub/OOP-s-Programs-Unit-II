#include <iostream>                                      // Includes the input/output stream library

using namespace std;                                     // Allows us to use cout without std::

class Base {                                             // Defines the Base class
public:

    virtual void display() const {                       // Virtual function enables runtime polymorphism
        cout << "Base object\n";                         // Displays message for Base object
    }

    virtual ~Base() = default;                           // Virtual destructor for safe polymorphic deletion
};

class Derived : public Base {                            // Derived inherits publicly from Base
public:

    void display() const override {                      // Overrides Base::display()
        cout << "Derived object\n";                      // Displays message for Derived object
    }
};

// Function demonstrating object slicing
void displayByValue(Base object) {                       // Base object is passed by value
    object.display();                                    // Calls Base::display() because slicing occurs
}

// Function demonstrating polymorphism through reference
void displayByReference(const Base& object) {             // Base reference refers to the original object
    object.display();                                    // Calls Derived::display() due to virtual dispatch
}

// MODIFICATION: Function added to demonstrate pointer passing
void displayByPointer(const Base* object) {              // Accepts a pointer to a constant Base object
    object->display();                                   // Calls display() using pointer and preserves polymorphism
}

int main() {                                              // Program execution starts here

    Derived derived;                                      // Creates an object of the Derived class

    cout << "Passing by value: ";                         // Displays heading for pass-by-value
    displayByValue(derived);                              // Derived object is copied into Base object
                                                         // This causes object slicing

    cout << "Passing by reference: ";                     // Displays heading for reference
    displayByReference(derived);                          // Passes Derived object by reference
                                                         // No slicing occurs

    // MODIFICATION: Passing the address of the Derived object
    cout << "Passing by pointer: ";                       // Displays heading for pointer
    displayByPointer(&derived);                           // Passes address of Derived object as Base pointer
                                                         // Virtual function preserves polymorphism

    return 0;                                             // Indicates successful program termination
}
