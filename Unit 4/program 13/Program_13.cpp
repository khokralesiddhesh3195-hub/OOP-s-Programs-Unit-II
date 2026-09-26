#include <fstream>  // Provides file input stream classes.
#include <iostream> // Provides console input and output.
#include <string>   // Provides the std::string class.

int main() // Program execution starts from the main() function.
{
    std::ifstream inputFile("missing_file.txt");
    // Attempts to open missing_file.txt for reading.

    if (!inputFile.is_open())
    // Checks whether the file failed to open.
    {
        std::cerr << "Error: File could not be opened.\n";
        // Displays an error message.

        std::cerr << "Check whether missing_file.txt exists "
                     "in the current folder.\n";
        // Provides information about the possible cause.

        return 1;
        // Terminates the program with an error status.
    }

    std::string line;
    // Stores one line read from the file.

    while (std::getline(inputFile, line))
    // Reads the file line by line.
    {
        std::cout << line << '\n';
        // Displays each line.
    }

    if (inputFile.eof())
    // Checks whether the end of the file was reached.
    {
        std::cout << "End of file reached normally.\n";
        // Displays the normal end-of-file message.
    }
    else if (inputFile.bad())
    // Checks for a serious input/output error.
    {
        std::cerr << "A serious file I/O error occurred.\n";
        // Displays the serious error message.
    }
    else if (inputFile.fail())
    // Checks for a logical file read error.
    {
        std::cerr << "A logical file read error occurred.\n";
        // Displays the logical error message.
    }

    return 0;
    // Terminates the program successfully.
}


📄 REQUIRED FILE

missing_file.txt

If this file does not exist in the program's current folder,
the opening operation will fail.


▶️ SAMPLE OUTPUT WHEN THE FILE DOES NOT EXIST

Error: File could not be opened.
Check whether missing_file.txt exists in the current folder.
