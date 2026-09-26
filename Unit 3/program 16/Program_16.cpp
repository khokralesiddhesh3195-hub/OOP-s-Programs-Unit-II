#include <iostream>  // Includes the input/output library.
#include <string>    // Provides string support.
#include <utility>   // Provides std::move.

class Employee {  // Defines the abstract Employee class.

protected:
    int employeeId;  // Stores the employee ID.
    std::string name;  // Stores the employee name.

public:
    Employee(int id, std::string employeeName)
        : employeeId(id), name(std::move(employeeName)) {}
    // Constructor initializes employee details.

    virtual double calculateSalary() const = 0;
    // Declares calculateSalary() as a pure virtual function.

    void displayBasicDetails() const {
        // Displays basic employee information.

        std::cout << "Employee ID: " << employeeId << '\n';
        // Displays the employee ID.

        std::cout << "Name: " << name << '\n';
        // Displays the employee name.
    }

    virtual ~Employee() = default;
    // Defines a virtual destructor.
};

class PermanentEmployee : public Employee {
    // Defines the PermanentEmployee class.

private:
    double basicSalary;  // Stores the basic salary.
    double allowance;    // Stores the allowance.

public:
    PermanentEmployee(
        int id,
        std::string employeeName,
        double basic,
        double extra
    )
        : Employee(id, std::move(employeeName)),
          basicSalary(basic),
          allowance(extra) {}
    // Constructor initializes permanent employee details.

    double calculateSalary() const override {
        // Implements salary calculation.

        return basicSalary + allowance;
        // Returns basic salary plus allowance.
    }
};

class ContractEmployee : public Employee {
    // Defines the ContractEmployee class.

private:
    double hourlyRate;  // Stores the hourly payment rate.
    int hoursWorked;    // Stores the number of hours worked.

public:
    ContractEmployee(
        int id,
        std::string employeeName,
        double rate,
        int hours
    )
        : Employee(id, std::move(employeeName)),
          hourlyRate(rate),
          hoursWorked(hours) {}
    // Constructor initializes contract employee details.

    double calculateSalary() const override {
        // Implements salary calculation.

        return hourlyRate * hoursWorked;
        // Returns hourly rate multiplied by hours worked.
    }
};

void printPaySlip(const Employee& employee) {
    // Accepts any Employee-derived object by reference.

    employee.displayBasicDetails();
    // Displays the employee's basic details.

    std::cout << "Salary: Rs. "
              << employee.calculateSalary()
              << "\n\n";
    // Calls the appropriate salary calculation at run time.
}

int main() {
    // Program execution begins here.

    PermanentEmployee permanentEmployee(
        101, "Asha", 40000.0, 8000.0
    );
    // Creates a permanent employee.

    ContractEmployee contractEmployee(
        102, "Vikas", 500.0, 80
    );
    // Creates a contract employee.

    printPaySlip(permanentEmployee);
    // Displays the permanent employee's salary details.

    printPaySlip(contractEmployee);
    // Displays the contract employee's salary details.

    return 0;
    // Indicates successful execution.
}

🎯 Expected Output

Employee ID: 101
Name: Asha
Salary: Rs. 48000

Employee ID: 102
Name: Vikas
Salary: Rs. 40000
