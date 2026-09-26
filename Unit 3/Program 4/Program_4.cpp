#include <iostream>  // Includes the input/output library.

class Counter {  // Defines the Counter class.
private:
    int value;  // Stores the counter value.

public:
    explicit Counter(int initialValue = 0) : value(initialValue) {}
    // Constructor initializes the counter.

    Counter& operator++() {
        // Overloads the prefix increment operator.

        ++value;
        // Increments the value first.

        return *this;
        // Returns the updated object.
    }

    Counter operator++(int) {
        // Overloads the postfix increment operator.
        // The dummy int distinguishes postfix from prefix.

        Counter old = *this;
        // Saves the current value.

        ++value;
        // Increments the current object.

        return old;
        // Returns the old value.
    }

    void display() const {
        // Displays the counter value.

        std::cout << value << '\n';
        // Prints the value.
    }
};

int main() {
    // Program execution begins here.

    Counter counter(5);
    // Creates a Counter object with value 5.

    std::cout << "After prefix increment: ";
    // Displays a message.

    ++counter;
    // Performs prefix increment.

    counter.display();
    // Displays the updated value.

    std::cout << "Value returned by postfix increment: ";
    // Displays a message.

    Counter oldValue = counter++;
    // Performs postfix increment and stores the old value.

    oldValue.display();
    // Displays the old value.

    std::cout << "Counter after postfix increment: ";
    // Displays a message.

    counter.display();
    // Displays the final counter value.

    return 0;
    // Indicates successful execution.
}

🎯 Expected Output

After prefix increment: 6
Value returned by postfix increment: 6
Counter after postfix increment: 7
