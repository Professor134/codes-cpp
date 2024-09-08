//WAP TO SHOW NO OF SPACE, TAB,NEW LINE,CHARECTER FROM FILE
#include<iostream>
#include<fstream>
using namespace std;
 int main()
 {
    char p;
    int cc=0,cs=0,ct=0,cn=0;
    ifstream iff;
    iff.open("copy.txt",ios::in);
    while (!iff.eof())
    {
      iff.get(p);
      if (p=='\t')
      {
         ct++;
      }
      else if (p=='\n')
      {
         cn++;
      }
      else if (p==' ')
      {
         cs++;
      }
      else 
      {
         cc++;
      }
   }
    cout<<"\n no of charecter in file="<<cc;
    cout<<"\n no of tabs in file="<<ct;
    cout<<"\n no of new line in file="<<cn;
    cout<<"\n no of space in file="<<cs;
 }
