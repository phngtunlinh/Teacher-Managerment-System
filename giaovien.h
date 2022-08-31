#ifndef giaovien_h
#define giaovien_h
#include<iostream>
#include<fstream>
#include<string>
#include<windows.h>
using namespace std;
const string Data = "giaovien.txt";
class giaovien 
{
protected:
    string ID;
    string name;
    string subject;
    string grade;
public:
    giaovien();
    giaovien(string ID_, string name_, string subject_, string class_);
    bool compare(string input);
    void modify(int a);
    void write(string file);
    void output();
};
#endif



