#include <fstream>  // Provides std::ofstream for writing data to files.
#include <iostream> // Provides std::cout and std::cerr for console output.

int main() // Program execution starts from the main() function.
{
    std::ofstream outputFile("message.txt");
    // Creates or opens a file named message.txt for writing.

    if (!outputFile)
    // Checks whether the file was opened/created successfully.
    {
        std::cerr << "Error: Could not create message.txt\n";
        // Displays an error message if the file cannot be opened.

        return 1;
        // Terminates the program with an error status.
    }

    outputFile << "Welcome to C++ File Handling\n";
    // Writes the first line into message.txt.

    outputFile << "This is the first line written to a file.\n";
    // Writes the second line into message.txt.

    outputFile << "Files store data permanently.\n";
    // Writes the third line into message.txt.

    outputFile.close();
    // Closes the file after completing the writing operation.

    std::cout << "Data written successfully to message.txt\n";
    // Displays a success message on the screen.

    return 0;
    // Terminates the program successfully.
}


📄 SAMPLE FILE CONTENT — message.txt
────────────────────────────────────────────────────────────

Welcome to C++ File Handling
This is the first line written to a file.
Files store data permanently.


▶️ SAMPLE OUTPUT
────────────────────────────────────────────────────────────

Data written successfully to message.txt
