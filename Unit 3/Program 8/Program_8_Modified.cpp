#include <iostream>                                      // Include the input/output stream library
using namespace std;                                     // Use the standard namespace

class Base {                                             // Define the Base class
public:                                                  // Start public members of Base
    void display() const {                               // Define non-virtual display() function
        cout << "Base display function\n";               // Print Base class message
    }                                                    // End display() function
};                                                       // End Base class

class Derived : public Base {                            // Define Derived class inheriting from Base
public:                                                  // Start public members of Derived
    void display() const {                               // Define Derived class display() function
        cout << "Derived display function\n";            // Print Derived class message
    }                                                    // End display() function
};                                                       // End Derived class

int main() {                                             // Start the main() function

    Derived derivedObject;                               // Create an object of Derived class

    Base* basePointer = &derivedObject;                 // Base pointer points to Derived object

    cout << "Direct call using Derived object:\n";       // Display heading for direct call

    derivedObject.display();                             // MODIFICATION: Directly call Derived's display()
                                                         // This calls Derived::display() because the object
                                                         // itself is of Derived class type

    cout <<
