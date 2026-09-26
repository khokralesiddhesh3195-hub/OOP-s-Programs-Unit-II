#include <iostream>              // Includes the iostream library for input and output operations

using namespace std;             // Allows the use of cout without writing std::

int main() {                      // Main function where program execution begins

    int marks = 45;               // Declares an integer variable 'marks' and stores the value 45

    if (marks >= 40) {            // Checks whether the marks are greater than or equal to 40

        cout << "Pass";           // Displays "Pass" if the condition is true

    } else {                      // Executes when the if condition is false

        cout << "Fail";           // Displays "Fail" if the marks are below 40
    }

    return 0;                     // Returns 0 to indicate successful program execution
}
