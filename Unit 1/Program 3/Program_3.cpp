#include <iostream>                  // Includes the iostream library for input and output operations

using namespace std;                 // Allows the use of cout without writing std::

int main() {                         // Main function where program execution begins

    int marks[5] = {78, 82, 91, 67, 88};   // Declares an integer array 'marks' with 5 student marks

    for (int i = 0; i < 5; i++) {   // Loop that runs from index 0 to index 4

        cout << marks[i] << " ";     // Displays the current array element followed by a space
    }

    return 0;                       // Returns 0 to indicate successful program execution
}
