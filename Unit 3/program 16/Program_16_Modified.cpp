#include <iostream>              // Provides input/output operations.
#include <string>                // Provides the string data type.
#include <utility>               // Provides std::move().
#include <vector>                // MODIFICATION: Used to store multiple employees.
#include <memory>                // MODIFICATION: Provides unique_ptr and make_unique.

using namespace std;             // Allows us to use standard library names directly.


// ============================================================
// ABSTRACT BASE CLASS: Employee
// ============================================================

class Employee
{
protected:
    int employeeId;              // Stores the employee ID.
    string name;                  // Stores the employee name.

public:

    // Constructor to initialize employee details.
    Employee(int id, string employeeName)
        : employeeId(id), name(move(employeeName))
    {
    }

    // Pure virtual function.
    // It makes Employee an abstract class.
    virtual double calculateSalary() const = 0;

    // Displays the basic employee information.
    void displayBasicDetails() const
    {
        cout << "Employee ID: " << employeeId << '\n';
        cout << "Name: " << name << '\n';
    }

    // Virtual destructor.
    // MODIFICATION: Ensures proper destruction through a base-class pointer.
    virtual ~Employee() = default;
};


// ============================================================
// PERMANENT EMPLOYEE CLASS
// ============================================================

class PermanentEmployee : public Employee
{
private:
    double basicSalary;           // Stores the basic salary.
    double allowance;             // Stores the allowance.

    // MODIFICATION: Stores the tax percentage.
    double taxRate;

public:

    // Constructor for PermanentEmployee.
    // MODIFICATION: taxRate added as a new parameter.
    PermanentEmployee(
        int id,
        string employeeName,
        double basic,
        double extra,
        double tax)
        : Employee(id, move(employeeName)),
          basicSalary(basic),
          allowance(extra),
          taxRate(tax)
    {
    }

    // Calculates the salary after tax deduction.
    double calculateSalary() const override
    {
        double grossSalary = basicSalary + allowance;
        
        // MODIFICATION: Calculate tax amount.
        double taxAmount = grossSalary * taxRate / 100.0;

        // MODIFICATION: Return salary after tax deduction.
        return grossSalary - taxAmount;
    }
};


// ============================================================
// CONTRACT EMPLOYEE CLASS
// ============================================================

class ContractEmployee : public Employee
{
private:
    double hourlyRate;            // Stores payment per hour.
    int hoursWorked;              // Stores the number of hours worked.

public:

    // Constructor for ContractEmployee.
    ContractEmployee(
        int id,
        string employeeName,
        double rate,
        int hours)
        : Employee(id, move(employeeName)),
          hourlyRate(rate),
          hoursWorked(hours)
    {
    }

    // Calculates salary based on hourly rate and hours worked.
    double calculateSalary() const override
    {
        return hourlyRate * hoursWorked;
    }
};


// ============================================================
// FREELANCE EMPLOYEE CLASS
// MODIFICATION 1: Newly added class.
// ============================================================

class FreelanceEmployee : public Employee
{
private:
    double projectAmount;         // Stores the project payment.
    int completedProjects;        // Stores number of completed projects.

public:

    // Constructor for FreelanceEmployee.
    FreelanceEmployee(
        int id,
        string employeeName,
        double amount,
        int projects)
        : Employee(id, move(employeeName)),
          projectAmount(amount),
          completedProjects(projects)
    {
    }

    // MODIFICATION 1:
    // Calculates salary based on project payment.
    double calculateSalary() const override
    {
        return projectAmount * completedProjects;
    }
};


// ============================================================
// DISPLAY PAYROLL INFORMATION
// ============================================================

void printPaySlip(const Employee& employee)
{
    // Display basic employee information.
    employee.displayBasicDetails();

    // Display calculated salary using runtime polymorphism.
    cout << "Salary: Rs. "
         << employee.calculateSalary()
         << "\n\n";
}


// ============================================================
// MAIN FUNCTION
// ============================================================

int
