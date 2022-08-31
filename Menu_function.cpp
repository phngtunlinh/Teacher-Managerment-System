#include "menu_fuction.h"
void menu() {
    int choice;
    system("cls");
    cout << "\n\n\n\n\n\n";
    cout << "\t\t\t\t    --------------------------------------\n";
    cout << "\t\t\t\t    |HE THONG QUAN LY DANH SACH GIAO VIEN|\n";
    cout << "\t\t\t\t    --------------------------------------\n";
    cout << "\n\n\t\t1. Them thong tin giao vien.";
    cout << "\n\n\t\t2. Tim kiem thong tin giao vien.";
    cout << "\n\n\t\t3. Hien thi thong tin toan bo giao vien.";
    cout << "\n\n\t\t4. Chinh sua thong tin giao vien.";
    cout << "\n\n\t\t5. Xoa thong tin giao vien.";
    cout << "\n\n\t\t6. Xoa toan bo thong tin giao vien.";
    cout << "\n\n\t\t7. Thoat.";
    cout << "\n\n\t\tVui long chon cac chuc nang tren: "; cin >> choice;
    giaovien tch; nhatruong school;
    switch (choice) {
    case 1: school.createInfo(tch); break;
    case 2: school.searchInfo(); break;
    case 3: school.listInfo(); break;
    case 4: school.modifyInfo(); break;
    case 5: school.deleteInfo(); break;
    case 6: school.deleteAll(); break;
    case 7: exitProgram(); break;
    default:
        cout << "\nKhong co chuc nang nay, vui long nhap lai: "; menu(); break;
    }
}
int countLine(string Data_)
{
    fstream Outfile;
    if (!Outfile)
    {
        Outfile.open(Data_, fstream::in | fstream::out | fstream::trunc);
        Outfile.close();
    }
    Outfile.open(Data_);
    int countL = 0;
    char c; Outfile.get(c);
    while (!Outfile.eof()) //eof = end of file
    {
        if (c == '\n') countL++; Outfile.get(c);
    }
    if (countL == 0) countL = 1;
    Outfile.close();
    return countL;
}
void load_Info(giaovien*& teacher) {
    int count = countLine(Data);
    teacher = new giaovien[count];
    ifstream file;
    string arr[4]; string line;
    int j = 0;
    file.open(Data);
    for (int i = 1; i <= count; i++)
    {
        getline(file, line);
        ofstream In_temp; In_temp.open("temp.txt"); In_temp << line; In_temp.close();
        ifstream Out_temp; Out_temp.open("temp.txt");
        for (int k = 0; k <= 3; k++) getline(Out_temp, arr[k], ',');
        giaovien temp(arr[0], arr[1], arr[2], arr[3]); teacher[j] = temp; j++;
        Out_temp.close(); clearFile("temp.txt");
    }
    file.close();
}
void clearFile(string file) {
    ofstream ofs(file, ios::out);
    ofs.close();
}
void exitProgram() {
    system("cls");
    cout << "\n\n\n\n\t\t\t\t\tDA KHOAT KHOI CHUONG TRINH\n";
    system("pause"); exit(0);
}
