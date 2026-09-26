#include <fstream> // Provides file input and output streams.
#include <iostream> // Provides console input and output.
#include <string> // Provides the std::string class.

int main() // Program execution starts from the main() function.
{
    std::ifstream inputFile("message.txt");
    // Opens message.txt for reading.

    if (!inputFile)
    // Checks whether the file was opened successfully.
    {
        std::cerr << "Error: Could not open message.txt\n";
        // Displays an error message if the file cannot be opened.

        return 1;
        // Terminates the program with an error status.
    }

    std::string searchWord;
    // Stores the word entered by the user.

    std::cout << "Enter word to search: ";
    // Prompts the user to enter a search word.

    std::cin >> searchWord;
    // Reads the search word.

    std::string word;
    // Stores each word read from the file.

    int count = 0;
    // Stores the number of occurrences.

    while (inputFile >> word)
    // Reads words from the file until the end of the file.
    {
        if (word == searchWord)
        // Checks whether the current word matches the search word.
        {
            ++count;
            // Increases the occurrence count.
        }
    }

    std::cout << "The word '" << searchWord
              << "' occurred " << count << " time(s).\n";
    // Displays the number of occurrences.

    return 0;
    // Terminates the program successfully.
}


📄 SAMPLE FILE CONTENT — message.txt

Welcome to C++ File Handling
C++ is powerful.
C++ supports file handling.


⌨️ SAMPLE INPUT

Enter word to search: C++


▶️ SAMPLE OUTPUT

The word 'C++' occurred 3 time(s).
