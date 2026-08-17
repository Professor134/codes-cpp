// Design a C++ program to implement a class Bank Account that uses constructors to initialize
// account details and a destructor to indicate object destruction. Use a static data member to maintain
// the count of total bank accounts created.

#include<iostream>
#include<string.h>
using namespace std;

class BankAccount {
    int accountNumber;
    char accountHolderName[20];
    float balance;
    static int totalAccounts;
    public:
        BankAccount(int accNum, const char name[], float bal) {
            accountNumber = accNum;
            strcpy(accountHolderName, name);
            balance = bal;
            totalAccounts++;
        };
        void displaya() {
            cout << "accNo:" << accountNumber << endl;
            cout << "name:" << accountHolderName << endl;
            cout << "balance:" << balance << endl;
        };
        static void displayTotalAccounts() {
            cout << "Total bank accounts created:" << totalAccounts << endl;
        };
        ~BankAccount() {
            totalAccounts--;
            cout << "destructor for " << accountHolderName << endl;

        };
};

int  BankAccount::totalAccounts = 0;

int main() {
    BankAccount b1(101, "parth", 5089);
    BankAccount b2(102, "yash", 4354);

    b1.displaya();
    b2.displaya();
    BankAccount::displayTotalAccounts();
    
return 0;
};
