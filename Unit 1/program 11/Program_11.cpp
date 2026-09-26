#include <iostream>                  // Includes the iostream library for input and output operations
#include <string>                    // Includes the string library for using string data type

using namespace std;                 // Allows the use of standard C++ objects without std::

class Product {                      // Defines a class named Product

private:                             // Declares private data members of the class

    int productId;                   // Stores the unique ID of the product
    string productName;              // Stores the name of the product
    double price;                    // Stores the price of the product
    int stockQuantity;               // Stores the available quantity of the product
    static int totalProducts;        // Static variable shared by all Product objects

public:                              // Makes the following members publicly accessible

    Product(int id, string name, double p, int stock)
        : productId(id), productName(name), price(p), stockQuantity(stock) {
                                      // Constructor initializes all product data members

        totalProducts++;             // Increases the total product count when an object is created
    }

    inline int getId() const {       // Inline function to return the product ID
        return productId;            // Returns the product ID
    }

    inline string getName() const {  // Inline function to return the product name
        return productName;          // Returns the product name
    }

    inline double getPrice() const { // Inline function to return the product price
        return price;                // Returns the product price
    }

    void updateStock(int quantity) { // Defines a function to update the stock quantity
        stockQuantity = quantity;    // Assigns the new quantity to stockQuantity
    }

    static int getTotalProducts() {  // Defines a static function to access total product count
        return totalProducts;        // Returns the total number of Product objects
    }

    void display() const {           // Defines a function to display product information

        cout << "ID: " << productId
             << "\n | Product: " << productName
             << "\n | Price: Rs. " << price
             << "\n | Stock: " << stockQuantity << endl;
                                      // Displays product ID, name, price, and stock quantity
    }

    ~Product() {                     // Defines the destructor of the Product class

        totalProducts--;             // Decreases the total product count when an object is destroyed
    }
};                                  // Ends the Product class definition

int Product::totalProducts = 0;     // Defines and initializes the static variable totalProducts to 0

int main() {                         // Main function where program execution begins

    Product p1(1001, "Laptop", 55000, 15);
                                      // Creates the first Product object with ID, name, price, and stock

    Product p2(1002, "Mouse", 450, 50);
                                      // Creates the second Product object

    Product p3(1003, "Keyboard", 1200, 30);
                                      // Creates the third Product object

    cout << "=== Product Catalog ===" << endl;
                                      // Displays the heading of the product catalog

    p1.display();                     // Displays details of the first product

    p2.display();                     // Displays details of the second product

    p3.display();                     // Displays details of the third product

    cout << "\nTotal Products in Catalog: "
         << Product::getTotalProducts() << endl;
                                      // Displays the total number of Product objects

    return 0;                         // Returns 0 to indicate successful program execution
}
