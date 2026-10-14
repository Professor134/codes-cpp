
#include <iostream>
using namespace std;

// Base class
class Employee
{
protected:
    int empId;
    string empName;
    float basicSalary;

public:
    void getDetails()
    {
        cout << "Enter Employee ID: ";
        cin >> empId;

        cout << "Enter Employee Name: ";
        cin >> empName;

        cout << "Enter Basic Salary: ";
        cin >> basicSalary;
    }

    virtual void calculateSalary()
    {
        cout << "Basic Salary: " << basicSalary << endl;
    }

    virtual void display()
    {
        cout << "\nEmployee ID: " << empId << endl;
        cout << "Employee Name: " << empName << endl;
        calculateSalary();
    }
};

// Derived class for permanent employees
class PermanentEmployee : public Employee
{
public:
    void calculateSalary() override
    {
        float hra = basicSalary * 0.20;
        float da = basicSalary * 0.10;
        float totalSalary = basicSalary + hra + da;

        cout << "Basic Salary: " << basicSalary << endl;
        cout << "HRA (20%): " << hra << endl;
        cout << "DA (10%): " << da << endl;
        cout << "Total Salary: " << totalSalary << endl;
    }
};

// Derived class for contract employees
class ContractEmployee : public Employee
{
public:
    void calculateSalary() override
    {
        float allowance = basicSalary * 0.05;
        float totalSalary = basicSalary + allowance;

        cout << "Basic Salary: " << basicSalary << endl;
        cout << "Contract Allowance (5%): "
             << allowance << endl;
        cout << "Total Salary: " << totalSalary << endl;
    }
};

// Main function
int main()
{
    PermanentEmployee p;
    ContractEmployee c;

    cout << "\nEnter Permanent Employee Details\n";
    p.getDetails();

    cout << "\nEnter Contract Employee Details\n";
    c.getDetails();

    cout << "\n--- Permanent Employee Salary Details ---";
    p.display();

    cout << "\n--- Contract Employee Salary Details ---";
    c.display();

    return 0;
}
