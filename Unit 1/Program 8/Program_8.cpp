#include <iostream>                  // Includes the iostream library for input and output operations

using namespace std;                 // Allows the use of cout without writing std::

class Test {                         // Defines a class named Test

private:                             // Declares private members of the class

    int value;                       // Declares a private integer variable to store a value

public:                              // Makes the members below publicly accessible

    Test(int v) {                    // Defines a parameterized constructor
        value = v;                   // Assigns the parameter v to the private variable value
    }

    inline int getValue() {          // Defines an inline member function to return the value
        return value;                // Returns the value stored in the private variable
    }

    friend void show(Test t);        // Declares show() as a friend function that can access private members
};                                  // Ends the Test class definition

void show(Test t) {                  // Defines the friend function show()
    cout << t.value;                 // Accesses and displays the private value of the Test object
}

int main() {                         // Main function where program execution begins

    Test obj(50);                    // Creates a Test object and initializes value to 50

    cout << obj.getValue() << endl;  // Calls getValue() and displays the returned value

    show(obj);                       // Calls the friend function to display the private value

    return 0;                        // Returns 0 to indicate successful program execution
}
