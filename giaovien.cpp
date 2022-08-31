#include "giaovien.h"

giaovien :: giaovien() { //constructor no variable
            ID = "ID";
            name = "name";
            subject = "subject";
            grade = "class";
        }
giaovien :: giaovien(string ID_, string name_, string subject_, string class_) {//constructor with variable
            name = name_;
            subject = subject_;
            grade = class_;
            ID = ID_;
        }
bool giaovien :: compare(string input)
        {
            if (ID == input) return true; else return false;
        }
void giaovien ::   modify(int a)
        {
            string change;
            if (a == 1) {
                cout << "Nhap lai thong tin ma giao vien sau chinh sua: "; cin >> change; ID = change;
            }
            if (a == 2) {
                cout << "Nhap lai thong tin ten giao vien sau chinh sua: "; cin.ignore(); getline(cin, change); name = change;
            }
            if (a == 3) {
                cout << "Nhap lai thong tin mon hoc sau chinh sua: "; cin.ignore(); getline(cin, change); subject = change;
            }
            if (a == 4) {
                cout << "Nhap lai thong tin lop chu nhiem sau chinh sua: "; cin.ignore(); getline(cin, change); grade = change;
            }
        }
void giaovien ::   write(string file) {
            ofstream filedata;
            filedata.open(file, ios::app);
            filedata << ID << "," << name << "," << subject << "," << grade << "\n";
            filedata.close();
        }
void giaovien ::   output() {
            cout << ID << "   ||   " << name << "   ||   " << subject << "   ||   " << grade << endl << endl;
        }
