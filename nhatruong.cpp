#include "nhatruong.h"

    void nhatruong :: createInfo(giaovien tch) {//function 1
        system("cls");
        giaovien* teacher;
        load_Info(teacher);
        int count = countLine(Data);
        cout << "\n\n\n\n\n\n";
        cout << "\t\t\t\t    --------------------------\n";
        cout << "\t\t\t\t    |NHAP THONG TIN GIAO VIEN|\n";
        cout << "\t\t\t\t    --------------------------\n";
        cout << "\n\n\t1. Nhap ma giao vien (vi du: GV1)              : "; cin >> ID;
        for (int i = 0; i < count; i++)
            while (teacher[i].compare(ID) == true)
            {
                cout << "\n\tDa bi trung thong tin ma giao vien, vui long nhap lai: "; cin >> ID;
            }
        cout << "\n\n\t2. Nhap ho va ten giao vien                    : "; cin.ignore(); getline(cin, name);
        cout << "\n\n\t3. Nhap mon hoc giao vien                      : "; cin.ignore(); getline(cin, subject);
        cout << "\n\n\t4. Nhap lop giao vien chu nhiem (vi du: K61DB) : "; cin.ignore(); getline(cin, grade);
        char choice1;
        cout << "\n\n\n\n\t Ban co muon luu lai thong tin khong [Y/N]?     "; cin >> choice1;
        ofstream filedata;
        if ((choice1 == 'Y') || (choice1 == 'y')) {
            filedata.open(Data, ios::app); 
            filedata << ID << "," << name << "," << subject << "," << grade << "\n";
            filedata.close();
            cout << "Da luu data thanh cong!\n\n";
            char choice2; cout << "Ban co muon tiep tuc bo sung thong tin moi khong? [Y/N]  "; cin >> choice2;
            if ((choice2 == 'Y') || (choice2 == 'y'))
                createInfo(tch);
            else
            {
                system("pause"); menu();
            }
        }
        else { cout << "Huy bo luu data!\n\n"; system("pause"); menu(); }
    }
    void nhatruong :: searchInfo() {//function 2
        int count = countLine(Data); int note;
        giaovien* teacher;
        load_Info(teacher);
        system("cls");
        string ID_search;
        cout << "Nhap ma giao vien can tim: "; cin >> ID_search; system("cls");
        int i; int check = 0; char choice, choice2;
        for (i = 0; i < count; i++)
            if (teacher[i].compare(ID_search) == true)
            {
                check++; note = i;
            }
        if (check == 1) {
            cout << "\t\tHien thi thong tin giao vien: " << endl << endl;
            cout << "Ma giao vien   ||   Ten giao vien   ||   Mon hoc   ||   Lop chu nhiem";
            cout << "\n=====================================================================\n";
            teacher[note].output();
            cout << "Ban co muon tiep tuc tim kiem khong? [y/n]  "; cin >> choice;
            if ((choice == 'Y') || (choice == 'y'))
                searchInfo();
            else { cout << "\nNhan phim bat ky de quay lai menu!" << endl; system("pause"); menu(); }
        }
        if (check == 0) {
            cout << "\nKhong tim thay thong tin!\n";
            cout << "Ban co muon thao tac lai khong? [y/n]  "; cin >> choice;
            if ((choice == 'Y') || (choice == 'y'))
                searchInfo();
            else { cout << "\nNhan phim bat ky de quay lai menu!" << endl; system("pause"); menu(); }
        }
    };
    void nhatruong :: listInfo()//function 3
    {
        giaovien* teacher;
        load_Info(teacher);
        system("cls");
        cout << "\t\t\tDANH SACH GIAO VIEN\n";
        cout << "=====================================================================\n";
        cout << "Ma giao vien   ||   Ten giao vien   ||   Mon hoc   ||   Lop chu nhiem";
        cout << "\n=====================================================================\n";
        int i;
        int count = countLine(Data);
        for (i = 0; i < count; i++)
            teacher[i].output();
        cin.sync(); cout << "\n\nNhan phim bat ky de quay lai Menu\n\n";
        system("pause"); menu();
    }
    void nhatruong :: modifyInfo() {//function 4
        giaovien* teacher;
        load_Info(teacher);
        system("cls");
        int count = countLine(Data);
        string ID_modify;
        cout << "Nhap ma giao vien cua thong tin can chinh sua: "; cin >> ID_modify; system("cls");
        int i; int check = 0; int note;
        for (i = 0; i < count; i++)
            if (teacher[i].compare(ID_modify) == true)
            {
                check++; note = i;
            }
        if (check == 0)
        {
            cout << "\nKhong tim thay thong tin!";
        }
        else
        {
            int choice;
            cout << "\n\t\tChon hang muc can chinh sua: ";
            cout << "\n\t1. Chinh sua ma giao vien. ";
            cout << "\n\t2. Chinh sua ten giao vien. ";
            cout << "\n\t3. Chinh sua mon hoc. ";
            cout << "\n\t4. Chinh sua lop chu nhiem. ";
            cout << "\n\t5. Huy bo thao tac. ";
            cout << "\n\n\tVui long chon cac chuc nang tren: "; cin >> choice;
            while (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5)
            {
                cout << "Khong co chuc nang nay, vui long nhap lai: "; cin >> choice;
            }
            if (choice != 5)
            {
                teacher[note].modify(choice);
                clearFile(Data);
                for (int j = 0; j < count; j++)
                    teacher[j].write(Data);
                cout << "\nChinh sua thong tin thanh cong!\n";
                char choice2; cout << "Ban co muon thao tac lai khong? [Y/N]  "; cin >> choice2;
                if ((choice2 == 'Y') || (choice2 == 'y'))
                    modifyInfo();
                else { cout << "\nNhan phim bat ky de quay lai menu!" << endl; system("pause"); menu(); }
            }
            else {
                cout << "\nNhan phim bat ky de quay lai menu!" << endl; system("pause"); menu();
            }
        }
    }
    void nhatruong :: deleteInfo() {//function 5
        giaovien* teacher;
        int count = countLine(Data);
        load_Info(teacher);
        system("cls");
        string ID_delete;
        cout << "Nhap ma giao vien cua thong tin can xoa: "; cin >> ID_delete; system("cls");
        int i; int check = 0; int note; char choice;
        for (i = 0; i < count; i++)
            if (teacher[i].compare(ID_delete) == true)
            {
                check++; note = i;
            }
        if (check == 0) {
            cout << "\nKhong tim thay thong tin!" << endl;
            cout << "Ban co muon thao tac lai khong? [Y/N]  "; cin >> choice;
            if ((choice == 'Y') || (choice == 'y'))
                deleteInfo();
            else { cout << "\nNhan phim bat ky de quay lai menu!" << endl; system("pause"); menu(); }
        }
        else {
            for (int j = note; j < count - 1; j++) teacher[j] = teacher[j + 1];
            clearFile(Data);
            for (int j = 0; j < count - 1; j++)
                teacher[j].write(Data);
            cout << "\nXoa thong tin thanh cong!\n";
            cout << "Ban co muon thao tac lai khong? [Y/N]  "; cin >> choice;
            if ((choice == 'Y') || (choice == 'y'))
                deleteInfo();
            else { cout << "\nNhan phim bat ky de quay lai menu!" << endl; system("pause"); menu(); }
            cout << "\nNhan phim bat ky de quay ve menu!\n";
            system("pause"); menu();
        }
    }
    void nhatruong :: deleteAll() {//function 6
        char choice;
        cout << "Ban co chac chan muon xoa toan bo danh sach khong? [y/n]  ";
        cin >> choice;
        if ((choice == 'Y') || (choice == 'y'))
        {
            string pass; string word = "admin";
            cout << "\nVui long nhap mat khau: "; cin >> pass;
            if (pass == word) {
                clearFile(Data);
                cout << "\nDa xoa toan bo thong tin" << endl << endl << "Nhan nut bat ky de quay lai menu chinh" << endl;
                system("pause"); menu();
            }
            else {
                cout << "\nSai mat khau, nhan nut bat ky de quay lai menu chinh" << endl;
                system("pause"); menu();
            }
        }
    }
