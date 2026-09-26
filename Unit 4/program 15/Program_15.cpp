#include <cstdio>   // Provides remove() and rename().
#include <fstream>  // Provides file input and output.
#include <iostream> // Provides console input and output.
#include <limits>   // Provides numeric_limits.
#include <sstream>  // Provides string stream parsing.
#include <string>   // Provides the std::string class.

void addStudent()
{
    std::ofstream outputFile("student_records.txt", std::ios::app);
    // Opens the student record file in append mode.

    if (!outputFile)
    // Checks whether the file opened successfully.
    {
        std::cerr << "Error: Could not open student_records.txt\n";
        // Displays an error message.

        return;
        // Returns to the menu.
    }

    int rollNumber;
    // Stores the student's roll number.

    std::string name;
    // Stores the student's name.

    double marks;
    // Stores the student's marks.

    std::cout << "Enter roll number: ";
    // Prompts for roll number.

    std::cin >> rollNumber;
    // Reads roll number.

    std::cout << "Enter name: ";
    // Prompts for the student's name.

    std::cin.ignore(
        std::numeric_limits<std::streamsize>::max(), '\n');
    // Clears the remaining newline.

    std::getline(std::cin, name);
    // Reads the complete name.

    std::cout << "Enter marks: ";
    // Prompts for marks.

    std::cin >> marks;
    // Reads marks.

    outputFile << rollNumber << '|' << name << '|' << marks << '\n';
    // Saves the student record.

    std::cout << "Record added successfully.\n";
    // Displays a success message.
}

void displayStudents()
{
    std::ifstream inputFile("student_records.txt");
    // Opens the student record file for reading.

    if (!inputFile)
    // Checks whether the file exists.
    {
        std::cout << "No student record file found.\n";
        // Displays a message if the file does not exist.

        return;
        // Returns to the menu.
    }

    std::string line;
    // Stores one record line.

    std::cout << "\nRoll No.\tName\t\tMarks\n";
    // Displays the table heading.

    std::cout << "----------------------------------------\n";
    // Displays a table separator.

    while (std::getline(inputFile, line))
    // Reads all records line by line.
    {
        std::stringstream record(line);
        // Creates a stream for parsing the record.

        std::string rollText;
        // Stores the roll number.

        std::string name;
        // Stores the student's name.

        std::string marksText;
        // Stores the marks.

        if (std::getline(record, rollText, '|') &&
            std::getline(record, name, '|') &&
            std::getline(record, marksText))
        // Extracts all three fields.
        {
            std::cout << rollText << "\t\t"
                      << name << "\t\t"
                      << marksText << '\n';
            // Displays the student record.
        }
    }
}

void searchStudent()
{
    std::ifstream inputFile("student_records.txt");
    // Opens the record file for reading.

    if (!inputFile)
    // Checks whether the file exists.
    {
        std::cout << "No student record file found.\n";
        // Displays an error message.

        return;
        // Returns to the menu.
    }

    int targetRoll;
    // Stores the roll number to search.

    std::cout << "Enter roll number to search: ";
    // Prompts for a roll number.

    std::cin >> targetRoll;
    // Reads the roll number.

    std::string line;
    // Stores one record.

    bool found = false;
    // Tracks whether the student was found.

    while (std::getline(inputFile, line))
    // Reads records one by one.
    {
        std::stringstream record(line);
        // Creates a parser for the record.

        std::string rollText;
        // Stores the roll number as text.

        std::string name;
        // Stores the student's name.

        std::string marksText;
        // Stores the marks as text.

        if (std::getline(record, rollText, '|') &&
            std::getline(record, name, '|') &&
            std::getline(record, marksText))
        // Extracts all record fields.
        {
            if (std::stoi(rollText) == targetRoll)
            // Checks whether the roll number matches.
            {
                std::cout << "Record Found\n";
                // Displays the result.

                std::cout << "Roll Number: "
                          << rollText << '\n';
                // Displays the roll number.

                std::cout << "Name: " << name << '\n';
                // Displays the student's name.

                std::cout << "Marks: " << marksText << '\n';
                // Displays the marks.

                found = true;
                // Marks the record as found.

                break;
                // Stops searching.
            }
        }
    }

    if (!found)
    // Checks whether the student was not found.
    {
        std::cout << "Student not found.\n";
        // Displays the not-found message.
    }
}

void updateMarks()
{
    std::ifstream inputFile("student_records.txt");
    // Opens the original file for reading.

    std::ofstream temporaryFile("student_records_temp.txt");
    // Creates a temporary file for updated records.

    if (!inputFile || !temporaryFile)
    // Checks whether either file failed to open.
    {
        std::cerr << "Error: Could not open record file(s).\n";
        // Displays an error message.

        return;
        // Returns to the menu.
    }

    int targetRoll;
    // Stores the roll number to update.

    double newMarks;
    // Stores the new marks.

    std::cout << "Enter roll number to update: ";
    // Prompts for the roll number.

    std::cin >> targetRoll;
    // Reads the roll number.

    std::cout << "Enter new marks: ";
    // Prompts for new marks.

    std::cin >> newMarks;
    // Reads the new marks.

    std::string line;
    // Stores one record line.

    bool found = false;
    // Tracks whether the record was found.

    while (std::getline(inputFile, line))
    // Reads all records.
    {
        std::stringstream record(line);
        // Creates a stream for parsing.

        std::string rollText;
        // Stores the roll number.

        std::string name;
        // Stores the student's name.

        std::string marksText;
        // Stores the marks.

        if (std::getline(record, rollText, '|') &&
            std::getline(record, name, '|') &&
            std::getline(record, marksText))
        // Extracts all fields.
        {
            if (std::stoi(rollText) == targetRoll)
            // Checks whether this is the selected student.
            {
                temporaryFile << rollText << '|'
                              << name << '|'
                              << newMarks << '\n';
                // Writes the updated record.

                found = true;
                // Marks the student as found.
            }
            else
            {
                temporaryFile << line << '\n';
                // Copies unchanged records.
            }
        }
    }

    inputFile.close();
    // Closes the original file.

    temporaryFile.close();
    // Closes the temporary file.

    if (!found)
    // Checks whether no record was found.
    {
        std::remove("student_records_temp.txt");
        // Deletes the temporary file.

        std::cout << "Student not found. No changes made.\n";
        // Displays the result.

        return;
        // Returns to the menu.
    }

    if (std::remove("student_records.txt") != 0 ||
        std::rename("student_records_temp.txt",
                    "student_records.txt") != 0)
    // Removes the old file and renames the temporary file.
    {
        std::cerr << "Error: Could not replace the record file.\n";
        // Displays an error message.

        return;
        // Returns to the menu.
    }

    std::cout << "Marks updated successfully.\n";
    // Displays a success message.
}

int main() // Program execution starts here.
{
    int choice;
    // Stores the menu choice.

    do
    {
        std::cout << "\nStudent Record Manager\n";
        // Displays the menu heading.

        std::cout << "1. Add Student\n";
        // Displays option 1.

        std::cout << "2. Display All Students\n";
        // Displays option 2.

        std::cout << "3. Search Student\n";
        // Displays option 3.

        std::cout << "4. Update Marks\n";
        // Displays option 4.

        std::cout << "0. Exit\n";
        // Displays the exit option.

        std::cout << "Enter choice: ";
        // Prompts for a choice.

        std::cin >> choice;
        // Reads the menu choice.

        switch (choice)
        {
            case 1:
                addStudent();
                // Calls the add-student function.
                break;

            case 2:
                displayStudents();
                // Calls the display function.
                break;

            case 3:
                searchStudent();
                // Calls the search function.
                break;

            case 4:
                updateMarks();
                // Calls the update function.
                break;

            case 0:
                std::cout << "Exiting program.\n";
                // Displays the exit message.
                break;

            default:
                std::cout << "Invalid choice. Try again.\n";
                // Handles an invalid menu choice.
        }

    } while (choice != 0);
    // Repeats the menu until the user chooses 0.

    return 0;
    // Terminates the program successfully.
}


📄 SAMPLE FILE CONTENT — student_records.txt

101|Amit Patil|85.5
102|Neha Sharma|91
103|Ravi Kumar|78


⌨️ SAMPLE INTERACTION

Student Record Manager
1. Add Student
2. Display All Students
3. Search Student
4. Update Marks
0. Exit
Enter choice: 2


▶️ SAMPLE OUTPUT

Roll No.        Name            Marks
----------------------------------------
101             Amit Patil      85.5
102             Neha Sharma     91
103             Ravi Kumar      78
