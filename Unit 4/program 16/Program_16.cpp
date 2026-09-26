#include <fstream>  // Provides file input and output streams.
#include <iostream> // Provides console input and output.
#include <limits>   // Provides numeric_limits.
#include <sstream>  // Provides string stream parsing.
#include <string>   // Provides the std::string class.
#include <utility>  // Provides std::move().

class Book
{
private:
    int bookId;
    // Stores the unique book ID.

    std::string title;
    // Stores the book title.

    std::string author;
    // Stores the author's name.

    bool issued;
    // Stores whether the book is issued.

public:
    Book(int id,
         std::string bookTitle,
         std::string bookAuthor,
         bool issueStatus = false)
        : bookId(id),
          title(std::move(bookTitle)),
          author(std::move(bookAuthor)),
          issued(issueStatus)
    {
    }
    // Constructor initializes the Book object.

    int getBookId() const
    {
        return bookId;
        // Returns the book ID.
    }

    std::string toFileRecord() const
    {
        return std::to_string(bookId) + "|" +
               title + "|" +
               author + "|" +
               (issued ? "1" : "0");
        // Converts the Book object into a delimiter-separated record.
    }

    void display() const
    {
        std::cout << "Book ID: " << bookId << '\n';
        // Displays the book ID.

        std::cout << "Title: " << title << '\n';
        // Displays the book title.

        std::cout << "Author: " << author << '\n';
        // Displays the author.

        std::cout << "Status: "
                  << (issued ? "Issued" : "Available")
                  << '\n';
        // Displays the current book status.
    }
};

void addBook()
{
    int id;
    // Stores the book ID.

    std::string title;
    // Stores the book title.

    std::string author;
    // Stores the author's name.

    std::cout << "Enter book ID: ";
    // Prompts for the book ID.

    std::cin >> id;
    // Reads the book ID.

    std::cin.ignore(
        std::numeric_limits<std::streamsize>::max(), '\n');
    // Clears the input buffer.

    std::cout << "Enter title: ";
    // Prompts for the title.

    std::getline(std::cin, title);
    // Reads the complete title.

    std::cout << "Enter author: ";
    // Prompts for the author.

    std::getline(std::cin, author);
    // Reads the complete author name.

    Book book(id, title, author);
    // Creates a Book object.

    std::ofstream outputFile("library_books.txt", std::ios::app);
    // Opens the library file in append mode.

    if (!outputFile)
    // Checks whether the file opened successfully.
    {
        std::cerr << "Error: Could not open library_books.txt\n";
        // Displays an error message.

        return;
        // Returns to the menu.
    }

    outputFile << book.toFileRecord() << '\n';
    // Saves the book record into the file.

    std::cout << "Book added successfully.\n";
    // Displays a success message.
}

void displayBooks()
{
    std::ifstream inputFile("library_books.txt");
    // Opens the library file for reading.

    if (!inputFile)
    // Checks whether the library file exists.
    {
        std::cout << "No library record file found.\n";
        // Displays a message if no file exists.

        return;
        // Returns to the menu.
    }

    std::string line;
    // Stores one book record.

    while (std::getline(inputFile, line))
    // Reads every book record.
    {
        std::stringstream record(line);
        // Creates a parser for the record.

        std::string idText;
        // Stores the book ID as text.

        std::string title;
        // Stores the title.

        std::string author;
        // Stores the author.

        std::string issuedText;
        // Stores the issued status.

        if (std::getline(record, idText, '|') &&
            std::getline(record, title, '|') &&
            std::getline(record, author, '|') &&
            std::getline(record, issuedText))
        // Extracts all four fields.
        {
            Book book(std::stoi(idText),
                      title,
                      author,
                      issuedText == "1");
            // Reconstructs a Book object from the stored record.

            book.display();
            // Displays the book information.

            std::cout << "-------------------------\n";
            // Separates individual book records.
        }
    }
}

int main() // Program execution starts from the main() function.
{
    int choice;
    // Stores the menu choice.

    do
    {
        std::cout << "\nLibrary Record System\n";
        // Displays the menu heading.

        std::cout << "1. Add Book\n";
        // Displays the add-book option.

        std::cout << "2. Display Books\n";
        // Displays the display-books option.

        std::cout << "0. Exit\n";
        // Displays the exit option.

        std::cout << "Enter choice: ";
        // Prompts for the user's choice.

        std::cin >> choice;
        // Reads the menu choice.

        switch (choice)
        {
            case 1:
                addBook();
                // Calls the function to add a book.
                break;

            case 2:
                displayBooks();
                // Calls the function to display books.
                break;

            case 0:
                std::cout << "Exiting program.\n";
                // Displays the exit message.
                break;

            default:
                std::cout << "Invalid choice.\n";
                // Handles an invalid choice.
        }

    } while (choice != 0);
    // Repeats the menu until the user selects 0.

    return 0;
    // Terminates the program successfully.
}


📄 FILE FORMAT — library_books.txt

bookId|title|author|issuedStatus


⌨️ SAMPLE INTERACTION

Library Record System
1. Add Book
2. Display Books
0. Exit
Enter choice: 1

Enter book ID: 101
Enter title: C++ Programming
Enter author: Bjarne Stroustrup


▶️ SAMPLE OUTPUT

Book added successfully.


📄 SAMPLE FILE CONTENT — library_books.txt

101|C++ Programming|Bjarne Stroustrup|0


⌨️ SAMPLE INTERACTION FOR DISPLAY

Library Record System
1. Add Book
2. Display Books
0. Exit
Enter choice: 2


▶️ SAMPLE OUTPUT

Book ID: 101
Title: C++ Programming
Author: Bjarne Stroustrup
Status: Available
