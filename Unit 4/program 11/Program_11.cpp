#include <cstring>  // Provides std::strncpy().
#include <fstream>  // Provides binary file streams.
#include <iostream> // Provides console input and output.

struct StudentRecord
{
    int rollNumber;
    // Stores the student's roll number.

    char name[30];
    // Stores the student's name using a fixed-size character array.

    float marks;
    // Stores the student's marks.
};

int main() // Program execution starts from the main() function.
{
    StudentRecord student{};
    // Creates and initializes a StudentRecord object.

    student.rollNumber = 101;
    // Assigns the roll number.

    std::strncpy(student.name, "Amit Patil",
                 sizeof(student.name) - 1);
    // Copies the student's name into the fixed-size character array.

    student.marks = 85.5F;
    // Assigns the student's marks.

    {
        std::ofstream outputFile("students.dat", std::ios::binary);
        // Opens students.dat in binary writing mode.

        if (!outputFile)
        // Checks whether the binary file was created successfully.
        {
            std::cerr << "Error: Could not create students.dat\n";
            // Displays an error message.

            return 1;
            // Terminates the program.
        }

        outputFile.write(reinterpret_cast<const char*>(&student),
                         sizeof(student));
        // Writes the complete structure as raw bytes.
    }

    StudentRecord readStudent{};
    // Creates a structure to store the record read from the file.

    {
        std::ifstream inputFile("students.dat", std::ios::binary);
        // Opens students.dat in binary reading mode.

        if (!inputFile)
        // Checks whether the file opened successfully.
        {
            std::cerr << "Error: Could not open students.dat\n";
            // Displays an error message.

            return 1;
            // Terminates the program.
        }

        inputFile.read(reinterpret_cast<char*>(&readStudent),
                       sizeof(readStudent));
        // Reads the binary record into readStudent.

        if (!inputFile)
        // Checks whether the read operation succeeded.
        {
            std::cerr << "Error: Could not read record from students.dat\n";
            // Displays an error message.

            return 1;
            // Terminates the program.
        }
    }

    std::cout << "Roll Number: " << readStudent.rollNumber << '\n';
    // Displays the roll number.

    std::cout << "Name: " << readStudent.name << '\n';
    // Displays the student's name.

    std::cout << "Marks: " << readStudent.marks << '\n';
    // Displays the student's marks.

    return 0;
    // Terminates the program successfully.
}


📄 BINARY FILE

students.dat

The file contains binary data and is not intended to be
opened as normal readable text.


▶️ SAMPLE OUTPUT

Roll Number: 101
Name: Amit Patil
Marks: 85.5
