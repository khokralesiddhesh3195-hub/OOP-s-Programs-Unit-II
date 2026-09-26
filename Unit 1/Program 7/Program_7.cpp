#include <iostream>                  // Includes the iostream library for input and output operations

using namespace std;                 // Allows the use of cout without writing std::

class Student {                      // Defines a class named Student

public:                              // Makes the members below publicly accessible

    static int count;                // Declares a static data member shared by all Student objects

    Student() {                      // Defines the constructor of the Student class
        count++;                      // Increments the shared count whenever an object is created
    }
};                                  // Ends the Student class definition

int Student::count = 0;             // Defines and initializes the static member count to 0

int main() {                         // Main function where program execution begins

    Student s1, s2, s3;              // Creates three Student objects; constructor increments count three times

    cout << Student::count;          // Displays the current value of the static count variable

    return 0;                        // Returns 0 to indicate successful program execution
}
