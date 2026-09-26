#include <fstream>  // Provides file input and output streams.
#include <iostream> // Provides console input and output.
#include <sstream>  // Provides std::stringstream.
#include <string>   // Provides the std::string class.

int main() // Program execution starts from the main() function.
{
    std::ifstream inputFile("students.txt");
    // Opens students.txt for reading.

    if (!inputFile)
    // Checks whether the file was opened successfully.
    {
        std::cerr << "Error: Could not open students.txt\n";
        // Displays an error message.

        return 1;
        // Terminates the program with an error status.
    }

    int targetRollNumber;
    // Stores the roll number entered for searching.

    std::cout << "Enter roll number to search: ";
    // Prompts the user for the roll number.

    std::cin >> targetRollNumber;
    // Reads the target roll number.

    std::string line;
    // Stores one complete record line.

    bool found = false;
    // Tracks whether the required student was found.

    while (std::getline(inputFile, line))
    // Reads the file one record at a time.
    {
        std::stringstream record(line);
        // Creates a string stream for parsing the record.

        std::string rollText;
        // Stores the roll number as text.

        std::string name;
        // Stores the student name.

        std::string marksText;
        // Stores the marks as text.

        if (std::getline(record, rollText, '|') &&
            std::getline(record, name, '|') &&
            std::getline(record, marksText))
        // Extracts the three fields separated by |.
        {
            int rollNumber = std::stoi(rollText);
            // Converts the roll number from text to integer.

            double marks = std::stod(marksText);
            // Converts marks from text to double.

            if (rollNumber == targetRollNumber)
            // Checks whether the roll number matches.
            {
                std::cout << "Record Found\n";
                // Displays that the record was found.

                std::cout << "Roll Number: " << rollNumber << '\n';
                // Displays the roll number.

                std::cout << "Name: " << name << '\n';
                // Displays the student's name.

                std::cout << "Marks: " << marks << '\n';
                // Displays the student's marks.

                found = true;
                // Marks the record as found.

                break;
                // Stops searching after finding the record.
            }
        }
    }

    if (!found)
    // Checks whether no matching record was found.
    {
        std::cout << "Student record not found.\n";
        // Displays the not-found message.
    }

    return 0;
    // Terminates the program successfully.
}


📄 SAMPLE FILE CONTENT — students.txt

101|Amit Patil|85.5
102|Neha Sharma|91
103|Ravi Kumar|78


⌨️ SAMPLE INPUT

Enter roll number to search: 102


▶️ SAMPLE OUTPUT

Record Found
Roll Number: 102
Name: Neha Sharma
Marks: 91
