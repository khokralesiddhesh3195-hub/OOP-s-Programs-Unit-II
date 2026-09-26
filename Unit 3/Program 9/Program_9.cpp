#include <iostream>  // Includes the input/output library.

class Animal {  // Defines the base class.
public:
    virtual void sound() const {
        // Declares sound() as a virtual function.

        std::cout << "Animal makes a sound\n";
        // Displays the base-class message.
    }

    virtual ~Animal() = default;
    // Provides a virtual destructor for safe polymorphic use.
};

class Dog : public Animal {  // Defines the Dog class.
public:
    void sound() const override {
        // Overrides the virtual sound() function.

        std::cout << "Dog barks\n";
        // Displays the Dog's sound.
    }
};

class Cat : public Animal {  // Defines the Cat class.
public:
    void sound() const override {
        // Overrides the virtual sound() function.

        std::cout << "Cat meows\n";
        // Displays the Cat's sound.
    }
};

int main() {
    // Program execution begins here.

    Dog dog;
    // Creates a Dog object.

    Cat cat;
    // Creates a Cat object.

    Animal* animal = &dog;
    // Base pointer points to the Dog object.

    animal->sound();
    // Calls Dog::sound() through virtual dispatch.

    animal = &cat;
    // Base pointer now points to the Cat object.

    animal->sound();
    // Calls Cat::sound() through virtual dispatch.

    return 0;
    // Indicates successful execution.
}

🎯 Expected Output

Dog barks
Cat meows
