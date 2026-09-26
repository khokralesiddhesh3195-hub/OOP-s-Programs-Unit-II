#include <iostream>  // Includes the input/output library.

class Base {  // Defines the base class.
public:
    virtual ~Base() {
        // Defines a virtual destructor.

        std::cout << "Base destructor\n";
        // Displays a message when Base is destroyed.
    }
};

class Derived : public Base {
    // Defines the Derived class.

public:
    ~Derived() override {
        // Defines the Derived destructor.

        std::cout << "Derived destructor\n";
        // Displays a message when Derived is destroyed.
    }
};

int main() {
    // Program execution begins here.

    Base* pointer = new Derived();
    // Creates a Derived object and stores it in a Base pointer.

    delete pointer;
    // Deletes the object through the base pointer.
    // Because the destructor is virtual, Derived is destroyed first.

    return 0;
    // Indicates successful execution.
}

🎯 Expected Output

Derived destructor
Base destructor
