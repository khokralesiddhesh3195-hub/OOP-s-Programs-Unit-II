
#include <fstream>   // Provides file handling classes
#include <iostream>  // Provides input and output functions
#include <string>    // Provides the string data type
#include <cctype>    // MODIFIED: Provides character conversion functions

using namespace std; // Allows standard names without std::

int main() { // Main function starts

    ifstream inputFile("message.txt"); // Open the file for reading

    // Check whether the file opened successfully
    if (!inputFile) {
        cerr << "Error: Could not open message.txt\n";
        return 1; // Exit if the file cannot be opened
    }

    string searchWord; // Stores the word entered by the user

    cout << "Enter word to search: "; // Ask for the search word
    cin >> searchWord; // Read the word from the user

    // MODIFIED: Convert the search word to lowercase
    for (char &ch : searchWord) {
        ch = static_cast<char>(
            tolower(static_cast<unsigned char>(ch))
        );
    }

    string word; // Stores each word read from the file
    int count = 0; // Counts matching occurrences

    // Read the file one whitespace-separated word at a time
    while (inputFile >> word) {

        // MODIFIED: Remove punctuation from the beginning and end
        size_t start = 0;
        size_t end = word.size();

        while (start < end &&
               ispunct(static_cast<unsigned char>(word[start]))) {
            start++; // Skip leading punctuation
        }

        while (end > start &&
               ispunct(static_cast<unsigned char>(word[end - 1]))) {
            end--; // Skip trailing punctuation
        }

        // MODIFIED: Extract the word without surrounding punctuation
        word = word.substr(start, end - start);

        // MODIFIED: Convert the file word to lowercase
        for (char &ch : word) {
            ch = static_cast<char>(
                tolower(static_cast<unsigned char>(ch))
            );
        }

        // Compare the normalized word with the search word
        if (word == searchWord) {
            count++; // MODIFIED: Increment matching word count
        }
    }

    inputFile.close(); // Close the file after searching

    // Display the total number of occurrences
    cout << "The word '" << searchWord
         << "' occurred " << count << " time(s).\n";

    return 0; // End the program successfully
}


🌿Sample message.txt content
C++ is useful.
I like c++!
C++ is powerful, and C++ is popular.

🌿Sample Input
Enter word to search: c++

🌿Expected Console Output
The word 'c++' occurred 4 time(s).
