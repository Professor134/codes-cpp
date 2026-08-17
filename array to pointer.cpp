#include<iostream>
using namespace std;
class birthday
{
    int d, m, y;
public:
    void set ()
    {

        cout << "Enter d, m, y=" << endl;
        cin >> d>>m>>y;
    }
    void show()
    {
        cout <<"\n date"<< d<<"/"<<m<<"/"<<y << endl;
    }

};
int main()
{
    birthday *p, *q;
    int i, n=3;
    p=q=new birthday[n];
    for(i=0; i<n; i++)
    {
        p->set();
        p++;
    }
    for(i=0; i<n; i++)
    {
        q->show();
        q++;;
    }
}
