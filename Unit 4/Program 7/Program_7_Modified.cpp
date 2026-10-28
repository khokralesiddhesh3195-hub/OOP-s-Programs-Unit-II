
#include <fstream>   // Provides file handling classes
#include <iostream>  // Provides input and output functions
#include <limits>    // Provides numeric_limits
#include <string>    // Provides the string data type

using namespace std; // Allows standard names without std::

int main() { // Main function starts

    // Open students.txt in append mode to preserve existing records
    ofstream outputFile("students.txt", ios::app);

    // Check whether the file opened successfully
    if (!outputFile) {
        cerr << "Error: Could not open students.txt\n";
        return 1; // Exit if the file cannot be opened
    }

    int rollNumber;       // Stores the student's roll number
    string name;          // Stores the student's name
    double marks;         // Stores the student's marks

    // MODIFIED: Added course name and mobile number variables
    string courseName;    // Stores the student's course name
    string mobileNumber;  // Stores the mobile number as text

    cout << "Enter roll number: "; // Ask for roll number
    cin >> rollNumber; // Read roll number

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    // Clear the leftover newline before reading text

    cout << "Enter name: "; // Ask for student's name
    getline(cin, name); // Read the full name, including spaces

    cout << "Enter marks: "; // Ask for marks
    cin >> marks; // Read marks

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    // MODIFIED: Clear the newline before reading course name

    // MODIFIED: Ask for course name
    cout << "Enter course name: ";
    getline(cin, courseName); // Read the complete course name

    // MODIFIED: Ask for mobile number
    cout << "Enter mobile number: ";
    getline(cin, mobileNumber); // Read mobile number as text

    // MODIFIED: Save all five fields separated by |
    outputFile << rollNumber << '|'
               << name << '|'
               << marks << '|'
               << courseName << '|'
               << mobileNumber << '\n';

    outputFile.close(); // Close the file and save the record

    cout << "Student record saved successfully.\n";
    // Display confirmation message

    return 0; // End the program successfully
}


🌿Sample Input
Enter roll number: 101
Enter name: Amit Patil
Enter marks: 85.5
Enter course name: B.Tech AI&DS
Enter mobile number: 9876543210

🌿Expected Console Output
Student record saved successfully.

🌿Expected file content (students.txt)
101|Amit Patil|85.5|B.Tech AI&DS|9876543210
