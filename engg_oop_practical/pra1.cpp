//Design and implement a C++ program to create a class Student with data members for roll number,
//name, and marks. Implement member functions to accept and display the student details
#include<iostream>
using namespace std;

class Student {
    int rollno;
    char name[20];
    float marks;
    public:
        void accept() {
            cout << "Enter roll number:";
            cin >> rollno;
            cout << "Enter name:";
            cin >> name;
            cout << "Enter marks:";
            cin >> marks;
        };
        void display() {
            cout << "roll number:" << rollno << endl;
            cout << "name:" << name << endl;
            cout << "marks:" << marks << endl;
        }
};

int main() {
    Student s;
    s.accept();
    s.display();
    return 0;
};