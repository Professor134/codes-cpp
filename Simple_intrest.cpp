#include<iostream>
using namespace std;

class staff
{
    float s, p, t;
    static int r;
public:
    void set()
    {
        cout << "\n enter amount, time in year, rate=" << endl;
        cin >> p>>t;
    }
    void show();

    void cal()
    {
        s = (p* staff::r * t)/100;
    }
};
int staff :: r=15;
void staff :: show()
{
    cout << "si="<<s<<endl;
}

int main()
{
    staff s;
    s. set();
    s. cal();
    s. show();
}