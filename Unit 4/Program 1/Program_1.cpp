#include <fstream>
#include <iostream>

int main() {
    // Open the file for writing.
    // If the file does not exist, it will be created.
    std::ofstream file("message.txt");

    // Check whether the file was opened successfully.
    if (!file) {
        std::cerr << "Error: Could not open file.\n";
        return 1;
    }

    // Write text into the file.
    file << "Hello, this is a C++ file handling program.\n";

    // Close the file.
    file.close();

    // Display success message.
    std::cout << "Data written successfully.\n";

    return 0;
}
