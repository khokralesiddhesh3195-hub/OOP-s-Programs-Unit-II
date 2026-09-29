#include <iostream>  // Includes the input/output stream library.
#include <string> // Provides the std::string data type

// Function to add two integers.
int add(int first, int second) {
    return first + second;  // Returns the sum of two integers.
}

// Function to add two double values.
double add(double first, double second) {
    return first + second;  // Returns the sum of two double values.
}

// Function to add three integers.
int add(int first, int second, int third) {
    return first + second + third;  // Returns the sum of three integers.
} 

// MODIFICATION: Overloaded add() function to join two strings
std::string add(std::string first, std::string second) {
    return first + second;
}

// Main function where program execution begins.
int main() {

    // Calls add() with two integers and displays the result.
    std::cout << "Sum of two integers: " << add(10, 20) << '\n';

    // Calls add() with two double values and displays the result.
    std::cout << "Sum of two doubles: " << add(2.5, 3.7) << '\n';

    // Calls add() with three integers and displays the result.
    std::cout << "Sum of three integers: " << add(10, 20, 30) << '\n';

    // MODIFICATION: Calls add(string, string) to join two strings
    std::cout << "Joined strings: " << add("Hello ", "World!") << '\n';

    return 0;  // Indicates successful program execution.
}

🎯 Expected Output

Sum of two integers: 30
Sum of two doubles: 6.2
Sum of three integers: 60
Joined strings: Hello World!
