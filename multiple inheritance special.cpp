/*
   Write a C++ program to calculate the area and perimeter
    of rectangles using concept of inheritance

       +----------+        +----------------+
       |   Area |        | Perimeter  |
       | area()  |        | perimeter()|
       +----------+        +----------------+
            \                     /
             \                   /
              \                 /
               \               /
                \             /
            +----------------------------+
            |     Rectangle           |
            | Data members:      |
            |   length, breadth    |
            | Functions:              |
            |   void get_data()      |
            |  void display()        |
            +---------------------------+

*/


#include<iostream>
using namespace std;

class Area
{
 protected:
 float a;
public:
    float area(int l, int b)
    {
        a=l*b;
        return a;
    }
    
};
class perimeter
{
 protected:
 float p;
public:
    float pere(int l, int b)
    {
        p=2*(l+b);
        return p;
    }
    
};
class rect : public Area, public perimeter
{
protected:
    float len, bre;
public:
    void set()
    {
        cout << "\n enter len, bre=" << endl;
        cin>>len>>bre;
    }
    void show()
    {
        cout << "\n area==" <<area(len, bre)<< endl;
        cout << "\n pere=" <<pere(len, bre)<< endl;
    }
};
int main()
{
    rect s;
    s. set();
    s. show();
}