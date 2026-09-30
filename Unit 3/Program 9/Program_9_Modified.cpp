#include <iostream>  // Includes the input/output stream library

using namespace std;  // Allows us to use cout without std:: prefix


// Base class
class Animal
{
public:

    // Virtual function allows run-time polymorphism
    virtual void sound() const
    {
        cout << "Animal makes a sound" << endl;
    }

    // Virtual destructor for safe deletion through base pointer
    virtual ~Animal() = default;
};


// Derived class: Dog
class Dog : public Animal
{
public:

    // Overrides the sound() function of Animal
    void sound() const override
    {
        cout << "Dog barks" << endl;
    }
};


// Derived class: Cat
class Cat : public Animal
{
public:

    // Overrides the sound() function of Animal
    void sound() const override
    {
        cout << "Cat meows" << endl;
    }
};


// 🆕 MODIFICATION: Added Cow class
class Cow : public Animal
{
public:

    // 🆕 MODIFICATION: Overrides sound() for Cow
    void sound() const override
    {
        cout << "Cow moos" << endl;
    }
};


int main()
{
    // Creates a Dog object
    Dog dog;

    // Creates a Cat object
    Cat cat;

    // 🆕 MODIFICATION: Creates a Cow object
    Cow cow;

    // Base class pointer points to Dog object
    Animal* animal = &dog;

    // Calls Dog's sound() because sound() is virtual
    animal->sound();

    // Base pointer now points to Cat object
    animal = &cat;

    // Calls Cat's sound()
    animal->sound();

    // 🆕 MODIFICATION: Base pointer now points to Cow object
    animal = &cow;

    // 🆕 MODIFICATION: Calls Cow's overridden sound()
    animal->sound();

    // Indicates successful program termination
    return 0;
}
