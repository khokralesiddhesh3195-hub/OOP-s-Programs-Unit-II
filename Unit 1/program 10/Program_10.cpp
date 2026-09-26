#include <iostream>                  // Includes the iostream library for input and output operations
#include <string>                    // Includes the string library for using string data type

using namespace std;                 // Allows the use of standard C++ objects without std::

class Student {                      // Defines a class named Student

private:                             // Declares private data members of the class

    int rollNo;                      // Stores the student's roll number
    string name;                     // Stores the student's name
    int totalDays;                   // Stores the total number of attendance days
    int presentDays;                 // Stores the number of days the student was present

public:                              // Makes the following members publicly accessible

    Student(int r, string n)
        : rollNo(r), name(n), totalDays(0), presentDays(0) {}
                                      // Constructor initializes roll number, name, total days, and present days

    void markAttendance(bool isPresent) {
                                      // Defines a function to record the student's attendance

        totalDays++;                  // Increases the total number of attendance days by 1

        if (isPresent) {              // Checks whether the student was present

            presentDays++;            // Increases the number of present days by 1
        }
    }

    double getAttendancePercentage() const {
                                      // Defines a function to calculate and return attendance percentage

        if (totalDays == 0) {         // Checks whether no attendance has been recorded

            return 0.0;               // Returns 0.0% if there are no attendance records
        }

        return (presentDays * 100.0) / totalDays;
                                      // Calculates and returns the attendance percentage
    }

    void display() const {            // Defines a function to display student details

        cout << "Roll: " << rollNo
             << " | Name: " << name
             << " | Attendance: " << getAttendancePercentage() << "%" << endl;
                                      // Displays roll number, name, and attendance percentage
    }
};                                  // Ends the Student class definition

int main() {                         // Main function where program execution begins

    Student s1(101, "Rahul");        // Creates student s1 with roll number 101 and name Rahul

    Student s2(102, "Priya");        // Creates student s2 with roll number 102 and name Priya

    s1.markAttendance(true);         // Marks Rahul as present for the first day
    s1.markAttendance(true);         // Marks Rahul as present for the second day
    s1.markAttendance(false);        // Marks Rahul as absent for the third day

    s2.markAttendance(true);         // Marks Priya as present for the first day
    s2.markAttendance(true);         // Marks Priya as present for the second day
    s2.markAttendance(true);         // Marks Priya as present for the third day

    cout << "=== Attendance Report ===" << endl;
                                      // Displays the heading for the attendance report

    s1.display();                    // Displays Rahul's attendance details

    s2.display();                    // Displays Priya's attendance details

    return 0;                        // Returns 0 to indicate successful program execution
}
