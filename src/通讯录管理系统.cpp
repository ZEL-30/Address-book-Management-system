#include "通讯录管理系统.h"

void Pause(){
    system("echo 按任意键继续... ");
    system("read -n 1");
}

void showMenu(){
    cout << "*************************" << endl;
	cout << "***** 1、添加联系人 *****" << endl;
	cout << "***** 2、显示联系人 *****" << endl;
	cout << "***** 3、删除联系人 *****" << endl;
	cout << "***** 4、查找联系人 *****" << endl;
	cout << "***** 5、修改联系人 *****" << endl;
	cout << "***** 6、清空联系人 *****" << endl;
	cout << "***** 0、退出通讯录 *****" << endl;
	cout << "*************************" << endl;
}

void addLianXiRen(TongXun* tx){

    //判断通讯录是否已满
    if(tx->id == Max){
        cout << "通讯录已满，请删除联系人" << endl;
        Pause();
        system("clear");
    }else{
        cout << "请根据提示输入信息：" << endl;
		cout << "新增联系人姓名：" << endl;
        cin >> tx->Lx[tx->id].Name;
		cout << "新增联系人性别：" << endl;
        while(true){
            cout << "1 -- 男" << endl;
		    cout << "2 -- 女" << endl;
		    cin >> tx->Lx[tx->id].Gender;
            if(tx->Lx[tx->id].Gender >= 1 && tx->Lx[tx->id].Gender <= 2)     break;
        }
		cout << "新增联系人年龄：" << endl;
		cin >> tx->Lx[tx->id].Age;
		cout << "新增联系人联系电话：" << endl;
		cin >> tx->Lx[tx->id].Tel;
		cout << "新增联系人家庭住址：" << endl;
		cin >> tx->Lx[tx->id].Address;
		tx->id++;
		cout << "添加联系人成功！" << endl;
		Pause();
		system("clear");
    }
    
}

void printLianXiRen(TongXun* tx){
    if(tx->id == 0){
        cout << "记录为空，请添加联系人" << endl;
        Pause();
		system("clear");
    }else{
        cout << "您的通讯录的联系人有 " << tx->id << " 人" << endl;
        for(int i = 0;i < tx->id;i++){
            cout << "姓名：" << tx->Lx[i].Name << "\t性别：" << (tx->Lx[i].Gender == 1 ? "男" : "女") << "\t年龄：" << tx->Lx[i].Age
				<< "\t联系电话：" << tx->Lx[i].Tel << "\t家庭住址：" << tx->Lx[i].Address << endl;
        }
        Pause();
		system("clear");
    }
    
}

int findId(string name,TongXun tx){
    for(int i = 0;i < tx.id;i++){
        if(tx.Lx[i].Name == name){
            return i;
        }
    }
    return -1;
}

void delLianXiRen(TongXun* tx){
    string name  = "";
    cout << "请输入你要删除的联系人的姓名：" << endl;
    cin >> name;
    int Id = findId(name,*tx);
    if(Id != -1){
        tx->id--;
        cout << tx->Lx[Id].Name << "已删除" << endl;
        Pause();
        system("clear");
    }else{
        cout << "查无此人" << endl;
        Pause();
        system("clear");
    }
}

void findLianXiRen(TongXun tx){
    string name = "";
    cout << "请输入你要查找的联系人姓名：" << endl;
    cin >> name;
    int Id = findId(name,tx);
    if(Id != -1){
        cout << "姓名：" << tx.Lx[Id].Name << "\t性别：" << (tx.Lx[Id].Gender == 1 ? "男" : "女") << "\t年龄：" << tx.Lx[Id].Age
				<< "\t联系电话：" << tx.Lx[Id].Tel << "\t家庭住址：" << tx.Lx[Id].Address << endl;
        Pause();
        system("clear");
    }else{
        cout << "查无此人" << endl;
        Pause();
        system("clear");
    }
}

void alterLianXiRen(TongXun* tx){
    string name = "";
    cout << "请输入你要修改的联系人姓名：" << endl;
    cin >> name;
    int Id = findId(name,*tx);
    if(Id != -1){
        cout << "请根据提示输入信息：" << endl;
		cout << "修改联系人姓名：" << endl;
        cin >> tx->Lx[Id].Name;
		cout << "修改联系人性别：" << endl;
        while(true){
            cout << "1 -- 男" << endl;
		    cout << "2 -- 女" << endl;
		    cin >> tx->Lx[Id].Gender;
            if(tx->Lx[Id].Gender >= 1 && tx->Lx[Id].Gender <= 2)     break;
        }
		cout << "修改联系人年龄：" << endl;
		cin >> tx->Lx[Id].Age;
		cout << "修改联系人联系电话：" << endl;
		cin >> tx->Lx[Id].Tel;
		cout << "修改联系人家庭住址：" << endl;
		cin >> tx->Lx[Id].Address;
		cout << "修改联系人成功！" << endl;
		Pause();
		system("clear");
    }else{
        cout << "查无此人" << endl;
        Pause();
        system("clear");
    }


}

void clearLianXiRen(TongXun* tx){
    int select = 0;
    cout << "确认清空通讯录吗？" << endl;
    cout << "1、确认" << endl;
    cout << "2、取消" << endl;
    cin >> select;
    if(select == 1){
        tx->id = 0;
        cout << "通讯录已清空！" << endl;
        Pause();
        system("clear");
    }else{
        Pause();
        system("clear");
    }
        
}