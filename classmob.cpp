//WAP TO SHOW INFO OF MOBILE USING CLASS
#include<iostream>
#include<conio.h>
using namespace std;
class mobile
{
private:
    int pr;
    char nm[20];
public:
    void accept()
    {
        cout<<endl<<"enter prise=";
        cin>>pr;
        cout<<endl<<"enter name=";
        cin>>nm;
    }
    void display()
    {
        cout<<"prise="<<pr<<endl<<"name="<<nm;
    }
};
int main()
{
    mobile m1,m2;
    m1.accept();
    m1.display();
    m2.accept();
    m2.display();
}

