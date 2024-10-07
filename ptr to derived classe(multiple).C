#include<iostream>
using namespace std;

class polygon
{
    protected:
        int wed,hig;
    public:
        virtual void area()
        {
           cout<<"lets clculate the area yo ho.....";
        }
};

class rectangle:public polygon
{
    protected:
    public:
        void area()
        {
            cout<<"\n enter width and hight for rectangle=";
            cin>>wed>>hig;
            cout<<"\n area of rectangle="<<wed*hig;
        }
};

class triangle:public polygon
{
    public:
        void area()
        {
            cout<<"\n enter width and hight for triangle=";
            cin>>wed>>hig;
            cout<<"\n area of triangle="<<(wed*hig)/2;
        }
};
int main()
{
    polygon p1,*ptr;
    rectangle r1;
    triangle t1;
    ptr=&p1;
    ptr->area();
    ptr=&r1;
    ptr->area();
    ptr=&t1;
    ptr->area();
    
}