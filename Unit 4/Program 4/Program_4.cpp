#include <fstream>  // Provides file input and output stream classes.
#include <iostream> // Provides console input and output functions.
#include <string>   // Provides the std::string class.

int main() // Program execution starts from the main() function.
{
    std::ifstream sourceFile("message.txt");
    // Opens message.txt for reading.

    std::ofstream destinationFile("message_copy.txt");
    // Creates or opens message_copy.txt for writing.

    if (!sourceFile)
    // Checks whether the source file was opened successfully.
    {
        std::cerr << "Error: Could not open source file.\n";
        // Displays an error message if the source file cannot be opened.

        return 1;
        // Terminates the program with an error status.
    }

    if (!destinationFile)
    // Checks whether the destination file was opened successfully.
    {
        std::cerr << "Error: Could not create destination file.\n";
        // Displays an error message if the destination file cannot be created.

        return 1;
        // Terminates the program with an error status.
    }

    std::string line;
    // Declares a string variable to store one line at a time.

    while (std::getline(sourceFile, line))
    // Reads the source file line by line until the end of the file.
    {
        destinationFile << line << '\n';
        // Writes each read line into the destination file.
    }

    std::cout << "File copied successfully to message_copy.txt\n";
    // Displays a success message.

    return 0;
    // Terminates the program successfully.
}


📄 SAMPLE FILE CONTENT — message.txt

Welcome to C++ File Handling
This is the first line written to a file.
Files store data permanently.


📄 RESULTING FILE CONTENT — message_copy.txt

Welcome to C++ File Handling
This is the first line written to a file.
Files store data permanently.


▶️ SAMPLE OUTPUT

File copied successfully to message_copy.txt
