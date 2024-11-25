//compare two strings using'==' operator overloading

#include<iostream>
#include<string.h>
using namespace std;

class staff
{
    char str[20];
public:
    void set()
    {
        cout << "\n enter the str=" << endl;
        cin >> str;
    }
    void show();

    void operator ==(staff y)
    {
        if(strcmp(str, y. str)==0) 
        cout << "same" << endl;
        else
        cout << "diff" << endl;
    }
};
void staff :: show()
{
    cout << "str="<<str;
}


int main()
{
    staff s1, s2;
    s1. set();
    s2. set();
    s1. show();
    s2. show();
    s1==s2;

}