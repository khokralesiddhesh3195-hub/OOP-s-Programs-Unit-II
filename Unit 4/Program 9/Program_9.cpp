#include <cstdio>   // Provides remove() and rename().
#include <fstream>  // Provides file handling classes.
#include <iostream> // Provides console input and output.
#include <sstream>  // Provides std::stringstream.
#include <string>   // Provides the std::string class.

int main() // Program execution starts from the main() function.
{
    std::ifstream inputFile("students.txt");
    // Opens the original student file for reading.

    std::ofstream temporaryFile("students_temp.txt");
    // Creates a temporary file for the updated records.

    if (!inputFile || !temporaryFile)
    // Checks whether either file failed to open.
    {
        std::cerr << "Error: Could not open file(s).\n";
        // Displays an error message.

        return 1;
        // Terminates the program.
    }

    int targetRollNumber;
    // Stores the roll number whose marks must be updated.

    double updatedMarks;
    // Stores the new marks.

    std::cout << "Enter roll number to update: ";
    // Prompts the user for the roll number.

    std::cin >> targetRollNumber;
    // Reads the roll number.

    std::cout << "Enter updated marks: ";
    // Prompts the user for new marks.

    std::cin >> updatedMarks;
    // Reads the new marks.

    std::string line;
    // Stores one record line.

    bool found = false;
    // Tracks whether the student was found.

    while (std::getline(inputFile, line))
    // Reads all records from the original file.
    {
        std::stringstream record(line);
        // Creates a stream to parse the current record.

        std::string rollText;
        // Stores the roll number as text.

        std::string name;
        // Stores the student's name.

        std::string marksText;
        // Stores the marks as text.

        if (std::getline(record, rollText, '|') &&
            std::getline(record, name, '|') &&
            std::getline(record, marksText))
        // Extracts the three fields.
        {
            int rollNumber = std::stoi(rollText);
            // Converts the roll number into an integer.

            if (rollNumber == targetRollNumber)
            // Checks whether this is the record to update.
            {
                temporaryFile << rollNumber << '|' << name << '|'
                              << updatedMarks << '\n';
                // Writes the updated record to the temporary file.

                found = true;
                // Marks that the required student was found.
            }
            else
            {
                temporaryFile << line << '\n';
                // Copies unchanged records to the temporary file.
            }
        }
    }

    inputFile.close();
    // Closes the original file.

    temporaryFile.close();
    // Closes the temporary file before replacing the original.

    if (!found)
    // Checks whether the student was not found.
    {
        std::remove("students_temp.txt");
        // Deletes the unnecessary temporary file.

        std::cout << "Student record not found. No update performed.\n";
        // Displays the result.

        return 0;
        // Terminates successfully.
    }

    if (std::remove("students.txt") != 0)
    // Attempts to remove the old student file.
    {
        std::cerr << "Error: Could not remove old students.txt\n";
        // Displays an error if removal fails.

        return 1;
        // Terminates with an error.
    }

    if (std::rename("students_temp.txt", "students.txt") != 0)
    // Renames the temporary file as the original file.
    {
        std::cerr << "Error: Could not rename temporary file.\n";
        // Displays an error if renaming fails.

        return 1;
        // Terminates with an error.
    }

    std::cout << "Student marks updated successfully.\n";
    // Displays the success message.

    return 0;
    // Terminates successfully.
}


📄 SAMPLE FILE CONTENT — students.txt

101|Amit Patil|85.5
102|Neha Sharma|91
103|Ravi Kumar|78


⌨️ SAMPLE INPUT

Enter roll number to update: 102
Enter updated marks: 95


📄 UPDATED FILE CONTENT — students.txt

101|Amit Patil|85.5
102|Neha Sharma|95
103|Ravi Kumar|78


▶️ SAMPLE OUTPUT

Student marks updated successfully.
