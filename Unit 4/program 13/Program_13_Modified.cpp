#include <fstream>   // Includes file handling classes.
#include <iostream>  // Includes input and output functions.
#include <string>    // Includes the string class.

int main() {  // Main function starts here.

    std::ifstream inputFile;  // Declares an input file stream.
    std::string fileName;     // MODIFIED: Stores the filename entered by the user.

    // MODIFIED: Repeatedly asks for a filename until a valid file opens.
    while (true) {

        std::cout << "Enter the file name: ";  // MODIFIED: Prompts the user.
        std::getline(std::cin, fileName);      // MODIFIED: Reads the filename.

        inputFile.open(fileName);  // MODIFIED: Attempts to open the entered file.

        if (inputFile.is_open()) {  // Checks whether the file opened successfully.
            std::cout << "File opened successfully.\n";  // MODIFIED: Displays success.
            break;  // MODIFIED: Exits the loop when the file opens.
        }

        std::cerr << "Error: File could not be opened.\n";  // Displays an error.
        std::cerr << "Please enter a valid file name.\n";   // MODIFIED: Requests retry.

        inputFile.clear();  // MODIFIED: Clears error flags before retrying.
    }

    std::string line;  // Declares a string to store each line.

    // Reads the file one line at a time until the end is reached.
    while (std::getline(inputFile, line)) {
        std::cout << line << '\n';  // Displays the current line.
    }

    // Checks the stream state after reading.
    if (inputFile.eof()) {
        std::cout << "End of file reached normally.\n";
    }
    else if (inputFile.bad()) {
        std::cerr << "A serious file I/O error occurred.\n";
    }
    else if (inputFile.fail()) {
        std::cerr << "A logical file read error occurred.\n";
    }

    inputFile.close();  // Closes the file after reading.

    return 0;  // Returns 0 to indicate successful program termination.
}


Example Output

🌿Case 1: The user enters an invalid filename first.Enter the file name: missing.txt
Error: File could not be opened.
Please enter a valid file name.
Enter the file name: data.txt
File opened successfully.
Hello World
This is a sample file.
End of file reached normally.

🌿Case 2: The user enters a valid filename immediately.
Enter the file name: data.txt
File opened successfully.
Hello World
This is a sample file.
End of file reached normally.
