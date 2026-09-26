#include <cctype>  // Provides character classification functions.
#include <fstream> // Provides file handling classes.
#include <iostream> // Provides console input and output.
#include <string>  // Provides the std::string class.

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

    std::size_t lineCount = 0;
    // Stores the number of lines in the file.

    std::size_t wordCount = 0;
    // Stores the number of words in the file.

    std::size_t characterCount = 0;
    // Stores the number of characters in the file.

    bool insideWord = false;
    // Tracks whether the current character is inside a word.

    char ch;
    // Stores one character read from the file.

    while (inputFile.get(ch))
    // Reads the file one character at a time.
    {
        ++characterCount;
        // Increases the character count.

        if (ch == '\n')
        // Checks whether the current character is a newline.
        {
            ++lineCount;
            // Increases the line count.
        }

        if (std::isspace(static_cast<unsigned char>(ch)))
        // Checks whether the character is whitespace.
        {
            insideWord = false;
            // Marks that the current position is outside a word.
        }
        else if (!insideWord)
        // Checks whether a new word has started.
        {
            ++wordCount;
            // Increases the word count.

            insideWord = true;
            // Marks that the program is currently inside a word.
        }
    }

    if (characterCount > 0)
    // Checks whether the file contains at least one character.
    {
        inputFile.clear();
        // Clears the end-of-file state so the file can be repositioned.

        inputFile.seekg(-1, std::ios::end);
        // Moves the input pointer to the last character.

        char lastCharacter;
        // Stores the last character.

        inputFile.get(lastCharacter);
        // Reads the last character.

        if (lastCharacter != '\n')
        // Checks whether the file does not end with a newline.
        {
            ++lineCount;
            // Counts the final line.
        }
    }

    std::cout << "Lines: " << lineCount << '\n';
    // Displays the number of lines.

    std::cout << "Words: " << wordCount << '\n';
    // Displays the number of words.

    std::cout << "Characters: " << characterCount << '\n';
    // Displays the number of characters.

    return 0;
    // Terminates the program successfully.
}


📄 SAMPLE FILE CONTENT — message.txt

Welcome to C++ File Handling
This is the first line written to a file.
Files store data permanently.
C++ makes file handling easy.


▶️ SAMPLE OUTPUT

Lines: 4
Words: 25
Characters: 150
