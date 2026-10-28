
#include <fstream>   // Provides file handling classes
#include <iostream>  // Provides input and output functions
#include <sstream>   // Provides stringstream for parsing records
#include <string>    // Provides the string data type
#include <iomanip>   // MODIFIED: Provides setw() and formatting tools

using namespace std; // Allows standard names without std::

int main() { // Main function starts

    ifstream inputFile("students.txt"); // Open student records file

    // Check whether the file opened successfully
    if (!inputFile) {
        cerr << "Error: Could not open students.txt\n";
        return 1; // Exit if file opening fails
    }

    string line; // Stores each complete record from the file

    // MODIFIED: Print the formatted table heading
    cout << left
         << setw(12) << "Roll No."
         << setw(22) << "Name"
         << setw(12) << "Marks"
         << '\n';

    // MODIFIED: Print a separator below the heading
    cout << string(46, '-') << '\n';

    // Read every record from the file
    while (getline(inputFile, line)) {

        stringstream record(line); // Parse the current record

        string rollText;  // Stores roll number as text
        string name;      // Stores student's name
        string marksText; // Stores marks as text

        // Extract fields separated by the | delimiter
        if (getline(record, rollText, '|') &&
            getline(record, name, '|') &&
            getline(record, marksText, '|')) {

            // MODIFIED: Display each record as a table row
            cout << left
                 << setw(12) << rollText
                 << setw(22) << name
                 << setw(12) << marksText
                 << '\n';
        }
    }

    inputFile.close(); // Close the file after reading

    return 0; // End the program successfully
}


🌿Sample students.txt content
101|Amit Patil|85.5
102|Rahul Sharma|78.0
103|Priya Deshmukh|92.5

🌿Expected Console Output
Roll No.    Name                  Marks
----------------------------------------------
101         Amit Patil            85.5
102         Rahul Sharma          78.0
103         Priya Deshmukh        92.5
