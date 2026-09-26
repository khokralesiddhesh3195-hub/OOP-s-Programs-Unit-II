#include <fstream>  // Provides file stream classes.
#include <iostream> // Provides console input and output.
#include <string>   // Provides string support.

int main() // Program execution starts from the main() function.
{
    std::fstream file("navigation.txt",
                      std::ios::in | std::ios::out | std::ios::trunc);
    // Opens navigation.txt for both reading and writing.

    if (!file)
    // Checks whether the file opened successfully.
    {
        std::cerr << "Error: Could not open navigation.txt\n";
        // Displays an error message.

        return 1;
        // Terminates the program.
    }

    file << "ABCDE";
    // Writes five characters into the file.

    std::cout << "Output position after writing: "
              << file.tellp() << '\n';
    // Displays the current output pointer position.

    file.flush();
    // Ensures written data is transferred to the file.

    file.seekg(0, std::ios::beg);
    // Moves the input pointer to the beginning.

    char firstCharacter;
    // Stores the first character.

    file.get(firstCharacter);
    // Reads the first character.

    std::cout << "First character: " << firstCharacter << '\n';
    // Displays the first character.

    std::cout << "Input position after reading one character: "
              << file.tellg() << '\n';
    // Displays the current input pointer position.

    file.seekg(2, std::ios::beg);
    // Moves the input pointer to position 2.

    char thirdCharacter;
    // Stores the character at position 2.

    file.get(thirdCharacter);
    // Reads the character at position 2.

    std::cout << "Character at position 2: "
              << thirdCharacter << '\n';
    // Displays the selected character.

    file.seekp(5, std::ios::beg);
    // Moves the output pointer to position 5.

    file << "F";
    // Writes F at position 5.

    file.close();
    // Closes the file.

    std::cout << "Navigation completed. Check navigation.txt\n";
    // Displays a completion message.

    return 0;
    // Terminates the program successfully.
}


📄 RESULTING FILE CONTENT — navigation.txt

ABCDEF


▶️ SAMPLE OUTPUT

Output position after writing: 5
First character: A
Input position after reading one character: 1
Character at position 2: C
Navigation completed. Check navigation.txt
