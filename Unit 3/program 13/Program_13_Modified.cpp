#include <iostream>   // Provides input/output functions like std::cout
#include <memory>     // MODIFICATION: Provides std::unique_ptr and std::make_unique

// Base class
class Base
{
public:

    // Virtual destructor allows correct destruction through a Base pointer
    virtual ~Base()
    {
        // Displays message when Base destructor is executed
        std::cout << "Base destructor\n";
    }
};

// Derived class inherits publicly from Base
class Derived : public Base
{
public:

    // MODIFICATION: override confirms that this destructor overrides Base destructor
    ~Derived() override
    {
        // Displays message when Derived destructor is executed
        std::cout << "Derived destructor\n";
    }
};

int main()
{
    // MODIFICATION:
    // Instead of using "Base* pointer = new Derived();",
    // we use std::unique_ptr for automatic memory management.
    std::unique_ptr<Base> pointer = std::make_unique<Derived>();

    // MODIFICATION:
    // No "delete pointer;" is required.
    // unique_ptr automatically destroys the object when it goes out of scope.

    // Program ends here.
    // First, Derived destructor is called.
    // Then, Base destructor is called.
    return 0;
}
