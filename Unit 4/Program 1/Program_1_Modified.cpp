#include <iostream>   // Provides input and output functions
#include <fstream>    // Provides file handling classes
#include <string>     // Provides the string data type
using namespace std;  // Allows using standard names without std::

int main() {  // Main function starts here

    // MODIFIED: Accept user input instead of writing fixed text
    ofstream outputFile("notes.txt");  // Create or open notes.txt for writing

    // Check whether the file opened successfully
    if (!outputFile) {
        cerr << "Error: Could not create notes.txt\n";  // Display error
        return 1;  // Terminate the program if file opening fails
    }

    string line;  // Variable to store each line entered by the user

    // MODIFIED: Take three lines from the user
    cout << "Enter three lines of text:\n";

    for (int i = 1; i <= 3; i++) {  // Repeat the input process three times
        cout << "Line " << i << ": ";  // Ask for the current line
        getline(cin, line);  // Read the complete line, including spaces
        outputFile << line << '\n';  // Write the line to the file
    }

    outputFile.close();  // Close the file and save the written data

    cout << "Data written successfully to notes.txt\n";  // Show success message

    return 0;  // End the program successfully
}

🌿Sample Input :
Enter three lines of text:
Line 1: Welcome to C++ File Handling
Line 2: This is my first file program
Line 3: Files store data permanently

🌿Expected Console Output :
Enter three lines of text:
Line 1: Welcome to C++ File Handling
Line 2: This is my first file program
Line 3: Files store data permanently
Data written successfully to notes.txt

🌿Expected file content (notes.txt)
Welcome to C++ File Handling
This is my first file program
Files store data permanently
