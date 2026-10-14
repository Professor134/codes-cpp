
#include <iostream>
#include <string>
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
};

// Derived class: Permanent Employee
class PermanentEmployee : public Employee
{
public:
    void calculateSalary() override
    {
        float hra = basicSalary * 0.20;
        float da = basicSalary * 0.10;
        float total = basicSalary + hra + da;

        cout << "\n--- Permanent Employee ---" << endl;
        cout << "Employee ID: " << empId << endl;
        cout << "Employee Name: " << empName << endl;
        cout << "Basic Salary: " << basicSalary << endl;
        cout << "HRA (20%): " << hra << endl;
        cout << "DA (10%): " << da << endl;
        cout << "Total Salary: " << total << endl;
    }
};

// Derived class: Contract Employee
class ContractEmployee : public Employee
{
public:
    void calculateSalary() override
    {
        float allowance = basicSalary * 0.05;
        float total = basicSalary + allowance;

        cout << "\n--- Contract Employee ---" << endl;
        cout << "Employee ID: " << empId << endl;
        cout << "Employee Name: " << empName << endl;
        cout << "Basic Salary: " << basicSalary << endl;
        cout << "Contract Allowance (5%): "
             << allowance << endl;
        cout << "Total Salary: " << total << endl;
    }
};

int main()
{
    PermanentEmployee p;
    ContractEmployee c;

    cout << "Enter Permanent Employee Details\n";
    p.getDetails();

    cout << "\nEnter Contract Employee Details\n";
    c.getDetails();

    // Base class pointer
    Employee *ptr;

    // Calling PermanentEmployee function
    ptr = &p;
    ptr->calculateSalary();

    // Calling ContractEmployee function
    ptr = &c;
    ptr->calculateSalary();

    return 0;
}
