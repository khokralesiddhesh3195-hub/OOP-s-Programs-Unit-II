#include <fstream>  // Provides file handling classes.
#include <iostream> // Provides console input and output.
#include <limits>   // Provides numeric_limits.
#include <string>   // Provides the std::string class.

int main() // Program execution starts from the main() function.
{
    std::ofstream outputFile("students.txt", std::ios::app);
    // Opens students.txt in append mode.

    if (!outputFile)
    // Checks whether the file was opened successfully.
    {
        std::cerr << "Error: Could not open students.txt\n";
        // Displays an error message if the file cannot be opened.

        return 1;
        // Terminates the program with an error status.
    }

    int rollNumber;
    // Stores the student's roll number.

    std::string name;
    // Stores the student's name.

    double marks;
    // Stores the student's marks.

    std::cout << "Enter roll number: ";
    // Prompts the user for the roll number.

    std::cin >> rollNumber;
    // Reads the roll number.

    std::cout << "Enter name: ";
    // Prompts the user for the student's name.

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    // Removes the remaining newline from the input buffer.

    std::getline(std::cin, name);
    // Reads the complete student name including spaces.

    std::cout << "Enter marks: ";
    // Prompts the user for marks.

    std::cin >> marks;
    // Reads the marks.

    outputFile << rollNumber << '|' << name << '|' << marks << '\n';
    // Stores the complete student record in delimiter-separated format.

    std::cout << "Student record saved successfully.\n";
    // Displays a success message.

    return 0;
    // Terminates the program successfully.
}


📄 RECORD FORMAT

rollNumber|name|marks


⌨️ SAMPLE INPUT

Enter roll number: 101
Enter name: Amit Patil
Enter marks: 85.5


📄 SAMPLE FILE CONTENT — students.txt

101|Amit Patil|85.5


▶️ SAMPLE OUTPUT

Student record saved successfully.
