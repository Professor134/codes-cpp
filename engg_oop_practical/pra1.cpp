// Design and implement a C++ program to create a 
// class named Student with data members roll number, name, 
// and marks. Implement member functions to accept the student
//  details from the user and display the entered details. 
//  Create an object of the Student class and demonstrate the
//   functionality by calling the member functions.
#include<iostream>
using namespace std;

class Student {
    int rollno;
    char name[30];
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