#ifndef nhatruong_h
#define nhatruong_h
#include "giaovien.h"
void menu();
int countLine(string Data_);
void load_Info(giaovien*& teacher);
void clearFile(string file);
void exitProgram();
class nhatruong : public giaovien
{
public:
    void createInfo(giaovien tch);
    void searchInfo();
    void listInfo();
    void modifyInfo();
    void deleteInfo();
    void deleteAll();
};
#endif*/


