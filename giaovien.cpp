#include<iostream>
#include<sstream>
#include<fstream>
#include<string.h>
#include<windows.h>
using namespace std;
//khai báo các chức năng chính của chương trình
class giaovien;
void menu_gv(); //menu thao tác
int countLine(string Data_); //hàm đếm số phần tử lưu trong file
void load_Info(giaovien *&teacher); //hàm lấy data trong file
void clearFile(string file); //hàm xoá toàn bộ data trong file
void exitProgram(); //hàm thoát chương trình
//các hàm xử lý cho kiểu dữ liệu giáo viên========================================================
const string Data_gv = "giaovien.txt";
class giaovien{
    private:
        string ID_gv;
        string name_gv;
        string subject_gv;
        string class_gv;
    public:
        giaovien(){ //constructor no variable
            ID_gv = "ID";
            name_gv = "name";
			subject_gv = "subject";
			class_gv = "class";
        }
        giaovien (string ID_, string name_, string subject_, string class_){//constructor with variable
			name_gv = name_;
			subject_gv = subject_;
			class_gv = class_;
			ID_gv = ID_;
		}
        bool check(int count, giaovien *&tch, giaovien gv){
            load_Info(tch);
            int i;
            int length = gv.ID_gv.length();
            for (i=0; i<length;i++)
                if (gv.ID_gv[i] == '\n') gv.ID_gv.erase(i);
            int j=0;
            for (i=0; i<count; i++)
                if (tch[i].ID_gv == gv.ID_gv)  j++;
            if (j==0) return true; else return false;            
        }
        void createInfo_gv(int count, giaovien *&tch, giaovien gv)//chức năng số 1
            {   system("cls");//xoá màn hình
                cout << "\n\n\n\n\n\n";
                cout <<"\t\t\t\t    --------------------------\n";
                cout <<"\t\t\t\t    |NHAP THONG TIN GIAO VIEN|\n";
                cout <<"\t\t\t\t    --------------------------\n";
                cout << "\n\n\t1. Nhap ma giao vien (vi du: GV1)              : "; cin >> gv.ID_gv;
                while (check(count, tch, gv) == false) 
                    {
                        cout << "\n\tDa ton tai ma giao vien nay, vui long nhap lai!" <<endl;
                        cout << "\n\n\t1. Nhap ma giao vien (vi du: GV1)              : "; cin >> gv.ID_gv;
                    }
                cout << "\n\n\t2. Nhap ho va ten giao vien                    : "; cin.ignore(); getline(cin, gv.name_gv);
                cout << "\n\n\t3. Nhap mon hoc giao vien                      : "; cin.sync(); getline(cin, gv.subject_gv);
                cout << "\n\n\t4. Nhap lop giao vien chu nhiem (vi du: K61DB) : "; cin.sync(); getline(cin, gv.class_gv);
                char choice1;
                cout << "\n\n\n\n\t Ban co muon luu lai thong tin khong [Y/N]?     "; cin >> choice1;
                ofstream filedata;
                if ((choice1== 'Y') || (choice1 == 'y'))
                    {filedata.open (Data_gv, ios :: app); //đặt con trỏ về cuối file, sẽ ghi data mới vào cuối file
  	                filedata <<gv.ID_gv << "," << gv.name_gv << "," << gv.subject_gv << "," << gv.class_gv<<"\n";
  	                filedata.close();
                    cout << "Da luu data thanh cong!\n\n"; 
                    char choice2; cout << "Ban co muon tiep tuc bo sung thong tin moi khong? [Y/N]  "; cin >> choice2;
                    if ((choice2 == 'Y') || (choice2 == 'y'))
                        gv.createInfo_gv(count, tch, gv);
                    else
                        {system("pause"); menu_gv();}
                    }
                else {cout << "Huy bo luu data!\n\n"; system("pause"); menu_gv();}
            }
        void searchInfo_gv(int count, giaovien *&tch, giaovien gv){//chức năng số 2
            load_Info(tch);
            system("cls");
            string ID_search;
            cout <<"Nhap ma giao vien can tim: "; cin >> ID_search; system("cls");
            int i; int check = 0; char choice, choice2;
            for (i=0; i<count; i++)
                if(tch[i].ID_gv == ID_search)
                {   check = 1;
                    cout << "\t\tHien thi thong tin giao vien: "<< endl;
                    cout << "Ma giao vien : " << tch[i].ID_gv << endl;
                    cout << "Ten giao vien: " << tch[i].name_gv << endl;
                    cout << "Mon hoc      : " << tch[i].subject_gv << endl;
                    cout << "Lop chu nhiem: " << tch[i].class_gv << endl<<endl;
                    cout << "Ban co muon tiep tuc tim kiem khong? [y/n]  "; cin >> choice;
                    if ((choice == 'Y') || (choice == 'y'))
                        gv.searchInfo_gv(count, tch, gv);
                    else {cout << "\nNhan phim bat ky de quay lai menu!"<<endl; system("pause"); menu_gv();}
                }
            if (check == 0) 
            {   cout << "\nKhong tim thay thong tin!\n"; 
                cout << "Ban co muon thao tac lai khong? [y/n]  "; cin >> choice;
                if ((choice == 'Y') || (choice == 'y'))
                    gv.searchInfo_gv(count, tch, gv);
                else {cout << "\nNhan phim bat ky de quay lai menu!"<<endl; system("pause"); menu_gv();}
            }
        };
        void listInfo_gv(int count, giaovien *&tch, giaovien gv)//chức năng số 3
            {   load_Info(tch);
                system("cls");
                cout << "\t\t\tDANH SACH GIAO VIEN\n";
                cout << "=====================================================================\n";
                cout << "Ma giao vien   ||   Ten giao vien   ||   Mon hoc   ||   Lop chu nhiem";
                cout << "\n=====================================================================\n";
                int i;
                for (i=0; i<count; i++){
                    cout << tch[i].ID_gv << "   ||   " << tch[i].name_gv <<"   ||   " <<tch[i].subject_gv << "   ||   " << tch[i].class_gv << endl << endl;
                }
                cin.sync(); cout << "\n\nNhan phim bat ky de quay lai Menu\n\n";
                system("pause"); menu_gv();
            }
        void modifyInfo_gv(int count, giaovien *&tch, giaovien gv){//chức năng số 4
            load_Info(tch); system("cls");
            string ID_modify;
            cout <<"Nhap ma giao vien cua thong tin can chinh sua: "; cin >> ID_modify; system("cls");
            int i; int check = 0; int note;
            for (i=0; i<count; i++)
                if(tch[i].ID_gv == ID_modify)
                {   check++; note = i;}
            if (check == 0 )
            {   cout << "\nKhong tim thay thong tin!";}
            else
            {   int choice;
                cout << "\n\t\tChon hang muc can chinh sua: ";
                cout << "\n\t1. Chinh sua ma giao vien. ";
                cout << "\n\t2. Chinh sua ten giao vien. ";
                cout << "\n\t3. Chinh sua mon hoc. ";
                cout << "\n\t4. Chinh sua lop chu nhiem. ";
                cout << "\n\t5. Huy bo thao tac. ";
                cout <<"\n\n\tVui long chon cac chuc nang tren: "; cin >> choice;
                switch(choice){
                    case 1: 
                        cout <<"Nhap lai thong tin ma giao vien sau chinh sua: "; cin >> tch[note].ID_gv; break;
                    case 2: 
                        cout <<"Nhap lai thong tin lop chu nhiem sau chinh sua: "; cin >> tch[note].name_gv; break;
                    case 3: 
                        cout <<"Nhap lai thong tin lop chu nhiem sau chinh sua: "; cin >> tch[note].subject_gv; break;
                    case 4:
                        cout <<"Nhap lai thong tin lop chu nhiem sau chinh sua: "; cin >> tch[note].class_gv; break;
                    case 5: 
                        menu_gv(); break;
                    default: 
                        cout << "Khong co chuc nang nay, vui long nhap lai: "; gv.modifyInfo_gv(count, tch, gv); break;
                }
                clearFile(Data_gv);
                for (int j = 0; j<count; j++)
                {   ofstream filedata;
                    filedata.open (Data_gv, ios :: app);
                    filedata <<tch[j].ID_gv << "," << tch[j].name_gv << "," << tch[j].subject_gv << "," << tch[j].class_gv<<"\n";
                    filedata.close();}
                cout << "\nChinh sua thong tin thanh cong!\n";
                char choice2; cout << "Ban co muon thao tac lai khong? [Y/N]  "; cin >> choice2;
                if ((choice2 == 'Y') || (choice2 == 'y'))
                        gv.modifyInfo_gv(count, tch, gv);
                    else {cout << "\nNhan phim bat ky de quay lai menu!"<<endl; system("pause"); menu_gv();}
            }
        };
        void deleteInfo_gv(int count, giaovien *&tch, giaovien gv){//chức năng số 5
            load_Info(tch); system("cls");
            string ID_delete;
            cout <<"Nhap ma giao vien cua thong tin can xoa: "; cin >> ID_delete; system("cls");
            int i; int check = 0; int note; char choice;
            for (i=0; i<count; i++)
                if(tch[i].ID_gv == ID_delete)
                {   check++; note = i;}
            if (check == 0 )
            {   cout << "\nKhong tim thay thong tin!" << endl;
                cout << "Ban co muon thao tac lai khong? [Y/N]  "; cin >> choice;
                if ((choice == 'Y') || (choice == 'y'))
                        gv.deleteInfo_gv(count, tch, gv);
                else {cout << "\nNhan phim bat ky de quay lai menu!"<<endl; system("pause"); menu_gv();}
                cout << "\nNhan phim bat ky de quay ve menu!\n";
            }
            else
            {   for (int j = note; j<count-1; j++) tch[j] = tch[j+1];
                clearFile(Data_gv);
                for (int j = 0; j<count-1; j++)
                {   ofstream filedata;
                    filedata.open (Data_gv, ios :: app);
                    filedata <<tch[j].ID_gv << "," << tch[j].name_gv << "," << tch[j].subject_gv << "," << tch[j].class_gv<<"\n";
                    filedata.close();}
                cout << "\nXoa thong tin thanh cong!\n";
                cout << "Ban co muon thao tac lai khong? [Y/N]  "; cin >> choice;
                if ((choice == 'Y') || (choice == 'y'))
                        gv.deleteInfo_gv(count, tch, gv);
                    else {cout << "\nNhan phim bat ky de quay lai menu!"<<endl; system("pause"); menu_gv();}
                cout << "\nNhan phim bat ky de quay ve menu!\n"; 
                system("pause"); menu_gv();
            }
            
        };
        void deleteAll_gv(){//chức năng số 6
            char choice;
            cout << "\n\n\t\tBan co chac chan muon xoa toan bo data khong? [Y/N]  "; cin >> choice;
            if ((choice == 'Y') || (choice == 'y'))
            {   clearFile(Data_gv);
                cout << "\n\n\t\tDa xoa toan bo thong tin!" << "\nNhan phim bat ky de quay ve menu!\n"; system("pause"); menu_gv();
            }
            else {cout << "\n\n\t\tXoa thong tin that bai!" << "\nNhan phim bat ky de quay ve menu!\n"; system("pause"); menu_gv();}
        }
        ~giaovien(){};
};
int main(){
    system("cls");
    menu_gv();
}
void menu_gv(){
    int choice;
    system("cls");
    cout << "\n\n\n\n\n\n";
    cout <<"\t\t\t\t    --------------------------------------\n";
    cout <<"\t\t\t\t    |HE THONG QUAN LY DANH SACH GIAO VIEN|\n";
    cout <<"\t\t\t\t    --------------------------------------\n";
    cout <<"\n\n\t\t1. Them thong tin giao vien.";
    cout <<"\n\n\t\t2. Tim kiem thong tin giao vien.";
    cout <<"\n\n\t\t3. Hien thi thong tin toan bo giao vien.";
    cout <<"\n\n\t\t4. Chinh sua thong tin giao vien.";
    cout <<"\n\n\t\t5. Xoa thong tin giao vien.";
    cout <<"\n\n\t\t6. Xoa toan bo thong tin giao vien.";
    cout <<"\n\n\t\t7. Thoat.";
    cout <<"\n\n\t\tVui long chon cac chuc nang tren: "; cin >> choice;
    giaovien tch; giaovien *teacher;
    int count = countLine(Data_gv);
    switch (choice){
        case 1: tch.createInfo_gv(count, teacher, tch); break;
        case 2: tch.searchInfo_gv(count, teacher, tch); break;
        case 3: tch.listInfo_gv(count, teacher, tch); break;
        case 4: tch.modifyInfo_gv(count, teacher, tch); break;
        case 5: tch.deleteInfo_gv(count, teacher, tch); break;
        case 6: tch.deleteAll_gv(); break;
        case 7: exitProgram(); break;
        default: cout << "Khong co chuc nang nay, vui long chon lai!"; menu_gv();
    }
}
int countLine(string Data_)
{
	ifstream Outfile;
	Outfile.open(Data_);
	int countL = 0;
	char c; Outfile.get(c);
	while (!Outfile.eof()) //eof = end of file
	{if (c == '\n') countL++;Outfile.get(c);}
    if (countL == 0 ) countL = 1;
	Outfile.close();
	return countL;
}
void load_Info(giaovien *&tch){
    int count = countLine(Data_gv); //count là số phần tử đang lưu trữ
    tch = new giaovien[count];
    ifstream file;
    string arr[4]; string line;
    int j=0; //j là số phần tử của mảng lưu trữ object
    file.open(Data_gv); 
    for (int i = 1; i <= count; i++)
    {   getline(file, line);
        ofstream In_temp; In_temp.open("temp.txt"); In_temp << line; In_temp.close();
        ifstream Out_temp; Out_temp.open("temp.txt");
        for (int k=0; k<=3;k++) getline(Out_temp, arr[k],',');
        giaovien temp(arr[0], arr[1], arr[2], arr[3]); tch[j] = temp; j++;
        Out_temp.close(); clearFile("temp.txt");
    }
    file.close();
}
void clearFile(string file){
    ofstream ofs(file, ios::out);
    ofs.close();}
void exitProgram(){
  system("cls");
  cout << "\n\n\n\n\t\t\t\t\tDA KHOAT KHOI CHUONG TRINH\n";
  system("pause"); exit(0);
}