#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Employee
{
    int empId;
    string empName, designation;
    float salary;

public:
    void getData()
    {
        cout << "Enter Employee ID: ";
        cin >> empId;

        cout << "Enter Employee Name: ";
        cin >> empName;

        cout << "Enter Designation: ";
        cin >> designation;

        cout << "Enter Salary: ";
        cin >> salary;
    }

    void writeData()
    {
        ofstream fout("employee.txt", ios::app);

        if (!fout)
        {
            cout << "Error opening file for writing!" << endl;
            return;
        }

        fout << empId << " "
             << empName << " "
             << designation << " "
             << salary << endl;

        fout.close();

        cout << "Employee record saved successfully!" << endl;
    }

    void readData()
    {
        ifstream fin("employee.txt");

        if (!fin)
        {
            cout << "Error opening file for reading!" << endl;
            return;
        }

        cout << "\n--- Employee Records ---\n";

        while (fin >> empId >> empName
                   >> designation >> salary)
        {
            cout << "\nEmployee ID: " << empId;
            cout << "\nEmployee Name: " << empName;
            cout << "\nDesignation: " << designation;
            cout << "\nSalary: " << salary << endl;
        }

        fin.close();
    }
};

int main()
{
    Employee e;
    int choice;

    do
    {
        cout << "\n1. Write Employee Record";
        cout << "\n2. Read Employee Records";
        cout << "\n3. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                e.getData();
                e.writeData();
                break;

            case 2:
                e.readData();
                break;

            case 3:
                cout << "Exiting program...";
                break;

            default:
                cout << "Invalid choice!";
        }

    } while (choice != 3);

    return 0;
}
