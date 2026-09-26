// Include the file stream library for file input and output.
#include <fstream>

// Include the input/output stream library.
#include <iostream>

// Include the string stream library for parsing strings.
#include <sstream>

// Include the string library for using string data type.
#include <string>

// Use the standard namespace to avoid writing std:: repeatedly.
using namespace std;


// Define a class named Student to represent a student record.
class Student
{
private:

    // Store the student's roll number.
    int rollNo;

    // Store the student's name.
    string name;

    // Store the student's marks.
    double marks;

public:

    // Default constructor initializes roll number and marks.
    Student() : rollNo(0), marks(0.0)
    {
    }

    // Parameterized constructor initializes all student details.
    Student(int r, string n, double m)
        : rollNo(r), name(n), marks(m)
    {
    }

    // Function to save student details into a file.
    void saveToFile(ofstream& out) const
    {
        // Write roll number, name, and marks separated by commas.
        out << rollNo << ',' << name << ',' << marks << '\n';
    }

    // Function to load student details from one line of the file.
    bool loadFromLine(const string& line)
    {
        // Variable to temporarily store roll number as text.
        string rollText;

        // Variable to temporarily store marks as text.
        string marksText;

        // Create a string stream using the input line.
        stringstream stream(line);

        // Read roll number until the first comma.
        if (!getline(stream, rollText, ','))
            return false;

        // Read student name until the second comma.
        if (!getline(stream, name, ','))
            return false;

        // Read marks from the remaining part of the line.
        if (!getline(stream, marksText))
            return false;

        // Convert roll number from string to integer.
        rollNo = stoi(rollText);

        // Convert marks from string to double.
        marks = stod(marksText);

        // Return true when the record is successfully loaded.
        return true;
    }

    // Function to display student details.
    void display() const
    {
        // Display roll number, name, and marks.
        cout << "Roll: " << rollNo
             << " | Name: " << name
             << " | Marks: " << marks << endl;
    }
};


// Main function where program execution begins.
int main()
{
    // Open students.csv for writing.
    ofstream outFile("students.csv");

    // Check whether the file was opened successfully.
    if (!outFile)
    {
        // Display an error message if opening failed.
        cerr << "Unable to open students.csv for writing." << endl;

        // Terminate the program with an error code.
        return 1;
    }

    // Create the first student object.
    Student s1(101, "Rahul Patil", 85.5);

    // Create the second student object.
    Student s2(102, "Priya Sharma", 92.0);

    // Create the third student object.
    Student s3(103, "Amit Kulkarni", 78.5);

    // Save the first student's data into the file.
    s1.saveToFile(outFile);

    // Save the second student's data into the file.
    s2.saveToFile(outFile);

    // Save the third student's data into the file.
    s3.saveToFile(outFile);

    // Close the output file.
    outFile.close();

    // Open students.csv for reading.
    ifstream inFile("students.csv");

    // Check whether the file was opened successfully.
    if (!inFile)
    {
        // Display an error message if opening failed.
        cerr << "Unable to open students.csv for reading." << endl;

        // Terminate the program with an error code.
        return 1;
    }

    // Display the heading of the student report.
    cout << "=== Student Report ===" << endl;

    // Variable to store one line from the file.
    string line;

    // Read the file one line at a time.
    while (getline(inFile, line))
    {
        // Create an empty Student object.
        Student student;

        // Load the current line into the Student object.
        if (student.loadFromLine(line))
        {
            // Display the successfully loaded student record.
            student.display();
        }
    }

    // Return 0 to indicate successful execution.
    return 0;
}

📄 Sample File Content — students.csv
  
101,Rahul Patil,85.5
102,Priya Sharma,92
103,Amit Kulkarni,78.5
  
🖥️ Sample Output
  
=== Student Report ===
Roll: 101 | Name: Rahul Patil | Marks: 85.5
Roll: 102 | Name: Priya Sharma | Marks: 92
Roll: 103 | Name: Amit Kulkarni | Marks: 78.5
