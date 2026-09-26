#include <iostream>                  // Includes the iostream library for input and output operations

using namespace std;                 // Allows the use of cout without writing std::

class Demo {                         // Defines a class named Demo

public:                              // Makes the members of the class publicly accessible

    Demo() {                         // Defines the constructor of the Demo class
        cout << "Constructor called\n";  // Displays a message when the constructor is called
    }

    ~Demo() {                        // Defines the destructor of the Demo class
        cout << "Destructor called\n";   // Displays a message when the destructor is called
    }
};                                  // Ends the Demo class definition

int main() {                         // Main function where program execution begins

    Demo d;                          // Creates an object 'd' and automatically calls the constructor

    return 0;                        // Returns 0 and automatically calls the destructor before program ends
}
