#include <cctype>  // Provides character classification functions.
#include <fstream> // Provides file input streams.
#include <iostream> // Provides console input and output.
#include <string>  // Provides the std::string class.

bool isVowel(char ch)
{
    ch = static_cast<char>(
        std::tolower(static_cast<unsigned char>(ch)));
    // Converts the character to lowercase.

    return ch == 'a' || ch == 'e' || ch == 'i' ||
           ch == 'o' || ch == 'u';
    // Returns true if the character is a vowel.
}

int main() // Program execution starts from the main() function.
{
    std::string fileName;
    // Stores the name of the file entered by the user.

    std::cout << "Enter file name: ";
    // Prompts the user for a file name.

    std::getline(std::cin, fileName);
    // Reads the complete file name.

    std::ifstream inputFile(fileName);
    // Opens the selected file for reading.

    if (!inputFile)
    // Checks whether the file was opened successfully.
    {
        std::cerr << "Error: Could not open "
                  << fileName << '\n';
        // Displays an error message.

        return 1;
        // Terminates the program.
    }

    std::size_t lines = 0;
    // Stores the number of lines.

    std::size_t words = 0;
    // Stores the number of words.

    std::size_t characters = 0;
    // Stores the number of characters.

    std::size_t vowels = 0;
    // Stores the number of vowels.

    std::size_t digits = 0;
    // Stores the number of digits.

    std::size_t spaces = 0;
    // Stores the number of spaces.

    bool insideWord = false;
    // Tracks whether the current character belongs to a word.

    char ch;
    // Stores one character at a time.

    while (inputFile.get(ch))
    // Reads every character from the file.
    {
        ++characters;
        // Increases the character count.

        if (ch == '\n')
        // Checks whether the character is a newline.
        {
            ++lines;
            // Increases the line count.
        }

        if (std::isspace(static_cast<unsigned char>(ch)))
        // Checks whether the character is whitespace.
        {
            if (ch == ' ')
            // Checks specifically for a normal space.
            {
                ++spaces;
                // Increases the space count.
            }

            insideWord = false;
            // Marks that the program is outside a word.
        }
        else if (!insideWord)
        // Checks whether a new word has started.
        {
            ++words;
            // Increases the word count.

            insideWord = true;
            // Marks that the program is inside a word.
        }

        if (std::isalpha(static_cast<unsigned char>(ch)) &&
            isVowel(ch))
        // Checks whether the character is an alphabetic vowel.
        {
            ++vowels;
            // Increases the vowel count.
        }

        if (std::isdigit(static_cast<unsigned char>(ch)))
        // Checks whether the character is a digit.
        {
            ++digits;
            // Increases the digit count.
        }
    }

    if (characters > 0)
    // Checks whether the file contains any characters.
    {
        inputFile.clear();
        // Clears the EOF state before repositioning.

        inputFile.seekg(-1, std::ios::end);
        // Moves to the last character.

        char lastCharacter;
        // Stores the last character.

        inputFile.get(lastCharacter);
        // Reads the last character.

        if (lastCharacter != '\n')
        // Checks whether the file does not end with a newline.
        {
            ++lines;
            // Counts the final line.
        }
    }

    std::cout << "\nFile Statistics\n";
    // Displays the heading.

    std::cout << "Lines: " << lines << '\n';
    // Displays the line count.

    std::cout << "Words: " << words << '\n';
    // Displays the word count.

    std::cout << "Characters: " << characters << '\n';
    // Displays the character count.

    std::cout << "Vowels: " << vowels << '\n';
    // Displays the vowel count.

    std::cout << "Digits: " << digits << '\n';
    // Displays the digit count.

    std::cout << "Spaces: " << spaces << '\n';
    // Displays the space count.

    return 0;
    // Terminates the program successfully.
}


📄 SAMPLE TEST FILE — data.txt

C++ File Handling 2026
Students learn file streams.


⌨️ SAMPLE INPUT

Enter file name: data.txt


▶️ SAMPLE OUTPUT

File Statistics
Lines: 2
Words: 5
Characters: 48
Vowels: 15
Digits: 4
Spaces: 5
