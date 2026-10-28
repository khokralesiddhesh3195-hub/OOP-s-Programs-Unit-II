#include <cstdio>    // Provides remove() and rename()
#include <fstream>   // Provides file handling classes
#include <iostream>  // Provides input and output functions
#include <sstream>   // Provides stringstream for parsing records
#include <string>    // Provides the string data type
#include <limits>    // Provides numeric_limits

using namespace std; // Allows standard names without std::

int main() { // Main function starts

    ifstream inputFile("students.txt"); // Open original file for reading
    ofstream temporaryFile("students_temp.txt"); // Create temporary file

    // Check whether both files opened successfully
    if (!inputFile || !temporaryFile) {
        cerr << "Error: Could not open files.\n";
        return 1; // Exit if file opening fails
    }

    int targetRollNumber; // Roll number of student to update
    string updatedName;   // MODIFIED: Stores the new student name
    double updatedMarks;  // Stores the new marks

    cout << "Enter roll number to update: ";
    cin >> targetRollNumber; // Read target roll number

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    // Clear the leftover newline before reading the name

    // MODIFIED: Ask for the student's updated name
    cout << "Enter updated name: ";
    getline(cin, updatedName); // Read the complete name

    cout << "Enter updated marks: ";
    cin >> updatedMarks; // Read the updated marks

    string line; // Stores each original record
    bool found = false; // Tracks whether the student was found

    // Read each record from the original file
    while (getline(inputFile, line)) {

        stringstream record(line); // Parse the current record

        string rollText, name, marksText; // Store original fields

        // Extract roll number, name, and marks
        if (getline(record, rollText, '|') &&
            getline(record, name, '|') &&
            getline(record, marksText, '|')) {

            int rollNumber = stoi(rollText); // Convert roll number to integer

            // MODIFIED: Update both name and marks for the selected student
            if (rollNumber == targetRollNumber) {
                temporaryFile << rollNumber << '|'
                              << updatedName << '|'
                              << updatedMarks << '\n';

                found = true; // Mark the record as updated
            } else {
                // Keep all other student records unchanged
                temporaryFile << line << '\n';
            }

        } else {
            // Preserve any line that does not match the expected format
            temporaryFile << line << '\n';
        }
    }

    inputFile.close(); // Close the original file
    temporaryFile.close(); // Close the temporary file

    // If the student was not found, discard the temporary file
    if (!found) {
        remove("students_temp.txt");
        cout << "Student record not found. No update performed.\n";
        return 0;
    }

    // Replace the original file with the updated temporary file
    if (remove("students.txt") != 0) {
        cerr << "Error: Could not remove original file.\n";
        return 1;
    }

    // Rename the temporary file to the original filename
    if (rename("students_temp.txt", "students.txt") != 0) {
        cerr << "Error: Could not rename temporary file.\n";
        return 1;
    }

    cout << "Student name and marks updated successfully.\n";
    // MODIFIED: Display confirmation for both updated fields

    return 0; // End the program successfully
}


🌿Sample students.txt before updating
101|Amit Patil|85.5
102|Rahul Sharma|78
103|Priya Deshmukh|92.5

🌿Sample Input
Enter roll number to update: 102
Enter updated name: Rahul Patil
Enter updated marks: 88.5

🌿Expected Console Output
Student name and marks updated successfully.

🌿Updated students.txt
101|Amit Patil|85.5
102|Rahul Patil|88.5
103|Priya Deshmukh|92.5
