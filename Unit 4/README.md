📘Object-Oriented Programming with C++ – Unit IV

**🎓 Unit IV – Files and Streams**

Object-Oriented Programming with C++

---

**👨‍🎓 <b>Student Information</b>**

<b>👤 Student Name:</b> Siddhesh Goraksh Khokrale<br>
<b>🆔 ZPRN:</b> 125UAD1094<br>
<b>🏫 Class / Division:</b> S.Y. B-Tech (Div: B)<br>
<b>📚 Course Name:</b> Object-Oriented Programming with C++<br>
<b>🔢 Course Code:</b> ADPC303<br>
<b>🎓 Programme:</b> S.Y. B.Tech. Artificial Intelligence and Data Science<br>
<b>📖 Unit:</b> IV – Files and Streams<br>
<b>💻 Programming Language:</b> C++

---

***📖 About the Repository***

This repository contains C++ programs based on Unit IV – Files and Streams of the Object-Oriented Programming with C++ course.

The programs introduce file handling concepts in C++, including:

- 📝 Text File Handling
- 📖 Reading and Writing Files
- ➕ Appending Data
- 📋 File Copying
- 🔍 Searching in Files
- 📊 File Statistics
- 👨‍🎓 Student Records
- 📍 File Pointer Navigation
- 💾 Binary Files
- 🎯 Random Access
- ⚠️ File Error Handling
- 🗃️ Record Management

The repository also includes real-time application examples related to:

- 🎓 Student Record File System
- 🖥️ Server Log Analyzer
- 💾 Fixed-Size Binary Records
- 📚 Library Book Management System

---

***📚 Unit IV – Topics Covered***

- 🔹 Introduction to Files and Streams
- 🔹 Text File Handling
- 🔹 Reading from Text Files
- 🔹 Writing to Text Files
- 🔹 Appending Data to Files
- 🔹 Copying Files
- 🔹 Searching in Files
- 🔹 File Statistics
- 🔹 Student Record Management
- 🔹 File Pointer Navigation
- 🔹 Binary File Handling
- 🔹 Random Access in Binary Files
- 🔹 File Error Handling
- 🔹 Stream States
- 🔹 Temporary Files
- 🔹 Record Management
- 🔹 Sequential File Access
- 🔹 Random File Access

---

***💻 List of Programs***

*🔹 A. File Handling Concept-Based Programs*

1️⃣ Write Text to a File

📌 Concept: Text File Writing

Demonstrates writing text data into a file using C++ file streams.

The program uses:

- "ofstream" to create and write to a file
- File opening and closing operations
- Text data handling

📍 Scenario: Create a text file and store a message or information in it.

---

2️⃣ Read a File Line by Line

📌 Concept: Text File Reading

Demonstrates reading the contents of a text file line by line.

The program uses:

- "ifstream" to open a file for reading
- "getline()" to read complete lines
- File stream operations

📍 Scenario: Read and display the contents of a text file.

---

3️⃣ Append Data to a File

📌 Concept: File Appending

Demonstrates adding new data to an existing file without removing its previous contents.

The program uses:

- "ofstream"
- "ios::app"
- File opening and writing operations

📍 Scenario: Add new information to an existing text file.

---

4️⃣ Copy One Text File into Another

📌 Concept: File Copying

Demonstrates copying the contents of one text file into another file.

The program uses:

- "ifstream" for reading
- "ofstream" for writing
- Character-by-character or line-based file copying

📍 Scenario: Create a backup copy of a text file.

---

5️⃣ Count Lines, Words, and Characters

📌 Concept: File Statistics

Demonstrates processing a text file to calculate the number of lines, words, and characters.

The program calculates:

- 📄 Number of lines
- 📝 Number of words
- 🔤 Number of characters

📍 Scenario: Generate basic statistics from a text document.

---

6️⃣ Search for a Word in a File

📌 Concept: File Searching

Demonstrates searching for a specific word in a text file.

The program:

- Reads file contents
- Searches for the specified word
- Determines whether the word is present
- Displays the search result

📍 Scenario: Search for a keyword in a document.

---

7️⃣ Store Student Records in a Text File

📌 Concept: Text File Record Management

Demonstrates storing student information in a text file.

Each student record contains:

🆔 Roll Number
👤 Student Name
📊 Marks
🎓 Course Information

The program stores student records for later retrieval.

📍 Scenario: Store student information in a file-based record system.

---

8️⃣ Read and Search Student Records

📌 Concept: Reading and Searching Records

Demonstrates reading stored student records and searching for a particular student.

The program can:

- Read student records
- Display student information
- Search by roll number or name
- Display matching records

📍 Scenario: Find a student's information from stored records.

---

9️⃣ Update a Student Record Using a Temporary File

📌 Concept: File-Based Record Updating

Demonstrates updating an existing student record using a temporary file.

The program:

- Reads the original records
- Searches for the required student
- Updates the selected record
- Writes records to a temporary file
- Replaces the original file

📍 Scenario: Update student marks or other information in a file-based system.

---

🔟 File Pointer Navigation

📌 Concept: File Pointers

Demonstrates navigating through a file using file pointers.

The program demonstrates:

- "seekg()"
- "seekp()"
- "tellg()"
- "tellp()"

📍 Scenario: Move to specific positions in a file and read or write data.

---

1️⃣1️⃣ Binary File Writing and Reading

📌 Concept: Binary File Handling

Demonstrates writing and reading structured data using binary files.

The program uses:

- "ios::binary"
- Binary writing
- Binary reading
- File streams

📍 Scenario: Store records in compact binary format.

---

1️⃣2️⃣ Random Access in a Binary File

📌 Concept: Random File Access

Demonstrates accessing specific records directly from a binary file without reading all previous records.

The program uses:

- Fixed-size records
- "seekg()"
- "tellg()"
- Binary file operations

📍 Scenario: Access a specific student record directly using its record position.

---

1️⃣3️⃣ File Error Handling and Stream States

📌 Concept: File Error Handling

Demonstrates handling file-related errors and checking the state of file streams.

The program checks:

- "good()"
- "fail()"
- "bad()"
- "eof()"

📍 Scenario: Detect and handle errors while opening and reading files.

---

🌐 B. Unit IV – Mini-Projects

1️⃣4️⃣ File Statistics Mini-Project

📌 Concept: Integrated File Processing

Implements a File Statistics system for analyzing the contents of a text file.

The system calculates:

📄 Total Lines
📝 Total Words
🔤 Total Characters
🔢 Additional file statistics

The program demonstrates:

- File reading
- Text processing
- Character counting
- Word counting
- Line counting
- Statistical analysis

📍 Scenario: Analyze a text document and generate a statistical report.

---

1️⃣5️⃣ Mini-Project – Student Record Manager

📌 Concept: File-Based Record Management

Implements a Student Record Manager for storing and managing student information using files.

Each student record contains:

🆔 Roll Number
👤 Student Name
📊 Marks
🎓 Course Information

The system can:

- Add student records
- Display student records
- Search student records
- Update student records
- Manage records using files

This mini-project combines text file handling and record management concepts introduced in Unit IV.

---

1️⃣6️⃣ Mini-Project – Library Record Management

📌 Concept: File-Based Library Management

Implements a Library Record Management system for managing library records using file handling.

Each book record contains:

🆔 Book ID
📖 Book Name
✍️ Author Name
👤 Borrower Information
📌 Availability Status

The system can:

- Add book records
- Display book records
- Search for books
- Update book information
- Manage library records using files

📍 Scenario: Manage library book records using a file-based system.

---

*🌍 C. Unit IV – Real-World Applications*

1️⃣7️⃣ Student Record File System

📌 Concepts: Text Files, Records, Searching, Report Generation

Implements a file-based student record system.

The system stores student information in a text or CSV-like file.

Each record may contain:

🆔 Student ID
👤 Student Name
🏫 Course
📊 Marks
🎓 Grade

The program can:

- Store student information
- Read records from the file
- Search student records
- Process stored information
- Generate a student report

📍 Scenario: Maintain student records and generate reports using files.

---

1️⃣8️⃣ Server Log Analyzer

📌 Concepts: File Reading, Searching, String Processing, File Statistics

Implements a basic server log analyzer that processes log files.

The program reads server log entries and identifies:

ℹ️ Information messages
⚠️ Warning messages
❌ Error messages
🚨 Critical messages

The system can:

- Read server logs
- Search for specific log levels
- Count error messages
- Identify critical messages
- Generate basic log statistics

📍 Scenario: Analyze server logs to identify errors and critical events.

---

1️⃣9️⃣ Binary File for Fixed-Size Records

📌 Concepts: Binary Files, Fixed-Size Records, Sequential Access

Demonstrates storing fixed-size records in a binary file.

Each record contains structured information that occupies a fixed amount of storage.

The program demonstrates:

- Binary file creation
- Fixed-size record storage
- Binary reading
- Sequential record retrieval
- Compact data storage

📍 Scenario: Store and retrieve structured records efficiently using binary files.

---

2️⃣0️⃣ Library Book Management System

📌 Concepts: File Handling, Records, Searching, Updating, Record Management

Implements a file-based Library Book Management System.

Each book contains:

🆔 Book ID
📖 Book Title
✍️ Author
📅 Publication Information
📌 Availability Status

The system can:

- Add new books
- Display all books
- Search for books
- Issue books
- Return books
- Update book records
- Store records using files

📍 Scenario: Manage library books and their availability using a file-based system.

---

***🧠 File Handling Concepts Demonstrated***

📁 File

A file is a storage location used to permanently store data on secondary storage.

🌊 Stream

A stream represents a flow of data between a program and an input or output source.

📖 "ifstream"

Used to read data from files.

✍️ "ofstream"

Used to write data to files.

🔄 "fstream"

Used for both reading from and writing to files.

📝 Text File

Stores data in human-readable character format.

💾 Binary File

Stores data in binary form and is useful for structured and compact record storage.

➕ Append Mode

"ios::app" allows new data to be added at the end of an existing file.

📍 File Pointer

A file pointer represents the current position used for file input or output operations.

🔍 "seekg()"

Moves the input/get pointer to a specified position.

✏️ "seekp()"

Moves the output/put pointer to a specified position.

📌 "tellg()"

Returns the current position of the input/get pointer.

📌 "tellp()"

Returns the current position of the output/put pointer.

🎯 Random Access

Allows a program to directly access a specific location or record in a file.

📊 Sequential Access

Processes file contents sequentially from one record or position to the next.

⚠️ Stream States

Stream state functions are used to determine whether file operations are successful.

- "good()" – Stream is in a good state
- "fail()" – An operation has failed
- "bad()" – A serious I/O error has occurred
- "eof()" – End of file has been reached

🗃️ Record Management

Involves storing, searching, updating, and retrieving structured records using files.

---

***🛠️ Technologies Used***

💻 Language: C++
🧑‍💻 Programming Paradigm: Object-Oriented Programming
📚 Topic: Unit IV – Files and Streams
🔧 Compiler: Any Standard C++ Compiler
📦 Repository: GitHub

---

***🎯 Learning Objectives***

By completing these programs, the following concepts can be understood and practiced:

- ✅ Understand the concept of files and streams
- ✅ Create and open text files
- ✅ Read data from files
- ✅ Write data to files
- ✅ Append data to existing files
- ✅ Copy data from one file to another
- ✅ Search for information within files
- ✅ Calculate file statistics
- ✅ Store and retrieve student records
- ✅ Update records using temporary files
- ✅ Understand file pointer navigation
- ✅ Use "seekg()", "seekp()", "tellg()", and "tellp()"
- ✅ Understand binary file handling
- ✅ Implement random access in binary files
- ✅ Understand sequential and random file access
- ✅ Handle file errors using stream state functions
- ✅ Use "good()", "fail()", "bad()", and "eof()"
- ✅ Implement file-based record management
- ✅ Develop file statistics applications
- ✅ Develop student record management systems
- ✅ Develop library record management systems
- ✅ Analyze server log files
- ✅ Apply file handling concepts to real-world applications

---

***📌 Conclusion***

This repository provides a practical implementation of Unit IV – Files and Streams in C++.

The programs progress from basic text file operations such as reading, writing, appending, copying, and searching to advanced file handling concepts such as file pointer navigation, binary files, random access, error handling, and record management.

The mini-projects and real-time applications further demonstrate how file handling concepts can be applied to practical systems such as student record management, file statistics, server log analysis, and library book management.

Overall, the repository provides hands-on practice with C++ file handling and streams and demonstrates how data can be stored, processed, searched, updated, and retrieved using files.

---

***⭐ Thank You for Visiting! ⭐***

Object-Oriented Programming with C++ | Unit IV – Files and Streams

S.Y. B.Tech. Artificial Intelligence and Data Science
