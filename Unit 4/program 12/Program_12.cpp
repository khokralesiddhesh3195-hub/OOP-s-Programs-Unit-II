#include <cstring>  // Provides std::strncpy().
#include <fstream>  // Provides binary file streams.
#include <iostream> // Provides console input and output.

struct StudentRecord
{
    int rollNumber;
    // Stores the student's roll number.

    char name[30];
    // Stores the student's name.

    float marks;
    // Stores the student's marks.
};

void addRecord(std::ofstream& file,
               int rollNumber,
               const char* name,
               float marks)
{
    StudentRecord student{};
    // Creates an empty student record.

    student.rollNumber = rollNumber;
    // Stores the roll number.

    std::strncpy(student.name, name, sizeof(student.name) - 1);
    // Copies the student's name into the fixed-size array.

    student.marks = marks;
    // Stores the marks.

    file.write(reinterpret_cast<const char*>(&student),
               sizeof(student));
    // Writes the record into the binary file.
}

int main() // Program execution starts from the main() function.
{
    {
        std::ofstream outputFile("records.dat",
                                 std::ios::binary | std::ios::trunc);
        // Creates records.dat in binary mode.

        if (!outputFile)
        // Checks whether the file opened successfully.
        {
            std::cerr << "Error: Could not create records.dat\n";
            // Displays an error message.

            return 1;
            // Terminates the program.
        }

        addRecord(outputFile, 101, "Amit", 85.5F);
        // Writes the first student record.

        addRecord(outputFile, 102, "Neha", 91.0F);
        // Writes the second student record.

        addRecord(outputFile, 103, "Ravi", 78.0F);
        // Writes the third student record.
    }

    std::ifstream inputFile("records.dat", std::ios::binary);
    // Opens the binary file for reading.

    if (!inputFile)
    // Checks whether the file opened successfully.
    {
        std::cerr << "Error: Could not open records.dat\n";
        // Displays an error message.

        return 1;
        // Terminates the program.
    }

    int recordNumber;
    // Stores the record number selected by the user.

    std::cout << "Enter record number to read (1 to 3): ";
    // Prompts the user.

    std::cin >> recordNumber;
    // Reads the record number.

    if (recordNumber < 1 || recordNumber > 3)
    // Checks whether the record number is invalid.
    {
        std::cerr << "Invalid record number.\n";
        // Displays an error message.

        return 1;
        // Terminates the program.
    }

    const std::streamoff offset =
        static_cast<std::streamoff>(recordNumber - 1) *
        static_cast<std::streamoff>(sizeof(StudentRecord));
    // Calculates the byte position of the selected record.

    inputFile.seekg(offset, std::ios::beg);
    // Moves the input pointer directly to the selected record.

    StudentRecord selectedStudent{};
    // Creates a structure for the selected record.

    inputFile.read(reinterpret_cast<char*>(&selectedStudent),
                   sizeof(selectedStudent));
    // Reads the selected record.

    if (!inputFile)
    // Checks whether the read operation succeeded.
    {
        std::cerr << "Error: Could not read selected record.\n";
        // Displays an error message.

        return 1;
        // Terminates the program.
    }

    std::cout << "Roll Number: "
              << selectedStudent.rollNumber << '\n';
    // Displays the roll number.

    std::cout << "Name: " << selectedStudent.name << '\n';
    // Displays the student's name.

    std::cout << "Marks: " << selectedStudent.marks << '\n';
    // Displays the student's marks.

    return 0;
    // Terminates the program successfully.
}


📄 BINARY FILE CONTENT — records.dat

Record 1 → 101, Amit, 85.5
Record 2 → 102, Neha, 91.0
Record 3 → 103, Ravi, 78.0


⌨️ SAMPLE INPUT

Enter record number to read (1 to 3): 2


▶️ SAMPLE OUTPUT

Roll Number: 102
Name: Neha
Marks: 91
