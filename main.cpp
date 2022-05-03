#include "通讯录管理系统.h"

int main(){
    TongXun tx;

    int select = 0;
    while(true){
        showMenu();
        cout << "请选择你的操作：" << endl;
        cin >> select;
        switch(select){
            case 1:  //添加联系人
                addLianXiRen(&tx);
                break;
            case 2:  //显示联系人
                printLianXiRen(&tx);
                break;
            case 3:  //删除联系人
                delLianXiRen(&tx);
                break;
            case 4:  //查找联系人
                findLianXiRen(tx);
                break;
            case 5:  //修改联系人
                alterLianXiRen(&tx);
                break;
            case 6:  //清空联系人
                clearLianXiRen(&tx);
                break;
            case 0:  //退出通讯录
                cout << "欢迎下次使用！！！" << endl;
                exit(0);
                break;
            default :
                break;
        }
    }

    
    return 0;
} 