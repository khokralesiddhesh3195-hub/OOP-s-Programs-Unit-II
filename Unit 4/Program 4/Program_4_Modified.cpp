#include <fstream>   // Provides file handling classes
#include <iostream>  // Provides input and output functions
#include <string>    // Provides the string data type

using namespace std; // Allows using standard names without std::

int main() { // Main function starts

    ifstream sourceFile("message.txt"); // Open the source file for reading

    // MODIFIED: Create a new destination file named cpp_lines.txt
    ofstream destinationFile("cpp_lines.txt");

    // Check whether the source file opened successfully
    if (!sourceFile) {
        cerr << "Error: Could not open source file.\n";
        return 1; // Exit if the source file cannot be opened
    }

    // Check whether the destination file opened successfully
    if (!destinationFile) {
        cerr << "Error: Could not create destination file.\n";
        return 1; // Exit if the destination file cannot be created
    }

    string line; // Stores each line read from the source file
    int copiedLines = 0; // MODIFIED: Count matching lines

    // Read the source file one line at a time
    while (getline(sourceFile, line)) {

        // MODIFIED: Copy only lines containing the word "C++"
        if (line.find("C++") != string::npos) {
            destinationFile << line << '\n'; // Write matching line
            copiedLines++; // MODIFIED: Increase the matching-line count
        }
    }

    sourceFile.close(); // Close the source file
    destinationFile.close(); // Close the destination file

    // MODIFIED: Display the result of the filtered copy operation
    if (copiedLines > 0) {
        cout << "Matching lines copied successfully to cpp_lines.txt\n";
    } else {
        cout << "No lines containing C++ were found.\n";
    }

    return 0; // End the program successfully
}

🌿Sample input file: message.txt
Welcome to C++ File Handling.
Python is also a programming language.
C++ supports object-oriented programming.
Files store data permanently.
I am learning C++.

🌿Expected console output
Matching lines copied successfully to cpp_lines.txt

🌿Expected output file: cpp_lines.txt
Welcome to C++ File Handling.
C++ supports object-oriented programming.
I am learning C++.
