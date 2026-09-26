#include <iostream>                  // Includes the iostream library for input and output operations
using namespace std;                 // Allows the use of cout without writing std::

class Student {                      // Defines a class named Student

public:                              // Declares members below as publicly accessible

    string name;                     // Declares a string variable to store the student's name
    int age;                         // Declares an integer variable to store the student's age

    void show() {                    // Defines a member function to display student details
        cout << name << " " << age << endl;  // Displays the student's name and age
    }
};                                  // Ends the Student class definition

int main() {                         // Main function where program execution begins

    Student s1;                      // Creates an object 's1' of the Student class

    s1.name = "Amit";                // Assigns "Amit" to the name member of object s1

    s1.age = 20;                     // Assigns 20 to the age member of object s1

    s1.show();                       // Calls the show() function to display student details

    return 0;                        // Returns 0 to indicate successful program execution
}
