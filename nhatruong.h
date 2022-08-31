#ifndef nhatruong_h
#define nhatruong_h
#include "Menu_fuction.h"
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
#endif




