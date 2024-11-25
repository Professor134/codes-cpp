//exchange the values of two variables using friend function.

#include<iostream>
using namespace std;

class staff
{
    int num;
public:
    void set()
    {
        cout << "\n enter the num=" << endl;
        cin >> num;
    }
    void show();

    friend void cal(staff &x, staff &y);
};
void staff :: show()
{
    cout << "num="<<num;
}

void cal(staff &x, staff &y )
{
    staff z;
    z. num=x.num;
    x. num=y.num;
    y. num=z.num;
}
int main()
{
    staff s1, s2;
    s1. set();
    s2. set();
    cout << "before swap" << endl;
    s1. show();
    s2. show();
    cal(s1, s2);
    cout << "after swap" << endl;
    s1. show();
    s2. show();

}