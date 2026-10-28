
#include <cstring>   // Provides strncpy()
#include <fstream>   // Provides binary file handling
#include <iostream>  // Provides input and output functions

using namespace std; // Allows standard names without std::

struct StudentRecord { // Structure to store one student's record
    int rollNumber;    // Stores the student's roll number
    char name[30];     // Stores the student's name
    float marks;       // Stores the student's marks
};

int main() { // Main function starts

    StudentRecord students[3] = { // MODIFIED: Create three student records
        {101, "Amit Patil", 85.5F},
        {102, "Rahul Sharma", 78.0F},
        {103, "Priya Deshmukh", 92.5F}
    };

    // MODIFIED: Open binary file for writing three records
    ofstream outputFile("students.dat", ios::binary);

    // Check whether the output file opened successfully
    if (!outputFile) {
        cerr << "Error: Could not create students.dat\n";
        return 1; // Exit if file creation fails
    }

    // MODIFIED: Write all three records using a loop
    for (int i = 0; i < 3; i++) {
        outputFile.write(
            reinterpret_cast<const char*>(&students[i]),
            sizeof(StudentRecord)
        ); // Write one complete record as binary data
    }

    outputFile.close(); // Close the file after writing

    // MODIFIED: Open the binary file for reading
    ifstream inputFile("students.dat", ios::binary);

    // Check whether the input file opened successfully
    if (!inputFile) {
        cerr << "Error: Could not open students.dat\n";
        return 1; // Exit if file opening fails
    }

    StudentRecord readStudent; // Stores each record read from the file

    cout << "Student Records:\n"; // Display heading
    cout << "-------------------------\n";

    // MODIFIED: Read all records using a loop
    while (inputFile.read(
        reinterpret_cast<char*>(&readStudent),
        sizeof(StudentRecord)
    )) {
        // Display the current student's details
        cout << "Roll Number: " << readStudent.rollNumber << '\n';
        cout << "Name: " << readStudent.name << '\n';
        cout << "Marks: " << readStudent.marks << '\n';
        cout << "-------------------------\n";
    }

    inputFile.close(); // Close the file after reading

    return 0; // End the program successfully
}


🌿Expected Console Output
Student Records:
-------------------------
Roll Number: 101
Name: Amit Patil
Marks: 85.5
-------------------------
Roll Number: 102
Name: Rahul Sharma
Marks: 78
-------------------------
Roll Number: 103
Name: Priya Deshmukh
Marks: 92.5
-------------------------
