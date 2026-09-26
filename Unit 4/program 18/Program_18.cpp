// Include the file stream library for file handling.
#include <fstream>

// Include the input/output stream library.
#include <iostream>

// Include the string library for string operations.
#include <string>

// Include the vector library for storing multiple log entries.
#include <vector>

// Use the standard namespace.
using namespace std;


// Define a structure to represent one log entry.
struct LogEntry
{
    // Store the complete log line.
    string line;
};


// Main function where program execution begins.
int main()
{
    // Create and open the server log file for writing.
    ofstream sampleLog("server.log");

    // Check whether the log file was created successfully.
    if (!sampleLog)
    {
        // Display an error message if file creation failed.
        cerr << "Unable to create log file." << endl;

        // Terminate the program with an error code.
        return 1;
    }

    // Write an INFO message into the log file.
    sampleLog << "2026-09-09 08:00:00 INFO Server started\n";

    // Write a WARNING message into the log file.
    sampleLog << "2026-09-09 08:10:00 WARNING High memory usage\n";

    // Write an ERROR message into the log file.
    sampleLog << "2026-09-09 08:20:00 ERROR Database connection failed\n";

    // Write another INFO message into the log file.
    sampleLog << "2026-09-09 08:30:00 INFO Backup completed\n";

    // Write a CRITICAL message into the log file.
    sampleLog << "2026-09-09 08:40:00 CRITICAL Disk space low\n";

    // Close the file after writing.
    sampleLog.close();

    // Open the server log file for reading.
    ifstream logFile("server.log");

    // Check whether the log file was opened successfully.
    if (!logFile)
    {
        // Display an error message if opening failed.
        cerr << "Unable to open server.log." << endl;

        // Terminate the program with an error code.
        return 1;
    }

    // Create a vector to store ERROR and CRITICAL entries.
    vector<LogEntry> errors;

    // Variable to store one line from the log file.
    string line;

    // Read the log file one line at a time.
    while (getline(logFile, line))
    {
        // Check whether the line contains ERROR or CRITICAL.
        if (line.find("ERROR") != string::npos ||
            line.find("CRITICAL") != string::npos)
        {
            // Add the matching line to the vector.
            errors.push_back({line});
        }
    }

    // Display the heading for critical log events.
    cout << "=== Critical Log Events ===" << endl;

    // Traverse all stored error and critical entries.
    for (const auto& entry : errors)
    {
        // Display the complete log entry.
        cout << entry.line << endl;
    }

    // Display the total number of critical events found.
    cout << "Total critical events: "
         << errors.size() << endl;

    // Return 0 to indicate successful execution.
    return 0;
}

📄 Sample File Content — server.log
  
2026-09-09 08:00:00 INFO Server started
2026-09-09 08:10:00 WARNING High memory usage
2026-09-09 08:20:00 ERROR Database connection failed
2026-09-09 08:30:00 INFO Backup completed
2026-09-09 08:40:00 CRITICAL Disk space low

🖥️ Sample Output

=== Critical Log Events ===
2026-09-09 08:20:00 ERROR Database connection failed
2026-09-09 08:40:00 CRITICAL Disk space low
Total critical events: 2
