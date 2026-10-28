
#include <fstream>   // Provides file input/output operations
#include <iostream>  // Provides cin, cout, and cerr
#include <string>    // Provides the string data type

using namespace std; // Allows standard library names without std::

int main() { // Main function starts

    ifstream inputFile("message.txt"); // Open message.txt for reading

    // Check whether the file opened successfully
    if (!inputFile) {
        cerr << "Error: Could not open message.txt\n"; // Display error
        return 1; // Exit if the file cannot be opened
    }

    string line; // Stores each line read from the file
    int lineNumber = 1; // MODIFIED: Initialize line number to 1

    cout << "File Content:\n"; // Display the heading

    // Read the file one line at a time
    while (getline(inputFile, line)) {

        // MODIFIED: Display the line number before the line
        cout << lineNumber << ". " << line << '\n';

        lineNumber++; // MODIFIED: Increment the line number
    }

    inputFile.close(); // Close the file after reading

    return 0; // End the program successfully
}

🌿Expected Console Output
Assuming message.txt contains the three lines shown in your notes:
File Content:
1. Welcome to C++ File Handling
2. This is the first line written to a file.
3. Files store data permanently.
