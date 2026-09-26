#include <iostream>  // Includes the input/output library.

class Distance {  // Defines the Distance class.
private:
    int meters;  // Stores distance in meters.

public:
    explicit Distance(int value) : meters(value) {}
    // Constructor initializes the distance.

    bool operator>(const Distance& other) const {
        // Overloads the greater-than operator.

        return meters > other.meters;
        // Compares the meter values.
    }

    void display() const {
        // Displays the distance.

        std::cout << meters << " meters\n";
        // Prints the distance.
    }
};

int main() {
    // Program execution begins here.

    Distance first(120);
    // Creates the first distance.

    Distance second(90);
    // Creates the second distance.

    std::cout << "First distance: ";
    // Displays a message.

    first.display();
    // Displays the first distance.

    std::cout << "Second distance: ";
    // Displays a message.

    second.display();
    // Displays the second distance.

    if (first > second) {
        // Calls the overloaded > operator.

        std::cout << "First distance is greater\n";
        // Displays the result.
    } else {
        std::cout << "Second distance is greater or equal\n";
        // Displays the alternative result.
    }

    return 0;
    // Indicates successful execution.
}

🎯 Expected Output

First distance: 120 meters
Second distance: 90 meters
First distance is greater
