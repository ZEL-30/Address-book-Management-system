#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

#define Max 1000

struct LianXiRen{
    string   Name;
    int   Gender;
    int      Age;
    string   Tel;
    string   Address;
};

struct TongXun{
    int         id;
    LianXiRen   Lx[Max];  
};

void Pause();                                    //按任意键继续...

void showMenu();                                 //显示菜单栏

void addLianXiRen(TongXun* tx);                  //添加联系人

void printLianXiRen(TongXun* tx);                //显示联系人

int findId(string name,TongXun tx);                         //查找编号

void delLianXiRen(TongXun* tx);                             //删除联系人   

void findLianXiRen(TongXun tx);

void alterLianXiRen(TongXun* tx);                           //修改联系人

void clearLianXiRen(TongXun* tx);