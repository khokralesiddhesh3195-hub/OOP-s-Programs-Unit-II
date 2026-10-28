
#include <cstring>   // Provides strncpy()
#include <fstream>   // Provides binary file operations
#include <iostream>  // Provides input and output
using namespace std; // Allows use of standard names directly

struct StudentRecord { // Structure to store student information
    int rollNumber;    // Stores roll number
    char name[30];     // Stores student name
    float marks;       // Stores student marks
};

// Function to write one student record into the binary file
void addRecord(ofstream& file, int rollNumber,
               const char* name, float marks) {
    StudentRecord student{}; // Create and initialize a student record
    student.rollNumber = rollNumber; // Assign roll number
    strncpy(student.name, name, sizeof(student.name) - 1); // Copy name safely
    student.marks = marks; // Assign marks

    file.write(reinterpret_cast<const char*>(&student),
                sizeof(student)); // Write record as binary data
}

int main() { // Main function starts

    // Open binary file for writing
    ofstream outputFile("records.dat", ios::binary | ios::trunc);

    if (!outputFile) { // Check whether file opened successfully
        cerr << "Error: Could not create records.dat\n";
        return 1; // Stop if file creation fails
    }

    // Write three sample student records
    addRecord(outputFile, 101, "Amit", 85.5F);
    addRecord(outputFile, 102, "Neha", 91.0F);
    addRecord(outputFile, 103, "Ravi", 78.0F);

    outputFile.close(); // Close file after writing

    // Open binary file for reading
    ifstream inputFile("records.dat", ios::binary);

    if (!inputFile) { // Check whether file opened successfully
        cerr << "Error: Could not open records.dat\n";
        return 1; // Stop if file opening fails
    }

    int searchRollNumber; // Stores roll number entered by user

    cout << "Enter roll number to search: "; // Ask for roll number
    cin >> searchRollNumber; // Read user's input

    // MODIFIED: Search using roll number instead of record number
    StudentRecord student; // Variable to store each record
    bool found = false; // Indicates whether student was found

    // Read records one by one from the binary file
    while (inputFile.read(reinterpret_cast<char*>(&student),
                          sizeof(student))) {

        // MODIFIED: Compare the stored roll number with the input
        if (student.rollNumber == searchRollNumber) {
            cout << "\nRecord Found!\n"; // Display success message
            cout << "Roll Number: " << student.rollNumber << '\n';
            cout << "Name: " << student.name << '\n';
            cout << "Marks: " << student.marks << '\n';

            found = true; // Mark record as found
            break; // Stop searching after a match
        }
    }

    if (!found) { // Execute when no matching roll number exists
        cout << "Student record not found.\n";
    }

    inputFile.close(); // Close file after reading

    return 0; // End program successfully
}


🌿Sample output
Input:
Enter roll number to search: 102

🌿Output
Record Found!
Roll Number: 102
Name: Neha
Marks: 91
