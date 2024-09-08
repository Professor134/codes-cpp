//WAP TO SHOW NO OF VOWELS FROM FILE
#include<iostream>
#include<fstream>
using namespace std;
 int main()
 {
    char al;
    int cc=0;
    ifstream iff;
    iff.open("copy.txt",ios::in);
    while (!iff.eof())
    {
      iff.get(al);
      if (al=='a'||al=='e'||al=='i'||al=='o'||al=='u')
      {
         cc++;
      }
   }
    cout<<"\n no of vowel in file="<<cc;
 }


