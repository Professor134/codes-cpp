#include<iostream>
using namespace std;

class staff
{
     float bs,ds, hra, gs;
     char name[20];
     public:
         void set()
         {
             cout << "\n enter the name and bs=" << endl;
             cin >> name >> bs;
         }
         void show()
         {
             cout << "name=" << name << endl;
             cout << "bs=" << bs << endl;
             cout << "ds=" << ds << endl;
             cout << "hra=" << hra << endl;
             cout << "gs=" << gs << endl;
         }
         void cal()
         {
             hra=(30 * bs)/100;
             ds=(74.5 * bs)/100;
             gs=bs+hra+ds;
         }
};
int main() 
{
     staff s;
     s. set();
     s. cal();
     s. show();
}