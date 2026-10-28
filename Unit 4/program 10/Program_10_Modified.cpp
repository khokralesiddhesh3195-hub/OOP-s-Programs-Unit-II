
#include <fstream>   // Provides file handling classes
#include <iostream>  // Provides input and output functions
#include <string>    // Provides the string data type

using namespace std; // Allows standard names without std::

int main() { // Main function starts

    // Open the file for both reading and writing
    fstream file("navigation.txt",
                 ios::in | ios::out | ios::trunc);

    // Check whether the file opened successfully
    if (!file) {
        cerr << "Error: Could not open navigation.txt\n";
        return 1; // Exit if file opening fails
    }

    file << "ABCDE"; // Write five characters into the file
    cout << "Output position after writing: "
         << file.tellp() << '\n'; // Display output pointer position

    file.flush(); // Ensure written data is sent to the file

    file.seekg(0, ios::beg); // Move input pointer to the beginning

    char firstCharacter; // Stores the first character
    file.get(firstCharacter); // Read the first character

    cout << "First character: " << firstCharacter << '\n';
    cout << "Input position after reading one character: "
         << file.tellg() << '\n'; // Display current input position

    file.seekg(2, ios::beg); // Move input pointer to position 2

    char thirdCharacter; // Stores the character at position 2
    file.get(thirdCharacter); // Read the character at position 2

    cout << "Character at position 2: "
         << thirdCharacter << '\n';

    // MODIFIED: Move input pointer to the last character
    file.seekg(-1, ios::end);

    char lastCharacter; // MODIFIED: Stores the last character
    file.get(lastCharacter); // MODIFIED: Read the last character

    // MODIFIED: Display the last character
    cout << "Last character: " << lastCharacter << '\n';

    file.close(); // Close the file

    cout << "Navigation completed. Check navigation.txt\n";

    return 0; // End the program successfully
}


🌿Expected Console Output
Output position after writing: 5
First character: A
Input position after reading one character: 1
Character at position 2: C
Last character: E
Navigation completed. Check navigation.txt

🌿Expected file content (navigation.txt)
ABCDE
