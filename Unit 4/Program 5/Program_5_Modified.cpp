#include <cctype>   // Provides isalpha(), isdigit(), isspace()
#include <fstream>  // Provides file handling classes
#include <iostream> // Provides input and output functions
#include <string>   // Provides the string data type

using namespace std; // Allows standard names without std::

int main() { // Main function starts

    ifstream inputFile("message.txt"); // Open the file for reading

    // Check whether the file opened successfully
    if (!inputFile) {
        cerr << "Error: Could not open message.txt\n";
        return 1; // Exit if the file cannot be opened
    }

    // MODIFIED: Declare counters for character categories
    int vowels = 0;       // Counts vowels
    int consonants = 0;   // Counts consonants
    int digits = 0;       // Counts numeric digits
    int spaces = 0;       // Counts space characters
    int punctuation = 0;  // Counts punctuation marks

    char ch; // Stores each character read from the file

    // Read the file one character at a time
    while (inputFile.get(ch)) {

        // MODIFIED: Count vowels and consonants
        if (isalpha(static_cast<unsigned char>(ch))) {
            char lower = static_cast<char>(
                tolower(static_cast<unsigned char>(ch))
            ); // Convert the letter to lowercase

            if (lower == 'a' || lower == 'e' ||
                lower == 'i' || lower == 'o' ||
                lower == 'u') {
                vowels++; // Increase vowel count
            } else {
                consonants++; // Increase consonant count
            }
        }

        // MODIFIED: Count digits from 0 to 9
        else if (isdigit(static_cast<unsigned char>(ch))) {
            digits++;
        }

        // MODIFIED: Count space characters only
        else if (ch == ' ') {
            spaces++;
        }

        // MODIFIED: Count punctuation characters
        else if (ispunct(static_cast<unsigned char>(ch))) {
            punctuation++;
        }
    }

    inputFile.close(); // Close the file after reading

    // MODIFIED: Display the required character statistics
    cout << "Vowels: " << vowels << '\n';
    cout << "Consonants: " << consonants << '\n';
    cout << "Digits: " << digits << '\n';
    cout << "Spaces: " << spaces << '\n';
    cout << "Punctuation: " << punctuation << '\n';

    return 0; // End the program successfully
}


🌿Sample message.txt content
Hello C++ 2026!

🌿Expected Console Output
Vowels: 2
Consonants: 5
Digits: 4
Spaces: 2
Punctuation: 3
