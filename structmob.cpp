//WAP TO SHOW INFO OF MOBILE USING struct
#include<iostream>
#include<conio.h>
using namespace std;
struct mobile
{
    int pr;
    char nm[20];
};
int main()
{
    struct mobile m1,m2;
    cout<<endl<<"enter prise=";
    cin>>m1.pr;
    cout<<endl<<"enter name=";
    cin>>m1.nm;
    cout<<endl<<"enter prise=";
    cin>>m2.pr;
    cout<<endl<<"enter name=";
    cin>>m2.nm;
    cout<<"prise="<<m1.pr<<endl<<"name="<<m1.nm;
    cout<<"prise="<<m2.pr<<endl<<"name="<<m2.nm;
}
