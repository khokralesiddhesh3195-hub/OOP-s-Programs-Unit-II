#include <fstream>   // Provides file handling classes
#include <iostream>  // Provides input and output functions
#include <string>    // Provides the string data type

using namespace std; // Allows using standard names without std::

int main() { // Main function starts

    // MODIFIED: Open the file in append mode to preserve existing data
    ofstream outputFile("message.txt", ios::app);

    // Check whether the file opened successfully
    if (!outputFile) {
        cerr << "Error: Could not open message.txt for appending\n";
        return 1; // Exit if the file cannot be opened
    }

    string name; // MODIFIED: Variable to store the user's name
    string date; // MODIFIED: Variable to store the date entered by the user

    // MODIFIED: Ask the user to enter their name
    cout << "Enter your name: ";
    getline(cin, name); // Read the complete name, including spaces

    // MODIFIED: Ask the user to enter the current date
    cout << "Enter the date (DD-MM-YYYY): ";
    getline(cin, date); // Read the date as text

    // MODIFIED: Append the name and date to the existing file
    outputFile << "Name: " << name << " | Date: " << date << '\n';

    outputFile.close(); // Close the file and save the appended data

    cout << "Name and date appended successfully.\n"; // Display success message

    return 0; // End the program successfully
}

🌿Sample Input
Enter your name: Siddhesh Khokrale
Enter the date (DD-MM-YYYY): 28-10-2026

🌿Expected Console Output
Name and date appended successfully.

🌿Expected file content (message.txt)
If the file already contains previous text, that text remains unchanged. The following line is added at the end:
Name: Siddhesh Khokrale | Date: 28-10-2026
