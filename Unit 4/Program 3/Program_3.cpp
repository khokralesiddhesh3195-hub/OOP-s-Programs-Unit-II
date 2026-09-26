#include <fstream>  // Provides file handling classes such as std::ofstream.
#include <iostream> // Provides std::cout and std::cerr for console output.

int main() // Program execution starts from the main() function.
{
    std::ofstream outputFile("message.txt", std::ios::app);
    // Opens message.txt in append mode so new data is added at the end.

    if (!outputFile)
    // Checks whether the file was opened successfully.
    {
        std::cerr << "Error: Could not open message.txt for appending\n";
        // Displays an error message if the file cannot be opened.

        return 1;
        // Terminates the program with an error status.
    }

    outputFile << "This line was added using append mode.\n";
    // Adds a new line at the end of the existing file content.

    outputFile.close();
    // Closes the file after completing the append operation.

    std::cout << "New line appended successfully.\n";
    // Displays a success message on the screen.

    return 0;
    // Terminates the program successfully.
}


📄 SAMPLE FILE CONTENT — message.txt

Before running the program:

Welcome to C++ File Handling
This is the first line written to a file.
Files store data permanently.

After running the program:

Welcome to C++ File Handling
This is the first line written to a file.
Files store data permanently.
This line was added using append mode.


▶️ SAMPLE OUTPUT

New line appended successfully.
