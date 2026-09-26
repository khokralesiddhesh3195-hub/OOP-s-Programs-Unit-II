// Include the file stream library for file handling.
#include <fstream>

// Include the input/output stream library.
#include <iostream>

// Include the string stream library for parsing file records.
#include <sstream>

// Include the string library.
#include <string>

// Include the vector library for storing books in memory.
#include <vector>

// Use the standard namespace.
using namespace std;


// Define a class named Book to represent a library book.
class Book
{
private:

    // Store the ISBN of the book.
    string isbn;

    // Store the title of the book.
    string title;

    // Store the author's name.
    string author;

    // Store the category of the book.
    string category;

    // Store whether the book is available.
    bool available;

public:

    // Default constructor.
    Book() : available(true)
    {
    }

    // Parameterized constructor.
    Book(string i, string t, string a, string c, bool av)
        : isbn(i), title(t), author(a), category(c), available(av)
    {
    }

    // Return the ISBN of the book.
    string getISBN() const
    {
        return isbn;
    }

    // Return the availability status.
    bool isAvailable() const
    {
        return available;
    }

    // Set the availability status.
    void setAvailability(bool status)
    {
        available = status;
    }

    // Display all details of the book.
    void display() const
    {
        cout << "ISBN       : " << isbn << endl;
        cout << "Title      : " << title << endl;
        cout << "Author     : " << author << endl;
        cout << "Category   : " << category << endl;

        // Display the appropriate availability message.
        cout << "Availability: "
             << (available ? "Available" : "Issued")
             << endl;

        // Display a separator line.
        cout << "----------------------------------------" << endl;
    }

    // Convert book information into one file line.
    string toFileString() const
    {
        // Create a string stream.
        ostringstream output;

        // Store all fields separated by the pipe symbol.
        output << isbn << '|'
               << title << '|'
               << author << '|'
               << category << '|'
               << available;

        // Return the generated string.
        return output.str();
    }

    // Create a Book object from one file line.
    static bool fromFileString(const string& line, Book& book)
    {
        // Create a string stream using the file line.
        stringstream input(line);

        // Temporary variables for each field.
        string isbnValue;
        string titleValue;
        string authorValue;
        string categoryValue;
        string availableValue;

        // Read ISBN.
        if (!getline(input, isbnValue, '|'))
            return false;

        // Read title.
        if (!getline(input, titleValue, '|'))
            return false;

        // Read author.
        if (!getline(input, authorValue, '|'))
            return false;

        // Read category.
        if (!getline(input, categoryValue, '|'))
            return false;

        // Read availability.
        if (!getline(input, availableValue))
            return false;

        // Convert text availability into Boolean value.
        bool status = (availableValue == "1");

        // Create the book using the extracted information.
        book = Book(
            isbnValue,
            titleValue,
            authorValue,
            categoryValue,
            status
        );

        // Return true after successful parsing.
        return true;
    }
};


// Function to load all books from the file.
vector<Book> loadBooks()
{
    // Create an empty vector of books.
    vector<Book> books;

    // Open the library file for reading.
    ifstream file("library.txt");

    // Check whether the file opened successfully.
    if (!file)
    {
        // Return an empty collection if the file does not exist.
        return books;
    }

    // Variable to store one line from the file.
    string line;

    // Read the file line by line.
    while (getline(file, line))
    {
        // Ignore empty lines.
        if (line.empty())
            continue;

        // Create an empty Book object.
        Book book;

        // Convert the line into a Book object.
        if (Book::fromFileString(line, book))
        {
            // Add the valid book to the vector.
            books.push_back(book);
        }
    }

    // Close the file.
    file.close();

    // Return all loaded books.
    return books;
}


// Function to save all books to the file.
void saveBooks(const vector<Book>& books)
{
    // Open the library file for writing.
    ofstream file("library.txt");

    // Check whether the file opened successfully.
    if (!file)
    {
        // Display an error message.
        cerr << "Unable to open library.txt for writing." << endl;

        // Stop the function.
        return;
    }

    // Traverse every book.
    for (const Book& book : books)
    {
        // Write the book as one line.
        file << book.toFileString() << '\n';
    }

    // Close the file.
    file.close();
}


// Function to add a new book.
void addBook()
{
    // Load existing books.
    vector<Book> books = loadBooks();

    // Variables for the new book.
    string isbn;
    string title;
    string author;
    string category;

    // Ask the user for ISBN.
    cout << "Enter ISBN: ";
    cin >> isbn;

    // Check whether ISBN already exists.
    for (const Book& book : books)
    {
        if (book.getISBN() == isbn)
        {
            // Display duplicate warning.
            cout << "A book with this ISBN already exists." << endl;

            // Stop the function.
            return;
        }
    }

    // Clear the input buffer.
    cin.ignore();

    // Ask for book title.
    cout << "Enter title: ";
    getline(cin, title);

    // Ask for author name.
    cout << "Enter author: ";
    getline(cin, author);

    // Ask for category.
    cout << "Enter category: ";
    getline(cin, category);

    // Create the new book as available.
    books.emplace_back(isbn, title, author, category, true);

    // Save updated records.
    saveBooks(books);

    // Display success message.
    cout << "Book added successfully." << endl;
}


// Function to search for a book.
void searchBook()
{
    // Load all books.
    vector<Book> books = loadBooks();

    // Variable for ISBN search.
    string isbn;

    // Ask the user for ISBN.
    cout << "Enter ISBN to search: ";
    cin >> isbn;

    // Search through all books.
    for (const Book& book : books)
    {
        // Compare the current ISBN with entered ISBN.
        if (book.getISBN() == isbn)
        {
            // Display the matching book.
            book.display();

            // Stop searching.
            return;
        }
    }

    // Display message when book is not found.
    cout << "Book not found." << endl;
}


// Function to issue a book.
void issueBook()
{
    // Load all books.
    vector<Book> books = loadBooks();

    // Variable for ISBN.
    string isbn;

    // Ask for ISBN.
    cout << "Enter ISBN to issue: ";
    cin >> isbn;

    // Search for the book.
    for (Book& book : books)
    {
        // Check whether ISBN matches.
        if (book.getISBN() == isbn)
        {
            // Check whether the book is available.
            if (!book.isAvailable())
            {
                // Inform the user that the book is already issued.
                cout << "Book is already issued." << endl;
                return;
            }

            // Mark the book as issued.
            book.setAvailability(false);

            // Save the updated records.
            saveBooks(books);

            // Display success message.
            cout << "Book issued successfully." << endl;

            // Stop the function.
            return;
        }
    }

    // Display message when book is not found.
    cout << "Book not found." << endl;
}


// Function to return a book.
void returnBook()
{
    // Load all books.
    vector<Book> books = loadBooks();

    // Variable for ISBN.
    string isbn;

    // Ask for ISBN.
    cout << "Enter ISBN to return: ";
    cin >> isbn;

    // Search for the book.
    for (Book& book : books)
    {
        // Check whether ISBN matches.
        if (book.getISBN() == isbn)
        {
            // Check whether the book is already available.
            if (book.isAvailable())
            {
                // Inform the user.
                cout << "Book is already available." << endl;
                return;
            }

            // Mark the book as available.
            book.setAvailability(true);

            // Save the updated records.
            saveBooks(books);

            // Display success message.
            cout << "Book returned successfully." << endl;

            // Stop the function.
            return;
        }
    }

    // Display message when book is not found.
    cout << "Book not found." << endl;
}


// Function to update a book's details.
void updateBook()
{
    // Load all books.
    vector<Book> books = loadBooks();

    // Variable for ISBN.
    string isbn;

    // Ask for ISBN.
    cout << "Enter ISBN to update: ";
    cin >> isbn;

    // Search for the book.
    for (Book& book : books)
    {
        // Check whether ISBN matches.
        if (book.getISBN() == isbn)
        {
            // This simple implementation asks the user to replace
            // the complete book record except the ISBN and status.

            // Temporary variables for updated information.
            string title;
            string author;
            string category;

            // Clear input buffer.
            cin.ignore();

            // Ask for updated title.
            cout << "Enter new title: ";
            getline(cin, title);

            // Ask for updated author.
            cout << "Enter new author: ";
            getline(cin, author);

            // Ask for updated category.
            cout << "Enter new category: ";
            getline(cin, category);

            // Store current availability.
            bool currentStatus = book.isAvailable();

            // Replace the book object with updated information.
            book = Book(
                isbn,
                title,
                author,
                category,
                currentStatus
            );

            // Save the modified records.
            saveBooks(books);

            // Display success message.
            cout << "Book updated successfully." << endl;

            // Stop the function.
            return;
        }
    }

    // Display message when book is not found.
    cout << "Book not found." << endl;
}


// Function to generate an availability report.
void availabilityReport()
{
    // Load all books.
    vector<Book> books = loadBooks();

    // Display report heading.
    cout << "\n========== LIBRARY AVAILABILITY REPORT ==========\n";

    // Display all books.
    for (const Book& book : books)
    {
        // Display each book's details.
        book.display();
    }

    // Display total number of books.
    cout << "Total Books: " << books.size() << endl;
}


// Main function.
int main()
{
    // Variable for storing the user's menu choice.
    int choice;

    // Continue the program until the user chooses Exit.
    do
    {
        // Display the menu.
        cout << "\n========== LIBRARY BOOK MANAGEMENT ==========\n";
        cout << "1. Add Book\n";
        cout << "2. Search Book\n";
        cout << "3. Issue Book\n";
        cout << "4. Return Book\n";
        cout << "5. Update Book\n";
        cout << "6. Availability Report\n";
        cout << "0. Exit\n";

        // Ask the user to enter a choice.
        cout << "Enter your choice: ";
        cin >> choice;

        // Execute the selected operation.
        switch (choice)
        {
        case 1:
            // Add a new book.
            addBook();
            break;

        case 2:
            // Search for a book.
            searchBook();
            break;

        case 3:
            // Issue a book.
            issueBook();
            break;

        case 4:
            // Return a book.
            returnBook();
            break;

        case 5:
            // Update book information.
            updateBook();
            break;

        case 6:
            // Generate availability report.
            availabilityReport();
            break;

        case 0:
            // Display exit message.
            cout << "Exiting Library Management System..." << endl;
            break;

        default:
            // Handle an invalid menu choice.
            cout << "Invalid choice. Please try again." << endl;
        }

    // Repeat until the user selects 0.
    } while (choice != 0);

    // Return 0 for successful execution.
    return 0;
}


📄 Sample File Content — library.txt
The program stores each book as:
ISBN|Title|Author|Category|Availability
  
Example:
9780135166307|C++ Primer|Stanley Lippman|Programming|1
9780132350884|Clean Code|Robert Martin|Programming|0
9781491904244|Fluent Python|Luciano Ramalho|Programming|1
  
Here:
1 = 📗 Available
0 = 📕 Issued
  
  
🖥️ Sample Output

========== LIBRARY BOOK MANAGEMENT ==========
1. Add Book
2. Search Book
3. Issue Book
4. Return Book
5. Update Book
6. Availability Report
0. Exit
Enter your choice: 6

========== LIBRARY AVAILABILITY REPORT ==========
ISBN       : 9780135166307
Title      : C++ Primer
Author     : Stanley Lippman
Category   : Programming
Availability: Available
----------------------------------------
ISBN       : 9780132350884
Title      : Clean Code
Author     : Robert Martin
Category   : Programming
Availability: Issued
----------------------------------------
ISBN       : 9781491904244
Title      : Fluent Python
Author     : Luciano Ramalho
Category   : Programming
Availability: Available
----------------------------------------
Total Books: 3
