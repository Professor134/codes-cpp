#include<iostream>
using namespace std;

int main()
{
    char str[20],ch,*ptr;
    int falg=0;
    cout << "Enter str =" << endl;
    cin >> str;
    cout << "Enter ch =" << endl;
    cin >> ch;
    ptr=&str[0];
    while(*ptr != NULL)
    {
       if(ch==*ptr)
           falg=1;
       ptr++;    
    }
    if(falg==1)
           cout<<"char is found";
       else    
           cout<<"char is not found";
}