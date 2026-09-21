****<div align="center">📘 Object-Oriented Programming with C++ – Unit II****

   🎓 Unit II – Inheritance
   
Object-Oriented Programming with C++

</div>---

***👨‍🎓 Student Information***

**👤 Student Name:** Siddhesh Goraksh Khokrale <br>
**🆔 ZPRN:** 125UAD1094 <br>
**🏫 Class / Division:** S.Y. B-Tech (Div: B) <br>
**📚 Course Name:** Object-Oriented Programming with C++ <br>
**🔢 Course Code:** ADPC303 <br>
**🎓 Programme:** S.Y. B.Tech. Artificial Intelligence and Data Science <br>
**📖 Unit:** II – Inheritance <br>
**💻 Programming Language:** C++

---

***📖 About the Repository***

This repository contains C++ programs based on Unit II: Inheritance of the Object-Oriented Programming with C++ course.

The programs demonstrate fundamental and practical concepts of Inheritance, including:

- 🏛️ Base and Derived Classes
- 🔐 Protected Members
- 🔗 Relationships between Base and Derived Classes
- 🏗️ Constructors and Destructors
- 🔄 Function Overriding
- 🌳 Class Hierarchies
- 🔓 Public and Private Inheritance
- 🧬 Different Types of Inheritance
- ⚠️ Multiple-Inheritance Ambiguity
- 💠 Virtual Base Classes
- 🧩 Abstract Classes
- 🤝 Friend Classes
- 📦 Nested Classes

The repository also includes real-time application examples related to:

- 💼 Employee Payroll
- 💳 Digital Payment Gateway
- 🚚 Vehicle Fleet Management
- 🏦 Banking System

---

**📚 Unit II – Topics Covered***

- 🧬 Base and Derived Classes
- 🔐 Protected Members
- 🔗 Relationship between Base and Derived Classes
- 🏗️ Constructors and Destructors in Derived Classes
- 🔄 Function Overriding
- 🌳 Class Hierarchies
- 🔓 Public and Private Inheritance
- 🧩 Types of Inheritance
- ⚠️ Multiple-Inheritance Ambiguity
- 💠 Virtual Base Classes
- 🧱 Abstract Classes
- 🤝 Friend Classes
- 📦 Nested Classes

---

***💻 List of Programs***

*🔹 A. Inheritance Practical Programs*

1️⃣ Basic Single Inheritance

📌 Concept: Base and Derived Classes

Demonstrates basic single inheritance using "Person" as the base class and "Student" as the derived class. It shows how a derived class can use accessible members of its base class.

---

2️⃣ Protected Member Access

📌 Concept: Protected Access Specifier

Demonstrates how a derived class can directly access a protected data member inherited from its base class.

---

3️⃣ Public vs Private Inheritance

📌 Concept: Inheritance Modes

Demonstrates the difference between public and private inheritance and shows how the accessibility of inherited members changes.

---

4️⃣ Multilevel Inheritance

📌 Concept: Three-Level Inheritance Hierarchy

Demonstrates multilevel inheritance using the hierarchy:

Person
   ↓
Employee
   ↓
Manager

The program shows how properties and functions are inherited through multiple levels.

---

5️⃣ Hierarchical Inheritance

📌 Concept: One Base Class with Multiple Derived Classes

Demonstrates hierarchical inheritance using "Vehicle" as the common base class and "Car" and "Bike" as derived classes.

        Vehicle
        /     \
      Car     Bike

---

6️⃣ Multiple Inheritance

📌 Concept: Two Base Classes

Demonstrates multiple inheritance where the "Student" class inherits from both "Academic" and "Sports" classes and calculates the total marks.

Academic     Sports
     \         /
      \       /
       Student

---

7️⃣ Resolving Multiple-Inheritance Ambiguity

📌 Concept: Scope-Resolution Operator

Demonstrates how ambiguity caused by two base classes having functions with the same name can be resolved using the scope-resolution operator ("::").

---

8️⃣ Constructor and Destructor Order

📌 Concept: Object Lifecycle

Demonstrates the order in which constructors and destructors are called in inheritance.

🏗️ Construction : Base → Derived
🗑️ Destruction  : Derived → Base

---

9️⃣ Parameterized Base Constructor

📌 Concept: Constructor Initializer List

Demonstrates how a derived-class constructor initializes a parameterized constructor of its base class using a constructor initializer list.

---

🔟 Function Overriding

📌 Concept: "virtual" and "override"

Demonstrates function overriding using virtual functions, where derived classes provide their own implementation of a base-class function.

---

1️⃣1️⃣ Abstract Class

📌 Concept: Pure Virtual Function

Demonstrates the use of an abstract base class containing a pure virtual function. Derived classes implement the required functionality.

virtual void calculate() = 0;

---

1️⃣2️⃣ Virtual Base Class and Diamond Inheritance

📌 Concept: Virtual Inheritance

Demonstrates how a virtual base class prevents duplicate copies of a common base class in diamond inheritance.

          A
        /   \
       B     C
        \   /
          D

Virtual inheritance ensures that class "D" contains only one shared instance of class "A".

---

1️⃣3️⃣ Friend Class

📌 Concept: Special Access Permission

Demonstrates how a friend class can access private members of another class when explicitly granted friendship.

---

1️⃣4️⃣ Nested Class

📌 Concept: Class Inside Another Class

Demonstrates the creation and use of a nested class using "University" and its nested "Department" class.

University
    └── Department

---

1️⃣5️⃣ Mini-Project – Vehicle Rental System

📌 Concept: Integrated Inheritance

Implements a Vehicle Rental System using a base "Vehicle" class and derived classes such as "Car" and "Bike".

The program:

- 🚗 Manages different vehicle types
- 💰 Calculates rental charges
- 🔄 Demonstrates function overriding
- 🧬 Uses inheritance and polymorphism

---

1️⃣6️⃣ Mini-Project – Employee Payroll System

📌 Concept: Abstract Base Class and Function Overriding

Implements an Employee Salary System using an abstract "Employee" class and derived classes for different employee types.

Salary is calculated using overridden functions, demonstrating runtime polymorphism.

---

*🌐 B. Unit II – Real-Time Applications*

The following programs are based on the Unit II section of the Unit-Wise Real-Time Applications and Live Examples material.

---

1️⃣7️⃣ Employee Payroll System

📌 Concepts: Base and Derived Classes, Protected Members, Hierarchical Inheritance, Constructor Chaining, Function Overriding, Abstract Base Class

Models different types of employees such as:

- 👨‍💼 Full-Time Employee
- 🕐 Part-Time Employee
- 🎓 Intern

All employee types share common information while implementing their own salary-calculation methods.

---

1️⃣8️⃣ Digital Payment Gateway

📌 Concepts: Abstract Class, Hierarchical Inheritance, Pure Virtual Function, Virtual Destructor, Runtime Polymorphism

Demonstrates a payment gateway supporting different payment methods through a common interface.

Supported payment methods include:

- 💳 Credit Card
- 📱 UPI
- 🏦 Net Banking

The program demonstrates how runtime polymorphism allows different payment methods to implement their own behavior.

---

1️⃣9️⃣ Vehicle Fleet Management

📌 Concepts: Base and Derived Classes, Hierarchical Inheritance, Function Overriding, Virtual Functions, Protected Data

Models a logistics fleet containing:

- 🚛 Trucks
- 🚐 Delivery Vans
- 🛵 Delivery Bikes

Common vehicle information is maintained in the base class, while each derived class provides specialized information.

---

2️⃣0️⃣ Mini-Project – Banking System with Account Hierarchy

📌 Concept: Hierarchical Inheritance and Virtual Functions

Implements a Banking System using a base "Account" class and derived classes:

                 Account
                /   |    \
               /    |     \
       Savings   Current   Fixed Deposit
       Account   Account      Account

The program includes:

- 🆔 Account Number
- 👤 Account Holder Name
- 💰 Balance
- ➕ Deposit Operation
- ➖ Withdrawal Operation
- 📈 Interest Calculation

Virtual functions are used to provide account-specific behavior for different types of bank accounts.

---

***🧠 OOP Concepts Demonstrated***

- 🧬 Inheritance – Reusing properties and behaviors of an existing class.
- 🔐 Encapsulation – Binding data and functions together within classes.
- 🎭 Abstraction – Hiding implementation details and exposing essential functionality.
- 🔄 Polymorphism – Allowing the same interface to perform different behaviors.
- 🛠️ Function Overriding – Redefining a base-class function in a derived class.
- ⚡ Virtual Functions – Supporting runtime polymorphism.
- 🎯 Pure Virtual Functions – Defining interfaces for abstract classes.
- 🏗️ Constructor Chaining – Calling base-class constructors during derived-object creation.
- 💠 Virtual Inheritance – Avoiding duplicate base-class instances in diamond inheritance.
- 🤝 Friend Class – Providing special access to private members of another class.
- 📦 Nested Class – Defining a class within another class.

---

***🛠️ Technologies Used***

- 💻 Language: C++
- 🧑‍💻 Programming Paradigm: Object-Oriented Programming
- 📚 Topic: Unit II – Inheritance
- 🔧 Compiler: Any standard C++ compiler
- 📦 Repository: GitHub

---

***🎯 Learning Objectives***

By completing these programs, the following concepts can be understood and practiced:

- ✅ Understand different types of inheritance in C++
- ✅ Implement relationships between base and derived classes
- ✅ Understand access control using "public", "private", and "protected"
- ✅ Understand constructor and destructor execution order
- ✅ Implement function overriding
- ✅ Resolve ambiguity in multiple inheritance
- ✅ Understand virtual inheritance
- ✅ Implement abstract classes and pure virtual functions
- ✅ Apply runtime polymorphism
- ✅ Understand friend and nested classes
- ✅ Develop inheritance-based real-world applications

---

***📌 Conclusion***

This repository provides a practical implementation of Unit II – Inheritance in Object-Oriented Programming with C++.

The programs progress from basic inheritance concepts to real-time applications and mini-projects, providing hands-on practice with inheritance, abstraction, polymorphism, function overriding, virtual functions, and class hierarchies.

---

<div align="center">⭐ Thank You for Visiting! ⭐

Object-Oriented Programming with C++ | Unit II – Inheritance

S.Y. B.Tech. Artificial Intelligence and Data Science

</div>
