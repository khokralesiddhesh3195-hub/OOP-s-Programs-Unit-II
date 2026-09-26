#include <iostream>                  // Includes the iostream library for input and output operations

using namespace std;                 // Allows the use of cout without writing std::

int add(int, int);                   // Function declaration (prototype) for the add function

int main() {                         // Main function where program execution begins

    int a = 10, b = 20;              // Declares two integer variables and initializes them with 10 and 20

    cout << "Sum = " << add(a, b) << endl;  // Calls add() with a and b and displays the returned sum

    return 0;                        // Returns 0 to indicate successful program execution
}

int add(int x, int y) {              // Defines the add function with two integer parameters

    return x + y;                    // Adds x and y and returns the result
}
