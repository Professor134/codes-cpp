/*
   Write a C++ program declare a class "polygon" having data 
   members width and height. Derive classes "rectangle" and 
   "triangle" from "polygon" having area() as a member function.
   Calculate area of triangle and rectangle using pointer to derived class object.
*/


#include<iostream>
using namespace std;

class polygon
{
public:
    virtual void area(int l, int b)=0;
};

class rectangle :public polygon
{
public:
    void area(int l, int b)
    {
        cout << "area of rect "<<(l*b) << endl; 
    }
    
};
class triangle :public polygon
{
 protected:
 float a;
public:
    void area(int l, int b)
    {
        cout << "area of tri "<<((l*b)/2) << endl; 
    }
    
};
int main()
{
    polygon *ptr;
   rectangle r;
   triangle t;
   ptr=&t;
    ptr->area(4,5);
   ptr=&r;
    ptr->area(5,4); 
}